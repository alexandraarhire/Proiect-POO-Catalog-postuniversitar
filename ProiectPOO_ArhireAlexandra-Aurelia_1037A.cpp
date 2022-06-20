#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include<fstream> //librarie pt fisiere text
#include<vector>
#include<set>
#include<map>
using namespace std;


class Catalog {

private:
	const int idCatalog;
	string nume;
	int nr_medii;
	float* medii;
	int nr_materii;
	string* materii;
	int nr_absente;
	static int contor;

public:

	//Constructor default
	Catalog() :idCatalog(contor++) {
		this->nume = "Anonim";
		this->nr_medii = 0;
		this->medii = NULL;
		this->nr_materii = 0;
		this->materii = NULL;
		this->nr_absente = 0;
	}

	//Constructor cu toti parametrii
	Catalog(string nume, int nr_medii, float* medii, int nr_materii, string* materii, int nr_absente) :idCatalog(contor++) {
		this->nume = nume;
		if (nr_medii > 0) {
			this->nr_medii = nr_medii;
		}
		else {
			this->nr_medii = 0;
		}
		this->medii = new float[this->nr_medii];

		for (int i = 0; i < this->nr_medii; i++) {

			this->medii[i] = medii[i];
		}
		if (nr_materii > 0) {
			this->nr_materii = nr_materii;
		}
		else {
			this->nr_materii = 0;
		}
		this->materii = new string[this->nr_materii];
		for (int i = 0; i < this->nr_materii; i++) {

			this->materii[i] = materii[i];
		}
		if (nr_absente > 0) {
			this->nr_absente = nr_absente;
		}
		else {
			this->nr_absente = 0;
		}
	}

	//Destructor
	~Catalog() {
		if (this->medii != NULL) {
			delete[]this->medii;
		}
		if (this->materii != NULL) {
			delete[]this->materii;
		}
	}

	//Constructorul de copiere
	Catalog(const Catalog& c) :idCatalog(c.idCatalog) {
		this->nume = c.nume;
		this->nr_medii = c.nr_medii;
		this->medii = new float[this->nr_medii];

		for (int i = 0; i < this->nr_medii; i++) {

			this->medii[i] = c.medii[i];
		}
		this->nr_materii = c.nr_materii;
		this->materii = new string[this->nr_materii];
		for (int i = 0; i < this->nr_materii; i++) {

			this->materii[i] = c.materii[i];
		}
		this->nr_absente = c.nr_absente;
	}

	//Operatorul =
	Catalog& operator=(const Catalog& c) {
		if (this != &c) {
			if (this->medii != NULL) {
				delete[]this->medii;
			}
			if (this->materii != NULL) {
				delete[]this->materii;
			}
			this->nume = c.nume;
			this->nr_medii = c.nr_medii;
			this->medii = new float[this->nr_medii];

			for (int i = 0; i < this->nr_medii; i++) {

				this->medii[i] = c.medii[i];
			}
			this->nr_materii = c.nr_materii;
			this->materii = new string[this->nr_materii];
			for (int i = 0; i < this->nr_materii; i++) {

				this->materii[i] = c.materii[i];
			}
			this->nr_absente = c.nr_absente;
		}
		return *this;
	}

	//Getteri

	string getNume() {
		return this->nume;
	}

	int getNr_medii() {
		return this->nr_medii;
	}

	float* getMedii() {
		return this->medii;
	}

	int getNr_materii() {
		return this->nr_materii;
	}

	string* getMaterii() {
		return this->materii;
	}

	int getNr_absente() {
		return this->nr_absente;
	}

	//setteri

	void setNume(string nume) {
		this->nume = nume;
	}

	void setNr_medii(int nr_medii) {
		this->nr_medii = nr_medii;
	}

	void setMedii(int nr_medii, float* medii) {
		if (this->medii != NULL) {
			delete[]this->medii;
		}
		this->nr_medii = nr_medii;
		this->medii = new float[this->nr_medii];
		for (int i = 0; i < this->nr_medii; i++) {
			this->medii[i] = medii[i];
		}
	}
	void setNr_materii(int nr_materii) {
		this->nr_materii = nr_materii;
	}

