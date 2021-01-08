#pragma once
#include <functional>

#include "HotDrinkFactory.h"
#include "CoffeeFactory.h"
#include "TeaFactory.h"

struct DrinkFactory
{
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> factories;
public:
	DrinkFactory()
	{
		factories["coffee"] = std::make_unique<CoffeeFactory>();
		factories["tea"] = std::make_unique<TeaFactory>();
	}

	std::unique_ptr<HotDrink> make_drink(const std::string& name)
	{
		auto drink = factories[name]->make();
		drink->prepare(200);

		return drink;
	}
};

//Functional factory
class DrinkWithVolumeFactory
{
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;
public:
	DrinkWithVolumeFactory() 
	{
		factories["tea"] = [] {
			auto tea = std::make_unique<Tea>();
			tea->prepare(100);
			return tea;
		};

		factories["coffee"] = [] {
			auto tea = std::make_unique<Coffee>();
			tea->prepare(200);
			return tea;
		};
	}

	std::unique_ptr<HotDrink> make_drink(const std::string& name)
	{
		return factories[name]();
	}
};