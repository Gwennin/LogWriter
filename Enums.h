
#ifndef __ENUMS_H__
#define __ENUMS_H__

namespace Logger {

	enum LogLevel {
		UnknownLevel,
		Debug,
		Info,
		Warn,
		Alert,
		Critical
	};
		
	enum LogNameStyle {
		UnknownName,
		Date,
		AlphaLogLevel,
		NumericLogLevel,
		Date_AlphaLogLevel,
		Date_NumericLogLevel,
		AlphaLogLevel_Date,
		NumericLogLevel_Date
	};
}

#endif /* __ENUMS_H__ */

