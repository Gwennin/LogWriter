
#ifndef __LOGWRITER_H__
#define __LOGWRITER_H__

#include <fstream>
#include <string>

#include "Enums.h"

namespace Logger {
	
	class LogWriter {
		
	private:
		std::ofstream * _file; 
		
	protected:
		LogWriter();
		
		std::string formatFileName(std::string logPath, LogNameStyle logNameStyle, LogLevel logLevel);
		
	public:
		LogWriter(std::string logPath, LogNameStyle logNameStyle, LogLevel logLevel);
		
		void writeLog(std::string message, LogLevel logLevel);
		
		virtual ~LogWriter();
	};

}

#endif /* __LOGWRITER_H__ */

