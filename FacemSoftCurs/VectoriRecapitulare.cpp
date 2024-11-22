#include <iostream>
using namespace std;

int main() {
	int vector[4];
	vector[0] = 1;
	vector[1] = 2;
	vector[2] = 3;
	vector[3] = 4;

	unsigned int dimensiune = sizeof(vector) / sizeof(int);
	
	for (int i = 0; i < 4; i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
	unsigned int d = 4;
	int* v = new int[d];
	for (int i = 0; i < d; i++) {
		v[i] = i + 1;
	}
	cout << endl;
	for (int i = 0; i < d; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}