#pragma once


template <typename T>
class PointerVector
{

	public:
		PointerVector(unsigned int size = 0, const T& init = T());
		~PointerVector();
		
	public:
		void push(const T& object);
		void insert(const T& object, unsigned int index);
		void remove(unsigned int index);
		unsigned int size() const;
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		
	protected:
		void _Reallocate(unsigned int capacity);
		
	protected:
		T** _array = nullptr;
		T _init;
		unsigned int _capacity;
		unsigned int _size;
};

		
template <typename T>		
PointerVector<T>::PointerVector(unsigned int size, const T& init)
: _capacity(0), _size(0), _init(init)
{
	_Reallocate(size);
	_size = size;
}


template <typename T>
PointerVector<T>::~PointerVector()
{
	for (int i = 0; i < _capacity; i++)
		delete _array[i];
	delete[] _array;
}


template <typename T>
void PointerVector<T>::push(const T& object)
{
	if (_size == _capacity)
		_Reallocate(_capacity + (_capacity / 2) + 1);
	
	delete _array[_size];
	_array[_size] = new T(object);
	_size++;
}


template <typename T>
void PointerVector<T>::insert(const T& object, unsigned int index)
{
	if (_size == _capacity)
		_Reallocate(_capacity + (_capacity / 2) + 1);
		
	for (int i = _size; i > index; i--)
		_array[i] = _array[i - 1];
		
	_array[index] = new T(object);
	_size++;
}


template <typename T>
void PointerVector<T>::remove(unsigned int index)
{
	delete _array[index];
	
	for (int i = index; i < _size - 1; i++)
		_array[i] = _array[i + 1];
		
	_size--;
	_array[_size] = new T();
}


template <typename T>
unsigned int PointerVector<T>::size() const
{
	return _size;
}

template <typename T>
T& PointerVector<T>::operator[](unsigned int index)
{
	if (index < _size)
		return *(_array[index]);
		
	std::cout << "index out of range";
	exit(-1);
}

template <typename T>
const T& PointerVector<T>::operator[](unsigned int index) const
{
	if (index < _size)
		return *(_array[index]);
		
	std::cout << "index out of range";
	exit(-1);
}


template <typename T>
void PointerVector<T>::_Reallocate(unsigned int capacity)
{
	T** temp = new T*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		if (i < _size)
			temp[i] = _array[i];
			
		else
			temp[i] = new T(_init);
	}
	
	for (int i = capacity; i < _capacity; i++)
		delete _array[i];
		
	delete[] _array;
	_array = temp;
	_capacity = capacity;
}


