#include "Element.h"
#include "Element.cpp"
#include "Iterator.h"
#include "Iterator.cpp"
#include "ForwardList.h"
#include "ForwardList.cpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////

//#define BASE_CHECK
//#define ITERATOR_CHECK
//#define RANGE_BASED_ARRAY
//#define RANGE_BASED_LIST

void main()
{
	setlocale(LC_ALL, "Rus");
	
	
#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
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

	

#ifdef RANGE_BASED_ARRAY
	int arr[] = { 3,5,8,13,21 };
	cout << size(arr) << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)		// Range-based for (��������� - ���� for ��� ���������, ����� ��������� -  ��� ����������)
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