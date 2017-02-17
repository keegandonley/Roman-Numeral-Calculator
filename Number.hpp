#include<iostream>
#include<string>

#ifndef __NUMBERHPP
#define __NUMBERHPP


class Number {
public:
    Number( int n )         { intNumber = n; }
    Number( std::string s ) { strNumber = s; }

    // is the Roman number that is stored in "strNumber" a legal Roman number?
    // Returns true if the number is valid (formatting & value) otherwise false
    bool isALegalRomanNumber();

    // Return the int value of this Roman number.  If the instance was
    // created by having used a decimal number, just return it.
    // Otherwise, convert "strNumber" to its decimal counterpart and
    // return it.  Note that you may already have converted it when the
    // user called "isALegalRomanNumber".
    int intValue();

    // convert "intNumber" to its Roman counterpart and return it as a string.
    std::string romanValue();

private:
    std::string strNumber;
    int intNumber;
};

#endif
