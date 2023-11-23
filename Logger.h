#pragma once

class Logger
{
	static inline const std::string fileName{"output.csv"};
	std::ofstream fileOutput{fileName};

public:
	~Logger();

	void Log(const auto& printable);

	void Log(const auto& printable1, const auto& printable2);

	void LogOperationToFile(const std::string& operationName, const std::string& result);
};

void Logger::Log(const auto& printable)
{
	std::cout << printable << '\n';
}

void Logger::Log(const auto& printable1, const auto& printable2)
{
	std::cout << printable1 << " " << printable2 << '\n';
}