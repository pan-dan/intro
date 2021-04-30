#pragma once
#include "Distributed.h"

class Human
{
	string last_name;
	string first_name;
	//time_t birth_date;
	unsigned int age;

public:

	const string& get_last_name()const;
	const string& get_first_name()const;
	/*const time_t& get_birth_date()const
	{
		return birth_date;
	}*/
	unsigned int get_age()const;

	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);
	/*void set_birth_date(const time_t& birth_date)
	{
		this->birth_date = birth_date;
	}*/
	void set_age(unsigned int& age);


	//			Constructors
	Human(const string& last_name, const string& first_name, unsigned int age /*const time_t& birth_date*/);

	virtual ~Human();



	//			Methods
	virtual void info()const;
};
