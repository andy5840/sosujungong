#include "NoPersonException.h"
#include <iostream>
using namespace std;

int main() {
	int pizzaSlices = 12;
	int persons = -1;
	int slicesPerPersons = 0;
	try {
		cout << "사람 수를 입력하시오: ";
		cin >> persons;
		if (persons <= 0) {
			throw NoPersonException(persons);
		}
		slicesPerPersons = pizzaSlices / persons;
		cout << "한사람당 피자는 " <<
			slicesPerPersons << "입니다" << endl;
	}
	catch (NoPersonException e) {
		cout << "오류 : 사람이" << e.getPersons() << "명입니다." << endl;
	}

	return 0;
}
