#pragma once

#include "AbstractBinaryOperation.h"

template<typename T>
class AddOperation : public AbstractBinaryOperation<T>
{
	static inline const std::string className{ "AddOperation" };
	static constexpr char character{ '+' };
public:

	AddOperation(T operand1, T operand2);

	std::string GetClassName() override;

	constexpr static char GetCharacter();

	std::string Proceed() override;
};

template<typename T>
AddOperation<T>::AddOperation(T operand1, T operand2) :
	AbstractBinaryOperation<T>{ operand1, operand2 }
{
}

template<typename T>
std::string AddOperation<T>::GetClassName()
{
	return className;
}

template<typename T>
constexpr char AddOperation<T>::GetCharacter()
{
	return character;
}

template<typename T>
std::string AddOperation<T>::Proceed()
{
	const auto operand1{ AbstractBinaryOperation<T>::GetOperand1() };
	const auto operand2{ AbstractBinaryOperation<T>::GetOperand2() };

	const auto value{ operand1 + operand2 };

	return std::to_string(value);
}
