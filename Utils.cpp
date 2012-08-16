
#include <sstream>
#include <ctime>
#include <cstdlib>

#include "Enums.h"

#include "Utils.h"

using namespace Logger;
using namespace std;

string Utils::logNameStyleToString(LogNameStyle value) {
	if ((value > NumericLogLevel_Date) || (value < UnknownName)) {
		throw "Unvalid Log Name Style";
	}
	else {
		string stringArray[] = {"UnknownName", "Date", "AlphaLogLevel", "NumericLogLevel", "Date_AlphaLogLevel", "Date_NumericLogLevel", "AlphaLogLevel_Date", "NumericLogLevel_Date"};
		
		return stringArray[value];
	}
}

LogNameStyle Utils::stringToLogNameStyle(string value) {
	
	for (int i = 0; i < NumericLogLevel_Date; i++) {
		if (value == logNameStyleToString((LogNameStyle)i)) {
			return (LogNameStyle)i;
		}
	}
}

string Utils::logLevelToString(LogLevel value) {
	if ((value > Critical) || (value < UnknownLevel)) {
		throw "Unvalid Log Level";
	}
	else {
		string stringArray[] = {"UnknownLevel", "Debug", "Info", "Warn", "Alert", "Critical"};
		
		return stringArray[value];
	}
}
			
string Utils::intToString(int value) {
	ostringstream stream;
	stream << value;
	return stream.str();
}

string Utils::getStringFilenameDate() {
	
	tm * formatedTime = getDay();
	
	ostringstream stream;
	stream << formatedTime->tm_year << "_" << formatedTime->tm_mon + 1 << "_" << formatedTime->tm_mday;
	
	free(formatedTime);
	
	return stream.str();
}

string Utils::getStringDateTime() {
	time_t timestamp;
	
	time(&timestamp);
	
	return ctime(&timestamp);
}

tm * Utils::getDay() {
	time_t timestamp;
	tm * formatedTime;
	
	time(&timestamp);
	formatedTime = localtime(&timestamp);
	
	formatedTime->tm_sec = -1;
	formatedTime->tm_min = -1;
	formatedTime->tm_hour = -1;
	formatedTime->tm_wday = -1;
	formatedTime->tm_yday = -1;
	
	return formatedTime;
}

