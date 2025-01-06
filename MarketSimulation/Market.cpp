#include "Market.h"

#include <iostream>
#include <ranges>


Market::Market()
{
    Initialize();
}

void Market::Initialize()
{

    Item apple("Apple", 20.0f, 10, 0.0f);
    //Item tomato("Tomato", 10.0f, 20, 0.0f);
    //Item banana("Banana", 5, 50, 0);
    
    Items.emplace(Apple,apple);
    //Items.emplace(Tomato,tomato);
    //Items.emplace(Banana, banana);
}

void Market::PlaceBuyOrder( std::pmr::map<ItemID, Item>& userInventory, const ItemID itemId, float* userMoney)
{
    if (Items.contains(itemId))
    {
        Item* askedItem = &Items[itemId];
        if(*userMoney >= askedItem->FluctuatingCost)
        {
            askedItem->Supply -= 1;
            askedItem->Demand += 1;
            *userMoney -=  askedItem->FluctuatingCost;
            askedItem->FluctuatingCost =  askedItem->Cost * ( 1 + (askedItem->Demand - askedItem->Supply)/ (askedItem->Supply + 0.00001f));

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
                
                *userMoney += askedItem->FluctuatingCost;
                askedItem->Supply += 1;
                askedItem->Demand -= 1;
                askedItem->FluctuatingCost =  askedItem->Cost * 1 * askedItem->Demand;

                userInventory[itemId].Supply -= 1;
            }
        }
    }
}

float Market::CalculateDynamicPriceV1(const Item& Item)
{
   // askedItem->FluctuatingCost =  askedItem->Cost * 1 * askedItem->Demand;

    //
    float NewPrice{};
    NewPrice = Item.Cost * Item.Demand;
    return NewPrice;
}

float Market::CalculateDynamicPriceV2(const Item& Item)
{
    // askedItem->FluctuatingCost =  askedItem->Cost * 1 * askedItem->Demand;

     //
    float NewPrice{};

    float DeltaDemand = (Item.Demand - Item.AverageDemand) / Item.AverageDemand;
    float DeltaSupply = (Item.Supply - Item.AverageSupply) / Item.AverageSupply;

   
    NewPrice = Item.Cost * (1 + Item.DemandWeight   * DeltaDemand   +
                                Item.SupplyWeight   * DeltaSupply   +
                                Item.ScarcityWeight * Item.Scarcity +
                                Item.EventWeight    * Item.EventMultiplier);
        return NewPrice;
}

void Market::PrintMarket()
{
    std::cout << "      Market " << '\n';
    
    for (const auto& val : Items | std::views::values)
    {
        std::cout <<"Name: " << val.Name
        << "Cost: " << val.FluctuatingCost
        << "Supply: " << val.Supply
        << "Demand: " << val.Demand << '\n';
    }
}


