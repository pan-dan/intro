#pragma once

#include <iostream>
#include <string>
#include <ctime>

using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::string;


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

