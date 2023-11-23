#pragma once
#include "OperationFactory.h"

class MathematicalParser
{
public:
	std::tuple<std::string, std::string> Parse(const std::string& input);

private:
	bool IsDecimalSeparator(char character);
	bool IsWhitespace(char character);
	bool IsDigit(char character);
	bool IsOperator(char character);
};
