////example where its important to use prototypes
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//struct Address {
//	std::string street_addr, city;
//
//	int suite = 0;
//
//	friend std::ostream& operator<<(std::ostream& os, const Address& addr)
//	{
//		return os << "street : " << addr.street_addr << "\ncity : " << addr.city << "\nsuite : " << addr.suite << "\n";
//	}
//};
//
//struct Contact
//{
//	std::string name;
//	Address* work_addr;
//
//	Contact(const std::string& n, Address* addr)
//		:name(n), work_addr(new Address{ *addr })
//	{}
//
//	//prototyping is all about deep copies instead of shallow copies
//	Contact(const Contact& other)
//		:name(other.name),
//		work_addr(new Address{*other.work_addr})
//	{}
//
//	~Contact()
//	{
//		delete work_addr;
//	}
//
//	friend std::ostream& operator<<(std::ostream& os, const Contact& c)
//	{
//		return os << "name : " << c.name << "\n" << *(c.work_addr);
//	}
//};
//
//struct EmployeeFactory
//{
//	static Contact main, aux;
//
//	static std::unique_ptr<Contact> newMainOfficeEmployee(std::string name, int suite)
//	{
//		return NewEmployee(name, suite, main);
//	}
//
//	static std::unique_ptr<Contact> newAuxOfficeEmployee(std::string name, int suite)
//	{
//		return NewEmployee(name, suite, aux);
//	}
//
//private:
//	static std::unique_ptr<Contact> NewEmployee(std::string name, int suite, Contact& proto)
//	{
//		auto result = std::make_unique<Contact>(proto);
//		result->name = name;
//		result->work_addr->suite = suite;
//		return result;
//	}
//};
//
//Contact EmployeeFactory::main{ "", new Address{"123 East Dr", "London", 0} };
//Contact EmployeeFactory::aux{ "", new Address{"123b East Dr", "London", 0} };
//
//
//int main() 
//{
//	/*Address* addr = new Address{ "123 East Dr", "London" };
//
//	Contact John { "John Doe", addr };
//	John.work_addr->suite = 100;
//
//	Contact Jane { "Jane Doe", addr };
//	Jane.work_addr->suite = 50;
//
//	Contact Jill{ Jane };
//	Jill.work_addr->suite = 150;
//
//	std::cout << John << "\n" << Jane << "\n" << Jill;*/
//
//	//Contact John{employee};
//	//John.name = "John";
//	//John.work_addr->suite = 100;
//
//
//	//Contact Jane{ employee };
//	//Jane.name = "Jane";
//	//Jane.work_addr->suite = 50;
//
//	//std::cout << John << "\n" << Jane;
//
//	auto John = EmployeeFactory::newMainOfficeEmployee("John", 100);
//	auto Jane = EmployeeFactory::newAuxOfficeEmployee("Jane", 123);
//
//
//	std::cout << *John << "\n" << *Jane;
//
//	std::cin.get();
//	return 0;
//}