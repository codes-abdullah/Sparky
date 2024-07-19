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

std::string getTimestamp();

std::string buildMessage(const char *level, const std::string &msg);

void Logger::log(logs::LogLevel level, const std::string &msg) {
	switch (level) {
	case logs::LogLevel::DEBUG:
		debug(msg);
		break;
	case logs::LogLevel::INFO:
		info(msg);
		break;
	case logs::LogLevel::ERROR:
		error(msg);
		break;
	default:
		throw std::invalid_argument("unsupported log-level");
	}
}

void Logger::info(const std::string &msg) {
	std::cout << buildMessage(logs::DEBUG_LOG_LEVEL, msg) << std::endl;
}

void Logger::debug(const std::string &msg) {
	std::cout << buildMessage(logs::DEBUG_LOG_LEVEL, msg) << std::endl;
}

void Logger::error(const std::string &msg) {
	std::cerr << buildMessage(logs::INFO_LOG_LEVEL, msg) << std::endl;
}

std::string buildMessage(const char *level, const std::string &msg) {
	return std::string(level).append(" - ").append(getTimestamp()).append(
			": ").append(msg);
}

std::string getTimestamp() {
//	std::time_t time = std::time(nullptr);
//	std::tm *tmtime = std::gmtime(&time);
//	char str[std::size("hh:mm:ssZ")];
//	std::strftime(str, std::size(str), "%T", tmtime);
//	return std::string(str);
	return std::string("");
}

}