	void setMaterii(int nr_materii, string* materii) {
		if (this->materii != NULL) {
			delete[]this->materii;
		}
		this->nr_materii = nr_materii;
		this->materii = new string[this->nr_materii];
		for (int i = 0; i < this->nr_materii; i++) {
			this->materii[i] = materii[i];
		}
	}
	void setNr_absente(int nr_absente) {
		this->nr_absente = nr_absente;
	}



	//Operatorul <<
	friend ostream& operator<<(ostream& out, const Catalog& c) {
		out << "Id: " << c.idCatalog << endl;
		out << "Nume elev: " << c.nume << endl;
		out << "Numar de note: " << c.nr_medii << endl;
		out << "Note: ";
		for (int i = 0; i < c.nr_medii; i++) {
			out << c.medii[i] << " ";
		}
		out << endl;
		out << "Numar de materii: " << c.nr_materii << endl;
		out << "Materii: ";
		for (int i = 0; i < c.nr_materii; i++) {
			out << c.materii[i] << " ";
		}
		out << endl;
		out << "Numar de absente: " << c.nr_absente << endl;

		return out;
	}
	friend ofstream& operator<<(ofstream& out, const Catalog& c) {

		out << c.nume << endl;
		out << c.nr_medii << endl;
		for (int i = 0; i < c.nr_medii; i++) {
			out << c.medii[i] << " ";
		}
		out << endl;
		out << c.nr_materii << endl;

		for (int i = 0; i < c.nr_materii; i++) {
			out << c.materii[i] << " ";
		}

		out << c.nr_absente << endl;

		return out;
	}


	//Operator >>
	friend istream& operator>>(istream& in, Catalog& c) {
		if (c.medii != NULL) {
			delete[]c.medii;
		}
		if (c.materii != NULL) {
			delete[]c.materii;
		}
		cout << "Introduceti numele elevului: ";
		//in >> c.nume;//aici scriem doar un nume
		getline(in, c.nume);//aici putem scrie si doua nume, getline(in, c.nume,'\n'); pentru ca enter sa fie tasta de stop
		cout << "Introduceti numarul de medii: ";
		in >> c.nr_medii;
		c.medii = new float[c.nr_medii];
		cout << "Introduceti mediile materiilor:";
		for (int i = 0; i < c.nr_medii; i++) {
			in >> c.medii[i];
		}
		cout << "Introduceti numarul materiilor: ";
		in >> c.nr_materii;
		c.materii = new string[c.nr_materii];
		cout << "Introduceti materii: ";
		for (int i = 0; i < c.nr_materii; i++) {
			in >> c.materii[i];
		}
		cout << "Introduceti numar absente: ";
		in >> c.nr_absente;

		return in;
	}


	friend ifstream& operator>>(ifstream& in, Catalog& c) {
		if (c.medii != NULL) {
			delete[]c.medii;
		}
		if (c.materii != NULL) {
			delete[]c.materii;
		}

		//in >> c.nume;//aici scriem doar un nume
		getline(in, c.nume);//aici putem scrie si doua nume, getline(in, c.nume,'\n'); pentru ca enter sa fie tasta de stop

		in >> c.nr_medii;
		c.medii = new float[c.nr_medii];

		for (int i = 0; i < c.nr_medii; i++) {
			in >> c.medii[i];
		}

		in >> c.nr_materii;
		c.materii = new string[c.nr_materii];

		for (int i = 0; i < c.nr_materii; i++) {
			in >> c.materii[i];
		}

		in >> c.nr_absente;

		return in;
	}

	//Metoda medie medii
	float val_medie_anuala() {
		float medie = 0;
		float suma = 0;
		for (int i = 0; i < this->nr_materii; i++) {
			suma += this->medii[i];
		}
		medie = suma / nr_medii;
		return medie;
	}

	//Operator >
	bool operator >(Catalog c) {
		return this->nr_absente > c.nr_absente;
	}
	//Operatorul +=
	Catalog& operator +=(float c) {
		Catalog copie = *this;
		if (medii != NULL) {
			delete[]medii;
		}
		this->nr_medii = nr_medii + 1;
		this->medii = new float[this->nr_medii];

		for (int i = 0; i < this->nr_medii - 1; i++) {
			this->medii[i] = copie.medii[i];
		}
		this->medii[this->nr_medii - 1] = c;
		return *this;
	}

