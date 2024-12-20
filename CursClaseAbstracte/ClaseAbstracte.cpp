#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Ochelari {
private:
	char* brand;
	float pret;
public:
	Ochelari() : pret(0), brand(nullptr) {}
	Ochelari(float pret, const char* brand) {
		this->pret = pret;
		this->brand = new char[strlen(brand) + 1];
		memcpy(this->brand, brand, strlen(brand) + 1);
	}

	friend void operator<<(fstream& out, Ochelari ochelari) {
		out << ochelari.pret << endl;
		out << ochelari.brand << endl;
	}

	friend void operator>>(ifstream& in, Ochelari& ochelari) {
		in >> ochelari.pret;
		if (ochelari.brand != nullptr) {
			delete[] ochelari.brand;
			ochelari.brand = nullptr;
		}

		char buffer[50];
		in >> buffer;
		ochelari.brand = new char[strlen(buffer) + 1];
		strcpy(ochelari.brand, buffer);
	}

	friend void operator<<(ostream& out, Ochelari ochelari) {
		out << "Pret: " << ochelari.pret << endl;
		out << "Brand: " << ochelari.brand << endl;
	}

	float getPret() {
		return this->pret;
	}

	Ochelari operator+(const Ochelari o) {
		Ochelari copie = *this;
		copie.pret = copie.pret + o.pret;

		return copie;
	}
};

int suma(int a, int b) {
	return a + b;
}

template<class T>
T sumaT(T a, T b) {
	return a + b;
}


void main() {
	Ochelari ochelari(1000, "RayBan");
	fstream fileStream("Ochelari.txt", ios::out);

	fileStream << ochelari;
	fileStream.close();

	Ochelari ochelari2;
	ifstream iFileStream("Ochelari.txt", ios::in);
	iFileStream >> ochelari2;
	iFileStream.close();

	cout << ochelari2;

	cout << endl << suma(2, 3);
	cout << endl << sumaT(2.6, 3.7);

	Ochelari ochelari3 = sumaT(ochelari, ochelari2);

	cout << endl << ochelari3.getPret();
}