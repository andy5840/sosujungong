#include "NoPersonException.h"
#include <iostream>
using namespace std;

int main() {
	int pizzaSlices = 12;
	int persons = -1;
	int slicesPerPersons = 0;
	try {
		cout << "��� ���� �Է��Ͻÿ�: ";
		cin >> persons;
		if (persons <= 0) {
			throw NoPersonException(persons);
		}
		slicesPerPersons = pizzaSlices / persons;
		cout << "�ѻ���� ���ڴ� " <<
			slicesPerPersons << "�Դϴ�" << endl;
	}
	catch (NoPersonException e) {
		cout << "���� : �����" << e.getPersons() << "���Դϴ�." << endl;
	}

	return 0;
}
