#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define DEL "-------------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	char* str;		//��������� �� ������� � ������������ ������
	int size;		//������ ������

public:

	const char* get_str()const
	{
		return str;
	}

	char* get_str()
	{
		return str;
	}

	int get_size()const
	{
		return size;
	}


	//		Constructors

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << (size == 80? "Default" : "Size")<< "Constructor: \t" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy(this->str, str);			//String copy	
		//strcpy_s(this->str, size, str);
		cout << "Constructor: \t\t" << this << endl;
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyConstractor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor: \t\t" << this << endl;
	}

	
	//		Operators

	String& operator=(const String& other)
	{
		// 0) ���������, �� �������� �� ������ ������ ���� ��������:
		if (this == &other) return *this;
		delete[] this->str; // 1)� ������ ������� ������� ������ �������� �������,
		//� ������ ����� ����� ����������� ��� ����� ��������
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyConstractor:\t\t" << this << endl;
		
		return *this;
	}

	String& operator=(String&& other)
	{
		delete[] this->str;
		
		this->size = other.size;
		this->str = other.str;
		
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		
		return *this;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor: \t" << this << endl;
	}

	String& operator+=( const String& other)
	{
		/*this->size += other.size;
		char* StrForCopy = new char[this->size]{};
		strcpy(StrForCopy, this->str);

		delete[] this->str;
		this->str = StrForCopy;
	
		strcat(this->get_str(), other.get_str());
		return *this;*/


		return *this = *this + other;

	}

	const char& operator[](int i)const
	{
		return this->str[i];
	}
	char& operator[](int i)
	{
		return this->str[i];
	}

	//		Methods

	void print()const
	{
		cout << "str: \t" << str << endl;
		cout << "size \t" << size << endl;
	}

};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	
	/*for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];

	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];*/

	strcpy(result.get_str(), left.get_str());//��������� ����������� ������ left � ������ result
	strcat(result.get_str(), right.get_str());//��������� ������������ ������ right � ������ result

	return result;
}
 

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}



//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();

	//String str2 = 5;
	String str2(5);
	str2.print();

	cout << typeid("Hello").name() << endl;
	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = str3;		//Copy Constructor
	cout << "Str4 - " << str4 << endl;

	String str5;
	str5 = str4;
	cout << "Str5 - " << str4 << endl;

#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;


#endif // ASSIGMENT_CHECK

	String str1 = "Hello ";
	String str2 = "Wolrd";

	cout << DEL;
	String str3;
	str3 = str1 /*+ " "*/ + str2;	//�������� + ����� ��������� ������������ (�������) �����
	cout << DEL;
	cout << str3 << endl;

	/*str1 += str2;
	cout << str1 << endl;*/


}