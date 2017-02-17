#include<iostream>
#include<string>
#include "Number.hpp"
#include<vector>

bool Number::isALegalRomanNumber() {
    // If the number being checked is a string (Roman Numeral)
    if (strNumber.size() > 0) {
        Number testString(strNumber); // initialize new Number with a string of numerals
        int convertedInt = testString.intValue(); // Convert the string to an integer
        if (convertedInt > 3999) {return false;} // Too big!
        Number testInt(convertedInt); // Prepare to go back to a string of numerals
        std::string convertedString = testInt.romanValue(); // convert the integer to a string
        return convertedString == strNumber;
    // else if the number being checked is an integer
    } else {
        if (intNumber > 3999) {return false;} // Too big!
        Number testInt(intNumber); // initilize a new Number with an integer
        std::string convertedString = testInt.romanValue(); // Convert the integer to a string
        Number testString(convertedString); // Prepare to go back to an integer
        int convertedInt = testString.intValue(); // Convert the string to an integer
        return convertedInt == intNumber;
    }

}

int Number::intValue() {
    if (strNumber.length() < 1 && intNumber > -1) {
        return intNumber;
    }
    std::vector<int> numericValues;
    for (int i = 0; i < strNumber.size(); i++) {
        int value = 0;
        switch (strNumber[i]) {
            case 'I': value = 1; break;
            case 'V': value = 5; break;
            case 'X': value = 10; break;
            case 'L': value = 50; break;
            case 'C': value = 100; break;
            case 'D': value = 500; break;
            case 'M': value = 1000; break;
        }
        numericValues.push_back(value);
    }

    int runningTotal = 0;
    for (int i = 0; i < strNumber.size(); i++) {
        if (i == strNumber.size() - 1 )
            runningTotal += numericValues[i];
        else {
            if (numericValues[i] >= numericValues[i+1])
                runningTotal += numericValues[i];
            else
                runningTotal -= numericValues[i];
        }
    }
    return runningTotal;
}

std::string Number::romanValue() {
    if (intNumber == 0) { return "0"; }
    std::string result = "";
    for (int i = 0; i < intNumber / 1000; i++) { result += "M"; }
    int remaining = intNumber % 1000;
    for (int i = 0; i < remaining / 900; i++) { result += "CM"; }
    remaining = remaining % 900;
    for (int i = 0; i < remaining / 500; i++) { result += "D"; }
    remaining = remaining % 500;
    for (int i = 0; i < remaining / 400; i++) { result += "CD"; }
    remaining = remaining % 400;
    for (int i = 0; i < remaining / 100; i++) { result += "C"; }
    remaining = remaining % 100;
    for (int i = 0; i < remaining / 90; i++) { result += "XC"; }
    remaining = remaining % 90;
    for (int i = 0; i < remaining / 50; i++) { result += "L"; }
    remaining = remaining % 50;
    for (int i = 0; i < remaining / 40; i++) { result += "XL"; }
    remaining = remaining % 40;
    for (int i = 0; i < remaining / 10; i++) { result += "X"; }
    remaining = remaining % 10;
    for (int i = 0; i < remaining / 9; i++) { result += "IX"; }
    remaining = remaining % 9;
    for (int i = 0; i < remaining / 5; i++) { result += "V"; }
    remaining = remaining % 5;
    for (int i = 0; i < remaining / 4; i++) { result += "IV"; }
    for (int i = 0; i < remaining % 4; i++) { result += "I"; }

    return result;
}
