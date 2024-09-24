#include "Person.h"


std::string Person::getName() const 
{ 
	return name; 
}

unsigned Person::getAge() const 
{ 
	return age; 
}

void Person::setName(std::string personName) 
{ 
	name = personName; 
}

void Person::setAge(unsigned personAge) 
{ 
	age = personAge; 
}

