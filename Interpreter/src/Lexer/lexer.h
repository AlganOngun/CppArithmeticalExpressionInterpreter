#include <string>
#include <vector>
#include <memory>

#include "token.h"

#pragma once

class lexer
{
public:
	std::vector<std::unique_ptr<token>> tokenize(std::string code);
};
