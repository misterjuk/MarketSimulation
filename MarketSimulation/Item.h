    #pragma once
    #include <string>

    enum ItemID
    {
        Apple,
       // Tomato,
       // Banana,
        Last
    };


    struct Item
    {
        std::string Name{};
        float Cost{};
        float FluctuatingCost{};

        float Supply{};
        float AverageSupply{};
        float SupplyWeight{};

        float Demand{};
        float AverageDemand{};
        float DemandWeight{};

        float Scarcity{};
        float ScarcityWeight{};

        float EventWeight{};
        float EventMultiplier{};

       
        Item() : Name("Garbage"), Cost(0.0f), Supply(0), Demand(0.0f), FluctuatingCost(0.0f) {}
        
        Item(const std::string& name, float cost, int supply, float demand)
            : Name(name), Cost(cost), Supply(supply), Demand(demand), FluctuatingCost(cost) {}
    };


