//Implementation of CustomerOrder module
//File Name: CustomerOrder.cpp
//Author : Miraz Ahmed
//Date Last Modified : July 19, 2019 

#include "CustomerOrder.h"

namespace sict {

    //default constructor
    //
    CustomerOrder::CustomerOrder() {}

    //One argument constructor that extracts exactly three tokens from the recieved string
    //
    CustomerOrder::CustomerOrder(const std::string& srcStr)
    {
        size_t next_pos{ 0 };
        custName = utilities.extractToken(srcStr, next_pos);
        if (custName.size() > utilities.getFieldWidth())
        {
            utilities.setFieldWidth(custName.size());
        }

        if (next_pos <= srcStr.size())
        {
            prodName = utilities.extractToken(srcStr, next_pos);
        }

        while (next_pos <= srcStr.size())
        {
            ItemInfo* temp;
            temp = new ItemInfo[noOfItem];
            for (size_t i = 0; i < noOfItem; i++)
            {
                temp[i] = itemArray[i];
            }
            delete[] itemArray;
            itemArray = new ItemInfo[++noOfItem];

            for (size_t i = 0; i < noOfItem - 1; i++)
            {
                itemArray[i] = temp[i];
            }
            delete[] temp;
            itemArray[noOfItem - 1].itemName = utilities.extractToken(srcStr, next_pos);

        }

     }
    
    //move constructor
    //
    CustomerOrder::CustomerOrder(CustomerOrder&& src)
    {
        if (this != &src) { *this = std::move(src); }
    }

    //move assignment operator
    //
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)
    {
        if (this != &src)
        {
            delete[] itemArray;
            itemArray = nullptr;
            custName = src.custName;
            prodName = src.prodName;
            noOfItem = src.noOfItem;
            itemArray = src.itemArray;
            src.custName = "";
            src.prodName = "";
            src.noOfItem = 0;
            src.itemArray = nullptr;
        }
        return *this;
    }

    //destructor
    //
    CustomerOrder::~CustomerOrder() { delete[] itemArray; }

    //checks each item request, fills the requested item if iit is available and reports the filling as per the specified format
    //
    void CustomerOrder::fillItem(ItemSet& item, std::ostream& os)
    {
        for (size_t i = 0; i < noOfItem; i++)
        {
            if (item.getName() == itemArray[i].itemName)
            {
                if (item.getQuantity() > 0 && itemArray[i].filledStatus == false)
                {
                    itemArray[i].filledStatus = true;
                    itemArray[i].itemSerial = item.getSerialNumber();
                    --item;
                    os << " Filled " << custName << " [" << prodName << "][" << itemArray[i].itemName << "][" << itemArray[i].itemSerial << ']' << std::endl;
                }
                else if (item.getQuantity() > 0 && itemArray[i].filledStatus)
                {
                    os << " Unable to fill " << custName << " [" << prodName << "][" << itemArray[i].itemName << "][" << itemArray[i].itemSerial << "] already filled" << std::endl;
                }
                
                else
                {
                    os << " Unable to fill " << custName << " [" << prodName << "][" << itemArray[i].itemName << "][" << itemArray[i].itemSerial << "] out of stock" << std::endl;
                }
            }
        }
    }
    
    //checks whether the list of items is filled
    //
    bool CustomerOrder::isFilled() const
    {
        int allFilled{ 1 };
        for (size_t i = 0; i < noOfItem; i++)
        {
            allFilled *= static_cast<int>(itemArray[i].filledStatus);
        }
        return static_cast<bool>(allFilled);
    }

    //checks whether a particular item is filled
    //
    bool CustomerOrder::isItemFilled(const std::string& item) const
    {
        int allFilled{ 1 };
        for (size_t i = 0; i < noOfItem; i++)
        {
            if (itemArray[i].itemName == item)
            {
                allFilled *= static_cast<int>(itemArray[i].filledStatus);
            }
        }
        return static_cast<bool>(allFilled);
    }

    //Returns name of the custome and their product in a certain format
    //
    std::string CustomerOrder::getNameProduct() const
    {
        std::string nameProduct = custName + '[' + prodName + ']';
        return nameProduct;
    }
    
    //displays info of the product
    //
    void CustomerOrder::display(std::ostream& os, bool showDetail) const
    {
        if (!showDetail)
        {
            os.width(utilities.getFieldWidth());
            os << custName;
            os << " [" << prodName << ']' << std::endl;
            if (noOfItem > 0)
            {
                for (size_t i = 0; i < noOfItem; i++)
                {
                    for (size_t i = 0; i < utilities.getFieldWidth() + 1; i++) { os << ' '; }
                    os << itemArray[i].itemName << std::endl;
                }
            }
        }
        else
        {
            os << custName << " [" << prodName << ']' << std::endl;
            if (noOfItem > 0)
            {
                for (size_t i = 0; i < noOfItem; i++)
                {
                    for (size_t i = 0; i < utilities.getFieldWidth(); i++) { os << ' '; }
                    os << '[' << itemArray[i].itemSerial << "] " << itemArray[i].itemName;
                    os << " - " << itemArray[i].filledStatus << std::endl;
                }
            }
        }
    }
    
}