#include <cmath>
#include <iostream>

#include "HotDrink.h"
#include "DrinkFactory.h"

class Point
{
private:
	float x, y;

	Point(const float x, const float y)
		:x(x), y(y)
	{}

	class PointFactory
	{
	public:
		Point createCartesian(const float a, const float b)
		{
			return { a, b };
		}

		Point createPolar(const float r, const float theta)
		{
			return { r * std::cos(theta), r * std::sin(theta) };
		}
	};

public:
	
	friend std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		return os << "x: " << obj.x << "\ny: " << obj.y;
	}

	inline static PointFactory Factory;
};


//extern std::unique_ptr<HotDrink> make_drink(std::string type);

int main()
{

	Point p = Point::Factory.createCartesian(1, 2);
	Point p1 = Point::Factory.createPolar(5, 3.14 / 4);


	std::cout << p << "\n";
	std::cout << p1 << "\n";


	//Abstract factory example
	DrinkFactory df;
	df.make_drink("coffee");

	//functional factory
	DrinkWithVolumeFactory dvf;
	dvf.make_drink("tea");

	std::cin.get();
	return 0;
}