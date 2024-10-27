#include "User.h"

#include <iostream>

#include "Market.h"

User::User(const std::string& name, float gold, Market* marketPtr)
: m_Gold(gold), m_Name(name),m_MarketPtr(marketPtr)
{
    
}

std::string User::HandleInput()
{
    std::string response;
    std::cin >> response;

    if (response == "1")
    {
        m_MarketPtr->PlaceBuyOrder(m_Inventory, ItemID::Apple, &m_Gold);
    }
    else if (response == "2")
    {
        m_MarketPtr->PlaceSellOrder(m_Inventory, ItemID::Apple, &m_Gold);
    }
    else {
        
    }
    
    return response;
}

void User::PrintStats() const
{
    std::cout << "Name: " << m_Name << " Gold: " << m_Gold << '\n';
}
