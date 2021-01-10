#pragma once
#include <string>

struct PersonImpl;

struct Person {
	std::string name;

	PersonImpl* impl;
	Person();
	Person(PersonImpl* p);
	~Person();
	void greet();
};