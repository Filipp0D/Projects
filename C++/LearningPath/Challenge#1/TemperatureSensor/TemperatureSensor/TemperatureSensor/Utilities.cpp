#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;

string convertToReadableTimestamp(time_t timestamp) {
	char timebuffer[26];
	#ifdef WIN_32
	ctime_s(timebuffer, size(timebuffer), timestamp);
	#else
	strftime(timebuffer, size(timebuffer), "%c", localtime(&timestamp));
	#endif
	string readableTimestamp(timebuffer);

	if (readableTimestamp.empty() || readableTimestamp.back() == '\n') {
		readableTimestamp.pop_back();
	}

	return readableTimestamp;
}

time_t convertToTimestamp(const std::string& readableTimestamp) {
	tm tm = {};
	istringstream ss(readableTimestamp);

	// Il formato deve corrispondere a quello usato da "%c"
	ss >> std::get_time(&tm, "%c");

	if (ss.fail()) {
		throw std::runtime_error("Parsing del timestamp fallito: formato non valido.");
	}

	return std::mktime(&tm);  // Converte tm in time_t
}