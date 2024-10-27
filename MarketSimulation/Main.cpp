
#include <iostream>


#include "Market.h"
#include "User.h"


int main(int argc, char* argv[])
{
    std::unique_ptr market = std::make_unique<Market>();

    std::unique_ptr user = std::make_unique<User>("XXXGoldInMyVeinsXXX", 100);

    bool isActive{true};
    while(isActive == true)
    {
        system("cls");
        system("color a");
        market->PrintMarket();
        user->PrintStats();
        std::string response;
        std::cin >> response;
        if(response == "0")
        {
            isActive = false;
        }
    }
    
    
    return 0;
}
