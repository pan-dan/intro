#include <iostream>

using namespace std;
using std::cout;
#define tab "\t"

// �������� ���������
class Point  //������������� ����� �� ��� ���������
{


	// ��������� Point ��������� ����� �� ���������.
	double x;	//���������� x
	double y;	//���������� y

public:

	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;

	}

	void set_x(double x)
	{
		this ->x = x;
	}
	void set_y(double y)
	{
		this ->y = y;
	}


			//			Constructors:
	/*Point()
	{
		// ����������� �� ��������� ������ ����� � ������ ���������
		x = y = int();	// ����� �������� ����������� �� ��������� 
		//��� 'int', � �� ���������� �������� �� ��������� 
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		// ����������� � ����� ���������� ������ ����� �� ������
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentsConstructor:\t\t" << this << endl;
	}

	Point(double x, double y)
	{
		//����������� � ����������� ������ ����� �� ���������
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	
	}*/

	Point(double x = 0, double y = 0)
	{
		//���� ����������� � ����������� ����� ���� ������
		//-��� ����������
		//-� ����� ����������
		//-� ����� �����������

		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		// other - ��� ������ ������, ����� �������� �� ������.

		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}


	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
	}

	double distance(const Point& other)const
	{
		double x_distance = other.x - this->x;
		double y_distance = other.y - this->y;
		
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
			return distance;
	
	}	// sqrt - Square root (���������� ������)

				//Methods

	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//�������� ��������� ��� �����, �� ������ ����� ��� ������,
//� �������� ������� ����� ������ ��� ���������, �� ������ ���������� ������ ����.
//������ � ��������� ��� �������� ����������������� ������ ������


//					����� - ��� ��� ������
//					��������� - ��� ��� ������
//					������ - ��� ����� ������� ����������

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();

	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}



//#define INTRO
//#define CONSTRUCTORS
#define DISTANCE

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef INTRO
	int a;		//���������� ���������� 'a' ���� 'int'
	Point A;	//�������� ������� ���������
				//���������� ������� 'A' ��������� 'Point'
				//���������� ���������� 'A' ���� 'Point'

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A; //������ ��������� �� ������
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
#endif // INTRO


#ifdef CONSTRUCTORS
	Point A; //Default constructor
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5; //Single-Argument constructor
	B.print();

	Point C(8); //Single-Argument constructor
	C.print();

	Point D{ 12 }; //Single-Argument constructor
	D.print();

	// ������
	int a(2);
	int b{ 3 };
	cout << a << tab << b << endl;


	Point E(5, 3); //Paramet
	E.print();

	Point F = E;	//CopyConstructor. ����� �� ������ ������ � �������������� ��� ������ ��������
	Point G;		//DefaultConstructor
	G = D;		//CopyAssigment - operator=
	G.print();

	



#endif // CONSTRUCTORS


	Point A(2, 3);
	Point B(4, 5);
	cout << A.distance(B) << endl;

	cout << distance(A, B) << endl;


}