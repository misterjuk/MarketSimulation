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
        std::string Name;
        float Cost;
        int Supply;
        float Demand;

        Item() : Name("Garbage"), Cost(0.0f), Supply(0), Demand(0.0f) {}
        
        Item(const std::string& name, float cost, int supply, float demand)
            : Name(name), Cost(cost), Supply(supply), Demand(demand) {}
    };


