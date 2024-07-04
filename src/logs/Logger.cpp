/*
 * Logger.cpp
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#include "Logger.h"

namespace logs {

Logger::Logger() {

}

Logger::~Logger() {

}

void Logger::log(logs::LogLevel level, const char *msg) {
	std::cout << msg << std::endl;
}

void Logger::info(const char *msg) {
	this->log(logs::LogLevel::INFO, msg);
}

void Logger::debug(const char *msg) {
	this->log(logs::LogLevel::DEBUG, msg);
}



}
