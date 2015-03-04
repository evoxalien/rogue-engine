#ifndef LOG_H_INCLUDED

#define LOG_H_INCLUDED

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
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
		directory = "logs/";
		string stemp = directory + filename;
		log_file.open( stemp.data());
	}

	OutputLog(string filename, bool initPrint)
	{
		print = initPrint;
		directory = "logs/";
		string stemp = directory + filename;
		log_file.open( stemp.data());
	}


	template<typename T>
	OutputLog & operator << ( T& value) 
	{
		log_file << value;
		if(print)
			cout << value; 
		return *this;
	}


};

extern OutputLog debug_log;
extern OutputLog warning_log;
extern OutputLog error_log;

#endif