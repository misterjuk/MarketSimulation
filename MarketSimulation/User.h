#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

enum ItemID : int;
class Market;
struct Item;

class User
{
   

public:
    User(const std::string& name, float gold, Market* marketPtr);
    ~User() = default;
    std::string HandleInput();

    User(const User& other) = delete;
    User(User&& other) noexcept = delete;
    User& operator=(const User& other) = delete;
    User& operator=(User&& other) noexcept = delete;

    void PrintStats() const;
private:
    float m_Gold;
    std::string m_Name;

    Market* m_MarketPtr;
    std::pmr::map<ItemID, Item> m_Inventory;
};
