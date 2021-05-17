#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define DEL "----------------------------------------------------------"

class Vehicle	// Абстрактный класс
{

	int speed;

public:
	virtual void move() = 0;		// Чисто виртуальная функция


};

class AirVehicle :public Vehicle	// Тоже абстрактный класс
{
	int height;
public:
	virtual void takeoff() = 0;
	virtual void land() = 0;
};

class Airplain : public AirVehicle	//Конкретный класс
{

public:

	void move()
	{
		cout << "Летит по воздуху" << endl;
	}
	void takeoff()
	{
		cout << "Для взлёта нужна взлётная полоса" << endl;
		cout << "Взлетаем" << endl;
	}
	void land()
	{
		cout << "Для посадки нужна взлётная полоса" << endl;
		cout << "Захожу на посадку" << endl;
	}
};

class Helicopter : public AirVehicle
{
public:

	void takeoff()
	{
		cout << "Могу взлететь где удобно" << endl;
	}
	void move()
	{
		cout << "Плавненько перещаюсь по воздуху" << endl;
	}
	void land()
	{
		cout << "Могу сесть хоть в поле" << endl;
	}
};

class LandVehicle : public Vehicle
{


};

class Car :public LandVehicle
{

public:
	void move()
	{
		cout << "Едет по дороге на четырёх колосех" << endl;
	}
};

class  Bike: public LandVehicle
{

public:
	void move()
	{
		cout << "Едет по дороге на двух колёсах" << endl;
	}
};

class WaterVehicle :public Vehicle
{
	
public:
	void move()
	{
		cout << "Плывёт по воде" << endl;
	}
};

class Boat : public WaterVehicle
{

public:

};

void main()
{
	setlocale(LC_ALL, "Rus");

	//Vehicle v;				// Невозможно создать экземпляр абстрактного класса
	//AirVehicle av;			// Этот класс так же является абстрактным,
			// поскольку наследует чисто виртуальный метод базового класса - move().
			// и не реализует его


	Airplain plain;
	plain.takeoff();
	plain.move();
	plain.land();

	cout << DEL << endl;

	Helicopter chopper;
	chopper.takeoff();
	chopper.move();
	chopper.land();

	cout << DEL << endl;
	Car car;
	car.move();

	Bike bike;
	bike.move();

	cout << DEL << endl;

	Boat boat;
	boat.move();







}