#pragma once

#include "binaryOperator.h"
#include "token.h"

class additionOperator : public binaryOperator
{
public:
	using binaryOperator::binaryOperator;
	int operate(int right, int left) override
	{
		return right + left;
	}
};
