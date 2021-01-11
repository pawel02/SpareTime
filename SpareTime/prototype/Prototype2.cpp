#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>

#include <boost/serialization/serialization.hpp>
#include <boost\archive\text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

struct Address {
	std::string street_addr, city;

	int suite = 0;

	friend std::ostream& operator<<(std::ostream& os, const Address& addr)
	{
		return os << "street : " << addr.street_addr << "\ncity : " << addr.city << "\nsuite : " << addr.suite << "\n";
	}

private:
	friend class boost::serialization::access;
	
	template<class Ar> void serialize(Ar& ar, const unsigned int version)
	{
		ar & street_addr;
		ar & city;
		ar & suite;
	}
};

struct Contact
{
	std::string name;
	Address* addr = nullptr;

	friend std::ostream& operator<<(std::ostream& os, const Contact& c)
	{
		return os << "name : " << c.name << "\n" << *(c.addr);
	}

private:
	friend class boost::serialization::access;

	template<class Ar> void serialize(Ar& ar, const unsigned int version)
	{
		ar& name;
		ar& addr;
	}
};

int main() 
{
	Contact John;
	John.name = "John Doe";
	John.addr = new Address{"123 East Dr", "London", 123};

	auto clone = [](Contact c) {

		std::ostringstream oss;

		//serializing the Contact
		boost::archive::text_oarchive oa(oss);
		oa << c;

		std::string s = oss.str();

		//deserialize
		Contact result;
		std::istringstream iss(s);

		boost::archive::text_iarchive ia(iss);
		ia >> result;

		return result;
	};

	Contact Jane = clone(John);
	Jane.name = "Jane";

	std::cout << John << "\n" << Jane;

	std::cin.get();
	return 0;
}