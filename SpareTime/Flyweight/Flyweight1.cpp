#include <iostream>
#include <string>
#include <vector>
#include <boost/bimap.hpp>

/*
Flyweight is all about saving memory
This is an example of this instead of storing the all the names in each object
we store a static map with the names under keys
Another example would be with text where you want to make part of it bold. instead of having each character with metadata you can use ranges to 
say whether the text should be bold or not
*/

typedef uint32_t key;

struct User
{
	explicit User(const std::string& f, const std::string& l) noexcept
		:first_name{add(f)}, last_name{add(l)}
	{}

	const std::string& get_first() const
	{
		return names.left.find(first_name)->second;
	}

	const std::string& get_last() const
	{
		return names.left.find(last_name)->second;
	}

	friend std::ostream& operator<<(std::ostream& os, const User& obj)
	{
		return os << "first name: " << obj.first_name << " " << obj.get_first() << " "
			<< "last name: " << obj.last_name << " " << obj.get_last() << "\n";
	}

protected:
	static boost::bimap<key, std::string> names;
	static int seed;

	inline static key add(const std::string& s)
	{
		auto it = names.right.find(s);
		if (it == names.right.end())
		{
			key id = ++seed;
			names.insert(boost::bimap<key, std::string>::value_type(id, s));
			return id;
		}

		return it->second;
	}

	key first_name, last_name;
};

int User::seed = 0;
boost::bimap<key, std::string> User::names{};


int main()
{
	User john_doe{ "John", "Doe" };
	User jane_doe{ "Jane", "Doe" };

	std::cout << john_doe << jane_doe;

	std::cin.get();
	return 0;
}