
#include <iostream>


#include "Market.h"
#include "User.h"
#include "CSVWriter.h"


int main(int argc, char* argv[])
{
    const std::unique_ptr market = std::make_unique<Market>();

    const std::unique_ptr user = std::make_unique<User>("XXXGoldInMyVeinsXXX", 100, market.get());

    const std::unique_ptr csvWriter = std::make_unique<CSVWriter>();

    bool isActive{true};
    while(isActive == true)
    {
        system("cls");
        system("color a");
        market->PrintMarket();
        user->PrintStats();
        user->PrintInstructions();

        //csvWriter->WriteToCSV(market->GetItems());
     
        std::string response = user->HandleInput();
        if(response == "exit")
        {
            isActive = false;
        }
    }
    
    
    return 0;
}
