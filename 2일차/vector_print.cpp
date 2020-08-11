#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>&aa) {
	for 

	cout << endl;
}

int main() {
	vector<int> vec{ 10, 20, 30 };
	print(vec);

	vec[0] = 100;
	vec.at(1) = 200;

	print(vec);
	vec.push_back(400);
	print(vec);
	cout << endl;

	for (int& elem : vec) {
		cout << "ют╥б";
		cin >> elem;
	}
	for (int elem : vec) {
		cout << elem << ' ';
	}
	cout << endl;

}

