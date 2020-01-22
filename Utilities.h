// A support module that extracts token from a string
//File Name: Utilities.h
//Author : Miraz Ahmed
//Date Last Modified : July 10, 2019 

#ifndef SICT_UTILITIES_H_
#define SICT_UTILITIES_H_

#include <string>

namespace sict {

    class Utilities
    {
        static size_t fieldWidth;
        static char delimiter;
    public:
        Utilities();
        const std::string extractToken(const std::string& str, size_t& next_pos);
        const char getDelimiter() const;
        size_t getFieldWidth() const;
        static void setDelimiter(const char d);
        static void setFieldWidth(size_t);
    };

 }



#endif // !