	//Operatorul !
	bool operator !() {
		if (this->nr_absente > 1)
		{
			return true;
		}
		else {
			return false;
		}
	}

	//Metoda
	bool areAbsente() {
		return this->nr_absente > 0;
	}

	//operator de cast la int 
	//returneaza mediia anuala
	operator int() {
		int suma = 0;
		for (int i = 0; i < this->nr_materii; i++) {
			suma = suma + this->medii[i];
		}
		return suma;
	}

	//Operatorul de indexare
	//returneaza media unei materii in functie de indexul dat

	float operator[](int index) {
		if (index >= 0 && index < this->nr_medii) {
			return this->medii[index];
		}
		else {
			return 0;
		}
	}
	//Operatorul &&
	bool operator&&(Catalog c) {
		return(this->nume == c.nume && this->nr_medii == c.nr_medii && this->nr_materii == c.nr_materii && this->nr_absente == c.nr_absente);
	}

	virtual string arataMesaj() {
		return"Acesta este un catalog!";
	}

	//Operator <
	bool operator <(const Catalog& c)const {
		return this->nr_absente < c.nr_absente;
	}

};
int Catalog::contor = 1;




class Liceu {
private:
	string nume_liceu;
	int nr_elevi;
	int nr_cataloage;
	Catalog* cataloage;
public:
	//Constructor default
	Liceu() {
		this->nume_liceu = "Necunoscut";
		this->nr_elevi = 0;
		this->nr_cataloage = 0;
		this->cataloage = NULL;
	}
	//Constructor cu toti parametrii
	Liceu(string nume_liceu, int nr_elevi, int nr_cataloage, Catalog* cataloage) {
		this->nume_liceu = nume_liceu;
		this->nr_elevi = nr_elevi;
		this->nr_cataloage = nr_cataloage;
		this->cataloage = new Catalog[this->nr_cataloage];
		for (int i = 0; i < this->nr_cataloage; i++) {
			this->cataloage[i] = cataloage[i];
		}
	}

	//Constructor de copiere
	Liceu(const Liceu& l) {
		this->nume_liceu = l.nume_liceu;
		this->nr_elevi = l.nr_elevi;
		this->nr_cataloage = l.nr_cataloage;
		this->cataloage = new Catalog[this->nr_cataloage];
		for (int i = 0; i < this->nr_cataloage; i++) {
			this->cataloage[i] = l.cataloage[i];
		}
	}

	//Destructor
	~Liceu() {
		if (this->cataloage != NULL) {
			delete[]this->cataloage;
		}
	}

	//Operatorul =
	Liceu& operator=(const Liceu& l) {
		if (this != &l) {
			if (this->cataloage != NULL) {
				delete[]this->cataloage;
			}
			this->nume_liceu = l.nume_liceu;
			this->nr_elevi = l.nr_elevi;
			this->nr_cataloage = l.nr_cataloage;
			this->cataloage = new Catalog[this->nr_cataloage];
			for (int i = 0; i < l.nr_cataloage; i++) {
				this->cataloage[i] = l.cataloage[i];
			}
		}
		return *this;
	}

	//Operator<<
	friend ostream& operator<<(ostream& out, const Liceu& l) {
		out << "Nume liceu: " << l.nume_liceu << endl;
		out << "Numar elevi: " << l.nr_elevi << endl;
		out << "Numar cataloage: " << l.nr_cataloage << endl;
		out << "Cataloage: " << endl;
		for (int i = 0; i < l.nr_cataloage; i++) {
			out << l.cataloage[i] << endl;
		}
		return out;
	}

