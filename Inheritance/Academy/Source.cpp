#include <iostream>
#include <string>
#include <ctime>

using namespace std;
using std::cout;
using std::endl;
using std::cin;

#define DEL "--------------------------------------------------------"


class Human
{
	string last_name;
	string first_name;
	//time_t birth_date;
	unsigned int age;

public:

	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	/*const time_t& get_birth_date()const
	{
		return birth_date;
	}*/
	unsigned int get_age()const
	{
		return age;
	}

	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	/*void set_birth_date(const time_t& birth_date)
	{
		this->birth_date = birth_date;
	}*/
	void set_age(unsigned int& age)
	{
		this->age = age;
	}


	//			Constructors
	Human(const string& last_name, const string& first_name, unsigned int age /*const time_t& birth_date*/)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		/*set_birth_date(birth_date);*/
		set_age(age);

		cout << "HConstructor:\t" << this << endl;
	}

	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}



	//			Methods
	void info()const
	{
		//cout << "Last name: " << last_name << endl;
		//cout << "First name: " << first_name << endl;
		//cout << "Age: " << age << endl;
	/*	cout << "Birth date:" << birth_date << endl;*/
		cout << last_name << " " << first_name << ", " << age << " лет" << endl;
	}
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;

public:

	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	const double get_rating()const
	{
		return rating;
	}

	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}



	//			Constructors
	Student
	(
	const string& last_name, const string& first_name, unsigned int age,	// Атрибуты базового класса
	const string& speciality, const string& group, double rating			// Атрибуты нашего класса
	):Human(last_name, first_name,age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}

	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}



	//			Methods
	void info()const
	{
		Human::info();
		cout << speciality << ", " << group << ", успеваемость: " << rating << endl;
	}




};

class Teacher :public Human
{
	string spesiality;
	unsigned int experiance;


public:
	const string& get_speciality()const
	{
		return spesiality;
	}
	unsigned int get_experiance() const
	{
		return experiance;
	}

	void set_speciality(const string& speciality)
	{
		this->spesiality = speciality;
	}
	void set_experiance(unsigned int experiance)
	{
		this->experiance = experiance;
	}

	

	//			Constructors
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experiance
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experiance(experiance);
		
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}



	//			Methods
	void info()
	{
		Human::info();
		cout << spesiality << ", опыт предподавания: " << experiance << " лет." << endl;
			
	}

};


void main()
{
	setlocale(LC_ALL, "Rus");

	/*Human human("Тупенко", "Василий", 35);
	cout << DEL << endl;
	human.info();
	cout << DEL << endl;*/

	Student vasya("Тупенко", "Василий", 18, "Программирование", "BV_011", 4.5);
	vasya.info();

	Teacher teacher("Einstein", "Albert", 150, "Phisics", 120);
	teacher.info();
}