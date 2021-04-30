#pragma once

#include <iostream>
#include <string>
#include <ctime>

using namespace std;
using std::cout;
using std::endl;
using std::cin;


#define DEL "--------------------------------------------------------" 

#define HUMAN_TAKE_PARAMETERS const string& last_name, const string& first_name, unsigned int age
#define STUDENT_TAKE_PARAMETERS	const string& university, const string& speciality, const string& group, double rating	
#define TEACHER_TAKE_PARAMETERS	const string& speciality, unsigned int experiance

#define HUMAN_GIVE_PARAMETERS last_name, first_name,age
#define STUDENT_GIVE_PARAMETERS university,speciality,group,rating
#define TEACHER_GIVE_PARAMETERS speciality, experience


class Human;
class Student;
class Teacher;
class Graduate;


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

class Teacher :public Human
{
	string spesiality;
	unsigned int experiance;


public:
	const string& get_speciality()const;
	unsigned int get_experiance() const;

	void set_speciality(const string& speciality);
	void set_experiance(unsigned int experiance);



	//			Constructors
	Teacher
	(
		HUMAN_TAKE_PARAMETERS,
		TEACHER_TAKE_PARAMETERS
	);
	~Teacher();



	//			Methods
	void info();

};

class Graduate :public Student
{
	string diploma;					//Красный диплом или обычный
	string topic;					//Тема дипломного проекта


public:

	const string& get_diploma()const;
	const string& get_topic()const;


	void set_diploma(const string& diploma);
	void set_topic(const string& topic);

	//			Constructors
	Graduate
	(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS,
		const string& diploma, const string& topic
	);

	~Graduate();

	//			Methods
	void info()const;


};



