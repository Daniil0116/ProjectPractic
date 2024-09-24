#pragma once
#include "Person.h"

class PersonsIO
{
public:
    int CopyPersonsToStream(std::ostream& os, std::vector<Person>& persons);
    int WritePersonsToFile(std::string fileName, std::vector<Person>& persons);
    int ReadPersonsFromFile(std::string fileName, std::vector<Person>& persons);
};



