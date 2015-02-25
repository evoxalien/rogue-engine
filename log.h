#ifndef LOG_H_INCLUDED

#define LOG_H_INCLUDED

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


#define unint logDEBUG = 1;
#define unint logERROR = 2;

string log;

void logE(string message) {logError(message);}
void logD(string message) {logDebug(message);}

void logError(string message)
{
	printf("Error -  %s", message);
	log += "Error - " + message + "/n";
}

void logDebug(string message)
{
	printf("Debug -  %s", message);
	log += "Debug - " + message + "/n";
}


void consolePrint()
{

}

void FILE_LOG()


#endif