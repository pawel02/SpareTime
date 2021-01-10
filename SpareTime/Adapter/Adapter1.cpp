//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <boost/algorithm/string.hpp>
//
//class String {
//	std::string s;
//public:
//	String(const std::string& cs)
//		:s(cs)
//	{}
//
//	String to_lower() const
//	{
//		std::string ss{ s };
//		boost::to_lower(ss);
//		return { ss };
//	}
//
//	std::vector<std::string> split(const std::string& delimeter = " ") const
//	{
//		std::vector<std::string> result;
//
//		boost::split(result, s, boost::is_any_of(delimeter), boost::token_compress_on);
//
//		return result;
//	}
//};
//
//int main() 
//{
//	String s{ "Hello World!" };
//
//	auto parts = s.to_lower().split();
//
//	for (const auto& p : parts)
//		std::cout << "<" << p << ">\n";
//
//	std::cin.get();
//	return 0;
//}