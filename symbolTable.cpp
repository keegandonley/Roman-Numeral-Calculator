#include "symbolTable.hpp"
#include "Number.hpp"
#include <iostream>

bool symbolTable::symbolExists(char letter) {
    return !(symTab.find(letter) == symTab.end());
}

bool symbolTable::addSymbol(char letter, int value) {
    symTab[letter] = value;
    if (symbolExists(letter)) {
        return true;
    }
    return false;

}

void symbolTable::printTable() {
    for( auto iter = symTab.begin(); iter != symTab.end(); ++iter ){
        Number * convert = new Number(iter->second);
        std::cout << iter->first << " equals " << convert->romanValue() << std::endl;
    }
}

int symbolTable::getSymbol(char letter) {
    return symTab[letter];
}
