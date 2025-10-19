/*
NUME: Andrei Hirbu
INITIALE: A. H.
DOMENIU: Asamblare Hardware
*/

#include <iostream>
#include <cstring>

using namespace std;

class Procesor {
public:
	int numarNuclee;
	static int idProcesor;
	const float consum;
	char* socket;

	Procesor() : consum(45.5f) {
		this->numarNuclee = 2;

		this->socket = new char[strlen("LGA1151") + 1];
		strcpy_s(this->socket, strlen("LGA1151") + 1, "LGA1151");

		this->idProcesor++;
	}

	Procesor(const char* socket) : consum(25.6f) {
		this->numarNuclee = 4;

		this->socket = new char[strlen(socket) + 1];
		strcpy_s(this->socket, strlen(socket) + 1, socket);

		this->idProcesor++;
	}

	Procesor(const int numarNuclee, const char* socket) : consum(65.0f) {
		this->numarNuclee = numarNuclee;

		this->socket = new char[strlen(socket) + 1];
		strcpy_s(this->socket, strlen(socket) + 1, socket);

		this->idProcesor++;
	}

	static float calculareEficienta(const Procesor &p) {
		return p.consum / p.numarNuclee;
	}

	void afisareDetalii() {
		cout << "Procesor ID:  " << this->idProcesor << '\n';
		cout << "Numar Nuclee: " << this->numarNuclee << '\n';
		cout << "Consum:       " << this->consum << "W" << '\n';
		cout << "Socket:       " << this->socket << "\n\n";
	}
};

class PlacaDeBaza {
public:
	int numarSloturiRAM;
	static int idPlacaDeBaza;
	const float dimensiune;
	char* socketProcesor;

	PlacaDeBaza() : dimensiune(30.5f) {
		this->numarSloturiRAM = 2;

		this->socketProcesor = new char[strlen("LGA1151") + 1];
		strcpy_s(this->socketProcesor, strlen("LGA1151") + 1, "LGA1151");

		this->idPlacaDeBaza++;
	}

	PlacaDeBaza(const char* socketProcesor) : dimensiune(25.0f) {
		this->numarSloturiRAM = 4;

		this->socketProcesor = new char[strlen(socketProcesor) + 1];
		strcpy_s(this->socketProcesor, strlen(socketProcesor) + 1, socketProcesor);

		this->idPlacaDeBaza++;
	}

	PlacaDeBaza(const int numarSloturiRAM, const char* socketProcesor) : dimensiune(40.0f) {
		this->numarSloturiRAM = numarSloturiRAM;

		this->socketProcesor = new char[strlen(socketProcesor) + 1];
		strcpy_s(this->socketProcesor, strlen(socketProcesor) + 1, socketProcesor);

		this->idPlacaDeBaza++;
	}

	static bool verificaCompatibilitate(const Procesor& p, const PlacaDeBaza& pb) {
		return strcmp(p.socket, pb.socketProcesor) == 0;
	}

	void afisareDetalii() {
		cout << "Placa de Baza ID:    " << this->idPlacaDeBaza << '\n';
		cout << "Numar Sloturi RAM:   " << this->numarSloturiRAM << '\n';
		cout << "Dimensiune:          " << this->dimensiune << " cm2" << '\n';
		cout << "Socket Procesor:     " << this->socketProcesor << "\n\n";
	}
};

class SursaDeAlimentare {
public:
	int output;
	static int idSursa;
	const float eficienta;
	char* producator;

	SursaDeAlimentare() : eficienta(85.0f) {
		this->output = 500;

		this->producator = new char[strlen("Corsair") + 1];
		strcpy_s(this->producator, strlen("Corsair") + 1, "Corsair");

		this->idSursa++;
	}

	SursaDeAlimentare(const int output) : eficienta(90.0f) {
		this->output = output;

		this->producator = new char[strlen("EVGA") + 1];
		strcpy_s(this->producator, strlen("EVGA") + 1, "EVGA");

		this->idSursa++;
	}

	SursaDeAlimentare(const int output, const char* producator) : eficienta(92.0f) {
		this->output = output;

		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);

		this->idSursa++;
	}

	static float calculareConsum(const SursaDeAlimentare& s) {
		return s.output * (s.eficienta / 100);
	}

	void afisareDetalii() {
		cout << "Sursa de Alimentare ID: " << this->idSursa << '\n';
		cout << "Output:                 " << this->output << "W" << '\n';
		cout << "Eficienta:              " << this->eficienta << "%" << '\n';
		cout << "Producator:             " << this->producator << "\n\n";
	}
};

int Procesor::idProcesor = 0;
int PlacaDeBaza::idPlacaDeBaza = 0;
int SursaDeAlimentare::idSursa = 0;

int main() {
	Procesor p1;
	p1.afisareDetalii();

	Procesor p2("AM4");
	p2.afisareDetalii();

	Procesor p3(8, "LGA1200");
	p3.afisareDetalii();

	cout << "Eficienta Procesor p3: " << Procesor::calculareEficienta(p3) << " W/nucleu\n\n";

	PlacaDeBaza pb1;
	pb1.afisareDetalii();

	PlacaDeBaza pb2("AM4");
	pb2.afisareDetalii();

	PlacaDeBaza pb3(8, "LGA1200");
	pb3.afisareDetalii();

	cout << "Compatibilitate p3 si pb3: " << (PlacaDeBaza::verificaCompatibilitate(p3, pb3) ? "Da" : "Nu") << "\n\n";

	SursaDeAlimentare s1;
	s1.afisareDetalii();

	SursaDeAlimentare s2(650);
	s2.afisareDetalii();

	SursaDeAlimentare s3(750, "Seasonic");
	s3.afisareDetalii();

	cout << "Consum Sursa s3: " << SursaDeAlimentare::calculareConsum(s3) << " W\n";

	return 0;
}