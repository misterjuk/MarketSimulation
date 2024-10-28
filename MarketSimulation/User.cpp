#include "User.h"

#include <iostream>
#include <ranges>

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
        m_SelectedItemId -= 1;
        if(m_SelectedItemId == -1)
        {
            m_SelectedItemId = static_cast<int>(ItemID::Last) - 1;
        }
    }
    else if (response == "2")
    {
        m_SelectedItemId += 1;
        if(m_SelectedItemId == static_cast<int>(ItemID::Last))
        {
                m_SelectedItemId = 0;
        }
    }
    else if (response == "3")
    {
        m_MarketPtr->PlaceBuyOrder(m_Inventory, static_cast<ItemID>(m_SelectedItemId), &m_Gold);
    }
    else if (response == "4")
    {
        m_MarketPtr->PlaceSellOrder(m_Inventory,static_cast<ItemID>(m_SelectedItemId), &m_Gold);
    }
    else {
        
    }
    
    return response;
}

void User::PrintStats() const
{
    std::cout << "          User " << '\n';
    
    std::cout << "Name: " << m_Name << " Gold: " << m_Gold << '\n';

    std::cout << "Inventory: " << '\n';
    for (const auto& element : m_Inventory | std::views::values)
    {
        std::cout << "Name: " << element.Name << " Count: " << element.Supply << '\n';
    }
    std::cout << "Selected item ID: " << m_SelectedItemId << '\n';
}

void User::PrintInstructions() const
{
    std::cout << "Type '1' or '2' to scroll through items, type '3' to buy and '4' to sell" << '\n';
}
