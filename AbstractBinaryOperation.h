#pragma once

#include "AbstractOperation.h"

template<typename T>
class AbstractBinaryOperation : public AbstractOperation
{
	T operand1_;
	T operand2_;

public:
	AbstractBinaryOperation(T operand1, T operand2) :
		operand1_{operand1},
		operand2_{operand2}
	{
	}

	T GetOperand1()
	{
		return operand1_;
	}

	T GetOperand2()
	{
		return operand2_;
	}
};
