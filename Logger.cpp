#include "pch.h"
#include "Logger.h"

Logger::~Logger()
{
	fileOutput.close();
}

void Logger::LogOperationToFile(const std::string& operationName, const std::string& result)
{
	fileOutput << operationName << ',' << result << '\n';
}
