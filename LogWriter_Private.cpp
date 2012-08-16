
#include <iostream>

#include "Utils.h"
#include "Enums.h"

#include "LogWriter_Private.h"

using namespace Logger;
using namespace std;

LogWriter::LogWriter() {}

LogWriter::LogWriter(string logPath, LogNameStyle logNameStyle, LogLevel logLevel) {

	string fileName = formatFileName(logPath, logNameStyle, logLevel);
	
	_file = new ofstream();
	_file->open(fileName.c_str());
}

string LogWriter::formatFileName(string logPath, LogNameStyle logNameStyle, LogLevel logLevel) {
	string fileName = logPath + "/";
	
	string alphaLogLevel = Utils::logLevelToString(logLevel);
	string numericLogLevel = Utils::intToString(logLevel);
	string date = Utils::getStringFilenameDate();
	
	switch (logNameStyle) {
		case Date:
			fileName += date;
			break;
		case AlphaLogLevel:
			fileName += alphaLogLevel;
			break;
		case NumericLogLevel:
			fileName += numericLogLevel;
			break;
		case Date_AlphaLogLevel:
			fileName += date + "_" + alphaLogLevel;
			break;
		case Date_NumericLogLevel:
			fileName += date + "_" + numericLogLevel;
			break;
		case AlphaLogLevel_Date:
			fileName += alphaLogLevel + "_" + date;
			break;
		case NumericLogLevel_Date:
			fileName += numericLogLevel + "_" + date;
			break;
		default:
			throw "Unknown Log Name Style.";
			break;
	}
	
	fileName += ".log";
	
	return fileName;
}

void LogWriter::writeLog(std::string message, LogLevel logLevel) {
	
	string logLine = Utils::logLevelToString(logLevel);
	logLine += "@";
	logLine += Utils::getStringDateTime();
	logLine += " : ";
	logLine += message;
	logLine += "\r\n";
	
	(*_file) << logLine;
	cerr << logLine;
	cout << logLine;
}

LogWriter::~LogWriter() {
	_file->close();
	delete _file;
	_file = 0;
}
