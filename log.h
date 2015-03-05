#ifndef LOG_H_INCLUDED

#define LOG_H_INCLUDED

#include <stdio.h>
#include <string>
#include <fstream>
#include <time.h>
#include <iostream>
//#include <mutex>

using namespace std;

class OutputLog
{
private:

	ofstream log_file;
	string directory;

public:

	bool print;
	
	OutputLog(string filename)
	{
		print = false;
		directory = "";
		string stemp = directory + filename;
		log_file.open( stemp.data());
	}

	OutputLog(string filename, bool initPrint)
	{
		print = initPrint;
		directory = "";
		string stemp = directory + filename;
		log_file.open( stemp.data());

	}

	~OutputLog()
	{
		log_file.close();
	}

	template<typename T>
	OutputLog & operator << ( T& value) 
	{
		log_file << value;
		if(print)
			cout << value; 
		return *this;
	}

/*
	time_t systemTime;

	bool Init()
	{
		screenOutput = false;
		systemTime = time(0);

		char cYear[100];
		char cMonth[100];
		char cDay[100];

		string sYear, sMonth, sDay = "";

		struct tm * now = localtime(&systemTime);

		sprintf(cYear, "%d", (now->tm_year + 1900));
		sprintf(cMonth, "%d", (now->tm_mon + 1));
		sprintf(cDay, "%d", (now->tm_mday));

		sYear = cYear;
		sMonth = cMonth;
		sDay = cDay;


		sLOG = "";

		sLOG += " --- System Date: " + sMonth + "-" + sDay + "-" + sYear + " --- \n";

		cout << sLOG;
		//Check if output file is in existance
		//Put Starting Time Stamp in Log
		//Setup for use.

		return true;
	}
*/

};

extern OutputLog debug_log;
extern OutputLog warning_log;
extern OutputLog error_log;

#endif