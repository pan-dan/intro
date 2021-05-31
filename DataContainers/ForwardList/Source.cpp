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
	Element(T Data, Element<T>* pNext = nullptr) :Data(Data), pNext(pNext)
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
	friend class Iterator<T>;
	friend class ForwardList<T>;
};

template<typename T>
int Element<T>::count = 0;		//Инициализация статической переменной

template<typename T>
class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr)
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
		Iterator<T> old = *this;
		Temp = Temp->pNext;
		return old;
	}


	bool operator==(const Iterator<T>& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator<T>& other)const
	{
		return this->Temp != other.Temp;
	}

	Element<T>*& operator->()
	{
		return Temp;
	}
	Element<T>* get_current_addres()
	{
		return Temp;
	}

	const T& operator*()const
	{
		return Temp->Data;
	}

	T& operator*()
	{
		return Temp->Data;
	}

	

};

template<typename T>
class ForwardList
{
	Element<T>* Head;
	int size;

public:
	Iterator<T> getHead()
	{
		return Head;
	}
	
	Iterator<T> begin()
	{
		return Head;
	}
	Iterator<T> end()
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
	ForwardList(const ForwardList<T>& other)
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
	ForwardList(initializer_list<T> il) :ForwardList()
	{	
		// il - контейнер, такой же, как наш Forward list
		// У любого контейнера есть методы begin() и end(),
		// которые возвращают укатели на начало и конец контейнера.
		cout << typeid(il.begin()).name() << endl;
		for (T const* it = il.begin(); it != il.end(); it++)
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
	ForwardList<T>& operator=(const ForwardList<T>& other)
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
	void pop_front()
	{
		// 1) Прежде чем исключить элемент из списка, нужно запомнить его адрес, для того, чтобы можно было удалить его из памяти
		Element<T>* Temp = Head;
		// 2) Исключаем элемент из списка
		Head = Head->pNext;
		// 3) Удаляем элемент из памяти
		delete Temp;
		size--;
	}

	void pop_back()
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

	void erase(int index)
	{
		if (index > size) return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		
		// 1) Доходим до нужного элемента
		Element<T>* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		// 2) Запоминаем адрес удаляемого элемента
		Element<T>* to_del = Temp->pNext;
		// 3) Исключаемый удаляемый элемент из списка
		Temp->pNext = Temp->pNext->pNext;
		// 4) Удаляем элемент из памяти
		delete to_del;
		size--;


	}

	//		Adding elements
	void push_front(T Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;*/
		
		Head = new Element<T>(Data, Head);
		size++;
	}
	void push_back(T Data)
	{
		//Этот метод НЕ умеет работать с пустым списком
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
	void insert(T Data, int index)
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
		for (Iterator<T> Temp = Head; Temp != nullptr; Temp++)
			//cout << Temp.get_current_addres()<< tab << Temp->Data << tab << Temp->pNext << endl;
		//cout << endl;
			//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			cout << tab << *Temp;
		cout << endl;
			
		cout << "Количество элементов в списке: " << size << endl;
		cout << "Общее количество элементов: " << Element<T>::count << endl;
	}

	
	
};


//#define BASE_CHECK
//#define ITERATOR_CHECK
//#define RANGE_BASED_ARRAY
//#define RANGE_BASED_LIST

void main()
{
	setlocale(LC_ALL, "Rus");
	
	
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList<int> list;
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

#ifdef RANGE_BASED_LIST
	ForwardList<int> list = { 3,3,4,5 };
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

#endif // RANGE_BASED_LIST

	ForwardList<double> list = { 2.5, 3.14, 8.3, 5.4 };
	for (double i : list)
	{
		cout << i << tab;
	}
	cout << endl;






}