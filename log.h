#ifndef LOG_H_INCLUDED

#define LOG_H_INCLUDED

#include <stdio.h>
#include <string>
#include <vector>
//#include <mutex>

class OutputLog
{
private:
	string sLOG;
	//mutex log_mutex;
	void log(string nextLine);

public:

	OutputLog()
	{
		sLOG = "";
	}

	//void logDebug(string message);
	//void logError(string message);
	//void logE(string message) {logError(message);}
	//void logD(string message) {logDebug(message);}
	void FILE_LOG();
	void consolePrint();

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