#include "User.h"

#include <iostream>

User::User(const std::string& name, float gold)
: m_Gold(gold), m_Name(name)
{
    
}

void User::PrintStats() const
{
    std::cout << "Name: " << m_Name << " Gold: " << m_Gold << '\n';
}
