#pragma once

#include <iostream>

class Reader {
public:
    explicit Reader(const std::string& name = "No Name",
        const int age = -1,);

    std::string getName() const;
    int getAge() const;
    int getDebt() const;
    int getReaderID() const;

    void setName(const std::string& name);
    void setAge(const int age);
    void setDebt(const float age);
private:
    std::string name;
    int age;
    float debt;
    const int readerID;
};