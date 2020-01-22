//Implementation of "Utility" class
//File Name: Utilities.cpp
//Author : Miraz Ahmed
//Date Last Modified : August 02, 2019 

#include <string>
#include "Utilities.h"

namespace sict {

    size_t Utilities::fieldWidth = 0;
    char Utilities::delimiter = '|';

    //Default Constructor
    Utilities::Utilities() {}

    //A modifier that extracts the next token in the string starting at the position next_pos
    const std::string Utilities::extractToken(const std::string& str, size_t& next_pos)
    {
        std::string tmp{};
        if (str.size() > next_pos)
        {
            tmp = str.substr(next_pos, str.find(delimiter, next_pos) - next_pos);
        }
        else
        {
            tmp = "";
        }

        if (str.find(delimiter, next_pos) != std::string::npos)
        {
            next_pos = str.find(delimiter, next_pos) + 1;
        }
        else
        {
            next_pos = std::string::npos;
        }

        if (tmp.size() == 0)
        {
            throw "The token is emtpty";
        }
        return tmp;
    }

    //A query that returns delimiting character
    const char Utilities::getDelimiter() const { return delimiter; }

    //Returns the field width for the current object
    size_t Utilities::getFieldWidth() const { return fieldWidth; }

    //Sets the delimiter character for objects
    void Utilities::setDelimiter(const char d) { delimiter = d; }

    //sets the field width for the current object
    void Utilities::setFieldWidth(size_t newWidth) { fieldWidth = newWidth; }
}
