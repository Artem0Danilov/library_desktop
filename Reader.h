#pragma once

#include <iostream>

class Reader {
public:
    std::string getName() const;
    int getAge() const;
    int getDebt() const;

    void setName(const std::string& name);
    void setAge(const int age);
    void setDebt(const float age);
private:
    std::string name;
    int age;
    float debt;
};