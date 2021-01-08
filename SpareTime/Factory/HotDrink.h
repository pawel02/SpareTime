#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>

struct HotDrink
{
	virtual void prepare(int valume) = 0;
};

struct Tea : public HotDrink
{
	void prepare(int volume) override
	{
		std::cout << "Take tea bag, boil water, pour " << volume << "ml\n";
	}
};

struct Coffee : public HotDrink
{
	void prepare(int volume) override
	{
		std::cout << "Grind some beans, boil water, pour " << volume << "ml\n";
	}
};

std::unique_ptr<HotDrink> make_drink(std::string type)
{
	std::unique_ptr<HotDrink> drink;

	if (type == "tea")
	{
		drink = std::make_unique<Tea>();
		drink->prepare(200);
	}
	else
	{
		drink = std::make_unique<Coffee>();
		drink->prepare(500);
	}

	return drink;
}