#include "shape.h"
#include "vector.h"
#include "pointer_vector.h"
#include <ctime>
#include <iostream>

double VECTOR_INSERT_AVG;
double VECTOR_REMOVE_AVG;
	
double POINTER_VECTOR_INSERT_AVG;
double POINTER_VECTOR_REMOVE_AVG;


void TestVector()
{
	double VECTOR_INSERT_SUM = 0;
	
	Vector<Shape> vec(100);
	Shape object;
	
	// insert
	
	std::clock_t begin;
	std::clock_t end;
	
	for (int i = 0; i < 10; i++)
	{
		begin = std::clock();
		vec.insert(object, 0);
		end = std::clock();
		
		VECTOR_INSERT_SUM += (1000.0 * (end - begin) / CLOCKS_PER_SEC);
	}
	VECTOR_INSERT_AVG = VECTOR_INSERT_SUM / 10;
	
	// remove
	
	double VECTOR_REMOVE_SUM = 0;
	
	for (int i = 0; i < 10; i++)
	{
		begin = std::clock();
		vec.remove(0);
		end = std::clock();
		
		VECTOR_REMOVE_SUM += (1000.0 * (end - begin) / CLOCKS_PER_SEC);
	}
	
	VECTOR_REMOVE_AVG = VECTOR_REMOVE_SUM / 10;
}


void TestPointerVector()
{
	double POINTER_VECTOR_INSERT_SUM = 0;
	
	PointerVector<Shape> pvec(100);
	Shape object;
	
	// insert
	
	std::clock_t begin;
	std::clock_t end;
	
	for (int i = 0; i < 10; i++)
	{
		begin = std::clock();
		pvec.insert(object, 0);
		end = std::clock();
		
		POINTER_VECTOR_INSERT_SUM += (1000.0 * (end - begin) / CLOCKS_PER_SEC);
	}
	POINTER_VECTOR_INSERT_AVG = POINTER_VECTOR_INSERT_SUM / 10;
	
	// remove
	
	double POINTER_VECTOR_REMOVE_SUM = 0;
	
	for (int i = 0; i < 10; i++)
	{
		begin = std::clock();
		pvec.remove(0);
		end = std::clock();
		
		POINTER_VECTOR_REMOVE_SUM += (1000.0 * (end - begin) / CLOCKS_PER_SEC);
	}
	
	POINTER_VECTOR_REMOVE_AVG = POINTER_VECTOR_REMOVE_SUM / 10;
}

int main()
{
	
	TestVector();
	TestPointerVector();
	
	std::cout << "vector insert time average: " << VECTOR_INSERT_AVG << std::endl;
	std::cout << "vector remove time average: " << VECTOR_REMOVE_AVG << std::endl;
	std::cout << "double pointer vector insert time average: " << POINTER_VECTOR_INSERT_AVG << std::endl;
	std::cout << "double pointer vector remove time average: " << POINTER_VECTOR_REMOVE_AVG << std::endl;
	
	std::cin.get();
}
