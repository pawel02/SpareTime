#include <iostream>
#include <string>
#include <vector>

/*
Iheritance example
*/
struct Image {
	Image()
	{
		std::cout << "Image Constructor\n";
	}

	virtual ~Image()
	{
		std::cout << "Image destructor\n";
	}

	virtual void draw() = 0;
};

struct Bitmap : virtual Image
{
	Bitmap() 
	{
		std::cout << "Bitmap constructor\n";
	}

	~Bitmap()
	{
		std::cout << "Bitmap destructor\n";
	}

	// Inherited via Image
	virtual void draw() override
	{
		std::cout << "Drawing a bitmap\n";
	}
};

struct Bitmap2 : virtual Image
{
	Bitmap2()
	{
		std::cout << "Bitmap2 constructor\n";
	}

	~Bitmap2()
	{
		std::cout << "Bitmap2 destructor\n";
	}

	// Inherited via Image
	virtual void draw() override
	{
		std::cout << "Drawing a Bitmap2\n";
	}
};

struct Bitmap3 : Bitmap2, Bitmap
{
	Bitmap3()
	{
		std::cout << "Bitmap3 constructor\n";
	}

	~Bitmap3()
	{
		std::cout << "Bitmap3 destructor\n";
	}

	// Inherited via Image
	virtual void draw() override
	{
		std::cout << "Drawing a Bitmap3\n";
	}
};



int main()
{
	{
		Bitmap3 b;
		b.draw();
	}

	std::cin.get();
	return 0;
}