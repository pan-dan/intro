#include "Element.h"
#include "Iterator.h"
#include "ForwardList.h"

template<typename T> Iterator<T>ForwardList<T>:: getHead()
	{
		return Head;
	}

	template<typename T>Iterator<T>ForwardList<T>:: begin()
	{
		return Head;
	}

	template<typename T>Iterator<T> ForwardList<T>::end()
	{
		return nullptr;
	}

	template<typename T>ForwardList<T>::ForwardList():Head(nullptr)
	{
		//DefaultConstructor ������ ������ ������
		Head = nullptr;
		size = 0;
#ifdef DEBUG
		cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

	}

	template<typename T>ForwardList<T>::ForwardList<T>(const ForwardList<T>& other)
	{
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
#ifdef DEBUG
		cout << "LCopyConstructor: " << this << endl;
#endif // DEBUG

	}
	
	template<typename T>ForwardList<T>::ForwardList<T>(initializer_list<T> il) :ForwardList()
	{
		// il - ���������, ����� ��, ��� ��� Forward list
		// � ������ ���������� ���� ������ begin() � end(),
		// ������� ���������� ������� �� ������ � ����� ����������.
		cout << typeid(il.begin()).name() << endl;
		for (T const* it = il.begin(); it != il.end(); it++)
		{
			// it - ��� ��������, ������� �������� �� il. il - initializer list
			push_back(*it);
		}
	}
	template<typename T>ForwardList<T>::~ForwardList()
	{
		while (Head)pop_front();
#ifdef DEBUG
		cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

	}


	//			Operators
	template<typename T>ForwardList<T>& ForwardList<T>:: operator=(const ForwardList<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		Element<T>* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
#ifdef DEBUG
		cout << "LCopyAssigment: " << this << endl;
#endif // DEBUG


		return *this;
	}


	//		Erasing elements
	template<typename T>void ForwardList<T>::pop_front()
	{
		// 1) ������ ��� ��������� ������� �� ������, ����� ��������� ��� �����, ��� ����, ����� ����� ���� ������� ��� �� ������
		Element<T>* Temp = Head;
		// 2) ��������� ������� �� ������
		Head = Head->pNext;
		// 3) ������� ������� �� ������
		delete Temp;
		size--;
	}

	template<typename T>void ForwardList<T>::pop_back()
	{
		Element<T>* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	template<typename T>void ForwardList<T>::erase(int index)
	{
		if (index > size) return;
		if (index == 0)
		{
			pop_front();
			return;
		}

		// 1) ������� �� ������� ��������
		Element<T>* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		// 2) ���������� ����� ���������� ��������
		Element<T>* to_del = Temp->pNext;
		// 3) ����������� ��������� ������� �� ������
		Temp->pNext = Temp->pNext->pNext;
		// 4) ������� ������� �� ������
		delete to_del;
		size--;


	}

	//		Adding elements
	template<typename T>void ForwardList<T>::push_front(T Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/

		Head = new Element<T>(Data, Head);
		size++;
	}

	template<typename T>void ForwardList<T>::push_back(T Data)
	{
		//���� ����� �� ����� �������� � ������ �������
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}

		//Element* New = new Element(Data);
		Element<T>* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element<T>(Data);
		size++;
	}

	template<typename T>void ForwardList<T>::insert(T Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element<T>* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr) break;
		//Temp = Temp->pNext
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		Temp->pNext = new Element<T>(Data, Temp->pNext);
		size++;

	}


	//		Methods
	template<typename T>void ForwardList<T>::print()
	{
		//Element* Temp = Head;		//Temp - ��� ��������
		//while (Temp != nullptr)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;
		//}

		//for (Initialization; Condition; Expression)...
		//for (Element* Temp = Head; Temp;/*Temp = Temp->pNext*/ Temp++)
		for (Iterator<T> Temp = Head; Temp != nullptr; Temp++)
			//cout << Temp.get_current_addres()<< tab << Temp->Data << tab << Temp->pNext << endl;
		//cout << endl;
			//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			cout << tab << *Temp;
		cout << endl;

		cout << "���������� ��������� � ������: " << size << endl;
		cout << "����� ���������� ���������: " << Element<T>::count << endl;
	}



