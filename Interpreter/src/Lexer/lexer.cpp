#include "lexer.h"

#include <iostream>
#include <memory>
#include "token.h"
#include "additionOperator.h"
#include "multiplicationOperator.h"
#include "divisionOperator.h"
#include "subtractionOperator.h"
#include "tokenType.h"
#include "../Utilities/charUtilities.h"

std::vector<std::unique_ptr<token>> lexer::tokenize(std::string code)
{
    int currentPosition = 0;
    std::vector<std::unique_ptr<token>> tokens;

    while(currentPosition < code.length())
    {
        int tokenStartingPosition = currentPosition;
        char lookaheadCharacter = code[currentPosition];

        if(Utilities::charUtilities::isDigit(lookaheadCharacter))
        {
            std::string data;
            while(Utilities::charUtilities::isDigit(lookaheadCharacter))
            {
                data.push_back(lookaheadCharacter);
                currentPosition++;
                lookaheadCharacter=code[currentPosition];
            }
            tokens.push_back(std::make_unique<token>(token(INT, tokenStartingPosition, data)));
        }
        else if(lookaheadCharacter == '(')
        {
            std::string data;
            data.push_back(lookaheadCharacter);
			int index = currentPosition;
            while(lookaheadCharacter != ')')
            {
                if(index+1 >= code.length())
				{
                    std::cout << "Error: Not Closed Parantheses" << std::endl;
					return {};
				}
                index++;
                lookaheadCharacter=code[index];
            }
            currentPosition++;
            tokens.push_back(std::make_unique<token>(token(PARANTHESES_OPEN, tokenStartingPosition, data)));
        }
		else if(lookaheadCharacter == ')')
		{
			std::string data;
            data.push_back(lookaheadCharacter);
			int index = currentPosition;
			while(lookaheadCharacter != '(')
			{
				if(index-1 < 0)
				{
					std::cout << "Error: Not Opened Parantheses" << std::endl;
					return {};
				}
				index--;
                lookaheadCharacter=code[index];
			}
            currentPosition++;
            tokens.push_back(std::make_unique<token>(token(PARANTHESES_CLOSE, tokenStartingPosition, data)));
		}
        else if(lookaheadCharacter == '+')
        {
            std::string data;
            data.push_back(lookaheadCharacter);
            tokens.push_back(std::make_unique<additionOperator>(additionOperator(ADDITION, tokenStartingPosition, data)));
            currentPosition++;
        }
        else if(lookaheadCharacter == '-')
        {
            std::string data;
            data.push_back(lookaheadCharacter);
            tokens.push_back(std::make_unique<subtractionOperator>(subtractionOperator(SUBTRACTION, tokenStartingPosition, data)));
            currentPosition++;
        }
        else if(lookaheadCharacter == '*')
        {
            std::string data;
            data.push_back(lookaheadCharacter);
            tokens.push_back(std::make_unique<multiplicationOperator>(multiplicationOperator(MULTIPLICATION, tokenStartingPosition, data)));
            currentPosition++;
        }
        else if(lookaheadCharacter == '/')
        {
            std::string data;
            data.push_back(lookaheadCharacter);
            tokens.push_back(std::make_unique<divisionOperator>(divisionOperator(DIVISION, tokenStartingPosition, data)));
            currentPosition++;
        }
        else if(lookaheadCharacter == ' ')
        {
            currentPosition++;
        }
        else
        {
            std::cerr << "Invalid Token" << std::endl;
        }
    }
    return tokens;
}
