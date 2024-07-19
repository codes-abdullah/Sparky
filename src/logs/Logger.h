/*
 * Log.h
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#ifndef LOGS_LOGGER_H_
#define LOGS_LOGGER_H_
#include <iostream>
#include <string.h>
#include <ctime>
namespace logs {
constexpr const char *INFO_LOG_LEVEL = "INFO";
constexpr const char *DEBUG_LOG_LEVEL = "DEBUG";
constexpr const char *ERROR_LOG_LEVEL = "ERROR";
enum LogLevel {
	INFO, DEBUG, ERROR
};
class Logger {
private:
	Logger(){};
public:


	static void info(const std::string &msg);
	static void debug(const std::string &msg);
	static void error(const std::string &msg);
	static void log(logs::LogLevel level, const std::string &msg);
	Logger(const Logger&) = delete;
	virtual ~Logger();

	static Logger& get(){
		static Logger l;
		return l;
	}


};

}

#endif /* LOGS_LOGGER_H_ */
