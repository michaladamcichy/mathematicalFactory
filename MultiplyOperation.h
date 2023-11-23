#pragma once
#include "pch.h"

#include "AbstractBinaryOperation.h"

template<typename T>
class MultiplyOperation : public AbstractBinaryOperation<T>
{
	static inline const std::string className{ "MultiplyOperation" };
	static constexpr char character{'*'};

public:
	MultiplyOperation(T operand1, T operand2);
	std::string GetClassName() override;

	static constexpr char GetCharacter();

	std::string Proceed() override;
};

template<typename T>
MultiplyOperation<T>::MultiplyOperation(T operand1, T operand2) : AbstractBinaryOperation<T>{ operand1, operand2 }
{
}

template<typename T>
std::string MultiplyOperation<T>::GetClassName()
{
	return className;
}

template<typename T>
constexpr char MultiplyOperation<T>::GetCharacter()
{
	return character;
}

template<typename T>
std::string MultiplyOperation<T>::Proceed()
{
	const auto operand1{ AbstractBinaryOperation<T>::GetOperand1() };
	const auto operand2{ AbstractBinaryOperation<T>::GetOperand2() };

	const auto value{ operand1 * operand2 };

	return std::to_string(value);
}
