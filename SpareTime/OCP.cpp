////open close principle VERY IMPORTANT
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//enum class Color { Red, Green, Blue };
//enum class Size { Small, Medium, Large };
//
//struct Product
//{
//	std::string name;
//	Color color;
//	Size size;
//};
//
//template<typename T>
//struct ISpecification
//{
//	virtual bool is_satisfied(const T& item) const = 0;
//};
//
//template<typename T>
//struct IFilter
//{
//	virtual std::vector<T> filter(const std::vector<T>& items, ISpecification<T>& spec) = 0;
//};
//
//struct ProductFilter : IFilter<Product>
//{
//	typedef std::vector<Product> Items;
//
//	std::vector<Product> filter(const std::vector<Product>& items, ISpecification<Product>& spec) override
//	{
//		Items result;
//
//		for (auto& p : items)
//		{
//			if (spec.is_satisfied(p))
//			{
//				result.emplace_back(p);
//			}
//		}
//
//		return result;
//	}
//};
//
//struct ColorSpec : ISpecification<Product>
//{
//	Color compare_color;
//
//	explicit ColorSpec(const Color c) noexcept
//		:compare_color(c)
//	{}
//
//	bool is_satisfied(const Product& item) const override
//	{
//		return item.color == compare_color;
//	}
//};
//
//int main()
//{
//	std::vector<Product> products
//	{
//		{"shirt1", Color::Blue, Size::Medium},
//		{ "shirt2", Color::Red, Size::Large },
//		{ "shirt3", Color::Blue, Size::Medium },
//		{ "shirt4", Color::Green, Size::Large },
//		{ "shirt5", Color::Green, Size::Small },
//		{ "shirt6", Color::Blue, Size::Medium }
//	};
//
//	ColorSpec colorSpec(Color::Green);
//	ProductFilter filter;
//
//	std::vector<Product> filtered{ filter.filter(products, colorSpec) };
//
//	for (auto& p : filtered)
//	{
//		std::cout << p.name << "\n";
//	}
//
//	std::cin.get();
//	return 0;
//}