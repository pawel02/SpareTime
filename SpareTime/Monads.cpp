//#include <iostream>
//#include <string>
//#include <vector>
//#include <type_traits>
//#include <optional>
//
////maybe monad fun
//template<typename T>
//struct Maybe;
//
////getting type deduction
//template<typename T>
//Maybe<T> maybe(T* context)
//{
//	return Maybe<T>(context);
//}
//
//template<typename T>
//struct Maybe {
//	T* context;
//
//	explicit Maybe(T* c)
//		:context{ c }
//	{}
//
//	template<typename Func>
//	auto with(Func evaluator)
//	{
//		if (context != nullptr)
//		{
//			return maybe(evaluator(context));
//		}
//		else
//		{
//			return Maybe<typename std::remove_pointer<decltype(evaluator(context))>::type >(nullptr);
//		}
//	}
//
//	template<typename Func>
//	auto Do(Func Action)
//	{
//		if (context != nullptr)
//		{
//			Action(context);
//			return *this;
//		}
//	}
//};
//
//struct Address
//{
//	std::string* house_name;
//};
//
//struct Person
//{
//	Address* address;
//};
//
//void print_house_name(Person* p)
//{
//	/*if (p != nullptr && p->address != nullptr && p->address->house_name != nullptr)
//	{
//		std::cout << p->address->house_name << "\n";
//	}*/
//
//	maybe(p)
//		.with([](auto x) { return x->address; })
//		.with([](auto x) { return x->house_name; })
//		.Do([](auto x) { std::cout << *x << "\n"; });
//}
//
//int main()
//{
//	Person p;
//	p.address = new Address;
//	p.address->house_name = new std::string("Hello world");
//	print_house_name(&p);
//
//	delete p.address->house_name;
//	delete p.address;
//
//	std::cin.get();
//	return 0;
//}