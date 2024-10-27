#pragma once

#include <vector>

#include "Item.h"

class Market final
{
public:
    Market();
    ~Market() = default;
    
    Market(const Market& other) = delete;
    Market(Market&& other) = delete;
    Market& operator=(const Market& other) = delete;
    Market& operator=(Market&& other) = delete;

    void Initialize();
    void PlaceOrder(ItemID itemID);
    void PrintMarket();
private:

    std::vector<Item> Items;
};
