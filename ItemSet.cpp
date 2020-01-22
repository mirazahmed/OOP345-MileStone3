//Implementation of "ItemSet" class
//File Name: ItemSet.cpp
//Author : Miraz Ahmed
//Date Last Modified : July 10, 2019 

#include <iostream>
#include <string>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

    //Constructor that extract tokens from the received string, populates the object with tokens, and determine the fieldwidth for displaying data
    ItemSet::ItemSet(const std::string& source)
    {
        size_t next_pos{ 0 };
        name = utility.extractToken(source, next_pos);

        if (name.size() > utility.getFieldWidth())
        {
            utility.setFieldWidth(name.size());
        }

        if (next_pos <= source.size())
        {
            serialNumber = std::stoul(utility.extractToken(source, next_pos));
        }       
        if (next_pos <= source.size())
        {
            quantity = std::stoul(utility.extractToken(source, next_pos));
        }
        
        if (next_pos <= source.size())
        {
            description = utility.extractToken(source, next_pos);
        }
    }


    //Move Constructor
    ItemSet::ItemSet(ItemSet&& source)
    {
        name = source.name;
        serialNumber = source.serialNumber;
        quantity = source.quantity;
        description = source.description;
        source.name = "";
        source.serialNumber = 0;
        source.quantity = 0;
    }

    //Returns a reference to the name of item
    const std::string& ItemSet::getName() const { return name; }

    //Returns the serial number of the item
    const unsigned int ItemSet::getSerialNumber() const { return serialNumber; }

    //returns the remaining number of items in the set
    const unsigned int ItemSet::getQuantity() const { return quantity; }

    //Reduces the number of items in stock by one and increases the serial number by one
    ItemSet& ItemSet::operator--()
    {
        quantity--; 
        serialNumber++;
        return *this;
    }

    //Inserts the data to ostream object if other parameter returns true.
    void ItemSet::display(std::ostream& os, bool full) const
    {
        if (full)
        {
            os.width(utility.getFieldWidth());
            os << std::left;
            os.fill(' ');
            os << name;
            os << " [";
            os.fill('0');
            os.width(5);
            os << serialNumber;
            os.fill(' ');
            os << "] Quantity ";
            os << std::left;
            os.width(3);
            os << quantity;
            os << " Description: ";
            os << description;
            os << std::endl;
        }
        else
        {
            os.width(utility.getFieldWidth());
            os << std::left;
            os.fill(' ');
            os << name;
            os << " [";
            os.fill('0');
            os.width(5);
            os << serialNumber + 1 << ']';
            os << std::endl;
        }


    }

}