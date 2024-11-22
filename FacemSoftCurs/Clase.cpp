# include<iostream>
# include <string>

using namespace std;

class TelefonMobil {
	string producator;
	string model;
	

public:
	int nivelBaterie;
	TelefonMobil() {
		producator = "";
		model = "";
		nivelBaterie = 0;
		cout << "constructor implicit " << endl;
	}
	TelefonMobil(string _producator , string _model) : producator(_producator), model(_model), nivelBaterie(0) {

	}
	TelefonMobil(int _nivelBaterie) : TelefonMobil() {
		nivelBaterie = _nivelBaterie;

	}
	TelefonMobil(const TelefonMobil& t) {
		this->producator = t.producator;
		this->model = t.model;
		this->nivelBaterie = t.nivelBaterie - 1;
		cout << "se apeleaza constructor de copiere" << endl;


	}
	string getProducator() {
		return producator;
		
	}
	int getNivelBaterie() {
		return nivelBaterie;
	}

	void setNivelBaterie(int _nivelBaterie) {
		if (_nivelBaterie > 0 && nivelBaterie<=100) {
			nivelBaterie = _nivelBaterie;
		}
	}

	void descarca(int nivelBaterie);

	string getModel() {
		return model;
	}
	void setModel(string _model) {
		model = _model;

	}

	~TelefonMobil() {
		cout << "apel destructor" << endl;
	}
};

TelefonMobil incrementeazaNivelBaterie(TelefonMobil t) {
	t.nivelBaterie++;
	return t;

}
void TelefonMobil::descarca(int nivelBaterie) {
	this->nivelBaterie -= nivelBaterie;
}
int main() {
	TelefonMobil  telefonPersonal;
	
	

	TelefonMobil* pTelefon = new TelefonMobil;

	delete pTelefon;
	pTelefon = nullptr;

	TelefonMobil telefonDeServiciu("Samsung", "s20");
	pTelefon = new TelefonMobil("Apple", "Iphone 14");

	delete pTelefon;
	pTelefon = nullptr;
	TelefonMobil samsung = 60;

	TelefonMobil telefon5(samsung);
	TelefonMobil telefon6 = telefon5;
	incrementeazaNivelBaterie(telefon6);
	cout << telefonDeServiciu.getProducator() << endl;
	samsung.descarca(20);
	cout << samsung.getNivelBaterie() << endl;
	

}	