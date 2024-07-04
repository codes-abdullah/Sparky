/*
 * Log.h
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#ifndef LOGS_LOGGER_H_
#define LOGS_LOGGER_H_
#include "Level.h"
namespace logs {
class Logger {
public:
	void info(const char *msg);
	void debug(const char *msg);
	void log(Level level, const char *msg);
	Logger();
	virtual ~Logger();
};
}

#endif /* LOGS_LOGGER_H_ */
