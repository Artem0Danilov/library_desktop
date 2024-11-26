#pragma once

#include <iostream>

class Reader {
public:
    explicit Reader(const std::string& name = "No Name",
        const int age = -1,);

    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    int getAge() const;
    int getReaderID() const;

    void setName(std::string& name);
    void setAddress(std::string& address);
    void setPhoneNumber(std::string& phoneNumber);
    void setAge(int age);
private:
    std::string name;
    std::string phoneNumber;
    std::string address;
    unsigned int age;
    const int readerID;
    static int count;
};