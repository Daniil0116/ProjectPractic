#include "Person.h"
#include "PersonsIO.h"

std::ostream& operator << (std::ostream& os, const Person& person)
{
    return os << person.getName() << " " << person.getAge();
}

std::istream& operator >> (std::istream& in, Person& person)
{
    std::string name;
    unsigned    age;

    in >> name >> age;

    if (in)
    {
        person.setName(name);
        person.setAge(age);
    }

    return in;
}

int PersonsIO::CopyPersonsToStream(std::ostream& os, std::vector<Person>& persons)
{
    std::copy(persons.begin(), persons.end(), std::ostream_iterator<Person>(os, "\n"));
    return 0;
}

int PersonsIO::WritePersonsToFile(std::string fileName, std::vector<Person>& persons)
{
    std::ofstream out(fileName);
    if (out.is_open())
    {
        CopyPersonsToStream(out, persons);
    }
    else
    {
        return 1;
    }
    out.close();

    return 0;
}

int PersonsIO::ReadPersonsFromFile(std::string fileName, std::vector<Person>& persons)
{
    std::ifstream in(fileName);
    if (in.is_open())
    {
        Person person{ "",0 };
        while (in >> person)
        {
            persons.push_back(person);
        }
    }
    else
    {
        return 1;
    }
    in.close();

    return 0;
}