#include "Person.h"
#include "PersonsIO.h"


int main()
{
    PersonsIO personsIO;
    std::vector<Person> people =
    {
        Person{"Tom", 23},
        Person{"Bob", 25},
        Person{"Alice", 22},
        Person{"Kate", 31}
    };

    personsIO.WritePersonsToFile("people.txt", people);
    people.clear();

    personsIO.ReadPersonsFromFile("people.txt", people);

    std::cout << "All people:" << std::endl;
    personsIO.CopyPersonsToStream(std::cout, people);

}