#include<iostream>
#include<string>
using namespace std;

class Doctor {
private:
	string numeDoctor;
	const int idDoctor;
	static int nrDoctori;
	string specializare;
	int nrGarzi;
	int* garda;
	
public:
	Doctor():idDoctor(++nrDoctori) {
		cout << "Am apelat constructorul fara parametrii" << endl;
		this->numeDoctor = "Nume Doctor";
		this->specializare = "Medicina";
		this->nrGarzi = 0;
		this->garda = nullptr;
	}
	Doctor(string numeDoctor) :idDoctor(++nrDoctori) {
		cout << "Am apelat constructorul cu un parametru" << endl;
		this->numeDoctor = numeDoctor;
		this->specializare = "Medicina";
		this->nrGarzi = 0;
		this->garda = nullptr;
	}
	Doctor(string numeDoctor, string specializare, int nrGarzi, int* garda) :idDoctor(++nrDoctori) {
		cout << "Am apelat constructorul cu parametrii" << endl;
		if (numeDoctor != "") {
			this->numeDoctor = numeDoctor;
		}
		else
			this->numeDoctor = "Nume Doctor";
		if (specializare != "") {
			this->specializare = specializare;

		}
		else
			this->specializare = "medicina";
		if (nrGarzi > 0 && garda != nullptr) {
			this->garda = new int[nrGarzi];
			for (int i = 0; i < nrGarzi; i++)
				this->garda[i] = garda[i];
		}
		else {
			this->nrGarzi = 0;
			this->garda = nullptr;
		}

	}
	Doctor(const Doctor& d) :idDoctor(d.idDoctor) {
		cout << "Am apelat constructorul de copiere" << endl;
		if (numeDoctor != "") {
			this->numeDoctor = d.numeDoctor;
		}
		else
			this->numeDoctor = "Nume Doctor";
		if (specializare != "") {
			this->specializare = d.specializare;

		}
		else
			this->specializare = "medicina";
		++nrDoctori;
		if (d.nrGarzi > 0 && d.garda != nullptr) {
			this->garda = new int[d.nrGarzi];
			for (int i = 0; i < d.nrGarzi; i++)
				this->garda[i] = d.garda[i];
		}
		else {
			this->nrGarzi = 0;
			this->garda = nullptr;
		}
	}
	static int getnrDoctori() {
		return nrDoctori;
	}

	~Doctor() {
		cout << "S-a apelat destructorul" << endl;
		if (this-> garda != nullptr) {
			delete[] this->garda;
			
			}
		}
	Doctor& operator=(const Doctor& d)  {
		cout << "Am apelat operatorul de atribuire " << endl;
		if (this != &d) {
			if (this->garda != nullptr) {
				delete[] this->garda;

			}
			if (numeDoctor != "") {
				this->numeDoctor = d.numeDoctor;
			}
			else
				this->numeDoctor = "Nume Doctor";
			if (specializare != "") {
				this->specializare = d.specializare;

			}
			else
				this->specializare = "medicina";

			++nrDoctori;
			if (d.nrGarzi > 0 && d.garda != nullptr) {
				this->garda = new int(d.nrGarzi);
				for (int i = 0; i < d.nrGarzi; i++)
					this->garda[i] = d.garda[i];
			}
			else {
				this->nrGarzi = 0;
				this->garda = nullptr;
			}
		}
		return *this;
	
	}



};

class Medicament {
private:
	const int idMedicament;
	string numeMedicament;
	static int numarMedicamente;
	float dozaj;
	char* categorie;
	

};

class Consulatie {
private:
	const int codConsulatatie;
	static int nrConsulatii;
	string departament;
	int* tarife;
	int nrTarife;

};

int Doctor::nrDoctori = 0;

int main() {
	
	Doctor orto("Andrei", "Ortopedie", 5, new int[5] {6, 4, 8, 4,8});
	Doctor chir;
	Doctor bun("Felix");
	chir = orto;
	Doctor rau = orto;
	//functia statica pentru Doctori
	cout <<"Avem " << Doctor::getnrDoctori() << " Doctori "<< endl;


}