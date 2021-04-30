#include "Distributed.h"
#include "Teacher.h"

	const string& Teacher::get_speciality()const
	{
		return spesiality;
	}
	unsigned int Teacher::get_experiance() const
	{
		return experiance;
	}

	void Teacher::set_speciality(const string& speciality)
	{
		this->spesiality = speciality;
	}
	void Teacher::set_experiance(unsigned int experiance)
	{
		this->experiance = experiance;
	}



	//			Constructors
	Teacher::Teacher
	(
		HUMAN_TAKE_PARAMETERS,
		TEACHER_TAKE_PARAMETERS
	) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experiance(experiance);

		cout << "TConstructor:\t" << this << endl;
	}
	Teacher::~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}



	//			Methods
	void Teacher::info()
	{
		Human::info();
		cout << spesiality << ", опыт предподавания: '" << experiance << " лет." << endl;

	}

	ostream& operator<<(ostream& os, const Teacher& obj)
	{
		os << (Human)obj << ", ";
		return os << obj.get_speciality() << ", опыт предподавания " << obj.get_experiance() << " лет";
	}
