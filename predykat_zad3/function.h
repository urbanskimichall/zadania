
#ifndef PREDYKAT_ZAD3_FUNCTION_H
#define PREDYKAT_ZAD3_FUNCTION_H

#include <string>
#include <iostream>

template<typename F>
std::string getReduced( std::string &input, const F *predicate, const std::string &stringToCut)
{
    std::string subString{input.substr(0, stringToCut.length())};
    while ((*predicate)(subString, stringToCut))
    {
        input.erase(0, stringToCut.length());
        subString = input.substr(0, stringToCut.length());
    }

    subString = input.substr(input.length() - stringToCut.length(), stringToCut.length());
    std::string reversedStringToCut = std::string(stringToCut.rbegin(), stringToCut.rend());

    while ((*predicate)(subString, reversedStringToCut))
    {
        input.erase(input.length() - reversedStringToCut.length(), reversedStringToCut.length());
        subString = input.substr(input.length() - reversedStringToCut.length(), reversedStringToCut.length());
    }
    return input;
}

//predicate
auto isGivenStringToCut = [](const std::string &subString, const std::string &stringToCut) -> bool
{
    if (subString == stringToCut)
    {
        return true;
    }
    return false;
};

#endif //PREDYKAT_ZAD3_FUNCTION_H
