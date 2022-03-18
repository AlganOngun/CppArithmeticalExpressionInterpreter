#include "parser.h"
#include <exception>
#include <vector>
#include <memory>
#include <string>

parser::parser(std::vector<std::unique_ptr<token>> tokens) {
    this->tokens = std::move(tokens);
}

void parser::skipToken()
{
    if(currentTokenIndex+1 < tokens.size())
        currentTokenIndex++;
}

int parser::presedence()
{
	tokenType type = tokens[currentTokenIndex]->getTokenType();
	int result = 0;
	if(type == INT)
	{
		result = std::stoi(tokens[currentTokenIndex]->getData());
		skipToken();
	}
	else if(type == PARANTHESES_OPEN)
	{
		skipToken();	
		result = parse();
		skipToken();
	}

	return result;
}

int parser::term()
{
    int result = presedence();

    tokenType type = tokens[currentTokenIndex]->getTokenType();

    while(type == MULTIPLICATION || type == DIVISION)
    {
        std::unique_ptr<token>& currentToken = tokens[currentTokenIndex];

        skipToken();
        int right = presedence();

        result = currentToken->operate(result, right);
        type = tokens[currentTokenIndex]->getTokenType();
    }
    return result;
}

int parser::parse()
{
    int result = term();

    tokenType type = tokens[currentTokenIndex]->getTokenType();

    while(type == ADDITION || type == SUBTRACTION)
    {
        std::unique_ptr<token>& currentToken = tokens[currentTokenIndex];

        skipToken();
        int right = term();
        result = currentToken->operate(result, right);
        type = tokens[currentTokenIndex]->getTokenType();
    }

    return result;
}
