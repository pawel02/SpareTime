//#include <iostream>
//#include <vector>
//#include <string>
//
//struct Neuron
//{
//	std::vector<Neuron*> in, out;
//	int id;
//
//	Neuron()
//	{
//		static int id = 1;
//		this->id = id++;
//	}
//
//	Neuron* begin() { return this; }
//	Neuron* end() { return this + 1; }
//
//	void connect_to(Neuron& other)
//	{
//		out.push_back(&other);
//		other.in.push_back(this);
//	}
//	template<typename T>
//	void connect_to(T& other)
//	{
//		for (Neuron& target : other)
//			connect_to(target);
//	}
//
//	friend std::ostream& operator<<(std::ostream& os, const Neuron& obj)
//	{
//		for (Neuron* n : obj.in)
//		{
//			os << n->id << "\t-->\t[" << obj.id << "]\n";
//			
//		}
//
//		for (Neuron* n : obj.out)
//		{
//			os << "[" << obj.id << "]\t-->\t" << n->id << "\n";
//		}
//
//		return os;
//	}
//};
//
//struct NeuronLayer : std::vector<Neuron>
//{
//	NeuronLayer(int count)
//	{
//		while (count-- > 0)
//		{
//			emplace_back(Neuron{});
//		}
//	}
//
//	template< typename T>
//	void connect_to(T& other)
//	{
//		for (Neuron& from : *this)
//			for (Neuron& to : other)
//				from.connect_to(to);
//	}
//
//	friend std::ostream& operator<<(std::ostream& os, const NeuronLayer& obj)
//	{
//		for (const auto& n : obj)
//		{
//			os << n;
//		}
//		return os;
//	}
//};
//
//int main() 
//{
//	Neuron n1, n2;
//	n1.connect_to(n2);
//
//	std::cout << n1 << n2 << "\n";
//
//	NeuronLayer l1{5};
//	Neuron n3;
//	l1.connect_to(n3);
//
//	std::cout << "Neuron " << n3.id << "\n" << n3 << "\n";
//	std::cout << "Layer \n" << l1 << "\n";
//
//	std::cin.get();
//	return 0;
//}