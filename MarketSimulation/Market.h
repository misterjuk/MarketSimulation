#pragma once

#include <map>
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
    void PlaceBuyOrder(std::pmr::map<ItemID, Item>& userInventory, const ItemID itemId, float* userMoney);
    void PlaceSellOrder(std::pmr::map<ItemID, Item>& userInventory, const ItemID itemId, float* userMoney);
    void PrintMarket();

    const  std::map<ItemID, Item>& GetItems() { return Items; };
private:

    std::map<ItemID, Item> Items;
};
