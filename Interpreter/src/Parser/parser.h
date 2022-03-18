#pragma once

#include "../Lexer/token.h"
#include <memory>
#include <vector>
#include <string>

class parser
{
	std::vector<std::unique_ptr<token>> tokens;
	int term();
	int presedence();
	void skipToken();
	int currentTokenIndex = 0;
public:
	parser(std::vector<std::unique_ptr<token>> tokens);
	int parse();
};
