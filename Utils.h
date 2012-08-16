
#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

#include "Enums.h"

namespace Logger {
	
	class Utils
	{
		protected:
			Utils ();
	
		public:
			static std::string logNameStyleToString(LogNameStyle value);
			static LogNameStyle stringToLogNameStyle(std::string value);
			
			static std::string logLevelToString(LogLevel value);
			
			static std::string intToString(int value);
			
			static std::string getStringFilenameDate();
			static std::string getStringDateTime();
			static tm * getDay();
	};
}

#endif /* __UTILS_H__ */

