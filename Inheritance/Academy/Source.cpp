#include "Distributed.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Graduate.h"


//#define INHERITANCE_CHECK

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


		//Polymorphism

	// 1.Generalization:
	// при заполении массива выполняется преобразование дочернего объекта в базовый тип - upcast
	Human* group[] =
	{
		new Student("Батодалаев", "Даши", 16, "StepA","РПО", "PD_011",5),
		new Student("Загидуллин", "Линар", 32, "StepA", "РПО", "PD_011", 5),
		new Graduate("Шугани", "Сергей", 15, "StepA", "РПО", "PD_011", 5, "Красный", "Защита персональных данных"),
		new Teacher("Einstein", "Albert", 141, "Astrophysics", 110),
		new Student("Маркин", "Даниил", 17, "StepA", "РПО", "BV_011", 5),
		new Teacher("Richter", "Jeffrie", 45, "Windows development", 20)

	};

	cout << sizeof(group) << endl;
	//2) Specialization
	cout << DEL << endl;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		//group[i]->info();
		cout << typeid(*group[i]).name() << endl;
		//cout << *group[i] << ", ";
		
		// Преобразование базового объекта в дочерний класс - downcast.
		// down cast выполняет dynamic_cast.
		// dynamic_cast преобразует указатель на базовый класс (Human) в указатель на дочерний класс
		
		if(typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		
		cout << DEL << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}


}