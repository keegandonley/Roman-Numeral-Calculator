#include <iostream>
#include <string>
#include "Tokenizer.hpp"
#include "Token.hpp"


std::vector<Token *> &Tokenizer::tokenize() {
    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];
        if (!(current == ' ' || current == '\t')) {
            // If it's not a space
            if (isOperator(current)) {
                // Operator includes +,-,*,/,%,(,),=
                tokens.push_back(new Token(current));
            } else if (isRomanLetter(current)) {
                std::string romanString = "";
                int j = i;
                char tempRomanLetter = expression[j];
                while (isRomanLetter(tempRomanLetter)) {
                    romanString+= expression[j];
                    tempRomanLetter = expression[++j];
                }
                tokens.push_back(new Token(romanString));
                i = j - 1;
            } else {
                // we assume it's an identifier at this point
                tokens.push_back(new Token(current));
            }
        }
        // If it's a space, we move on
    }
    Token *token = new Token();
    token->eol(true);
    tokens.push_back(token);
    return tokens;
}

bool Tokenizer::isRomanLetter(char letter) {
    if (letter == 'I' || letter == 'V' || letter == 'X' || letter == 'L' || letter == 'C' || letter == 'D' || letter == 'M')
        return true;
    return false;
}

bool Tokenizer::isOperator(char letter) {
    if (letter == '=' || letter == '+' || letter == '-' || letter == '*' || letter == '%' || letter == '/' || letter == '(' || letter == ')')
        return true;
    return false;
}
