#pragma once
#include <vector>
#define MEGABYTE 1024*1024



class Shape
{
	public:
		Shape(unsigned int size = 1)
		: _data(size * MEGABYTE), _size(size){}
		
	private:
		std::vector<char> _data;
		unsigned int _size;
};



