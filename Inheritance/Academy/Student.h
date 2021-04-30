#pragma once
#include "Distributed.h"
#include "Human.h"

class Student :public Human
{
	string speciality;
	string group;
	double rating;
	string university;

public:

	const string& get_university()const;
	const string& get_speciality()const;
	const string& get_group()const;
	const double get_rating()const;


	void set_university(const string& university);
	void set_speciality(const string& speciality);
	void set_group(const string& group);
	void set_rating(double rating);



	//			Constructors
	Student
	(
		HUMAN_TAKE_PARAMETERS,							// Атрибуты базового класса
		STUDENT_TAKE_PARAMETERS			// Атрибуты нашего класса
	);


	~Student();



	//			Methods
	void info()const;




};
