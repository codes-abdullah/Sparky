/*
 * Log.h
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#ifndef LOGS_LOGGER_H_
#define LOGS_LOGGER_H_
#include <iostream>

namespace logs {
enum LogLevel {
	INFO, DEBUG
};
class Logger {
private:
	Logger(){};
public:

	void info(const char *msg);
	void debug(const char *msg);
	void log(logs::LogLevel level, const char *msg);
	Logger(const Logger&) = delete;
	virtual ~Logger();

	static Logger& get(){
		static Logger l;
		return l;
	}


//	inline static void inf(const char *msg){
//		Logger::log(logs::LogLevel::INFO, msg);
//	}
//
//	inline static void debug(const char *msg){
//		Logger::log(logs::LogLevel::DEBUG, msg);
//	}
//
//	inline static void log(logs::LogLevel level, const char *msg){
//		get().log(level, msg);
//	}
};

}

#endif /* LOGS_LOGGER_H_ */
