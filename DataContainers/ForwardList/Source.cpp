#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define DEL	"---------------------------------------------------------------------------"
//#define DEBUG

class Element
{
	int Data;				//Значение элемента
	Element* pNext;			//Указатель на следубщий элемент
	static int count;

public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	friend class Iterator;
	friend class ForwardList;
};

int Element::count = 0;		//Инициализация статической переменной

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr)
	{
		this->Temp = Temp;
#ifdef DEBUG
		cout << "IConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Iterator()
	{
#ifdef DEBUG
		cout << "IDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//		Operators
	Iterator& operator++() 
	{
		Temp = Temp->pNext;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}


	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	Element*& operator->()
	{
		return Temp;
	}
	Element* get_current_addres()
	{
		return Temp;
	}

	const int& operator*()const
	{
		return Temp->Data;
	}

	int& operator*()
	{
		return Temp->Data;
	}

	

};

class ForwardList
{
	Element* Head;
	int size;

public:
	Iterator getHead()
	{
		return Head;
	}
	
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}

	ForwardList():Head(nullptr) 
	{
		//DefaultConstructor создаёт пустой список
		Head = nullptr;
		size = 0;
#ifdef DEBUG
		cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

	}
	ForwardList(const ForwardList& other)
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
	ForwardList(initializer_list<int> il) :ForwardList()
	{	
		// il - контейнер, такой же, как наш Forward list
		// У любого контейнера есть методы begin() и end(),
		// которые возвращают укатели на начало и конец контейнера.
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			// it - это итератор, который проходит по il. il - initializer list
			push_back(*it);
		}
	}
	~ForwardList()
	{
		while (Head)pop_front();
#ifdef DEBUG
		cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

	}


	//			Operators
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		Element* Temp = other.Head;
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
	void pop_front()
	{
		// 1) Прежде чем исключить элемент из списка, нужно запомнить его адрес, для того, чтобы можно было удалить его из памяти
		Element* Temp = Head;
		// 2) Исключаем элемент из списка
		Head = Head->pNext;
		// 3) Удаляем элемент из памяти
		delete Temp;
		size--;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void erase(int index)
	{
		if (index > size) return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		
		// 1) Доходим до нужного элемента
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		// 2) Запоминаем адрес удаляемого элемента
		Element* to_del = Temp->pNext;
		// 3) Исключаемый удаляемый элемент из списка
		Temp->pNext = Temp->pNext->pNext;
		// 4) Удаляем элемент из памяти
		delete to_del;
		size--;


	}

	//		Adding elements
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		//Этот метод НЕ умеет работать с пустым списком
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}

		//Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr) break;
		//Temp = Temp->pNext
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	
	}
	

	//		Methods
	void print()
	{
		//Element* Temp = Head;		//Temp - это итератор
		//while (Temp != nullptr)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext;
		//}

		//for (Initialization; Condition; Expression)...
		//for (Element* Temp = Head; Temp;/*Temp = Temp->pNext*/ Temp++)
		for (Iterator Temp = Head; Temp != nullptr; Temp++)
			//cout << Temp.get_current_addres()<< tab << Temp->Data << tab << Temp->pNext << endl;
		//cout << endl;
			//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			cout << tab << *Temp;
		cout << endl;
			
		cout << "Количество элементов в списке: " << size << endl;
		cout << "Общее количество элементов: " << Element::count << endl;
	}

	
	
};


//#define BASE_CHECK
//#define ITERATOR_CHECK
//#define RANGE_BASED_ARRAY

void main()
{
	setlocale(LC_ALL, "Rus");
	
	
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
#endif // BASE_CHECK

#ifdef ITERATOR_CHECK
	for (Iterator it = list.getHead(); it != nullptr; it++)
	{
		*it = rand() % 100;
	}
	list.print();
#endif // ITERATOR_CHECK

	

#ifdef BASE_CHECK
	list.push_front(123);
	list.print();
	cout << DEL << endl;
	
	list.pop_front();
	list.print();
	cout << DEL << endl;
	
	list.pop_back();
	list.print();
	cout << DEL << endl;
	
	int value;
	int index;
	cout << "ВВедите добавляемое значение: "; cin >> value;
	cout << "ВВедите индекс добавляемого значения: "; cin >> index;
	list.insert(value, index);
	list.print();
	cout << DEL << endl;

	/* cout << "Ещё один список:\n";
	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(6);
	list2.print();*/

	cout << "ВВедите индекс удаляемого значения: "; cin >> index;
	list.erase(index);
	list.print();
#endif // BASE_CHECK

	//ForwardList list2 = list; //когда создаваемый объект делатеся копией	//CopyConstructor	(отр
	//list2.print();
	//ForwardList list3;
	//list3 = list2;		// когда объект уже создан	//CopyAssigment
	//list3.print();

	

#ifdef RANGE_BASED_ARRAY
	int arr[] = { 3,5,8,13,21 };
	cout << size(arr) << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)		// Range-based for (дословный - цикл for для диапозона, более павильный -  для контейнера)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_ARRAY

	ForwardList list = { 3,3,4,5 };
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

}