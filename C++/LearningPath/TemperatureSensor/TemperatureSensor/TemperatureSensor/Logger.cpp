#include <fstream>
#include <iostream>
#include "Logger.hpp"
#include "Utilities.hpp"

using namespace std;

void LogEvent(const string& level, const string& message) {
	
	ofstream logfile("log.txt", ios::app);
	// check and print error if file doesn't open
	if (!logfile)
	{
		cerr << "[ERROR] Unable to open log.txt" << endl;
		return;
	}

	logfile << "[" << convertToReadableTimestamp(time(nullptr)) << "]" << ":" << "[" << level << "]" << "," << message << endl;
	logfile.close();

}