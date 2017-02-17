#include "Token.hpp"
#include "Tokenizer.hpp"
#include "InfixToPostfix.hpp"
#include "symbolTable.hpp"
#include "Number.hpp"

#include<vector>

int arithmeticStack (std::vector<Token *> tokens, symbolTable * symbols);
bool validateInput(std::vector<Token *> postfixTokens);
int arithmeticSingle(char op, int lh, int rh);


int main() {

    // Input an infix expression
    std::cout << "Enter infix expressions using Roman Numerals (one per line)\n";
    std::string numerals;
    getline(std::cin, numerals);
    symbolTable * symbols = new symbolTable;

    while (numerals.length() > 0) {
        // Tokenize infix expression
        Tokenizer *tok = new Tokenizer(numerals);
        std::vector<Token *> tokens = tok->tokenize();

        // Make sure the first token is a variable
        if (!(tokens[0] -> isAVariable())) {
            std::cout << "Please enter a proper assignment expression\n";
            return 1;
        }
        char symbol = tokens[0] -> getVariable();
        tokens.erase(tokens.begin());

        // Make sure the second token is an '=' sign
        if (!(tokens[0] -> isEqualSign())) {
            std::cout << "Please enter a proper assignment expression\n";
            return 2;
        }
        tokens.erase(tokens.begin());

        // Convert to postfix expression
        InfixToPostfix *itop = new InfixToPostfix();
        std::vector<Token *> postfixTokens;
        itop->convert( tokens, tokens.size(), postfixTokens);

        // Validate the values in the postfix expression
        bool validation = validateInput(postfixTokens);
        // Calculate stack
        int result = arithmeticStack(postfixTokens, symbols);
        // Check both validity conditions
        if (!validation) { // incorrect numeral
            std::cout << symbol << " UNDEFINED\n";
        } else if (result < 0) { // negative return value
            std::cout << symbol << " UNDEFINED\n";
        } else {
            // Store in symbol table
            bool successfulAdd = symbols -> addSymbol(symbol, result);
            if (!successfulAdd) {
                std::cout << "Symbol failed to be saved!\n";
                return 2;
            }
        }
        // Get another expression
        getline(std::cin, numerals);
    }
    symbols -> printTable();
    return 0;
}

// Returns the solution to the expression given.
// Preconditions: tokens is a list of Token instances
//                symbols is a map of all existing stored values
int arithmeticStack (std::vector<Token *> tokens, symbolTable * symbols) {
    std::vector<int> calcValues;
    TokenIterator *iterator = new TokenIterator(tokens, tokens.size());
    while (iterator->hasMoreTokens()) {
        Token *current = iterator->next();
        if(current->isRomanNumber()) {
            Number *digit = new Number(current->romanNumber());
            calcValues.push_back(digit->intValue());
        } else if (!(current->isRomanNumber()) && !(current -> isAVariable())) {
            char currentOperator = current->getVariable();
            int value1 = calcValues.back();
            calcValues.pop_back();
            int value2 = calcValues.back();
            calcValues.pop_back();
            calcValues.push_back(arithmeticSingle(currentOperator, value2, value1));
        } else if (current -> isAVariable()) {
            char symbol = current -> getVariable();
            if (symbols -> symbolExists(symbol)) {
                calcValues.push_back(symbols -> getSymbol(symbol));
            } else {
                // If the symbol doesn't exit, we return -1 to indicate
                // this assignment results in an UNDEFINED value
                return -1;
            }
        }
    }
    // Make sure there's a result. If there wasn't, indicate a null response
    // and return -1.
    if (calcValues.size() > 0)
        return calcValues.back();
    return -1; // NOTE: code should never reach this point.
}

bool validateInput(std::vector<Token *> postfixTokens) {
    TokenIterator *iterator = new TokenIterator(postfixTokens, postfixTokens.size());
    while (iterator -> hasMoreTokens()) {
        Token *current = iterator->next();
        if(current->isRomanNumber()) {
            Number *digit = new Number(current->romanNumber());
            if (!digit -> isALegalRomanNumber()) {
                return false;
            }
        }
    }
    return true;
}

int arithmeticSingle(char op, int lh, int rh) {
    switch (op) {
        case '+': return lh+rh;
        case '-': return lh-rh;
        case '*': return lh*rh;
        case '/': return lh/rh;
        case '%': return lh%rh;
        default: return 0;
    }
}
