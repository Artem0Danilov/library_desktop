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

    void setName(const std::string& name);
    void setAddress(const std::string& name);
    void setPhoneNumber(const std::string& phoneNumber);
    void setAge(const int age);
private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    unsigned int age;
    const int readerID;
    static int count;

};