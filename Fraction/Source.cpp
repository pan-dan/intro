#include <iostream>

using namespace std;

using std::cout;
using std::endl;
using std::cin;

#define tab "\t"
//#define DEBUG
#define DEL "--------------------------------------------------------------"

class Fraction;			//Class declaration - ���������� ������
Fraction operator+(Fraction left, Fraction right);	//�������� ��������� +
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	bool minus;
	int integer;		//����� �����
	int numerator;		//���������
	int denominator;	//�����������


public:

	bool get_minus()const
	{
		return minus;
	}
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_minus(bool minus)
	{
		this->minus = minus;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	///////////////////////////////////////////////////////
	Fraction& set_minus_to_number()
	{
		if (minus)
		{
			integer = -integer;
			numerator = -numerator;
			minus = false;
		}
		return *this;
	}
	Fraction& get_minus_from_number()
	{
		if (integer < 0)
		{
			integer = -integer;
			minus = true;
		}
		if (numerator < 0)
		{
			numerator = -numerator;
			minus = true;
		}
		return *this;
	}

			//CONSTRUCTORS
	
	Fraction()					//Default consturctor
	{
		this->minus = false;

		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "Constructor0: \t" << this << endl;
#endif // DEBUG

	}
	
	explicit Fraction(int integer)
	{
		this->minus = false;
		
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		
		if (integer < 0)
		{
			minus = true;
			this->integer = -integer;
		}
#ifdef DEBUG
		cout << "Constructor1: \t" << this << endl;
#endif // DEBUG

	}

	Fraction(int numerator, int denominator)
	{
		this->minus = false;

		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);

		if (numerator < 0)
		{
			minus = true;
			this->numerator = -numerator;
		}
#ifdef DEBUG
		cout << "Constructor2: \t" << this << endl;
#endif // DEBUG

	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->minus = false;

		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);

		if (integer < 0)
		{
			minus = true;
			this->integer = -integer;
		}
		if (numerator < 0)
		{
			minus = true;
			this->numerator = -numerator;
		}
#ifdef DEBUG
		cout << "Constructor3: \t" << this << endl;
#endif // DEBUG

	}

	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor: \t" << this << endl;
#endif // DEBUG
	}



	Fraction& operator=(const Fraction& other)
	{
		this->minus = other.minus;
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyAssigment:\t" << this << endl;
#endif // DEBUG
		return *this;
	}

	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this+other;

	}

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;

	}



	//			Inrcrement/Decrement
	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}
	
	//			Type cast operators
	operator int()const
	{
		return minus ? -integer : integer;
	}



	//			Methods
	Fraction& to_proper()
	{
		/*if (integer >= 0) integer += numerator / denominator;
		else integer -= numerator / denominator;*/		

		integer += numerator / denominator; 

		get_minus_from_number();

		numerator %= denominator;
		return *this;
	}

	Fraction& to_improper()
	{
		get_minus_from_number();
		numerator += integer * denominator;
		integer = 0;
	
		return *this;
	}

	Fraction& reduce() 
	{
		if (numerator == 0) return *this;
		int more, less, rest; // rest - �������

		// �������� ��� ������, ��������� ��� �����������
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;

		// ������ ���������� ����� ��������
		do 
		{
			rest = more % less;
			more = less;
			less = rest;

		} while (rest);

		int GCD = more; // Greatest Common Divisor (���������� ����� ��������)

		// ����������, ��������� �����
		numerator /= GCD;
		denominator /= GCD;

		return *this;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	left.set_minus_to_number();
	right.set_minus_to_number();

	Fraction result;

	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper().get_minus_from_number().reduce();

	return result;
}