	//operator +
	Liceu operator + (const Catalog& c) {
		bool existaInLiceu = 0;
		Liceu copie = *this;
		for (int i = 0; i < this->nr_cataloage; i++) {
			if (this->cataloage[i] && c) {
				existaInLiceu = 1;
			}
		}
		if (existaInLiceu == 0) {
			if (copie.cataloage != NULL) {
				delete[]copie.cataloage;
			}

			copie.nr_cataloage++;
			copie.cataloage = new Catalog[copie.nr_cataloage];
			for (int i = 0; i < copie.nr_cataloage; i++) {
				copie.cataloage[i] = this->cataloage[i];
			}
			copie.cataloage[copie.nr_cataloage - 1] = c;
		}
		return copie;
	}
	Liceu& operator +=(const Catalog& c) {
		bool existaInLiceu = 0;
		Liceu copie = *this;
		for (int i = 0; i < this->nr_cataloage; i++) {
			if (this->cataloage[i] && c) {
				existaInLiceu = 1;
			}
		}
		if (existaInLiceu == 0) {
			if (this->cataloage != NULL) {
				delete[]this->cataloage;
			}

			this->nr_cataloage++;
			this->cataloage = new Catalog[this->nr_cataloage];
			for (int i = 0; i < copie.nr_cataloage; i++) {
				this->cataloage[i] = copie.cataloage[i];
			}
			this->cataloage[this->nr_cataloage - 1] = c;
		}
		return *this;
	}

	Liceu operator - (const Catalog& c) {
		bool existaInLiceu = 0;
		Liceu copie = *this;
		for (int i = 0; i < this->nr_cataloage; i++) {
			if (this->cataloage[i] && c) {
				existaInLiceu = 1;
			}
		}
		if (existaInLiceu == 1) {

			if (copie.cataloage != NULL) {
				delete[]copie.cataloage;
			}

			copie.nr_cataloage--;
			copie.cataloage = new Catalog[copie.nr_cataloage];
			int pozitie = 0;
			for (int i = 0; i < this->nr_cataloage; i++) {
				if ((this->cataloage[i] && c) == false) {
					copie.cataloage[pozitie] = this->cataloage[i];
					pozitie++;
				}
			}
		}
		return copie;
	}

	Liceu& operator -= (const Catalog& c) {
		bool existaInLiceu = 0;
		Liceu copie = *this;
		for (int i = 0; i < this->nr_cataloage; i++) {

			if (this->cataloage[i] && c) {
				existaInLiceu = 1;
			}
		}

		if (existaInLiceu == 1) {

			if (this->cataloage != NULL) {
				delete[]this->cataloage;
			}

			this->nr_cataloage--;
			copie.cataloage = new Catalog[copie.nr_cataloage];
			int pozitie = 0;
			for (int i = 0; i < copie.nr_cataloage; i++) {
				if ((copie.cataloage[i] && c) == false) {
					this->cataloage[pozitie] = copie.cataloage[i];
					pozitie++;
				}
			}
		}
		return *this;
	}

	Catalog operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < this->nr_cataloage) {
			return this->cataloage[pozitie];
		}
		else {
			Catalog c;
			return c;
		}
	}

	Catalog operator[](string nume) {//daca elevul respectiv este in catalog
		bool gasit = 0;
		for (int i = 0; i < this->nr_cataloage; i++) {
			if (nume == this->cataloage[i].getNume()) {
				gasit = 1;
				return this->cataloage[i];
			}
		}
		if (gasit == 0) {
			Catalog c;
			return c;
		}
	}
	bool operator!() {
		return this->nr_cataloage == 0;
	}

};



class CatalogElectronic :public Catalog {
protected:
	int nr_accesari;
	bool stareVizualizareMedii; //arata daca mediile au fost vizualizate sau  nu de catre utilizator 1-vizualizat 0-nevizualizat inca

public:
	//Constructorul default
	CatalogElectronic() :Catalog() {

		this->nr_accesari = 0;
		this->stareVizualizareMedii = false;
	}
	//Constructorul cu toti parametrii
	CatalogElectronic(string nume, int nr_medii, float* medii, int nr_materii, string* materii, int nr_absente, int nr_accesari, bool stareVizualizareMedii) :Catalog(nume, nr_medii, medii, nr_materii, materii, nr_absente) {
		this->nr_accesari = nr_accesari;
		this->stareVizualizareMedii = stareVizualizareMedii;
	}

