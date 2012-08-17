LogWriter
=========

A little logger lib utility.

##Log Levels

  Debug = 1,
	Info = 2,
	Warn = 3,
	Alert = 4,
  Critical = 5
    
##Log Name Style

  Date, // ex : 2012_12_21.log
  AlphaLogLevel, // ex : Debug.log
	NumericLogLevel, // ex : 1.log
	Date_AlphaLogLevel, // ex : 2012_12_21_Debug.log
	Date_NumericLogLevel, // ex : 2012_12_21_1.log
	AlphaLogLevel_Date, // ex : Debug_2012_12_21.log
	NumericLogLevel_Date // ex : 1_2012_12_21.log

##Example

Includes 'Log.h' & 'Enums.h'.

  Logger::Log::setLogNameStyle("Date");
  Logger::Log::setLogPath("./");
	
	Logger::Log::log("What else?", Logger::Alert);
	
	Logger::Log::close();