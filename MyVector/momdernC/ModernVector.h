#ifndef MODERNVECTOR_H
#define MODERNVECTOR_H

#include <utility>
#include <stdexcept>
#include <iostream>

template <class T>
class ModernVector
{
public:
	typedef T * iterator;

	ModernVector();
	ModernVector(size_t size);
	ModernVector(const ModernVector<T> & vector); // копіюєм
	ModernVector(ModernVector<T> && vector); // переміщаєм
	~ModernVector();

	size_t capacity() const;
	size_t size() const;

	iterator begin();
	iterator end();

	void push_back(const T & value);
	void push_back(T && value);
	void pop_back();

	void reserve(size_t capacity);

	T & operator[](size_t index);
	ModernVector<T> & operator=(const ModernVector<T> & vector); // копіюєм
	ModernVector<T> & operator=(ModernVector<T> && vector); // переміщаєм

private:
	size_t vectorSize;
	size_t vectorCapacity;
	T * buffer;
};


template<class T>
ModernVector<T>::ModernVector()
{
	vectorSize = 0;
	vectorCapacity = 0;
	buffer = nullptr;
}

template<class T>
ModernVector<T>::ModernVector(size_t size) 
  : vectorCapacity(size),
	vectorSize(0)
{
	buffer = new T[vectorCapacity];
}

template<class T>
ModernVector<T>::ModernVector(const ModernVector<T> & vector) 
  : vectorSize(vector.vectorSize),
	vectorCapacity(vector.vectorCapacity),
	buffer(new T[vector.vectorSize])
{
	for (size_t i = 0; i < vectorSize; ++i)
	{
		buffer[i] = vector.buffer[i];
	}
}


template<class T>
ModernVector<T>::ModernVector(ModernVector<T> && vector) // все переміщаєм
  : vectorSize(vector.vectorSize),
	vectorCapacity(vector.vectorCapacity),
	buffer(vector.buffer)
{
	vector.vectorSize = 0;
	vector.vectorCapacity = 0;
	vector.buffer = nullptr;
}

template<class T>
ModernVector<T>::~ModernVector()
{
	delete[] buffer;
}

template<class T>
size_t ModernVector<T>::capacity() const
{
	return vectorCapacity;
}

template<class T>
size_t ModernVector<T>::size() const
{
	return vectorSize;
}

template<class T>
typename ModernVector<T>::iterator ModernVector<T>::begin()
{
	return buffer; // вказівник масива показує на 1 елемент
}

template<class T>
typename ModernVector<T>::iterator ModernVector<T>::end()
{
	return buffer + size(); // наступний після останнього елемент
}

template<class T>
void ModernVector<T>::push_back(const T & value)
{
	if (vectorSize >= vectorCapacity)
	{
		reserve(vectorCapacity + vectorCapacity/4 + 1); // не знаю принципа підрахунку збільшення капасіті, но думаю так будет ок
	}

	std::cout << "copy " << value << std::endl;
	buffer[vectorSize] = value;
	++vectorSize;
}

template<class T>
void ModernVector<T>::push_back(T &&value)
{
	if (vectorSize >= vectorCapacity)
	{
		reserve(vectorCapacity + vectorCapacity / 4 + 1);
	}
	std::cout << "move " << value << std::endl;
	buffer[vectorSize] = std::move(value);
	value = {}; // потрібно зробити його дефолтним
	++vectorSize;
}

template<class T>
void ModernVector<T>::pop_back()
{
	--vectorSize;
}

template<class T>
void ModernVector<T>::reserve(size_t capacity)
{
	T * Newbuffer = new T[capacity];
	vectorSize = capacity < vectorSize ? capacity : vectorSize;

	for (size_t i = 0; i < vectorSize; ++i)
	{
		Newbuffer[i] = std::move(buffer[i]);
	}

	vectorCapacity = capacity;
	delete[] buffer;
	buffer = Newbuffer;
}

template<class T>
T &ModernVector<T>::operator[](size_t index)
{
	if (index >= vectorSize)
	{
		throw std::length_error("The index is too large for our vector");
	}
	return buffer[index];
}

template<class T>
ModernVector<T> &ModernVector<T>::operator = (const ModernVector<T> & vector)
{
	if (&vector == this) // перевіряєм чи взагалі потрібно щось робити
		return *this;

	vectorSize = vector.vectorSize;
	vectorCapacity = vector.vectorCapacity;

	delete[] buffer;
	buffer = new T[vectorSize];

	for (size_t i = 0; i < vectorSize; i++)
	{
		buffer[i] = vector.buffer[i];
	}
	return *this;
}

template<class T>
ModernVector<T> &ModernVector<T>::operator=(ModernVector<T> &&vector)
{
	if (&vector == this) // перевіряєм чи взагалі потрібно переміщувати
		return *this;

	vectorSize = std::move(vector.vectorSize);
	vectorCapacity = std::move(vector.vectorCapacity);
	vector.vectorSize = 0;
	vector.vectorCapacity = 0;

	delete[] buffer;
	buffer = std::move(vector.buffer);

	vector.buffer = nullptr;
	return *this;
}

#endif // MODERNVECTOR_H