	//Constructorul de copiere
	CatalogElectronic(const CatalogElectronic& e) :Catalog(e) {
		this->nr_accesari = e.nr_accesari;
		this->stareVizualizareMedii = e.stareVizualizareMedii;
	}
	//Destructorul (nu avem atribute alocate dinamic)
	~CatalogElectronic() {

	}

	//Operatorul =
	CatalogElectronic& operator=(const CatalogElectronic& e) {
		Catalog::operator=(e);
		this->nr_accesari = e.nr_accesari;
		this->stareVizualizareMedii = e.stareVizualizareMedii;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const CatalogElectronic& e) {
		out << (Catalog&)e;
		out << "Numar accesari: " << e.nr_accesari << endl;
		out << "Mediile au fost vizualizate? (1-Da sau 0-Nu): " << e.stareVizualizareMedii << endl;
		return out;
	}
	string arataMesaj() {
		return"Acesta este un catalog electronic!";
	}

};

class Arhiva {
private:
	string director;//numele directorului liceului in care se afla cataloagele arhivate
	int nr_cataloage;
	Catalog** cataloage;
public:
	//constructor fara parametrii
	Arhiva() {
		this->director = "Necunoscut";
		this->nr_cataloage = 0;
		this->cataloage = NULL;
	}
	//constructor cu toti parametrii
	Arhiva(string director, int nrCataloage, Catalog** cataloage) {
		this->director = director;
		this->nr_cataloage = nr_cataloage;
		this->cataloage = new Catalog * [this->nr_cataloage];
		for (int i = 0; i < this->nr_cataloage; i++) {
			this->cataloage[i] = new Catalog(*cataloage[i]);
		}
	}
	//constructor de copiere
	Arhiva(const Arhiva& a) {
		this->director = a.director;
		this->nr_cataloage = a.nr_cataloage;
		this->cataloage = new Catalog * [this->nr_cataloage];
		for (int i = 0; i < this->nr_cataloage; i++) {
			this->cataloage[i] = new Catalog(*a.cataloage[i]);
		}
	}

	//destructor
	~Arhiva() {
		if (this->cataloage != NULL) {
			for (int i = 0; i < this->nr_cataloage; i++) {
				delete this->cataloage[i];
			}
			delete[]this->cataloage;
		}
	}
	//Operator<<
	friend ostream& operator<<(ostream& out, const Arhiva& a) {
		out << "Nume director: " << a.director << endl;
		out << "Numar cataloage: " << a.nr_cataloage << endl;
		out << "Cataloage: " << endl;
		for (int i = 0; i < a.nr_cataloage; i++) {
			out << *a.cataloage[i] << endl;
		}
		return out;
	}
};

//clasa template
template <typename tipulClaselor>
class gestiuneClase {
	int nrObiecte;
	tipulClaselor* elemente;
public:
	//constructor default
	gestiuneClase() {
		this->nrObiecte = 0;
		this->elemente = NULL;
	}

	//constructor cu toti parametrii
	gestiuneClase(int nrObiecte, tipulClaselor* elemente) {
		this->nrObiecte = nrObiecte;
		this->elemente = new tipulClaselor[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++) {
			this->elemente[i] = elemente[i];
		}
	}
	//Constructorul de copiere
	gestiuneClase(const gestiuneClase& g) {
		this->nrObiecte = g.nrObiecte;
		this->elemente = new tipulClaselor[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++) {
			this->elemente[i] = g.elemente[i];
		}
	}
	//destructor
	~gestiuneClase() {
		if (this->elemente != NULL) {
			delete[]this->elemente;
		}
	}
	//operatorul =
	gestiuneClase& operator=(const gestiuneClase& g) {
		if (this != g) {
			if (this->elemente != NULL) {
				delete[]this->elemente;
			}
			this->nrObiecte = g.nrObiecte;
			this->elemente = new tipulClaselor[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++) {
				this->elemente[i] = g.elemente[i];
			}
		}
		return *this;
	}

	//Operator<<
	friend ostream& operator<<(ostream& out, const gestiuneClase& g) {
		out << g.nrObiecte << endl;
		for (int i = 0; i < g.nrObiecte; i++) {
			out << g.elemente[i] << endl;
		}
		return out;
	}

