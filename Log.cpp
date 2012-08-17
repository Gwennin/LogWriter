
#include <cstdlib>

#include "Utils.h"
#include "LogWriter_Private.h"
#include "Enums.h"

#include "Log.h"

using namespace std;
using namespace Logger;

LogWriter * Log::_writer = 0;
LogLevel Log::_lastLogLevel = UnknownLevel;
tm * Log::_lastday = Utils::getDay();
string Log::_logPath = "./";
LogNameStyle Log::_logNameStyle = UnknownName;

void Log::log(const string message, const LogLevel level) {
	
	if ((_logPath.length() == 0) || (_logNameStyle == UnknownName) || (_logNameStyle > NumericLogLevel_Date)) {
		throw "Set LogPath & LogNameStyle before using the log method's.'";
	}
	
	tm * today = Utils::getDay();
	
	if ((_writer == 0) || ((_lastLogLevel != level) && (_logNameStyle != Date)) || (_lastday < today)) {
		if (_writer != 0) {
			delete _writer;
		}
		
		_writer = new LogWriter(_logPath, _logNameStyle, level);
		_lastLogLevel = level;
		
		_lastday = today;
	}
	
	_writer->writeLog(message, level);
}

void Log::setLogPath(const string path) {
	if (path.length() > 0) {
		_logPath = path;
		if (_writer != 0) {
			delete _writer;
			_writer = 0;
		}
	}
	else {
		throw "LogPath must not be empty.";
	}
}
		
void Log::setLogNameStyle(const string stringLogNameStyle) {
	if ((stringLogNameStyle.length() > 0) && (stringLogNameStyle != "UnknownName")) {
		_logNameStyle = Utils::stringToLogNameStyle(stringLogNameStyle);
		if (_writer != 0) {
			delete _writer;
			_writer = 0;
		}
	}
	else {
		throw "StringLogNameStyle must not be empty or equal to 'UnknownName'.";
	}
}

void Log::setLogNameStyle(const LogNameStyle enumLogNameStyle) {
	if ((enumLogNameStyle != UnknownName) && (enumLogNameStyle <= NumericLogLevel_Date)) {
		_logNameStyle = enumLogNameStyle;
		if (_writer != 0) {
			delete _writer;
			_writer = 0;
		}
	}
	else {
		throw "EnumLogNameStyle can't be equal to 'UnknownName'";
	}
}

void Log::close() {
	if (_writer != 0) {
		delete _writer;
		_writer = 0;
	}
}

