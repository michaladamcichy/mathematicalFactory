#include "pch.h"
#include "MathematicalParser.h"

std::tuple<std::string, std::string> MathematicalParser::Parse(const std::string& input)
{
	OperationFactory factory;
	auto floatingPointDetected{ false };

	std::string operand1;
	std::string operand2;
	std::optional<char> operatorCharacter;
	auto currentOperand{ &operand1 };

	for (const auto& character : input)
	{
		if (IsWhitespace(character))
			continue;

		if (IsDecimalSeparator(character))
		{
			floatingPointDetected = true;
			*currentOperand += '.';
			continue;
		}

		if (IsDigit(character))
		{
			*currentOperand += character;
			continue;
		}

		if (IsOperator(character) && !operatorCharacter.has_value())
		{
			operatorCharacter = character;
			currentOperand = &operand2;
			continue;
		}

		throw std::exception{ "invalid input" };
	}

	const auto operation{ floatingPointDetected ?
		factory.CreateOperation<double>(operatorCharacter.value(), std::stod(operand1), std::stod(operand2)) :
		factory.CreateOperation<long>(operatorCharacter.value(), std::stol(operand1), std::stol(operand2))
	};

	return { operation->GetClassName(), operation->Proceed() };
}

bool MathematicalParser::IsDecimalSeparator(char character)
{
	return character == '.' || character == ',';
}

bool MathematicalParser::IsWhitespace(char character)
{
	return character == ' ' || character == '\n';
}

bool MathematicalParser::IsDigit(char character)
{
	return std::isdigit(character) != 0;
}

bool MathematicalParser::IsOperator(char character)
{
	switch (character)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default: return false;
	}
}
