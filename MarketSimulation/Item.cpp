#include "Item.h"


float Item::CalculateDynamicPriceV1()
{
    // askedItem->FluctuatingCost =  askedItem->Cost * 1 * askedItem->Demand;

     //
    float NewPrice{};
    NewPrice = Cost * Demand;
    return NewPrice;
}

float Item::CalculateDynamicPriceV2()
{
    // askedItem->FluctuatingCost =  askedItem->Cost * 1 * askedItem->Demand;

     //
    float NewPrice{};

    float DeltaDemand = (Demand - AverageDemand) / AverageDemand;
    float DeltaSupply = (Supply - AverageSupply) / AverageSupply;


    NewPrice = Cost * (1 +  DemandWeight   * DeltaDemand +
                            SupplyWeight   * DeltaSupply +
                            ScarcityWeight * Scarcity +
                            EventWeight    * EventMultiplier);

    return NewPrice;
}