#include <iostream>
#include "device.h"
#include "vector.h"


int main()
{
	Poly circle(1);    // base for our simple object
	Device cylinder(&circle, 2, 3);  // simple object with base, height and density parameters
	
	Poly square(4, 1);  // square base with number of sides and distance from the center of the base as parameters
	Device cube(&square, 1, 1);
	
	Poly triangle(3, 2);
	Device prism(&triangle, 3, 1);
	
	
	Device d1;   // container device
	
	d1.add(&cylinder);  // adding simple devices;
	d1.add(&cube);
	
	Device d2;
	
	d2.add(&prism);
	
	
	Device d3;
	
	d3.add(&d1);  // adding sub devices
	d3.add(&d2);
	d3.add(&prism);
	
	
	std::cout << "total surface of d3: " << d3.surface() << std::endl;
	std::cout << "total volume of d3: " << d3.volume() << std::endl;
	std::cout << "total mass of d3: " << d3.mass() << std::endl;
	
	std::cin.get();
	
}
