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
        float SupplyWeight{0.5f};

        float Demand{};
        float AverageDemand{};
        float DemandWeight{0.5f};

        float Scarcity{};
        float ScarcityWeight{0.5f};

        float EventWeight{};
        float EventMultiplier{0.5f};

       
        Item() : Name("Garbage"), Cost(0.0f), Supply(0), Demand(0.0f), FluctuatingCost(0.0f) {}
        
        Item(const std::string& name, float cost, int supply, float demand)
            : Name(name), Cost(cost), AverageSupply(supply), Supply(supply),Demand(demand),AverageDemand(demand) 
        {

            CalculateDynamicPriceV2();
        }


        void CalculateDynamicPriceV1();
        void CalculateDynamicPriceV2();
    };


