#include "Fraction.h"

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPAUND_ASSIGMENTS_CHECK
//#define TYPE_CONVERTIONS
//#define INCREMENTS_CHECK
#define COMPARISON_OPERATORS

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
	Fraction A;		//В таких случаях вызывается коструктор по умолчания(Default constructor)
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


#ifdef INCREMENTS_CHECK
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
#endif // INCREMENTS_CHECK


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

	//int a = 2;				// No coversion
	//double b = 2;			// From less to more
	//int c = b;				// From more to less without loosing data
	//double d = 2.5;			// No conversion
	//int e = d;				//From more to less with loosing data

	//Fraction A = (Fraction)5; // Fron other to this. Это преобразование выполняет Single Argument Constructor
	
	Fraction A(2.3);		//Если конструктор explicit, то его можно вызвать только так
	
	cout << "Fraction A = " <<A << endl;
	//cout << sizeof(int) << endl;
	//cout << sizeof(Fraction) << endl;

	//Type cast operator
	int a = (int)A;			// From more to less, Possible loss of data (operator int)

	cout << "int a = " << a << endl;
	
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

	/*Fraction B(3, 4, 5);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;

	int c = (int)B;
	cout << c << endl;*/

	Fraction C = 2.3;
	cout << C << endl;
	cout << (double)C << endl;

#endif // TYPE_CONVERTIONS

#ifdef COMPARISON_OPERATORS

	Fraction A(1, 2);
	Fraction B(2, 4);

	if (A == B)
	{
		cout << "                    ___  " << endl;
		cout << "                   /   \\  " << endl;
		cout << "Сходиться         ('<->')   " << endl;
		cout << "             !!!   \\___/   !!!" << endl;
		cout << "             | |____| |____| | " << endl;
		cout << "             (____       ____)" << endl;
		cout << "                  |     |" << endl;
		cout << "                  |     |" << endl;
		cout << "                  |     |" << endl;
		cout << "                  |     |" << endl;
		cout << "                 _|     |_" << endl;
		cout << "                |    |    |" << endl;
		cout << "                |    |    |" << endl;
		cout << "                |____|____|" << endl;
	}
	else
	{
		cout << "                       ___  " << endl;
		cout << "                      /   \\  " << endl;
		cout << "Не Сходиться         ('<->')   " << endl;
		cout << "                !!!   \\___/   !!!" << endl;
		cout << "                | |____| |____| | " << endl;
		cout << "                (____       ____)" << endl;
		cout << "                     |     |" << endl;
		cout << "                     |     |" << endl;
		cout << "                     |     |" << endl;
		cout << "                     |     |" << endl;
		cout << "                    _|     |_" << endl;
		cout << "                   |    |    |" << endl;
		cout << "                   |    |    |" << endl;
		cout << "                   |____|____|" << endl;
	}

	cout << A << "  " << B << endl;

	cout << "Strict: \t" << endl;
	cout << "==  | " << (A == B) << endl;
	cout << "!=  |" <<(A != B) << endl;
	cout << "<  |" << (A < B) << endl;
	cout << ">  |" << (A > B) << endl;

	cout << "Not strict: \t" << endl;
	cout << ">=  |" << (A >= B) << endl;
	cout << "<=  |" << (A <= B) << endl;
	//cout << "Fractions " << (A == B ? "equal" : "differemnt") << endl;

#endif // COMPARISON_OPERATORS


	



}

