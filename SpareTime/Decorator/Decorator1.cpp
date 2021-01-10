//#include <iostream>
//#include <vector>
//#include <string>
//#include <functional>
//
//template<typename Func>
//struct Logger
//{
//	Func func;
//	std::string name;
//
//	explicit Logger(const Func& func, const std::string& name) noexcept
//		:func(func), name(name)
//	{}
//
//	void operator()() const
//	{
//		std::cout << name << "\n";
//		func();
//	}
//};
//
//template<typename Func>
//auto make_logger(Func f, const std::string& name)
//{
//	return Logger<Func>{f, name};
//}
//
//template<typename>
//struct Logger2;
//
//template<typename R, typename... Args>
//struct Logger2<R(Args...)>
//{
//	std::function<R(Args...)> func;
//	std::string name;
//
//	explicit Logger2(const std::function<R(Args...)>& func, const std::string& name) noexcept
//		:func(func), name(name)
//	{}
//
//	R operator()(Args... args)
//	{
//		std::cout << "Entering " << name << "\n";
//		R result = func(args...);
//		std::cout << "Exiting " << name << "\n";
//
//		return result;
//	}
//};
//
//double add(double a, double b) 
//{ 
//	std::cout << "a + b = " << (a + b) << "\n";
//	return a + b; 
//}
//
//
//template<typename R, typename... Args>
//auto make_logger2(R(*func)(Args...), const std::string& name)
//{
//	return Logger2<R(Args...)>{std::function<R(Args...)>(func), name};
//}
//
//int main()
//{
//	make_logger( []() {std::cout << "Hello calling\n"; }, "Hello func" )();
//	std::cout << "\n\n"; //some spacing in between
//	make_logger2(add, "add func")(2, 3);
//
//	std::cin.get();
//	return 0;
//}