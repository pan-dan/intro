#include <iostream>

using namespace std;


// Создание структуры
class Point  //Рассматриваем точку на оси координат
{


	// Структура Point опизывает точку на плоскости.
	double x;	//Координата x
	double y;	//Координата y

public:

	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;

	}

	void set_x(double x)
	{
		this ->x = x;
	}
	void set_y(double y)
	{
		this ->y = y;
	}


			//			Constructors:
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "DefaultConstructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


				//Methods

	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}



};

//Создавая структуру или класс, мы создаём новый тип данных,
//а объявляя объекты этого класса или структуры, мы создаём переменнуе нашего типа.
//Классы и структуры ещё называют пользовательскими типами данных


//					КЛАСС - ЭТО ТИП ДАННЫХ
//					СТРУКТУРА - ЭТО ТИП ДАННЫХ
//					ОБЪЕКТ - ЭТО САМАЯ ОБЫЧНАЯ ПЕРЕМЕННАЯ


//#define INTRO
#define CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef INTRO
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Создание объекта структуры
				//Объявление объекта 'A' структуры 'Point'
				//Объявление переменной 'A' типа 'Point'

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A; //Создаём указатель на объект
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
#endif // INTRO


#ifdef CONSTRUCTORS
	Point A; //Default constructor
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;
	B.print();
#endif // CONSTRUCTORS


}