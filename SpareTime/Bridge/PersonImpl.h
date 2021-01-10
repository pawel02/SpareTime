#pragma once
#include "Person.h"
#include <iostream>

struct PersonImpl
{
	virtual void greet(Person* p)
	{
		std::cout << "greetings " << p->name << "\n";
	}
};

struct AngryPerson : public virtual PersonImpl
{
	virtual void greet(Person* p) override
	{
		std::cout << "Angry person " << p->name << "\n";
	}
};
