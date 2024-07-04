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
public:

	void info(const char *msg);
	void debug(const char *msg);
	void log(logs::LogLevel level, const char *msg);
	Logger();
	virtual ~Logger();
};

}

#endif /* LOGS_LOGGER_H_ */
