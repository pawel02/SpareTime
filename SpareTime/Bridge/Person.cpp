#include "Person.h"
#include "PersonImpl.h"

Person::Person()
	:impl(new PersonImpl)
{}

Person::Person(PersonImpl* p)
	: impl(p)
{}

Person::~Person()
{
	delete impl;
}

void Person::greet()
{
	impl->greet(this);
}
