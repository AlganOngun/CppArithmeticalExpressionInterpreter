#pragma once

#include "tokenType.h"
#include <string>
#include <iostream>
#include <any>

class token
{
private:
	tokenType type;
	int startPosition;
	std::string data;
public:
	token(const token&) = delete;
	token(token&&) = default;
	virtual int operate(int left, int right)
	{
		std::cout << "this is not an operator" << std::endl;
		return 0;
	}
	tokenType getTokenType()
	{
		return type;
	}
	token(tokenType type, int startPosition, std::string data)
	{
		this->type = type;
		this->data = data;
		this->startPosition = startPosition;
	}

	int getStartPosition()
	{
		return startPosition;
	}

	std::string getData()
	{
		return data;
	}
};
