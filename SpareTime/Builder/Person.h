#pragma once

#include <iostream>
#include <string>

class PersonBuilder;

class Person
{
	//address
	std::string street_addr, post_code, city;

	//employment
	std::string company_name, position;
	int annual_income = 0;

	Person() {}
public:
	Person(Person&& p) noexcept
		:street_addr(std::move(p.street_addr)),
		post_code(std::move(p.post_code)),
		city(std::move(p.city)),
		company_name(std::move(p.company_name)),
		position(std::move(p.position)),
		annual_income(std::move(p.annual_income))
	{}

	friend std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		return os
			<< p.street_addr
			<< "\n"
			<< p.post_code
			<< "\n"
			<< p.city
			<< "\n"
			<< p.company_name
			<< "\n"
			<< p.position;
	}

	static PersonBuilder create();

	friend class PersonBuilder;
	friend class PersonAddressBuilder;
	friend class PersonJobBuilder;
};