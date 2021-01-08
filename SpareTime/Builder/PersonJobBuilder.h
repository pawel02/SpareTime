#pragma once
#pragma once
#include <string>

#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilder
{
	typedef PersonJobBuilder Self;

public:
	explicit PersonJobBuilder(Person& person)
		:PersonBuilder{ person }
	{}

	Self& at(std::string company)
	{
		person.company_name = company;
		return *this;
	}

	Self& as_a(std::string pos)
	{
		person.position = pos;
		return *this;
	}

	Self& income(int income)
	{
		person.annual_income = income;
		return *this;
	}

};