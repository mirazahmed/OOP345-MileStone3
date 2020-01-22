//This module manages a set of identical items and processes a queue of customer order
//File Name: Station.h
//Author : Miraz Ahmed
//Date Last Modified : August 2, 2019 

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <deque>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {

    class  Station
    {
        std::deque<CustomerOrder> orders{};
        std::string stationName;
        ItemSet item;
    public:
         Station(const std::string& src);
         void display(std::ostream& os) const;
         void fill(std::ostream& os);
         const std::string& getName() const;
         bool hasAnOrderToRelease() const;
         Station& operator--();
         Station& operator+=(CustomerOrder&& order);
         bool pop(CustomerOrder& ready);
         void validate(std::ostream& os) const;

         Station(const Station&) = delete;
         Station& operator=(const Station&) = delete;
         Station(const Station&&) = delete;
         Station& operator=(Station&&) = delete;

    

    };

    
}


#endif // !SICT_STATION_H


