#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <map>


template<class T>
class LRU
{
public:

	LRU(int size) : _size(size) {}

	void add(T val, std::string address)
	{
		
	}

private:
	template<class T>
	class node
	{
		T val;
		std::string address;
	}
	std::vector<std::weak_ptr<node>> _cache;
	int _size;

}