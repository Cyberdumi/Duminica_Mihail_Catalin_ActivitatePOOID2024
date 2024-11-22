#include<iostream>
#include<string>
using namespace std;

class Doctor {
private:
	string numeDoctor;
	const int idDoctor;
	static int nrDoctori;
	string specializare;
	int nrGarzi ;
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
	Doctor(string numeDoctor, string specializare, int nrGarzi,   int* garda) :idDoctor(++nrDoctori) {
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
			this->nrGarzi = nrGarzi;
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
			this->nrGarzi = d.nrGarzi;
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
			
				this->numeDoctor = d.numeDoctor;
			
				this->specializare = d.specializare;
		 	  ++nrDoctori;
				this->nrGarzi = d.nrGarzi;	
				this->garda = new int[d.nrGarzi];
				for (int i = 0; i < d.nrGarzi; i++)
					this->garda[i] = d.garda[i];
			
			
		}
		return *this;
	
	}

	int& operator[](int index) {
		if (index >= 0 && index < nrGarzi) {
			return garda[index];
		}
	}



};

class Medicament {
private:
	const int idMedicament;
	string numeMedicament;
	static int numarMedicamente;
	float dozaj;
	char* categorie;
public:
	Medicament():idMedicament(++numarMedicamente) {
		this->numeMedicament = "Paracetamol";
		this->dozaj = 100;
		this->categorie = new char[strlen("Generic") + 1];
		strcpy_s(this->categorie, strlen("Generic") + 1, "Generic");


	}
	Medicament(string numeMedicament, float dozaj, char* categorie) :idMedicament(++numarMedicamente) {
		this->numeMedicament = numeMedicament;
		this->dozaj = dozaj;
		this->categorie = new char[strlen(categorie) + 1];
		strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
		

	}
	Medicament(const Medicament& m) :idMedicament(++numarMedicamente) {
		this->numeMedicament = m.numeMedicament;
		this->dozaj = m.dozaj;
		this->categorie = new char[strlen(m.categorie) + 1];
		strcpy_s(this->categorie, strlen(m.categorie) + 1, m.categorie);

	}
	void setDozaj(float dozaj) {
		this->dozaj = dozaj;
	}
	float getDozaj() {
		return this->dozaj;
	}
	~Medicament() {
		if (categorie != nullptr) {
			delete[]this->categorie;
			
		}
	}
	Medicament operator=(const Medicament& m) {
		if (this != &m) {
			if (categorie != nullptr) {
				delete[]this->categorie;

			}
			this->numeMedicament = m.numeMedicament;
			this->dozaj = m.dozaj;
			this->categorie = new char[strlen(m.categorie) + 1];
			strcpy_s(this->categorie, strlen(m.categorie) + 1, m.categorie);

		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, Medicament m) {
		out << "Afiseaza medicamentele " << m.categorie << " " << m.dozaj << " " << m.idMedicament << " " << m.numarMedicamente << " " << m.numeMedicament << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Medicament& m) {
		cout << "Citeste medicamente aici ";
		in >> m.dozaj >> m.categorie >> m.numeMedicament;
		return in;
	}
	friend bool operator<(Medicament m1, Medicament m2) {
		if (m1.dozaj < m2.dozaj)
			return true;
		else
			return false;
	}
	friend bool operator==(Medicament m1, Medicament m2) {
		if (m1.dozaj == m2.dozaj) {
			return true;

		}
		else
			return false;
	}
	friend bool operator>(Medicament m1, Medicament m2) {
		if (m1.dozaj > m2.dozaj)
			return true;
		else
			return false;
	}
	friend Medicament operator+ (float valoare, Medicament medicament) {
		Medicament aux = medicament;
		aux.dozaj = medicament.dozaj + valoare;
		return aux;
	}
	friend Medicament operator+ (Medicament medicament, float valoare) {
		Medicament aux = medicament;
		aux.dozaj = medicament.dozaj + valoare;
		return aux;
	}
	friend Medicament operator/(float valoare, Medicament medicament) {
		Medicament aux = medicament;
		aux.dozaj = valoare / medicament.dozaj;
		return aux;
	}
	friend Medicament operator/(Medicament medicament, float valoare) {
		Medicament aux = medicament;
		aux.dozaj =medicament.dozaj / valoare;
		return aux;
	}

	Medicament operator++() {
		this->dozaj++;
		return *this;
	}

	Medicament operator++(int) {
		Medicament copie = *this;
		this->dozaj++;
		return copie;
	}

	explicit operator int() {
		return dozaj;
	}
	Medicament* operator->() {
		this->dozaj = 1000;
		return this;
	}
	float operator()() {
		float suma = dozaj + 450;
		return suma;
	}
	float operator()(int n) {
		float suma = dozaj + n;
		return suma;
	}
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
int Medicament::numarMedicamente = 0;

int main() {

	int* garda = new int[5] {8, 8, 4, 8, 5};
	Doctor orto("Andrei", "Ortopedie", 5,garda);
	Doctor chir;
	Doctor bun("Felix");
	chir = orto;
	Doctor rau = orto;
	//functia statica pentru Doctori
	cout <<"Avem " << Doctor::getnrDoctori() << " Doctori "<< endl;
	char* medicament = new char[strlen("Generic") + 1];
	strcpy_s(medicament, strlen("Generic") + 1, "Generic");
	Medicament medi("Atrosulfur", 250.20, medicament);
	cout << medi << endl;
	// cin >> medi;
	Medicament pastila("Rumalaya", 120.20, medicament);

	delete[] medicament;
	delete[] garda;
	if (pastila > medi) {
		cout << "Pastila mai mare decat medi" << endl;
	}
	else
		cout << "Pastila mai mica" << endl;
	if (pastila < medi) {
		cout << "Pastila  2 mai mica" << endl;
	}
	else
		cout << "Pastila 2 mai mare " << endl;
	if (pastila == medi) {
		cout << "Sunt egale" << endl;
		
	}
	else
		cout << "NU sunt egale" << endl;
	Medicament med3;
	cout << med3 << endl;
	cout << 15 + med3;
	cout << med3 + 15;
	cout << 10 / med3;
	++med3;
	cout << endl;
	cout << "operatorul de index " << orto[2] << endl;
	int noulDozajExplicit = (int)med3;
	cout << noulDozajExplicit;
	Medicament med5;
	med5.setDozaj(1);
	cout << med5->getDozaj();
	float suma = med5();
	cout << endl;
	cout << suma;
	cout << med5(123);


}