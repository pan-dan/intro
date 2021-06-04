#pragma once
#include "Element.h"
template<typename T>
class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr);
	~Iterator();

	//		Operators
	Iterator& operator++();

	Iterator operator++(int);


	bool operator==(const Iterator<T>& other)const;
	bool operator!=(const Iterator<T>& other)const;

	Element<T>*& operator->();
	Element<T>* get_current_addres();

	const T& operator*()const;

	T& operator*();
};
