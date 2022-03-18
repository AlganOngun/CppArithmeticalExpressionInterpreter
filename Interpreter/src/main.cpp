#include "Lexer/lexer.h"
#include <iostream>
#include <vector>
#include <string>
#include "Parser/parser.h"
#include "Lexer/token.h"
#include <memory>

int main(int argc, char** argv)
{
    while(1)
    {
        std::string code = "";
        std::cout << ">> ";
        std::getline(std::cin, code);

        if(code == ":clear")
        {
            std::system("clear");
            continue;
        }
        else if(code == ":q")
        {
            break;
        }

        lexer lexer;
        std::vector<std::unique_ptr<token>> tokens = lexer.tokenize(code);

        parser parser(std::move(tokens));
        std::string output = std::to_string(parser.parse());

        std::cout << output << std::endl;
    }
    return 0;
}
