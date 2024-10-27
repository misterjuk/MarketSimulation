#include "Market.h"

#include <iostream>


Market::Market()
{
    Initialize();
}

void Market::Initialize()
{

    Items.push_back(Item(Apple, 20,10,2));
}

void Market::PlaceOrder(ItemID itemID)
{
    for (auto& [Id, Cost, Supply, Demand] : Items)
    {
        if(Id == itemID)
        {
            Supply --;
            Demand ++;
        }
    }
}

void Market::PrintMarket()
{
    for (const auto& [Id, Cost, Supply, Demand] : Items)
    {
      
        std::cout << "Name: " << Id << "Cost: " << Cost << "Supply: " << Supply << "Demand: " << Demand << '\n';
        
    }
}
