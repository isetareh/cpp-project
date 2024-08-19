#pragma once
#include "shape.h"
#include "vector.h"


class Device: public Shape
{
	public:
		Device();
		Device(Poly* base, double height, double density);
		
	public:
		double surface() override
		{
			if (_height == -1)
			{
				_surface = 0;
				for (int i = 0; i < _device.size(); i++)
				{
					_surface += (_device[i] -> _surface);
				}
				return _surface;
			}
			
			else
				return _surface;
		}
		
		
		double volume() override
		{
			if (_height == -1)
			{
				_volume = 0;
				for (int i = 0; i < _device.size(); i++)
				{
					_volume += (_device[i] -> _volume);
				}
				return _volume;
			}
			
			else
				return _volume;
		}
		
		
		double mass() override
		{
			if (_height == -1)
			{
				_mass = 0;
				for (int i = 0; i < _device.size(); i++)
				{
					_mass += (_device[i] -> _mass);
				}
				return _mass;
			}
			
			else
				return _mass;
		}
		
	public:
		void add(Device* const object);
		void insert(Device* object, unsigned int index);
		const Device* operator[](unsigned int index) const;
		
	private:
		void _Update();
		
	private:
		Vector<Device*> _device;
};


Device::Device()
: Shape::Shape(){}


Device::Device(Poly* base, double height, double density)
: Shape::Shape(base, height, density)
{
	_device.push(this);
}


void Device::add(Device* const object)
{
	_device.push(object);
	_Update();
}


void Device::insert(Device* object, unsigned int index)
{
	_device.insert(object, index);
	_Update();
}


void Device::_Update()
{
	surface();
	volume();
	mass();
}
