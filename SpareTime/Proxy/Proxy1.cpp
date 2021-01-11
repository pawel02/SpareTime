#include <iostream>
#include <string>
#include <vector>
/*
Vritual proxy
*/

struct Image
{
	virtual ~Image() = default;
	virtual void draw() = 0;
};

struct Bitmap : Image
{
	Bitmap(const std::string& filename)
	{
		std::cout << "loading a file from " << filename << "\n";
	}

	void draw() override
	{
		std::cout << "drawing\n";
	}
};

struct LazyBitmap : Image
{
	LazyBitmap(const std::string& filename)
		:bmp{nullptr}, filename {filename}
	{}

	~LazyBitmap()
	{
		delete bmp;
	}

	void draw() override
	{
		if (!bmp)
			bmp = new Bitmap{ filename };
		bmp->draw();
	}
	
private:
	Bitmap* bmp = nullptr;
	std::string filename;
};

void draw_image(Image& img)
{
	std::cout << "about to draw image\n";
	img.draw();
	std::cout << "finished drawing image\n";
}

void draw_bmp()
{
	Bitmap bmp{ "filename.bmp" };
	draw_image(bmp);
	draw_image(bmp);
	draw_image(bmp);
}

int main()
{
	draw_bmp();

	std::cin.get();
	return 0;
}