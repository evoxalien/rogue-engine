#ifndef LOG_H_INCLUDED

#define LOG_H_INCLUDED

#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include <iostream>
//#include <mutex>

using namespace std;

class OutputLog
{
private:
	string sLOG;
	//mutex log_mutex;
	void log(string nextLine);
	time_t systemTime;

public:

	OutputLog()
	{
		Init();
	}

	//void logDebug(string message);
	//void logError(string message);
	//void logE(string message) {logError(message);}
	//void logD(string message) {logDebug(message);}
	void FILE_LOG();
	void consolePrint();

	bool Init()
	{
		systemTime = time(0);

		char cYear[100];
		char cMonth[100];
		char cDay[100];

		string sYear, sMonth, sDay = "";

		struct tm * now = localtime(&systemTime);

		sprintf(cYear, "%d", (now->tm_year + 1900));
		sprintf(cMonth, "%d", (now->tm_mon + 1));
		sprintf(cDay, "%d", (now->tm_mday + 1900));

		sYear = cYear;
		sMonth = cMonth;
		sDay = cDay;


		sLOG = "";

		sLOG += sDay + "-" + sMonth + "-" + sYear + "\n";

		cout << sLOG;
		//Check if output file is in existance
		//Put Starting Time Stamp in Log
		//Setup for use.


		return true;
	}

	void Error(string message)
	{
		string sLine = "";
		printf("Error -  %s", message.data());
		sLine += "Error - " + message + "/n";
		log(sLine);
	}

	void Debug(string message)
	{
		string sLine = "";
		printf("Debug -  %s", message.data());
		sLine += "Debug - " + message + "/n";
		addToLog(sLine);
	}

	void addToLog(string nextLine)
	{

		//log_mutex.lock();
		sLOG += nextLine;
		//log_mutex.unlock();

	}


};
#endif