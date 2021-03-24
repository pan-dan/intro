#include <iostream>

using namespace std;
using std::cout;
#define tab "\t"

// Создание структуры
class Point  //Рассматриваем точку на оси координат
{


	// Структура Point опизывает точку на плоскости.
	double x;	//Координата x
	double y;	//Координата y

public:

	double get_x()const
	{
		return x;
	}
	double get_y()const
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
	/*Point()
	{
		// Конструктор по умолчанию создаёт точку в начале координат
		x = y = int();	// Якобы вызываем конструктор по умолчанию 
		//для 'int', и он возвращает значение по умолчанию 
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		// Конструктор с одним параметром создаёт точку на прямой
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentsConstructor:\t\t" << this << endl;
	}

	Point(double x, double y)
	{
		//Конструктор с параметрами создаёт точку на плоскости
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	
	}*/

	Point(double x = 0, double y = 0)
	{
		//Этот конструктор с параметрами может быть вызван
		//-без параметров
		//-с одним параметром
		//-с двумя параметрами

		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		// other - это другой объект, копию которого мы создаём.

		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}


	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
	}

	double distance(const Point& other)const
	{
		double x_distance = other.x - this->x;
		double y_distance = other.y - this->y;
		
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
			return distance;
	
	}	// sqrt - Square root (квадратный корень)

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

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();

	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}



//#define INTRO
//#define CONSTRUCTORS
#define DISTANCE

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

	Point B = 5; //Single-Argument constructor
	B.print();

	Point C(8); //Single-Argument constructor
	C.print();

	Point D{ 12 }; //Single-Argument constructor
	D.print();

	// Пример
	int a(2);
	int b{ 3 };
	cout << a << tab << b << endl;


	Point E(5, 3); //Paramet
	E.print();

	Point F = E;	//CopyConstructor. Здесь мы создаём объект и инициализируем его другим объектом
	Point G;		//DefaultConstructor
	G = D;		//CopyAssigment - operator=
	G.print();

	



#endif // CONSTRUCTORS


	Point A(2, 3);
	Point B(4, 5);
	cout << A.distance(B) << endl;

	cout << distance(A, B) << endl;


}