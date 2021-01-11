#include <iostream>
#include <thread>

/*
Decouples interface hirearchy from implementation hirearchy

example here is with the pimple idiom
*/

#include "PersonImpl.h"

int main()
{
	AngryPerson* ap = new AngryPerson();
	Person p(ap);
	p.name = "Bob";
	p.greet();

	std::cin.get();
	return 0;
}