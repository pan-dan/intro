#include "Distributed.h"


	
	const string& Student::get_university()const
	{
		return university;
	}
	const string& Student::get_speciality()const
	{
		return speciality;
	}
	const string& Student::get_group()const
	{
		return group;
	}
	const double Student::get_rating()const
	{
		return rating;
	}


	void Student::set_university(const string& university)
	{
		this->university = university;
	}
	void Student::set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void Student::set_group(const string& group)
	{
		this->group = group;
	}
	void Student::set_rating(double rating)
	{
		this->rating = rating;
	}



	//			Constructors
	Student::Student
	(
		HUMAN_TAKE_PARAMETERS,							// �������� �������� ������
		STUDENT_TAKE_PARAMETERS			// �������� ������ ������
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_university(university);
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}

	Student::~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}



	//			Methods
	void Student::info()const
	{
		Human::info();
		cout << university << ", " << speciality << ", " << group << ", ������������: " << rating << ", " << endl;
	}

