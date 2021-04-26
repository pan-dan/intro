#include <iostream>
#include <string>
#include <ctime>

using namespace std;
using std::cout;
using std::endl;
using std::cin;


#define DEL "--------------------------------------------------------"

#define HUMAN_TAKE_PARAMETERS		const string& last_name, const string& first_name, unsigned int age
#define STUDENT_GET_PARAMETERS		const string& university, const string& speciality, const string& group, double rating	
#define TEACHER_GET_PARAMETERS		const string& speciality, unsigned int experiance

#define HUMAN_GIVE_PARAMETERS		last_name, first_name,age
#define STUDENT_GIVE_PARAMETERS		university,speciality,group,rating
#define TEACHER_GIVE_PARAMETERS		speciality, experience


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
	string university;

public:

	const string& get_university()const
	{
		return university;
	}
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
	

	void set_university(const string& university)
	{
		this->university = university;
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
	HUMAN_TAKE_PARAMETERS,							// Атрибуты базового класса
	STUDENT_GET_PARAMETERS			// Атрибуты нашего класса
	):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_university(university);
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
		cout << university << ", " << speciality << ", " << group << ", успеваемость: " << rating << ", "<< endl;
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
		HUMAN_TAKE_PARAMETERS,
		TEACHER_GET_PARAMETERS
	):Human(HUMAN_GIVE_PARAMETERS)
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
		cout << spesiality << ", опыт предподавания: '" << experiance << " лет." << endl;
			
	}

};

class Graduate:public Student
{
	string diploma;					//Красный диплом или обычный
	string topic;					//Тема дипломного проекта


public: 

	const string& get_diploma()const
	{
		return diploma;
	}
	const string& get_topic()const
	{
		return topic;
	}


	void set_diploma(const string& diploma)
	{
		this->diploma = diploma;
	}
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}

	//			Constructors
	Graduate
	(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_GET_PARAMETERS,
		const string& diploma, const string& topic
	):Student(HUMAN_GIVE_PARAMETERS,STUDENT_GIVE_PARAMETERS), diploma(diploma), topic(topic)
	{

		cout << "GConstructor:\t" << this << endl;

	}
	
	~Graduate()
	{
		cout << "GDestructor" << this << endl;
	}

	//			Methods
	void info()const
	{
		Student::info();
		cout << diploma << " диплом, " << "тема проекта: " << topic << "." << endl;
	}


};


#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef INHERITANCE_CHECK
	/*Human human("Тупенко", "Василий", 35);
cout << DEL << endl;
human.info();
cout << DEL << endl;*/

	Student vasya("Тупенко", "Василий", 18, "УРФО", "Программирование", "BV_011", 4.5);
	vasya.info();

	Teacher teacher("Einstein", "Albert", 150, "Phisics", 120);
	teacher.info();

	Graduate Tony("Montana", "Antonio", 25, "МГУ", "Современные технологии продаж",
		"BV_011", 80, "Красный", "Распространение кокаина");
	Tony.info();
#endif // INHERITANCE_CHECK

}