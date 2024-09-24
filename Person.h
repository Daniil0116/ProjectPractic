#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

class Person
{
public:
    Person(std::string name, unsigned age) : name{ name }, age{ age } {};
    std::string getName() const;
    unsigned getAge() const;

    void setName(std::string personName);
    void setAge(unsigned personAge);

private:
    std::string name;
    unsigned age{};
};


