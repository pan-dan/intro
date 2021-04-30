#pragma once
#include "Distributed.h"
#include "HUman.h"

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


