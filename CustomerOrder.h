//Declaration of CustomerOrder class which manages and processes customer order objects
//File Name: CustomerOrder.h
//Author : Miraz Ahmed
//Date Last Modified : July 19, 2019 

#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDER_H

#include <iostream>
#include "ItemSet.h"
#include "Utilities.h"


namespace sict {
    struct ItemInfo;
    
    class CustomerOrder
    {
        std::string custName{};
        std::string prodName{};
        ItemInfo* itemArray = nullptr;
        size_t noOfItem{ 0 };
        Utilities utilities;
    public:
        CustomerOrder();
        CustomerOrder(const std::string&);
        CustomerOrder(CustomerOrder&) = delete;
        CustomerOrder(CustomerOrder&&);
        ~CustomerOrder();
        void fillItem(ItemSet& item, std::ostream& os);
        bool isFilled() const;
        bool isItemFilled(const std::string& item) const;
        std::string getNameProduct() const;
        void display(std::ostream& os, bool showDetail = false) const;
        CustomerOrder& operator=(CustomerOrder&) = delete;
        CustomerOrder& operator=(CustomerOrder&&);
        
    };


    struct ItemInfo
    {
        std::string itemName{};
        unsigned int itemSerial{ 0 };
        bool filledStatus{ false };
    };
}











#endif
