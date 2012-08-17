
#ifndef __LOG_H__
#define __LOG_H__

#include <string>
#include <ctime>

#include "Enums.h"

namespace Logger {

	class LogWriter;

	class Log {
		
	public:
		static void log(const std::string message, const LogLevel level);
		
		static void setLogPath(const std::string path);
		
		static void setLogNameStyle(const std::string stringLogNameStyle);
		static void setLogNameStyle(const LogNameStyle enumLogNameStyle = Date);
		
		static void close();
		
	protected:
		Log();
		
	private:
		static std::string _logPath;
		static LogNameStyle _logNameStyle;
		static LogLevel _lastLogLevel;
		static tm * _lastday;
		
		static LogWriter * _writer;
		
	};
}

#endif /* __LOG_H__ */

