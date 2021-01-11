#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <boost/lexical_cast.hpp>

struct Logger
{
	virtual ~Logger() = default;
	virtual void info(const std::string& s) = 0;
	virtual void warning(const std::string& s) = 0;
};

struct BankAccount
{
	std::shared_ptr<Logger> log;

	std::string name;
	int balance = 0;

	BankAccount(const std::shared_ptr<Logger> l, const std::string& n, int b)
		:log(l), name(n), balance(b)
	{}

	void deposit(int amount)
	{
		balance += amount;
		log->info("deposited £" + boost::lexical_cast<std::string>(amount) + " to " + name + ", balance is now £" + boost::lexical_cast<std::string>(balance));
	}

	void withdraw(int amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			log->info("Withdrew £" + boost::lexical_cast<std::string>(amount) + " to " + name + ", balance is now £" + boost::lexical_cast<std::string>(balance));

		}
		else
		{
			log->warning("Not enough balance!!!");
		}
	}
};

struct ConsoleLogger : Logger
{
	virtual void info (const std::string& s) override
	{
		std::cout << "INFO: " << s << "\n";
	}

	virtual void warning(const std::string& s) override
	{
		std::cout << "WARN: " << s << "\n";
	}
};

//example of a null object
/*
Basically and empty implementation
*/
struct NullLogger : Logger
{
	virtual void info(const std::string& s) override {};
	virtual void warning(const std::string& s) override {};
};


int main()
{
	//auto logger = std::make_shared<ConsoleLogger>();
	auto logger = std::make_shared<NullLogger>();


	BankAccount acc{ logger, "primary acc", 1000 };
	acc.deposit(500);
	acc.deposit(200);
	acc.deposit(2000);


	std::cout << "Hello world!\n";

	std::cin.get();
	return 0;
}