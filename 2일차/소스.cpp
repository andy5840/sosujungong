#include <iostream>
using namespace std;

int DividePizza(int pizzaSlice, int person) {
	if (person == 0)
		throw person;
	return pizzaSlice / person;
}

int main() {
	int pizza_slices = 0;
	int person = -1;
	int slices_per_person = 0;
	try {
		cout << "���� ���� ���� �Է��Ͻÿ�";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�";
		cin >> person;

		slices_per_person = DividePizza(pizza_slices, person);
		cout << "�ѻ���� ���ڴ�" << slices_per_person << "�Դϴ�." << endl;
	}
	catch (int e) {
		cout << "�����" << e << "�� �Դϴ�." << endl;
	}
	return 0;
}

