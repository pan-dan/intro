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
	/*Human human("�������", "�������", 35);
cout << DEL << endl;
human.info();
cout << DEL << endl;*/

	Student vasya("�������", "�������", 18, "����", "����������������", "BV_011", 4.5);
	vasya.info();

	Teacher teacher("Einstein", "Albert", 150, "Phisics", 120);
	teacher.info();

	Graduate Tony("Montana", "Antonio", 25, "���", "����������� ���������� ������",
		"BV_011", 80, "�������", "��������������� �������");
	Tony.info();
#endif // INHERITANCE_CHECK


		//Polymorphism

	Human* group[] =
	{
		new Student("����������", "����", 16, "StepA","���", "PD_011",5),
		new Student("����������", "�����", 32, "StepA", "���", "PD_011", 5),
		new Graduate("������", "������", 15, "StepA", "���", "PD_011", 5, "�������", "������ ������������ ������"),
		new Teacher("Einstein", "Albert", 141, "Atrophisics", 110),
		new Student("������", "������", 17, "StepA", "���", "BV_011", 5),
		new Teacher("Richter", "Jeffrie", 45, "Windows development", 20)

	};

	cout << sizeof(group) << endl;
	//2) Specialization
	cout << DEL << endl;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		group[i]->info();
		cout << DEL << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}


}