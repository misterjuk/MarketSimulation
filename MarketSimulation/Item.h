#pragma once
#include <string>

enum ItemID
{
    Apple,
    Tomato,
    Banana
};


struct Item
{
    ItemID Id;
    int Cost;
    int Supply;
    float Demand;

    
    Item(ItemID id, int cost, int supply, float demand)
        : Id(id), Cost(cost), Supply(supply), Demand(demand) {}
};


