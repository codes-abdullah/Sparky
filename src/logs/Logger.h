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
enum LogLevel {
	INFO, DEBUG
};
class Logger {
private:
	Logger(){};
public:

	static const char *getTimestamp();
	static void info(const std::string &msg);
	static void debug(const std::string &msg);
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
