#pragma once
#include "Distributed.h"
#include "Student.h"

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