	void adaugaObiect(tipulClaselor obj) {
		gestiuneClase copie = *this;
		delete[]this->elemente;
		this->nrObiecte++;
		this->elemente = new tipulClaselor[this->nrObiecte];
		for (int i = 0; i < copie.nrObiecte; i++) {
			this->elemente[i] = copie.elemente[i];
		}
		this->elemente[this->nrObiecte - 1] = obj;
	}

};

int main() {
	//Testare constructor fara parametrii si getteri
	Catalog c;
	cout << "Nume elev: " << c.getNume() << endl;
	cout << "Numar de note:" << c.getNr_medii() << endl;
	for (int i = 0; i < c.getNr_medii(); i++) {
		cout << "Note: " << c.getMedii() << endl;
	}
	cout << "Numarul materiilor:" << c.getNr_materii() << endl;
	for (int i = 0; i < c.getNr_materii(); i++) {
		cout << "Materii: " << c.getMaterii() << endl;
	}
	cout << "Numar de absente:" << c.getNr_absente() << endl;
	cout << "-------------------" << endl;
	//Testare setteri
	cout << "Setteri: " << endl;
	float medii[]{ 10, 9, 8, 7 };
	string materii[]{ "Sport","Matematica","Engleza","Biologie" };
	c.setNume("Ionel");
	c.setNr_medii(4);
	c.setMedii(4, medii);
	c.setNr_materii(4);
	c.setMaterii(4, materii);
	c.setNr_absente(3);
	cout << c;
	cout << "-------------------" << endl;
	//Testare constructor cu toti parametrii
	Catalog c1("Tatiana", 3, new float[] {10, 6, 7}, 3, new string[]{ "Desen","Matematica","Limba Romana" }, 3);
	cout << c1;
	//Testarea constructorului de copiere
	cout << "-------------------" << endl;
	cout << "Constructor de copiere: " << endl;
	Catalog c2 = c;
	cout << c2;
	cout << "-------------------" << endl;
	cout << "Operatorul =" << endl;
	c1 = c1;
	cout << "Operatorul de afisare <<" << endl;
	cout << c1 << endl;
	cout << "-------------------" << endl;
	cout << "Operatorul de scriere >>" << endl;
	/*cin >> c1;*/
	//Metoda calculare medie anuala
	cout << "-------------------" << endl;
	cout << "Metoda medie anuala: " << endl;
	cout << c1.val_medie_anuala() << endl;
	cout << "-------------------" << endl;
	Catalog c3("Marian", 5, new float[] {10, 6, 7, 9, 5}, 5, new string[]{ "Desen","Matematica","Limba Romana","Istorie","Geografie" }, 7);
	Catalog c4("Iulia", 4, new float[] {10, 6, 7, 8}, 4, new string[]{ "Desen","Matematica","Limba Romana","Limba Franceza" }, 0);
	cout << "Operatorul >" << endl;
	cout << (c3 > c4) << endl;
	cout << "-------------------" << endl;
	//Operator +=
	cout << "Operatorul +=" << endl;
	float mediii[]{ 10,7,8,6 };
	string materiii[]{ "Istorie","Desen","Muzica","Biologie" };
	Catalog c5("Maria", 4, mediii, 4, materiii, 2);
	c5 += 7;
	cout << c5 << endl;
	cout << "-------------------" << endl;
	//Operator !
	cout << "Operatorul !" << endl;//daca are sau nu absente
	if (!c4)
		cout << "Are absente" << endl;
	else
		cout << "Nu are absente" << endl;
	//Metoda are absente
	cout << "-------------------" << endl;
	cout << "Metoda are absente" << endl;
	cout << c3.areAbsente() << endl;
	//Operator cast la int
	cout << "-------------------" << endl;
	cout << "Operator cast la int " << endl;
	cout << (int)c5 << endl;
	//operator indexare
	cout << "Operatorul de indexare " << endl;
	cout << c4[2];
	//operator &&
	cout << "-------------------" << endl;
	cout << "Operator &&" << endl;
	Catalog c6(c4);
	cout << (c6 && c4) << endl;
	cout << (c2 && c4) << endl;
	cout << c2 << endl;
	cout << c4 << endl;
	cout << "||||||||||||||||||||||||||||LICEU||||||||||||||||||||||||||||" << endl << endl << endl;
	Catalog vectCataloage[4] = { c1,c3,c4,c5 };
	//Testare constructor default
	Liceu l;
	cout << l << endl;
	//Testare constructor cu toti parametrii
	Liceu l1("Teoretic Constantin Angelescu", 150, 4, vectCataloage);
	Catalog c7("Maricica", 6, new float[] {10, 6, 7, 9, 5, 9}, 6, new string[]{ "Desen","Matematica","Limba Romana","Istorie","Geografie","Logica" }, 7);
	cout << l1 << endl;
	//Operatorul +
	cout << "-------------------" << endl;
	cout << "Operator ++ " << endl;
	l1 = l1 + c5;
	cout << l1 << endl;
	cout << "-------------------" << endl;
	cout << "Operator += " << endl;
	//Operatorul +=
	l1 += c7;
	cout << l1 << endl;
	//Operatorul -
	cout << "-------------------" << endl;
	cout << "Operator - " << endl;
	l1 = l1 - c7;
	cout << l1 << endl;
	//Operatorul -=
	cout << "-------------------" << endl;
	cout << "Operator -= " << endl;
	l1 -= c7;
	cout << l1 << endl;
	//Operatorul []
	cout << "-------------------" << endl;
	cout << "Operatorul[] care va returna catalogul de pe pozitia data" << endl;
	cout << l1[0] << endl;
	cout << "-------------------" << endl;
	//Operatorul []
	cout << "Operatorul[] care va returna catalogul care are studentul cu numele dat" << endl;
	cout << l1["Marian"] << endl;
	cout << "-------------------" << endl;
	//Operatorul !
	cout << "operatorul ! care returneaza valoarea true daca nu exista cataloage in liceu. " << endl;
	cout << !l << endl;
	cout << !l1 << endl;
	cout << "||||||||||||||||||||||||||||CATALOG ELECTRONIC||||||||||||||||||||||||||||" << endl << endl << endl;
	CatalogElectronic e;
	cout << e.getNume() << endl;
	e.setNume("George");
	cout << e.getNume() << endl;
	//Apelare constructor cu toti parametrii
	CatalogElectronic e1("Valeriu", 3, new float[] {8, 9, 7}, 3, new string[]{ "Fizica","Chimie","Istorie" }, 8, 4, true);
	CatalogElectronic e2("Mihaita", 4, new float[] {8, 9, 7, 8}, 4, new string[]{ "Fizica","Chimie","Istorie","Economie" }, 8, 0, false);
	cout << e1 << endl;
	cout << e2 << endl;
	//Apelare constructor de copiere
	CatalogElectronic e3 = e2;
	cout << e3 << endl;
	//Apelare operator egal
	cout << "Operatorul = " << endl;
	e3 = e2;
	cout << e3 << endl;
	cout << "~~~~~~~~~~~FISIERE~~~~~~~~~~~~" << endl;
	cout << "Operatorul de scriere >>" << endl;
	/*cin >> c;
	cout << c << endl;*/
	cout << "Operatorul de afisare in fisier op<< pt fisiere: " << endl;
	//Scrierea intr-un fisier text
	ofstream f("exemplu.txt", ios::out);
	/*f << c << endl;
	f.close();*/
	cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Operatorul de citire din fisier op>> pt fisiere: " << endl;
	ifstream g("test.txt", ios::in);
	Catalog c8;
	if (g.is_open()) {

		g >> c8;
		cout << "S-a citit din fisier!" << endl;
	}
	else {
		cout << "Fisierul cautat nu exista!" << endl;
	}

	cout << "-------------------" << endl;
	cout << c8 << endl;
	cout << "-------------------" << endl;
	//Apelare metoda
	cout << "METODA functie virtuala" << endl;
	cout << e1.arataMesaj() << endl;
	cout << c7.arataMesaj() << endl;
	cout << endl << endl;
	Catalog* pt = new Catalog(c7);
	Catalog* pt1 = new CatalogElectronic(e1);

	cout << pt->arataMesaj() << endl;
	cout << pt1->arataMesaj() << endl;
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
	cout << endl << endl << endl;
	cout << "Compunere (HAS A)" << endl;
	Arhiva a;
	cout << a << endl;
	Arhiva a1("Ghelase Emilia", 2, new Catalog * [2]{ &c3,&e2 });
	cout << a1;
	cout << "==============CLASA TEMPLATE=============" << endl;
	gestiuneClase<Catalog> gest(2, new Catalog[2]{ c5,c7 });
	gest.adaugaObiect(c8);
	cout << gest << endl;
	cout << "-------------------" << endl;
	cout << endl << endl << endl;
	gestiuneClase<Liceu> gest1(2, new Liceu[2]{ l,l1 });
	gest1.adaugaObiect(l1);
	cout << gest1 << endl;
	cout << "-------------------" << endl;
	cout << endl << endl << endl;
	gestiuneClase<CatalogElectronic> gest2(2, new CatalogElectronic[2]{ e1,e2 });
	gest2.adaugaObiect(e1);
	cout << gest2 << endl;
	cout << endl << endl << endl;
	cout << "*********************STL(Standard Template Library)*********************" << endl;
	cout << "/////////////////////////////Container SECVENTIAL STL" << endl;
	float mediile [] = {10, 6, 7, 9, 9, 5, 8, 9};
	string materiile[] ={ "Limba Romana","Istorie","Geografie","Logica","Sport","Limba Engleza","Limba latina","Economie" };
	Catalog ca("Maria", 4, mediile, 4, materiile, 7);
	Catalog ca1("Ion", 3, mediile, 3, materiile, 17);
	Catalog ca2("Cosmin", 2, mediile, 2, materiile, 10);
	Catalog ca3("Viorel", 3, mediile, 3, materiile, 23);
	Catalog ca4("Gina", 5,mediile , 5, materiile, 5);
	vector<Catalog> vectSTLCataloage; //vector pentru cataloage
	//populare vector STL
	vectSTLCataloage.push_back(ca);
	vectSTLCataloage.push_back(ca1);
	vectSTLCataloage.push_back(ca2);
	vectSTLCataloage.push_back(ca3);
	vectSTLCataloage.push_back(ca4);
	cout << "-------------------" << endl;
	//afisare nr de elemente din vector
	cout << vectSTLCataloage.size() << endl << endl;
	//afisare elemente vector
	for (int i = 0; i < vectSTLCataloage.size(); i++) {
		cout << vectSTLCataloage[i] << endl;
	}
	cout << "-------------------" << endl;
	//eliminare ultimul element
	vectSTLCataloage.pop_back();
	// iterator
	vector<Catalog>::iterator vit;
	for (vit = vectSTLCataloage.begin(); vit != vectSTLCataloage.end(); vit++) {
		cout << *vit << endl << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << "/////////////////////////////Container ASOCIATIV STL" << endl;
	cout << "-----------------SET----------------------" << endl;
	set<Catalog> setSTLCataloage;
	setSTLCataloage.insert(ca);
	setSTLCataloage.insert(ca1);
	setSTLCataloage.insert(ca2);
	setSTLCataloage.insert(ca3);
	setSTLCataloage.insert(ca4);

	set<Catalog>::iterator sit;
	for (sit = setSTLCataloage.begin(); sit != setSTLCataloage.end(); sit++) {
		cout << *sit << endl << endl;
	}
	cout << "-----------------MAP----------------------" << endl<<endl;
	map<int, Catalog>mapSTLCatalog;
	mapSTLCatalog.insert(pair<int, Catalog>(ca.getNr_absente(), ca));
	mapSTLCatalog.insert(pair<int, Catalog>(ca1.getNr_absente(), ca1));
	mapSTLCatalog.insert(pair<int, Catalog>(ca2.getNr_absente(), ca2));
	mapSTLCatalog.insert(pair<int, Catalog>(ca3.getNr_absente(), ca3));
	mapSTLCatalog.insert(pair<int, Catalog>(ca4.getNr_absente(), ca4));
	map<int,Catalog>::iterator mit;
	for (mit = mapSTLCatalog.begin(); mit != mapSTLCatalog.end(); mit++) {
		cout << mit->first << endl << endl;
		cout << mit->second << endl << endl;
	}

}