#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define DEL "---------------------------------------------------------------------"
#define tab "\t\t"

//#define DEBUG



template <typename T>
class List
{

	class Element
	{
		T Data;		//�������� ��������
		Element* pNext;	//��������� �� ��������� �������
		Element* pPrev;	//��������� �� ���������� �������

	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();

		friend class List<T>;
	};

	Element* Head;		// ��������� �� ��������� ������� ������
	Element* Tail;		// ��������� �� �������� ������� ������
	unsigned int size;	//������ ������

	class BaseIterator
	{
	protected:
		Element* Temp;

	public:

		BaseIterator(Element* Temp = nullptr);
		~BaseIterator();

		bool operator==(const BaseIterator& other)const;
		bool operator!=(const BaseIterator& other)const;

		const T& operator*()const;
		T& operator*();

	};

public:
	class Iterator :public BaseIterator
	{

	public:
		Iterator(Element* Temp = nullptr) :BaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "ITConstructor: \t" << this << endl;
#endif // DEBUG

		}
		~Iterator()
		{
#ifdef DEBUG
			cout << "ITDestructor: \t" << this << endl;
#endif // DEBUG
		}


		Iterator& operator++()		//Prefix increment
		{
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return old;
		}
		Iterator& operator--()
		{
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return old;
		}
	};

	class ReverseIterator :public BaseIterator
	{

	public:
		ReverseIterator(Element* Temp = nullptr) :BaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "RIConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ReverseIterator()
		{
#ifdef DEBUG
			cout << "RIDestructor:\t" << this << endl;
#endif // DEBUG

		}

		ReverseIterator& operator++()
		{
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return old;
		}
		ReverseIterator& operator--()
		{
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return *this;
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return old;
		}
	};

	size_t getSize()const;

	Iterator begin();
	const Iterator begin()const;

	Iterator end();
	const Iterator end() const;

	ReverseIterator rbegin();
	ReverseIterator rend();


	List();
	explicit List(int size);

	List(const initializer_list<T>& il);
	List(const List<T>& other);

	List(List<T>&& other);

	~List();

	//		Operators

	List<T>& operator=(const List<T>& other);

	List<T>& operator=(List<T>&& other);

	T& operator[](size_t index);


	//		Adding elements

	void push_front(T Data);

	void push_back(T Data);

	void insert(unsigned int Index, T Data);

	//		Erasing Elements
	void pop_front();

	void pop_back();

	void erase(size_t index);

	//		Methods
	void print();

	void print_reverse();

};

//----------------------------------------------------
template <typename T> List<T>::BaseIterator::BaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "BIConstructor:\t" << this << endl;
#endif // DEBUG

}
template <typename T> List<T>::BaseIterator::~BaseIterator()
{
#ifdef DEBUG
	cout << "BIDestructor:\t" << this << endl;
#endif // DEBUG

}

template <typename T>bool List<T>::BaseIterator::operator==(const BaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template <typename T>bool List<T>::BaseIterator::operator!=(const BaseIterator& other)const
{
	return this->Temp != other.Temp;
}

template <typename T>const T& List<T>::BaseIterator::operator*()const
{
	return Temp->Data;
}
template <typename T>T& List<T>::BaseIterator::operator*()
{
	return Temp->Data;
}

//----------------------------------------------------

template <typename T> List<T>::Element::Element(T Data, Element* pNext, Element* pPrev)
{
	this->Data = Data;
	this->pNext = pNext;
	this->pPrev = pPrev;
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
template <typename T> List<T>::Element::~Element()
{
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

}

//----------------------------------------------------

template <typename T>size_t List<T>::getSize()const
{
	return size;
}

template <typename T> typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template <typename T> const typename List<T>::Iterator List<T>::begin()const
{
	return Head;
}

template <typename T> typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template <typename T>const typename List<T>::Iterator List<T>::end() const
{
	return nullptr;
}

template <typename T> typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template <typename T> typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}

template <typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
#ifdef DEBUG
	cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

}
template <typename T>List<T>::List(int size) :List()
{
	while (size--)push_back(0);
}

template <typename T>List<T>::List(const initializer_list<T>& il) :List()
{
	//cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); it++) push_back(*it);
}
template <typename T>List<T>::List(const List<T>& other) :List()
{
	for (T i : other)push_back(i);
	cout << "CopyConstructor:\t" << this << endl;
}

template <typename T>List<T>::List(List<T>&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	this->Tail = other.Tail;

	other.Head = other.Tail = nullptr;

	cout << "MoveConstructor:\t" << this << endl;
}

template <typename T>List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
#ifdef DEBUG
	cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

}


template <typename T>List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (T i : other)push_back(i);
	cout << "CopyAssigment:\t" << this << endl;
}

