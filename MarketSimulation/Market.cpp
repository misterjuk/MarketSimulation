#include "Market.h"

#include <iostream>
#include <ranges>


Market::Market()
{
    Initialize();
}

void Market::Initialize()
{

    Item apple("Apple", 20.0f, 10, 2.0f);
    Item tomato("Tomato", 10.0f, 20, 2.0f);
    Item banana("Banana", 5, 50, 10);
    
    Items.emplace(Apple,apple);
    Items.emplace(Tomato,tomato);
    Items.emplace(Banana, banana);
}

void Market::PlaceBuyOrder( std::pmr::map<ItemID, Item>& userInventory, const ItemID itemId, float* userMoney)
{
    if (Items.contains(itemId))
    {
        Item* askedItem = &Items[itemId];
        if(*userMoney >= askedItem->Cost)
        {
            askedItem->Supply -= 1;
            askedItem->Demand += 1;
            *userMoney -=  askedItem->Cost;

            if(userInventory.contains(itemId))
            {
                userInventory[itemId].Supply += 1;
            }
            else
            {
                Item item  = {askedItem->Name, askedItem->Cost, 1, askedItem->Demand};
                userInventory.emplace(itemId, item);
            }
        }
    }
}

void Market::PlaceSellOrder( std::pmr::map<ItemID, Item>& userInventory, const ItemID itemId, float* userMoney)
{
    if(userInventory.contains(itemId))
    {
        if(userInventory[itemId].Supply > 0)
        {
            if(Items.contains(itemId))
            {
                Item* askedItem = &Items[itemId];
                
                *userMoney += askedItem->Cost;
                askedItem->Supply += 1;
                askedItem->Demand -= 1;

                userInventory[itemId].Supply -= 1;
            }
        }
    }
}

void Market::PrintMarket()
{
    std::cout << "      Market " << '\n';
    
    for (const auto& val : Items | std::views::values)
    {
        std::cout << "Name: " << val.Name
        << "Cost: " << val.Cost
        << "Supply: " << val.Supply
        << "Demand: " << val.Demand << '\n';
    }
}
