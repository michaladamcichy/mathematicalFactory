/*
* Requirements:
* type T should implement operators +,-,*,/ and should be accepted by std::to_string method 
* If you want to use your own class as T, maybe you should write an overload - std::to_string(T value)
*/

#pragma once
#include "AbstractOperation.h"

#include "AddOperation.h"
#include "SubstractOperation.h"
#include "MultiplyOperation.h"
#include "DivideOperation.h"

class OperationFactory
{
public:

	template<typename T>
	std::unique_ptr<AbstractOperation> CreateOperation(char operationCharacter, T operand1, T operand2);
};

template<typename T>
std::unique_ptr<AbstractOperation> OperationFactory::CreateOperation(char operationCharacter, T operand1, T operand2)
{
	switch (operationCharacter)
	{
	case AddOperation<T>::GetCharacter():
		return std::make_unique<AddOperation<T>>(operand1, operand2);
	case SubstractOperation<T>::GetCharacter():
		return std::make_unique<SubstractOperation<T>>(operand1, operand2);
	case MultiplyOperation<T>::GetCharacter():
		return std::make_unique<MultiplyOperation<T>>(operand1, operand2);
	case DivideOperation<T>::GetCharacter():
		return std::make_unique<DivideOperation<T>>(operand1, operand2);
	default:
		throw std::exception{ "bad character - no such operation" };
	}
}
