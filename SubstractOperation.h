#pragma once
#include "pch.h"
#include "AbstractOperation.h"
#include "AbstractBinaryOperation.h"

template<typename T>
class SubstractOperation : public AbstractBinaryOperation<T>
{
	static inline std::string className{ "SubstractOperation" };
	static constexpr char character{ '-' };
public:

	SubstractOperation(T operand1, T operand2, std::string className = SubstractOperation::className);
	std::string GetClassName() override;

	constexpr static char GetCharacter();

	std::string Proceed() override;
};

template<typename T>
SubstractOperation<T>::SubstractOperation(T operand1, T operand2, std::string className) :
	AbstractBinaryOperation<T>{ operand1, operand2 }
{
}

template<typename T>
std::string SubstractOperation<T>::GetClassName()
{
	return className;
}

template<typename T>
constexpr char SubstractOperation<T>::GetCharacter()
{
	return character;
}

template<typename T>
std::string SubstractOperation<T>::Proceed()
{
	const auto operand1{ AbstractBinaryOperation<T>::GetOperand1() };
	const auto operand2{ AbstractBinaryOperation<T>::GetOperand2() };

	const auto value{ operand1 - operand2 };

	return std::to_string(value);
}
