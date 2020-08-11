#include<iostream>
#include <vector>
#include <list>
using namespace std;

template<typename iter>
void print(const iter& iter_begin, const iter& iter_end) {
	for (iter iter1 = iter_begin; iter1!= iter_end; iter1++) {
		cout << *iter1 << ' ';
	}
	cout << endl;
}

template<typename iter>
void print_reserve(const iter& iter_begin, const iter& iter_end) {
	iter iter2 = iter_end;
	while (iter2 != iter_begin) {
		iter2--;
		cout << *iter2 << ' ';
	}
	cout << endl;

}

int main() {
	vector<int> v{ 1,2, 3, 4 };
	list<double> l{ 1,1, 2, 2, 3, 3, 4, 4 };
	int ary[] = { 100, 200, 300, 400 };
	print(begin(v), end(v));
	print(begin(l), end(l));
	print(begin(ary), end(ary));

	print_reserve(begin(v), end(v));
	print_reserve(begin(l), end(l));
	print_reserve(begin(ary), end(ary));


	return 0;
}