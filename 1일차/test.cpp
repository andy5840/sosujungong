#include<iostream>
#include<Windows.h>
#include<time.h>
using namespace std;

//struct Car {
//	int speed;
//	int gear;
//	char* pcolor;
//};
//
//void init(Car& c, char* color);
//void start(Car& c);
//void stop(Car& c);
//int get_speed(Car& c);
//void set_speed(Car& c, int speed);
//
//int main() {
//	Car car;
//	init(car, "red");
//	start(car);
//	set_speed(car, 60);
//	stop(car);
//	return 0;
//}
//

//class car {
//	int speed;
//	int gear;
//	char* pcolor;
//
//public:
//	void init(char* color);
//	void start();
//	void stop();
//	int get_speed();
//	void set_speed(int speed);
//};
//
//int main() {
//	car car;
//	car.init("red");
//	car.start();
//	car.set_speed(60);
//	car.stop(car);
//	return 0;
//}

class Car {
public:
	int speed;
	int gear;
	string color;
	int* golf = new int;
	const int MAX_SPEED;
public:
	Car();
	~Car();
	Car(int s, int g, string c);

	int getSpeed();
	void setSpeed(int s);
	int getGear();
	void setGear(int g);
	string getColor();
	void setColor(string c);
	void show();

};

Car::Car() :MAX_SPEED(200){
	cout << "생성자 호출" << endl;
	speed = 0;
	gear = 1;
	color = "white";
}
Car::~Car() {
	cout << "소멸자 호출" << endl;
	delete golf;
}
Car::Car(int s, int g, string c):speed(s), gear(g), color(c) , MAX_SPEED(200){
	cout << "생성자 호출" << endl;
}
void Car::setSpeed(int s) {
	speed = s;
}
int Car::getSpeed() {
	return speed;
}
void Car::setGear(int g) {
	gear = g;
}
int Car::getGear() { return speed; }
void Car::setColor(string c) { color = c; }
string Car::getColor() { return color; }

void Car::show(){
	cout << "=================" << endl;
	cout << "속도: " << speed << endl;
	cout << "기어: " << gear << endl;
	cout << "색상: " << color << endl;
	cout << "=================" << endl;
}

int main() {
	srand(time(NULL));
	srand(GetTickCount());
	Car car1(rand() % 200, 1, "red"), car2(rand() % 200, 1, "red");

	Car* a = new Car();

	car1.show();
	car2.show();

	if (car1.getSpeed() > car2.getSpeed()) {
		cout << "car1이 승리함" << endl;
	}
	else {
		cout << "car2가 승리함" << endl;
	}

	delete a;
	return 0;
}