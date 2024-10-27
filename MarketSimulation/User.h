#pragma once
#include <string>

class User
{
   

public:
    User(const std::string& name, float gold);
    ~User() = default;
    
    User(const User& other) = delete;
    User(User&& other) noexcept = delete;
    User& operator=(const User& other) = delete;
    User& operator=(User&& other) noexcept = delete;

    void PrintStats() const;
private:
    float m_Gold;
    std::string m_Name;
};
