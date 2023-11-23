#pragma once
#include "AbstractBinaryOperation.h"

template<typename T>
class DivideOperation : public AbstractBinaryOperation<T>
{
	static inline const std::string className{ "DivideOperation" };
	static constexpr char character{ '/' };

public:

	DivideOperation(T operand1, T operand2);
	std::string GetClassName() override;
	static constexpr char GetCharacter();
	std::string Proceed() override;
};

template<typename T>
DivideOperation<T>::DivideOperation(T operand1, T operand2) : AbstractBinaryOperation<T>{ operand1, operand2 }
{
}

template<typename T>
std::string DivideOperation<T>::GetClassName()
{
	return className;
}

template<typename T>
constexpr char DivideOperation<T>::GetCharacter()
{
	return character;
}

template<typename T>
std::string DivideOperation<T>::Proceed()
{
	const auto operand1{ AbstractBinaryOperation<T>::GetOperand1() };
	const auto operand2{ AbstractBinaryOperation<T>::GetOperand2() };

	if (operand2 == T{})
		throw std::runtime_error{ "zero division" };

	const auto value{ operand1 / operand2 };

	return std::to_string(value);
}
