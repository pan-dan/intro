#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define DEL "----------------------------------------------------------"

class Vehicle	// ����������� �����
{

	int speed;

public:
	virtual void move() = 0;		// ����� ����������� �������


};

class AirVehicle :public Vehicle	// ���� ����������� �����
{
	int height;
public:
	virtual void takeoff() = 0;
	virtual void land() = 0;
};

class Airplain : public AirVehicle	//���������� �����
{

public:

	void move()
	{
		cout << "����� �� �������" << endl;
	}
	void takeoff()
	{
		cout << "��� ����� ����� ������� ������" << endl;
		cout << "��������" << endl;
	}
	void land()
	{
		cout << "��� ������� ����� ������� ������" << endl;
		cout << "������ �� �������" << endl;
	}
};

class Helicopter : public AirVehicle
{
public:

	void takeoff()
	{
		cout << "���� �������� ��� ������" << endl;
	}
	void move()
	{
		cout << "���������� ��������� �� �������" << endl;
	}
	void land()
	{
		cout << "���� ����� ���� � ����" << endl;
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
		cout << "���� �� ������ �� ������ �������" << endl;
	}
};

class  Bike: public LandVehicle
{

public:
	void move()
	{
		cout << "���� �� ������ �� ���� ������" << endl;
	}
};

class WaterVehicle :public Vehicle
{
	
public:
	void move()
	{
		cout << "����� �� ����" << endl;
	}
};

class Boat : public WaterVehicle
{

public:

};

void main()
{
	setlocale(LC_ALL, "Rus");

	//Vehicle v;				// ���������� ������� ��������� ������������ ������
	//AirVehicle av;			// ���� ����� ��� �� �������� �����������,
			// ��������� ��������� ����� ����������� ����� �������� ������ - move().
			// � �� ��������� ���


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