#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
//#define CW
//#define STRANGE_JOKE
#define HW
#define DELIMETR "--------------------------------------------------------------------------------"

	//Создание класса Fraction
class Fraction
{
	int z;
	int x;
	int y;
	

public:

	int get_z() const
	{
		return z;
	}
	int get_x() const
	{
		return x;
	}
	int get_y() const
	{
		return y;
	}

	void set_z(int z)
	{
		this->z = z;
	}
	void set_x(int x)
	{
		this->x = x;
	}
	void set_y(int y)
	{
		this->y = y;
	}

	//						CONSTRUCTORS

	Fraction(int x = 0, int y = 0, int z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		cout << "TripleConstructor: \t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		cout << "CopyConstructor: \t\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


	//						Methods
	void print()
	{
		cout << z << "(" << x << "/" << y << ")" << endl;
	}

	void to_proper()
	{
		// x - числитель
		// y - знаменатель
		int right_x = x;
		int whole_part = 0;
		//	int condition = 0;
		if (x - y < 0)
		{
			cout << "Так то дробь " << x << "/" << y << " правильная" << endl;
			return;
		}
		else if (x - y == 0)
		{
			++whole_part;
			cout << "Правильная дробь: " << whole_part << endl;
			return;
		}
		else if (x - y > 0)
		{
			for (; right_x - y <= 0; )
			{
				right_x -= y;
				++whole_part;
			}
			if (right_x - y == 0)cout << whole_part << endl;
			else
			{
				cout << whole_part << "(" << right_x << "/" << y << ")" << endl;
			}
		}
	}


	void to_improper()
	{
		// x - целая часть
		// y - чилслитель
		// z - заменатель
		int whole_part = this->get_x();
		int right_y = this->get_y();

		if (whole_part == 0)
		{
			cout << y << "/" << z << endl;
			return;
		}
		else 
		{
			for(; whole_part == 0; whole_part--)
			{
				right_y += z;
			}
			cout << "Неправильная дробь: " << right_y << "/" << y << endl;
			return;
		}
	}
};

// Создание структуры
#ifdef CW
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
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
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
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;

		cout << "Operator+=\t\t" << this << endl;
		return *this;
	}

	//		Increment/Decrement
	Point& operator++()				//Prefix increment
	{
		this->x++;
		this->y++;
		cout << "Prefix increment: \t\t" << this << endl;
		return *this;
	}

	Point operator++(int)			//Postfix increment
	{
		Point old = *this;	//Copy constractor
		this->x++;
		this->y++;

		cout << "Postfix increment:\t\t" << this << endl;
		return old;
	}

	/*Point operator+(const Point& other) const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "Operator+:" << endl;
		return result;
	}*/

	/*Point operator-(const Point& other) const
	{
		Point result(this->x - other.x, this->y - other.y);
		cout << "Operator-:" << endl;
		return result;
	}*/

	/*Point operator*(const Point& other) const
	{

		return Point(this->x *other.x, this->y * other.y);
	}*/

	/*Point operator/(const Point& other) const
	{
		return Point(this->x / other.x, this->y / other.y);
	}*/

	double distance(const Point& other)const
	{
		//double x_distance = other.x - this->x;
		//double y_distance = other.y - this->y;

		//double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//	return distance;
		return	(sqrt((other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y)));

	}	// sqrt - Square root (квадратный корень)

				//Methods

	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
#endif // CW


//Создавая структуру или класс, мы создаём новый тип данных,
//а объявляя объекты этого класса или структуры, мы создаём переменнуе нашего типа.
//Классы и структуры ещё называют пользовательскими типами данных


//					КЛАСС - ЭТО ТИП ДАННЫХ
//					СТРУКТУРА - ЭТО ТИП ДАННЫХ
//					ОБЪЕКТ - ЭТО САМАЯ ОБЫЧНАЯ ПЕРЕМЕННАЯ

#ifdef CW
double distance(const Point& A, const Point& B)
{
	//double x_distance = A.get_x() - B.get_x();
	//double y_distance = A.get_y() - B.get_y();

	//double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	//return distance;
	return  (sqrt((A.get_x() - B.get_x()) * (A.get_x() - B.get_x()) + (A.get_y() - B.get_y()) * (A.get_y() - B.get_y())));
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	cout << "Global minus" << endl;
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	cout << "Global multiplication" << endl;
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}

Point operator/(const Point& left, const Point& right)
{
	cout << "Global divide" << endl;
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}
#endif // CW


#ifdef STRANGE_JOKE
ostream& operator<<(ostream& os /*uotput stream*/, const Point& obj)
{
	return os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
}

#endif // STRANGE_JOKE



//#define INTRO
//#define CONSTRUCTORS
//#define ASSIGMENT_CHECK
//#define DISTANCE
//#define OPERATOR_EXAMPLES
//#define OPERATOR_OVERLOADS
//#define ARITHMETICAL_OPERATORS
//#define COMPOUND_ASSIGMENTS;


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

#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	A = B = C = Point();

#endif // ASSIGMENT_CHECK

#if DISTANCE
	Point A(2, 3);
	Point B(4, 5);
	cout << A.distance(B) << endl;

	cout << distance(A, B) << endl;
#endif // DISTANCE
	
#ifdef OPERATOR_OVERLOADS

#ifdef OPERATOR_EXAMPLES
	Point A(2, 3);
	Point B(4, 5);
	cout << A + B << endl;				// Неявный вызов оператор '+'
	cout << A.operator+(B) << endl;		// Явный вызов оператора '+', перегруженнго в классе
	cout << operator+(A, B) << endl;	// Явный вызов оператора '+', перегруженнго за классом


#endif // OPERATOR_EXAMPLES


#ifdef ARITHMETICAL_OPERATORS
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	Point D = A - B;			//Неявный вызов оператора
	D.print();
	(A * B).print();
	//Point E = A.operator/(B);	//Явный вызов оператора. Мы его вызываем, как обычный метод
	Point E = operator / (A, B); //Явный вызов глобального оператора
	E.print();

#endif // ARITHMETICAL_OPERATORS

#ifdef COMPOUND_ASSIGMENTS
	Point A(2, 3);
	Point B(4, 5);
	A += B;
	A.print();
	
	/*++A;
	A.print();
	A++;
	A.print();*/
	
	cout << A++ << endl;
	cout << A << endl;
	cout << ++A << endl;
	cout << A << endl;
#endif // COMPOUND_ASSIGMENTS


#endif // OPERATOR_OVERLOADS

	Fraction A(5, 3);
	cout << "Не правильная дробь: "; A.print();
	A.to_proper();
	cout << DELIMETR << endl;

	Fraction B(2, 3, 4);
	cout << "Правильная дробь: "; B.print();
	B.to_improper();
	cout << DELIMETR << endl;
}