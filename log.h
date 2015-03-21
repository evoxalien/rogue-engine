#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <stdio.h>
#include <string>
#include <fstream>
#include <time.h>
#include <iostream>

using namespace std;

class OutputLog
{
private:

	ofstream log_file; //the output handle for the log file.
	string directory; //the directory that the log writes too.

public:

	bool print; //decides when the log should print to screen or not.
		//Logs always write to file regardless of printing to screen.
	
	OutputLog(string filename)
	{
		print = false; //Defaults to false so no output will show up in console.
		directory = "../../log/"; //Defaults to the same dirrectory as the exicutable
		string stemp = directory + filename; //Adds the file name to the directory
		log_file.open( stemp.data()); //Opens our new file for output
	}

	OutputLog(string filename, bool initPrint)
	{
		print = initPrint; //Takes user's pref.
		directory = "../../log/";
		string stemp = directory + filename;
		log_file.open( stemp.data());

	}

	~OutputLog()
	{
		log_file.close(); //On program close this closes the files.
	}

	template<typename T>
	OutputLog & operator << ( T& value) //This is where the magic happens.
	{
		log_file << value; //Overloaded redirection operator pushes to the log file any variable type passed in.
		if(print) //Only print if asked too.
			cout << value; 
		return *this; //Returns it self and sets up for the next << operator to add additional output.
	}
};

extern OutputLog debug_log;
extern OutputLog error_log;
extern OutputLog warning_log;

#endif

