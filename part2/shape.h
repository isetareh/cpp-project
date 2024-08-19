#pragma once
#include "poly.h"


class Shape      //prism object
{
	public:
		Shape();
		Shape(Poly* base, double height, double density);
		
	public:
		virtual double surface();
		virtual double volume();
		virtual double mass();
			
	protected:
		Poly* _base = nullptr;
		double _height;
		double _density;
		double _surface;
		double _volume;
		double _mass;
		
};



Shape::Shape()
: _height(-1), _density(-1), _surface(0), _volume(0), _mass(0){}


Shape::Shape(Poly* base, double height, double density)
: _height(height), _density(density)
{
	_base = base;
	_surface = surface();
	_volume = volume();
	_mass = mass();
}


double Shape::surface()
{
	double lateral = (_base -> perimeter()) * _height;
	return lateral + 2 * (_base -> area());
}


double Shape::volume()
{
	return (_base -> area()) * _height;
}


double Shape::mass()
{
	return _density * volume();
}


