#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>

using namespace std;

string convertToReadableTimestamp(time_t timestamp);

time_t convertToTimestamp( const string& readableTimestamp);

#endif // !UTILITIES_HPP