template <typename T>List<T>& List<T>::operator=(List<T>&& other)
{
	while (Head)pop_front();
	this->size = other.size;
	this->Head = other.Head;
	this->Tail = other.Tail;

	other.Head = other.Tail = nullptr;

	cout << "MoveAssigment:\t" << this << endl;
	return *this;
}

template <typename T>T& List<T>::operator[](size_t index)
{
	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (size_t i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (size_t i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
	}
	return Temp->Data;



}



template <typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	/*Element* New = new Element(Data);
	New->pNext=Head;
	Head->pPrev = New;
	Head = New;*/

	Head = Head->pPrev = new Element(Data, Head);
	size++;
}

template <typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	/*Element* New = new Element(Data);
	New->pPrev = Tail;
	Tail->pNext = New;
	Tail = New;*/


	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;


}

template <typename T>void List<T>::insert(unsigned int Index, T Data)
{
	if (Index > size)return;
	if (Index == 0)
	{
		push_front(Data);
		return;
	}
	if (Index == size)
	{
		push_back(Data);
		return;
	}
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (size_t i = 0; i < Index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (size_t i = 0; i < size - Index; i++)Temp = Temp->pPrev;
	}
	/*Element* New = new Element(Data);
	New->pNext = Temp;
	New->pPrev = Temp->pPrev;
	Temp->pPrev->pNext = New;
	Temp->pPrev = New;*/



	Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
	size++;
}


template <typename T>void List<T>::pop_front()
{
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr;
	size--;

}

template <typename T>void List<T>::pop_back()
{
	if (Head == Tail)
	{
		delete Tail;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}

template <typename T>void List<T>::erase(size_t index)
{
	if (index == 0)
	{
		pop_front();
		return;
	}
	if (index == size - 1)
	{
		pop_back();
		return;
	}
	if (index >= size)return;


	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (size_t i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (size_t i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
	}
	// 1) ������������ ��������� ������� �� ������
	Temp->pPrev->pNext = Temp->pNext;		// � ��������� pNext �������� Temp->pPrev ���������� ����� Temp->pNext
	Temp->pNext->pPrev = Temp->pPrev;		// � ��������� pPrev �������� Temp->pNext ���������� ����� �������� Temp ->pPrev
	// 2) ������� ������� �� ������
	delete Temp;

}


template <typename T>void List<T>::print()
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
	{
		cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << endl;
	cout << "���������� ��������� ������: " << size << endl;
}

template <typename T>void List<T>::print_reverse()
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
	{
		cout << Temp << tab;
		cout << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << endl;
	cout << "���������� ��������� ������: " << size << endl;
}

template <typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (T i : right)cat.push_back(i);
	return cat;
}


//#define BASE_CHECK
//#define SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR
//#define ITERATORS_CHECK
//#define COPY_METHODS_CHECK
//#define MOVE_METHODS_CHECK
#define TEMPLATES_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");
	
	//int n;
	//cout << "������� ������ ������:"; cin >> n;

#ifdef BASE_CHECK
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.print_reverse();

	/*list.pop_front();
	list.print();*/

	int Index;
	int value;

	cout << "������� ������ ������������ ��������: "; cin >> Index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list.insert(Index, value);
	list.print();
	list.print_reverse();

	cout << "������� ������ ���������� ��������: "; cin >> Index;
	list.erase(Index);
	list.print();
	list.print_reverse();

#endif // BASE_CHECK

#ifdef SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR

	//List list = n;		//Type conversion from int to list
	List list(n);
	for (size_t i = 0; i < list.getSize(); i++)list[i] = rand() % 100;
	for (size_t i = 0; i < list.getSize(); i++)cout << list[i] << tab;
	cout << endl;

	list.print();
#endif // SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR


#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	list.print();

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	for (List::Iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << DEL << endl;

	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // ITERATORS_CHECK

#ifdef COPY_METHODS_CHECK
	List list1 = { 3, 5, 8, 13, 21 };
	list1.print();
	//List list2 = list1;		//CopyConstructor
	List list2;
	list2 = list1;				//Copy Assigment
	list2.print();
#endif // COPY_METHODS_CHECK

#ifdef MOVE_METHODS_CHECK
	List<int> list1 = { 3, 5, 8, 13, 21 };
	List<int> list2 = { 34, 55, 89 };
	cout << DEL << endl;
	//List list3 = list1 + list2;		//MoveConstructor
	List<int> list3;
	list3 = list2 + list1;				//MoveAssigment
	cout << DEL << endl;
	list3.print();
#endif // MOVE_METHODS_CHECK

	List<int> i_list = { 3, 5, 8, 13, 21, };
	i_list.print();

	List<double> d_list = { 2.5, 3.14, 5.2, 8.3 };
	d_list.print();

	List<string> s_list = { "What", "can", "I", "do", "?" };
	for (string i : s_list)cout << i << tab; cout << endl;


}


