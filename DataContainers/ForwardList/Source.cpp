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
	int Data;				//�������� ��������
	Element* pNext;			//��������� �� ��������� �������
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
	friend class ForwardList;
};

int Element::count = 0;		//������������� ����������� ����������

class ForwardList
{
	Element* Head;
	int size;

public:
	ForwardList():Head(nullptr) 
	{
		//DefaultConstructor ������ ������ ������
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
		// 1) ������ ��� ��������� ������� �� ������, ����� ��������� ��� �����, ��� ����, ����� ����� ���� ������� ��� �� ������
		Element* Temp = Head;
		// 2) ��������� ������� �� ������
		Head = Head->pNext;
		// 3) ������� ������� �� ������
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
		
		// 1) ������� �� ������� ��������
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		// 2) ���������� ����� ���������� ��������
		Element* to_del = Temp->pNext;
		// 3) ����������� ��������� ������� �� ������
		Temp->pNext = Temp->pNext->pNext;
		// 4) ������� ������� �� ������
		delete to_del;
		size--;


	}

	//		Adding elements
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		//���� ����� �� ����� �������� � ������ �������
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}

		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}
	void insert(int Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr) return;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	
	}


	//		Methods
	void print()
	{
		Element* Temp = Head;		//Temp - ��� ��������
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}

		cout << "���������� ��������� � ������: " << size << endl;
		cout << "����� ���������� ���������: " << Element::count << endl;
	}
	
};


//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");
	
	
	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
	

#ifdef BASE_CHECK
	/*list.push_back(123);
list.print();

cout << DEL << endl;
list.pop_front();
list.print();
cout << DEL << endl;
list.pop_back();
list.print();*/
	cout << DEL << endl;
	int value;
	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	list.insert(value, index);
	list.print();
	cout << DEL << endl;

	/* cout << "��� ���� ������:\n";
	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(6);
	list2.print();*/

	cout << "������� ������ ���������� ��������: "; cin >> index;
	list.erase(index);
	list.print();
#endif // BASE_CHECK

	//ForwardList list2 = list; //����� ����������� ������ �������� ������	//CopyConstructor	(���
	//list2.print();
	//ForwardList list3;
	//list3 = list2;		// ����� ������ ��� ������	//CopyAssigment
	//list3.print();









}