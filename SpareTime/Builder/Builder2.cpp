//#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <memory>
//
//struct HtmlBuilder;
//
//struct HtmlElement
//{
//	std::string name;
//	std::string text;
//	std::vector<HtmlElement> elements;
//	const size_t indent_size = 2;
//
//	HtmlElement() {}
//
//	HtmlElement(const std::string& n, const std::string& t)
//		:name(n), text(t)
//	{}
//
//	std::string str(size_t indent = 0) const 
//	{
//		std::ostringstream oss;
//		std::string i(indent_size * indent, ' ');
//		oss << i << "<" << name << ">" << "\n";
//
//		if(text.size() > 0)
//			oss << std::string(indent_size * (indent + 1), ' ') << text << "\n";
//	
//		//call recursively on all children
//		for (const auto& e : elements)
//		{
//			oss << e.str(indent + 1);
//		}
//
//		oss << i << "</" << name << ">\n";
//		return oss.str();
//	}
//
//	static HtmlBuilder build(const std::string& root_name);
//	static std::unique_ptr<HtmlBuilder> create(const std::string& root_name);
//};
//
//struct HtmlBuilder
//{
//	HtmlBuilder(std::string root_name)
//	{
//		root.name = root_name;
//	}
//
//	HtmlBuilder& add_child(std::string child_name, std::string child_text)
//	{
//		HtmlElement e{ child_name, child_text };
//		root.elements.emplace_back(e);
//
//		return *this;
//	}
//
//	HtmlBuilder* add_child2(std::string child_name, std::string child_text)
//	{
//		HtmlElement e{ child_name, child_text };
//		root.elements.emplace_back(e);
//
//		return this;
//	}
//
//	HtmlElement root;
//
//	operator HtmlElement() { return root; }
//
//	std::string str() const { return root.str(); };
//};
//
//HtmlBuilder HtmlElement::build(const std::string& root_name)
//{
//	return HtmlBuilder{ root_name };
//}
//
//std::unique_ptr<HtmlBuilder> HtmlElement::create(const std::string& root_name)
//{
//	return std::make_unique<HtmlBuilder>( root_name );
//}
//
//int main()
//{
//	/*HtmlBuilder builder{ "ul" };
//	builder.add_child("li", "Hello")
//		.add_child("li", "World");*/
//
//	HtmlElement e = HtmlElement::build("ul").add_child("li", "Hello")
//		.add_child("li", "world");
//
//	HtmlElement ee = *HtmlElement::create("ul")->add_child2("li", "Hello")
//		->add_child2("li", "world");
//
//	std::cout << e.str() << "\n";
//	
//	std::cin.get();
//	return 0;
//}