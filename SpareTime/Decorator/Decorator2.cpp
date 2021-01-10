#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <sstream>

/*
Wrapping operator example
and
mixin inheritance
*/

struct Shape
{
	virtual std::string str() const = 0;
};

struct Circle : Shape {
	float radius;

	explicit Circle() noexcept
		:radius(5)
	{}

	explicit Circle(const float radius)
		:radius(radius)
	{}

	void resize(float factor)
	{
		radius *= factor;
	}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << "A circle of radius " << radius;
		return oss.str();
	}
};

struct Square : Shape {
	float width;

	explicit Square()
		:width(5)
	{}

	explicit Square(const float width)
		:width(width)
	{}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << "A square of width " << width;
		return oss.str();
	}
};


struct ColoredShape : Shape
{
	Shape& shape;
	std::string color;

	explicit ColoredShape(Shape& shape, const std::string& color) noexcept
		:shape{shape}, color{color}
	{}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << shape.str() << " has the color " << color << "\n";
		return oss.str();
	}
};

struct TransparentShape : Shape
{
	Shape& shape;
	uint8_t opacity;

	explicit TransparentShape(Shape& shape, uint8_t opacity) noexcept
		:shape{ shape }, opacity{ opacity }
	{}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << shape.str() << " has the opacity:  " << static_cast<float>(opacity) << "\n";
		return oss.str();
	}

};

//mixin inheritance
template<typename T>
struct ColoredShape2 : T
{
	static_assert(std::is_base_of<Shape, T>::value, "Template argument must be a shape");

	std::string color;

	template<typename... Args>
	explicit ColoredShape2(const std::string& color, Args ...args) noexcept
		:T{args...},color{ color }
	{}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << T::str() << " has the color " << color << "\n";
		return oss.str();
	}
};

template<typename T>
struct TransparentShape2 : T
{
	static_assert(std::is_base_of<Shape, T>::value, "Template argument must be a shape");

	uint8_t opacity;

	explicit TransparentShape2() noexcept
		: opacity{ 0 }
	{}

	template<typename... Args>
	explicit TransparentShape2(uint8_t opacity, Args... args) noexcept
		: T(args...), opacity {opacity}
	{}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << T::str() << " has the opacity:  " << static_cast<float>(opacity) << "\n";
		return oss.str();
	}
};

int main() 
{
	Circle circle{ 5 };
	std::cout << circle.str() << "\n";

	ColoredShape red_circle{ circle, "red" };
	std::cout << red_circle.str() << "\n";

	TransparentShape half{ circle, 127 };
	std::cout << half.str() << "\n";

	TransparentShape half_red{ red_circle, 127 };
	std::cout << half_red.str() << "\n";

	//mixin inheritance
	ColoredShape2<TransparentShape2<Circle>> red_half_circle2{ "red" };
	red_half_circle2.opacity = 125;

	std::cout << red_half_circle2.str() << "\n";

	TransparentShape2<Square> s{ 15, 5 };
	std::cout << s.str() << "\n";

	std::cin.get();
	return 0;
}