#pragma once

#include "binaryOperator.h"
#include "token.h"

class subtractionOperator : public binaryOperator
{
public:
	using binaryOperator::binaryOperator;
	int operate(int right, int left) override
	{
		return right - left;
	}
};
