#pragma once

class AbstractOperation
{
public:

	virtual std::string Proceed() = 0;
	virtual std::string GetClassName() = 0;
};
