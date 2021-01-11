#include <iostream>
#include <memory>
#include <vector>

#include <boost\accumulators\accumulators.hpp>
#include <boost\accumulators\statistics.hpp>

struct Expression
{
	virtual double eval() = 0;
	virtual void collect(std::vector<double>& v) = 0;
};

struct Literal : Expression
{
	double val;

	explicit Literal(const double value)
		:val(value)
	{}

	double eval() override
	{
		return val;
	}

	void collect(std::vector<double>& v) override
	{
		v.push_back(val);
	}
};

struct AdditionExpression : Expression
{
	std::shared_ptr<Expression> left, right;

	AdditionExpression(const std::shared_ptr<Expression>& l, const std::shared_ptr<Expression>& r)
		:left(l), right(r)
	{}

	double eval() override
	{
		return left->eval() + right->eval();
	}

	void collect(std::vector<double>& v) override
	{
		left->collect(v);
		right->collect(v);
	}
};

int main() 
{
	AdditionExpression sum
	{
		std::make_shared<Literal>(2),
		std::make_shared<AdditionExpression>
		(
			std::make_shared<Literal>(3),
			std::make_shared<Literal>(4)
		)
	};

	std::vector<double> v;
	sum.collect(v);

	for (const auto& u : v)
		std::cout << u << "\t";

	std::cout << "2 + (3 + 4) = " << sum.eval() << "\n";

	boost::accumulators::accumulator_set<double, boost::accumulators::stats<boost::accumulators::tag::mean>> acc;
	for (const auto& x : v) acc(x);
	std::cout << "average is " << boost::accumulators::mean(acc) << "\n";

	std::cin.get();
	return 0;
}