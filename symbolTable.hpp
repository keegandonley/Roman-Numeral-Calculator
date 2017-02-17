#include<iostream>
#include<map>

#ifndef __SYMBOLTABLE
#define __SYMBOLTABLE


class symbolTable {
public:
    symbolTable() {}
    symbolTable(char letter, int value) {symTab[letter] = value;}

    // Returns true if the symbols already exists in the table
    // Precondition: letter is a lower-case letter in the range a-z
    bool symbolExists(char letter);

    // Adds a sumbol the the table. Returns true to indicate success, false
    // to indicate failure
    // Preconditions: letter is a lower-case letter in the range a-z
    //                value is an integer to be stored at symTab[letter]
    bool addSymbol(char letter, int value);

    // Prints all the values that were stored in the table
    // displays the results of all computations that were calculated
    void printTable();

    // Returns the value of one symbol whose memory location is indicated
    // by "letter".
    // Precondition: letter is a lower-case letter in the range a-z
    int getSymbol(char letter);


private:
    std::map<char, int> symTab;
};

#endif
