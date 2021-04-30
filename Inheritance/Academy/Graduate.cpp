#include "Distributed.h"
#include "Graduate.h"



	const string& Graduate::get_diploma()const
	{
		return diploma;
	}
	const string& Graduate::get_topic()const
	{
		return topic;
	}


	void Graduate::set_diploma(const string& diploma)
	{
		this->diploma = diploma;
	}
	void Graduate::set_topic(const string& topic)
	{
		this->topic = topic;
	}

	//			Constructors
	Graduate::Graduate
	(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS,
		const string& diploma, const string& topic
	) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS), diploma(diploma), topic(topic)
	{

		cout << "GConstructor:\t" << this << endl;

	}

	Graduate::~Graduate()
	{
		cout << "GDestructor" << this << endl;
	}

	//			Methods
	void Graduate::info()const
	{
		Student::info();
		cout << diploma << " диплом, " << "тема проекта: " << topic << "." << endl;
	}





