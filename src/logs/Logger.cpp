/*
 * Logger.cpp
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#include "Logger.h"

namespace logs {

Logger::~Logger() {

}

const char* getTimestamp() {
	std::time_t time = std::time(nullptr);
	std::tm *localtime = std::localtime(&time);
	const char *str = std::asctime(localtime);
	return str;
}
void Logger::log(logs::LogLevel level, const std::string &msg) {
	switch (level) {
	case logs::LogLevel::DEBUG:
		debug(msg);
		break;
	case logs::LogLevel::INFO:
		info(msg);
		break;
	default:
		throw std::invalid_argument("unsupported log-level");
	}
}

void Logger::info(const std::string &msg) {
	std::string s = std::string("[INFO] - ").append(getTimestamp()).append(
			" - ").append(msg);
	std::cout << s << std::endl;
}

void Logger::debug(const std::string &msg) {
	std::string s = std::string("[DEBUG] - ").append(getTimestamp()).append(
			" - ").append(msg);
	std::cout << s << std::endl;
}


}
