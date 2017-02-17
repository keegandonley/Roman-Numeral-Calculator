#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"

#ifndef __TOKENIZER
#define __TOKENIZER

class Tokenizer {

public:
    // Initilize a Tokenizer instance and set the expression
    // Precondition: expr is a string containing an assignment expression
    Tokenizer( std::string expr ) { expression = expr; }

    // Break up the string in "expression" into tokens and return them.
    // Precondition: Expects that a Tokenizer insgance has been initilized,
    //               and the value of `expression` contains the string to be
    //               tokenized.
    std::vector<Token *> &tokenize();

private:
    std::string expression;
    std::vector<Token *> tokens;
    bool isRomanLetter(char letter);
    bool isOperator(char letter);



};

#endif
