cmake_minimum_required(VERSION 3.16)
project(ezMath)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES 
	src/main.cpp src/Lexer/lexer.cpp src/Utilities/fileReader.cpp src/Utilities/charUtilities.cpp src/Parser/parser.cpp
)
set(HEADERS 
	src/Lexer/lexer.h src/Utilities/fileReader.h src/Lexer/token.h src/Lexer/tokenType.h src/Utilities/charUtilities.h src/Parser/parser.h
		src/Lexer/binaryOperator.h src/Lexer/additionOperator.h src/Lexer/subtractionOperator.h src/Lexer/multiplicationOperator.h src/Lexer/divisionOperator.h
)

add_executable(ezMath ${HEADERS} ${SOURCES})