Fraction operator-(Fraction left, Fraction right)
{
	/*left.to_proper().set_minus_to_number();
	right.to_proper().set_minus_to_number();

	 Fraction result
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	);
	 return result.to_proper().get_minus_from_number().reduce();*/

	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();

	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().get_minus_from_number().reduce();
	 
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	Fraction result
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	);
	result.to_proper();
	if (left.get_minus() || right.get_minus()) result.set_minus(true);
	if (left.get_minus() && right.get_minus()) result.set_minus(false);
	return result.reduce();

}



ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_minus()) os << "(-";

	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator()) os << "(";
	if (obj.get_numerator())os << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator()) os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0) os << 0;
	if (obj.get_minus()) os << ")";
	return os;

}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPAUND_ASSIGMENTS_CHECK
#define TYPE_CONVERTIONS

void main()
{
	setlocale(LC_ALL, "Rus");

	/*Fraction A(7, 2);
	cout << A << " = ";
	A.to_proper();
	cout << A << endl;

	cout << A << " = ";
	A.to_improper();
	cout << A << endl;*/

	/*Fraction A(2, 3, 4);
	Fraction B(5, 6, 7);

	cout << A << endl;
	cout << B << endl << DEL << endl;*/


#ifdef ARITHMETICAL_OPERATORS_CHECK
	cout << A << tab << B << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << tab << B << endl;
	cout << DEL << endl;

	cout << A << tab << B << endl;
	cout << A << " / " << B << " = " << A / B << endl;
	cout << A << tab << B << endl;
	cout << DEL << endl;

	cout << A << tab << B << endl;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << A << tab << B << endl;
	cout << DEL << endl;

	cout << A << tab << B << endl;
	cout << B << " - " << A << " = " << B - A << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << A << tab << B << endl;
	cout << DEL << endl;

	//cout << A << tab << B << endl;
	//cout << A << " += " << B << ""; A += B;
	//cout << A << tab << B << endl;  
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//� ����� ������� ���������� ���������� �� ���������(Default constructor)
	cout << A << endl;

	Fraction B = -5;	 //Single Argumet constructor
	cout << B << endl;

	Fraction C(-1, 2);
	cout << C << endl;

	Fraction D(-2, 3, 4);
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef COMPAUND_ASSIGMENTS_CHECH
	A += B;
	cout << A << endl << DEL << endl;
	A -= B;
	cout << A << endl << DEL << endl;
	A *= B;
	cout << A << endl << DEL << endl;
	A /= B;
	cout << A << endl << DEL << endl;
#endif // COMPAUND_ASSIGMENTS_CHECH


	Fraction reduce(840, 3600);
	cout << reduce.reduce() << endl;
	cout << Fraction(27, 9).reduce() << endl;


	for (double i = 0.3; i < 10; i++)cout << i << tab;
	cout << endl << DEL << endl;

	for (Fraction i(1, 2); i.get_integer() < 10; ++i)cout << i << tab;
	cout << endl << DEL << endl;

	for (Fraction i(1, 2); i.get_integer() < 10; i++)cout << i << tab;
	cout << endl << DEL << endl;

	cout << typeid(3 + 2.5).name() << endl;

#ifdef TYPE_CONVERTIONS
	/*
--------------------------------------
Type Conversions:

From less to more:
char --> int
int --> double

From more to less:			(may cause a loss of data)
int --> char
double --> int
---------------------------------------
*/

	int a = 2;				// No coversion
	double b = 2;			// From less to more
	int c = b;				// From more to less without loosing data
	double d = 2.5;			// No conversion
	int e = d;				//From more to less with loosing data

	Fraction A = 5; // Fron other to this. ��� �������������� ��������� Single Argument Constructor

	cout << sizeof(int) << endl;
	cout << sizeof(Fraction) << endl;

	a = A;			// From more to less, Possible loss of data

	cout << sizeof(a) << endl;
	//Type cast operators
	/*
	----------------------------------------- 
	Type cast operator syntax:

	operator type()
	{
		.....
		.....
	}

	------------------------------------------
	*/





#endif // TYPE_CONVERTIONS






}

