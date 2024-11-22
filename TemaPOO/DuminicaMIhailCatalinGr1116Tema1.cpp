
#include <iostream>
#include<string.h>
using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:
	Autobuz():idAutobuz(0) {
		cout << "S-a apelat constructorul fara parametrii" << endl;
	
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->producator = new char[strlen("Publitrans") + 1];
		strcpy_s(this -> producator, strlen("Publitrans") + 1, "Publitrans");

	}
	Autobuz(int id, int capacitate, int nrPersoaneImbarcate, char* producator) :idAutobuz(id) {
		cout << "S-a apelat contructorul cu parametrii" << endl;
		if (capacitate >= 0) {
			this->capacitate = capacitate;
		}
		else
			this->capacitate = 0;
		if (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		else
			this->nrPersoaneImbarcate = 0;
		if (producator != nullptr && strlen(producator) >= 0) {
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator,strlen(producator)+1,producator);

		}
		else
			this->producator = nullptr;

	}
	Autobuz(const Autobuz& a) :idAutobuz(a.idAutobuz) {
		cout << "S-a apelat constructorul de copiere" << endl;

		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		if (a.producator != nullptr && strlen(a.producator) >= 0) {
			this->producator = new char[strlen(a.producator) + 1];
			strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
		}
		else
			this->producator = nullptr;
	}
	void setCapacitate(int capacitate) {
		if (capacitate >= 0) {
			this->capacitate = capacitate;
		}
		else {
			this->capacitate = 0;
		}
	}
	int getCapacitate() {
		return this->capacitate;
	}

	void setnrPersoaneImbarcate(int nrPersoaneImbarcate) {
		if (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		else {
			this->nrPersoaneImbarcate = 0;
		}
	}
	int getnrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	char* getProducator() {
		return this->producator;
	}
	
	const int getId() {
		return this->idAutobuz;
	}

	static int getnrAutobuze() {
		return nrAutobuze;
	}
	static void setnrAutobuze(int nrAutobuze) {
		Autobuz::nrAutobuze = nrAutobuze;
	 }

	~Autobuz() {
		if(this->producator != nullptr)
			delete[] producator;
	}

	Autobuz& operator=(const Autobuz& a) {
		cout << "S-a apelat operatorul de atribuire " << endl;
		if (this != &a) {
			if (producator != nullptr)
				delete[] producator;

			this->capacitate = a.capacitate;
			this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
			if (a.producator != nullptr && strlen(a.producator) >= 0) {
				producator = new char[strlen(a.producator) + 1];
				strcpy_s(producator, strlen(a.producator) + 1, a.producator);
			}
			else
				producator = nullptr;
		}
		return *this;

	}

	int getNumarLocuriLibere() {
		int locuriLibere = this->capacitate - this->nrPersoaneImbarcate;
		cout << "Am apelat metoda getNumarLocuriLibere" << endl;
		return locuriLibere;
	}
	
	operator int() {
		return nrPersoaneImbarcate;
	}
	
	friend ostream& operator<<(ostream& oStream, Autobuz autobuz);
	friend bool operator>(Autobuz, Autobuz);
};
bool operator>(Autobuz a, Autobuz b) {
	if (a.getCapacitate() > b.getCapacitate())
		return true;
	return false;

}
ostream& operator<<(ostream& oStream, Autobuz autobuz) {
	oStream << autobuz.getnrAutobuze() <<"; " << autobuz.getId()<<"; " << autobuz.getCapacitate()<<"; " << autobuz.getnrPersoaneImbarcate()<<"; " << autobuz.getProducator() << endl;

	return oStream;
}

int Autobuz::nrAutobuze = 15;

int main() {
	Autobuz bus;
	bus.setCapacitate(100);
	cout << "Capacitatea lui bus " << bus.getCapacitate() << endl;
	bus.setnrPersoaneImbarcate(90);
	cout << "Numarul de persoane din bus" << bus.getnrPersoaneImbarcate() << endl;
	cout << "Locurile libere din bus" << bus.getNumarLocuriLibere() << endl;
	char* nume = new char[strlen("Publitrans") + 1];
	strcpy_s(nume, strlen("Publitrans") + 1, "Publitrans");
	Autobuz stb(1, 100, 60, nume);
	Autobuz maxitaxi = stb;
	Autobuz microbuz;
	microbuz = maxitaxi;

	cout<<"Numarul de locuri libere este "<< stb.getNumarLocuriLibere() << endl;

	stb.setnrAutobuze(20);
	cout << "Elementele obiectului stb sunt " << stb << endl;
	int persoaneUrcate = stb; 
	cout << "Numarul de persoane urcate este " << persoaneUrcate << endl;
	if (stb > bus) {
		cout << "Stb are capacitatea mai mare" << endl;
	}
	else
		cout << "Bus are capacitatea mai mare" << endl;


	delete[] nume;



	
	


}