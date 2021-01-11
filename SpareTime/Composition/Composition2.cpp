#include <iostream>
#include <string>
#include <vector>

struct GraphicObject
{
	virtual void draw() = 0;
};

struct Circle : GraphicObject
{
	virtual void draw() override
	{
		std::cout << "Circle" << "\n";
	}
};

struct Group : GraphicObject
{
	std::string name;
	std::vector<GraphicObject*> objects;

	Group(const std::string& name)
		:name(name)
	{}

	virtual void draw() override
	{
		std::cout << "Group " << name << " contains: \n";
		for (auto&& o : objects)
		{
			o->draw();
		}
	}
};

int main() 
{
	Group root("root");
	Circle c1, c2;

	root.objects.push_back(&c1);

	Group subGroup("subGroup");

	subGroup.objects.push_back(&c2);

	root.objects.push_back(&subGroup);

	root.draw();

	std::cin.get();
	return 0;
}