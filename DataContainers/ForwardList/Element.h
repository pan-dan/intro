#pragma once

#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define DEL	"---------------------------------------------------------------------------"
//#define DEBUG


template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>
class Element
{
	T Data;				//Значение элемента
	Element<T>* pNext;			//Указатель на следубщий элемент
	static int count;

public:
	Element(T Data, Element<T>* pNext = nullptr);
	~Element();
	friend class Iterator<T>;
	friend class ForwardList<T>;
};

