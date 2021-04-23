#pragma once

#include <iostream>

using namespace std;

using std::cout;
using std::endl;
using std::cin;

#define tab "\t"
#define DEBUG
#define DEL "--------------------------------------------------------------"

class Fraction;			//Class declaration - объявление класса
Fraction operator+(Fraction left, Fraction right);	//Прототип оператора +
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	bool minus;
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель


public:

	bool get_minus()const;
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;

	void set_minus(bool minus);
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	///////////////////////////////////////////////////////
	Fraction& set_minus_to_number();
	Fraction& get_minus_from_number();

	//CONSTRUCTORS

	Fraction();

	explicit Fraction(int integer);

	Fraction(double decimal);

	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);

	~Fraction();



	Fraction& operator=(const Fraction& other);

	Fraction& operator+=(const Fraction& other);

	Fraction& operator-=(const Fraction& other);

	Fraction& operator*=(const Fraction& other);

	Fraction& operator/=(const Fraction& other);



	//			Inrcrement/Decrement
	Fraction& operator++();
	Fraction& operator++(int);

	//			Type cast operators
	explicit operator int()const;

	operator double()const;


	//			Methods
	Fraction& to_proper();

	Fraction& to_improper();

	Fraction& reduce();
};

Fraction operator+(Fraction left, Fraction right);

Fraction operator-(Fraction left, Fraction right);

Fraction operator*(Fraction left, Fraction right);

Fraction operator/(Fraction left, Fraction right);


bool operator ==(Fraction left, Fraction right);

bool operator!=(const Fraction& left, const Fraction& right);

bool operator<(const Fraction& left, const Fraction& right);

bool operator>(const Fraction& left, const Fraction& right);

bool operator>=(const Fraction& left, const Fraction& right);

bool operator<=(const Fraction& left, const Fraction& right);

ostream& operator<<(ostream& os, const Fraction& obj);


