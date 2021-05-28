#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define DEL	"---------------------------------------------------------------------------"

class Element
{
	int Data;				//Значение элемента
	Element* pNext;			//Указатель на следубщий элемент
	static int count;

public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
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
		cout << "IConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "IDestructor:\t" << this << endl;
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
};

class ForwardList
{
	Element* Head;
	int size;

public:
	ForwardList():Head(nullptr) 
	{
		//DefaultConstructor создаёт пустой список
		Head = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other)
	{
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyConstructor: " << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
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
		cout << "LCopyAssigment: " << this << endl;
		
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
			cout << Temp.get_current_addres()<< tab << Temp->Data << tab << Temp->pNext << endl;
		cout << endl;
			//cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

		cout << "Количество элементов в списке: " << size << endl;
		cout << "Общее количество элементов: " << Element::count << endl;
	}
	
};


//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");
	
	
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









}