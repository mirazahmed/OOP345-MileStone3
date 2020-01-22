//Implementation of Station module
//File Name: Station.cpp
//Author : Miraz Ahmed
//Date Last Modified : August 2, 2019 

#include "Station.h"

namespace sict {

    //One argument constructor that passes the reference to itemset subobject
    //
    Station::Station(const std::string& src) : item(src)
    {
        stationName = item.getName();
    }
    
    //Displays data for itemset on output stream
    //
    void Station::display(std::ostream& os) const
    {
        item.display(os, true);
    }

    //A modifier that fills the last order in the customer order queue
    //
    void Station::fill(std::ostream& os)
    {
        if (!orders.empty()) { orders.front().fillItem(item, os); }
    }

    //Returns a name of the itemSet sub-object
    //
    const std::string& Station::getName() const { return item.getName(); }

    //Returns the release state of the current object
    //
    bool Station::hasAnOrderToRelease() const
    {
       bool releaseState{ false };

        if (!orders.empty())
        {
            if (!item.getQuantity())
            {
                releaseState = true;
            }
            else
            {
                releaseState = orders.front().isItemFilled(stationName);
            }
        }
        return releaseState;
    }
    
    //A modifier that decrements the number of items in the itemset
    //    
    Station& Station::operator--()
    {
        --item;
        return *this;
    }

    //A modifier that moves the reference to a customer order to the back of the station's queue
    //
    Station& Station::operator+=(CustomerOrder&& order)
    {
        orders.push_back(std::move(order));
        return *this;
    }

    //A modifier that removes the order at the front of the queue
    //Moves the order to the calling function
    //Returns true if station filled its part of order
    //
    bool Station::pop(CustomerOrder& ready)
    {
        bool filled{ false };
        if (!orders.empty())
        {
            filled = orders.front().isItemFilled(stationName);
            ready = std::move(orders.front());
            orders.pop_front();
        }
        return filled;
    }

    //A query that reports the state of the ItemSet object according to the specified format
    //
    void Station::validate(std::ostream& os) const
    {
        os << " getName(): " << item.getName() << std::endl;
        os << " getSerialNumber(): " << item.getSerialNumber() << std::endl;
        os << " getQuantity(): " << item.getQuantity() << std::endl;
    }

}
