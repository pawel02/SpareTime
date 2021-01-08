#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>


struct Tag
{
	std::string name;
	std::string text;
	std::vector<Tag> elements;

	std::vector<std::pair<std::string, std::string>> attr;

	friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
	{
		//build the opening tag with attrs
		os << "<" << tag.name;

		for (const auto& att : tag.attr)
			os << " " << att.first << "=\"" << att.second << "\"";

		os << ">\n";

		//put in the text
		os << tag.text;

		//add any children
		for (const auto& e : tag.elements)
			os << e;

		//add the closing tag
		os << "</" << tag.name << ">\n";

		return os;
	}

protected:
	Tag(const std::string& n, const std::string& t)
		:name(n), text(t)
	{}

	Tag(const std::string& n, const std::vector<Tag>& el)
		:name(n), elements{ el }
	{}
};

struct P : Tag
{
	explicit P(const std::string& text)
		:Tag("p", text)
	{}

	explicit P(std::initializer_list<Tag> children)
		:Tag("p", children)
	{}
};

struct IMG : Tag
{
	explicit IMG(const std::string& url)
		:Tag("img", "")
	{
		attr.emplace_back(std::pair<std::string, std::string>("src", url));
	}
};

int main() 
{
	std::cout << 
		P{
			IMG{"http://localhost:8080"},
			P{"Hello"}
		}
	<< "\n";

	std::cin.get();
	return 0;
}