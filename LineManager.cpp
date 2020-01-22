//Implementation of LineManager.h
//File Name: LineManager.cpp
//Author : Miraz Ahmed
//Date Last Modified : August 2, 2019 


#include "LineManager.h"
namespace sict {
    
    //A five argument constructor that moves the customer orders 
    //to the front of a queue that holds the orders waiting to be filled and 
    //determines the index of the last station on the line
    //
    LineManager::LineManager(std::vector<Station*>& station, std::vector<size_t>& indexNxtStation, std::vector<CustomerOrder>& order, size_t indexStartStation, std::ostream& os)
    {
        stations.resize(station.size());
        for (size_t i = 0; i < station.size(); i++)
        {
            station.at(i) = station.at(i);
        }

        for (size_t i = 0; i < order.size(); i++)
        {
            waitingQueue.push_back(std::move(order.at(i)));
        }

        firstStation = indexStartStation;

        nextStations.resize(indexNxtStation.size());
        for (size_t i = 0; i < nextStations.size(); i++)
        {
            nextStations.at(i) = indexNxtStation.at(i);
        }

        lastStation = firstStation;
        while (nextStations.at(lastStation) != stations.size())
        {
            lastStation = nextStations.at(lastStation);
        }

    }

    //A query that displays completed and incomplete orders at the end of the line
    //
    void LineManager::display(std::ostream& os) const
    {
        os << "COMPLETED ORDERS" << std::endl;
        for (auto& i : completed) { i.display(os, true); }
        os << std::endl;
        os << "INCOMPLETE ORDERS" << std::endl;
        for (auto& i : incomplete) { i.display(os, true); }
    }

    //Completes full steps of assembly process by filling customer order at each station with one item from that station
    //Checks if any customer order to be released at each station on line according to user specified order
    //Releases the order from the station if there is an order to be released
    //If the station is the last one, moves the order to complete/incomplete; if not,moves the order to the next station
    //
    bool LineManager::run(std::ostream& os)
    {
        bool allProcessed{ false };
        size_t noOfOrders{ waitingQueue.size() };
        std::string past{};
        std::string next{};
        std::string nameProdudct{};

        while (!waitingQueue.empty() || noOfOrders)
        {
            if (!waitingQueue.empty())
            {
                *(stations.at(firstStation)) += std::move(waitingQueue.front());
                waitingQueue.pop_front();
            }
        

            for (size_t i = 0; i < stations.size(); i++)
            {
                stations.at(i)->fill(os);
            }

            size_t index = firstStation;
            CustomerOrder temp{};
            for (size_t i = 0; i < stations.size(); i++)
            {
                if (stations.at(i)->hasAnOrderToRelease())
                {
                    stations.at(i)->pop(temp);
                    if (i != lastStation)
                    {
                    past = stations.at(i)->getName();
                    index = nextStations.at(i);
                        if (index != stations.size())
                        {
                            next = stations.at(index)->getName();
                            nameProdudct = temp.getNameProduct();
                            *(stations.at(index)) += std::move(temp);
                            os << " --> " << nameProdudct << " moved from " << past << " to " << next << std::endl;
                        }
                    }
                    
                    else
                    {
                        nameProdudct = temp.getNameProduct();
                        past = stations.at(i)->getName();
                        os << " -->" << nameProdudct << " moved from " << past << " to ";

                        if (temp.isFilled())
                        {
                            os << "Completed Set" << std::endl;
                            completed.push_back(std::move(temp));
                        }

                        else
                        {
                            os << "Incomplete Set" << std::endl;
                            incomplete.push_back(std::move(temp));
                        }
                        --noOfOrders;
                    }
                }
            }
        }
    
        if (!noOfOrders)
        {
            allProcessed = true;
        }
        return allProcessed;
    }

}
    