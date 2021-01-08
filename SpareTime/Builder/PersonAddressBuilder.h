#pragma once
#include <string>

#include "PersonBuilder.h"

class PersonAddressBuilder : public PersonBuilder
{
	typedef PersonAddressBuilder Self;

public:
	explicit PersonAddressBuilder(Person& person)
		:PersonBuilder{person}
	{}

	Self& at(std::string street_addr)
	{
		person.street_addr = street_addr;
		return *this;
	}

	Self& with_postcode(std::string postcode)
	{
		person.post_code = postcode;
		return *this;
	}

	Self& city(std::string city)
	{
		person.city = city;
		return *this;
	}

};