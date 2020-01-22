//This module manages all the stations of the assembly line and processes a vector of customer orders
//File Name: LineManager.h
//Author : Miraz Ahmed
//Date Last Modified : August 2, 2019 


#ifndef SICT_LINE_MANAGER_H
#define SICT_LINE_MANAGER_H
#include <vector>
#include <deque>
#include <algorithm>
#include "Station.h"
#include "CustomerOrder.h"

namespace sict {

    class LineManager
    {
        std::vector<Station*> stations{};
        std::vector<size_t> assemnlyLine{};
        size_t firstStation{};
        size_t lastStation{};
        std::vector<size_t> nextStations{};
        std::deque<CustomerOrder> waitingQueue{};
        std::deque<CustomerOrder> completed{};
        std::deque<CustomerOrder> incomplete{};
    public:
        LineManager(std::vector<Station*>& station, std::vector<size_t>& indexNxtStation, std::vector<CustomerOrder>& order, size_t indexStartStation, std::ostream& os);
        void display(std::ostream& os) const;
        bool run(std::ostream& os);
    };

}





#endif // !SICT_LINE_MANAGER_H

