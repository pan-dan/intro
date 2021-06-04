#pragma once
#include "Element.h"
#include "Iterator.h"

template<typename T>
class ForwardList
{
	Element<T>* Head;
	int size;

public:
	Iterator<T> getHead();

	Iterator<T> begin();
	Iterator<T> end();

	ForwardList();
	ForwardList(const ForwardList<T>& other);
	ForwardList(initializer_list<T> il);
	~ForwardList();


	//			Operators
	ForwardList<T>& operator=(const ForwardList<T>& other);


	//		Erasing elements
	void pop_front();

	void pop_back();

	void erase(int index);

	//		Adding elements
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int index);


	//		Methods
	void print();



};