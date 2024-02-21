#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<sstream>

using namespace std;


class IFile {
	virtual void saveToFile(fstream& file) = 0;
	virtual void restoreFromFile(fstream& file) = 0;
};
class MateriePrima:IFile
{
private:
	char* numeMateriep = nullptr;
	float cantitateStocTotal = 0; //in grame
	int durataExp = 0; //zile

public:

	//CONSTRUCTORUL FARA PARAM
	MateriePrima()
	{}



	//FUNCTII ACCESOR

	void setNumeMateriep(const char* numeMateriep)
	{

		if (numeMateriep != nullptr)
		{
			delete[]this->numeMateriep;
			this->numeMateriep = new char[strlen(numeMateriep) + 1];
			strcpy(this->numeMateriep, numeMateriep);
		}

	}
	

	const char* getNumeMateriep() const
	{
		return this->numeMateriep;
	}

	void setCantitateStocTotal(float cantitateStocTotalNou)
	{
		if (cantitateStocTotalNou > 0)
		{
			this->cantitateStocTotal = cantitateStocTotalNou;
		}
	}

	float& getCantitateStocTotal()
	{
		return this->cantitateStocTotal;
	}

	void setDurataExp(int durataExp)
	{
		if (durataExp > 0 && durataExp < 30)
		{
			this->durataExp = durataExp;
		}
	}

	int getDurataExp()
	{
		return this->durataExp;
	}


	//cast la string
	operator string()
	{
		return this->numeMateriep;
	}

	//METODE DE AFISARE SI PRELUCRARE A ATRIBUTELOR
	//METODA DE AFISARE
	void afisareMateriePrima()
	{
		if (this->numeMateriep != nullptr)
		{
			cout << "Numele materiei prime este: " << this->numeMateriep;
		}
		else
		{
			cout << "Numele materiei prime este:-";
		}
		if (this->cantitateStocTotal > 0)
		{


			cout << "\nStocul total al materiei prime este: " << this->cantitateStocTotal;
		}
		else
		{
			cout << "\nStocul total al materiei prime este:- ";
		}

		if (this->durataExp > 0)
		{
			cout << "\nDurata de expirare a materiei prime este de: " << this->durataExp << "zile";

		}
		else
		{
			cout << "\nMateria prima nu are data de expirare";

		}
	}

	//METODA DE PRELUCRARE
	void CantitateaStoc1(float cantitateStoc1)
	{
		if (cantitateStoc1 > 0 && cantitateStoc1 <= this->cantitateStocTotal)
		{
			this->cantitateStocTotal -= cantitateStoc1;
			//cout << this->cantitateStocTotal;
		}
	}

	//CONSTRUCTOR CU  TOTI PARAMETRII
	MateriePrima(const char* numeMateriep, float cantitateStocTotal, int durataExp)
	{
		if (numeMateriep != nullptr)
		{
			this->numeMateriep = new char[strlen(numeMateriep) + 1];
			strcpy(this->numeMateriep, numeMateriep);
		}

		if (cantitateStocTotal > 0)
		{
			this->cantitateStocTotal = cantitateStocTotal;
		}

		if (durataExp > 0)
		{
			this->durataExp = durataExp;
		}

	}

	//CONSTRUCTOR CU UN PARAMETRU
	MateriePrima(const char* numeMateriep)
	{
		if (numeMateriep != nullptr)
		{
			this->numeMateriep = new char[strlen(numeMateriep) + 1];
			strcpy(this->numeMateriep, numeMateriep);
		}
	}

	//CONSTRUCTORUL DE COPIERE
	MateriePrima(const MateriePrima& m)
	{
		if (m.numeMateriep != nullptr)
		{
			this->numeMateriep = new char[strlen(m.numeMateriep) + 1];
			strcpy(this->numeMateriep, m.numeMateriep);
		}

		this->cantitateStocTotal = m.cantitateStocTotal;
		this->durataExp = m.durataExp;
	}


	//OP =
	MateriePrima& operator=(const MateriePrima& m)
	{
		if (this != &m)
		{
			delete[]this->numeMateriep;
			this->numeMateriep = nullptr;


			if (m.numeMateriep != nullptr)
			{
				this->numeMateriep = new char[strlen(m.numeMateriep) + 1];
				strcpy(this->numeMateriep, m.numeMateriep);
			}
			this->cantitateStocTotal = m.cantitateStocTotal;
			this->durataExp = m.durataExp;

		}
		return *this;
	}

	//op<<
	friend ostream& operator<<(ostream& out, const MateriePrima& m)
	{

		if (m.numeMateriep != nullptr)
		{
			out << m.numeMateriep;

		}
		else
		{
			out << "\nMateria prima este:-";
		}
		out << "\nCantitatea totala a stocului este: " << m.cantitateStocTotal;
		out << "\nDurata de valabilitate este: " << m.durataExp << " " << "zile";


		return out;
	}

	//RAPORT MATERII STOC>1000
	void Raport1( string numeFisier)
	{
		ofstream file(numeFisier, ios::in | ios::app);

		if (file.is_open())
		{
			if (this->cantitateStocTotal > 1000)
			{
				cout << endl;
				file <<this->numeMateriep<<" avand stocul de "<<this->cantitateStocTotal<<"\n";
				cout  << this->numeMateriep << " avand stocul de " << this->cantitateStocTotal<<"\n";
				file.close();
			}
		}
	}

	//RAPORT MATERII PRIME CE AU TERMENUL DE VAL <10 zile
	void Raport2(string numeFisier)
	{
		ofstream file2(numeFisier, ios::in | ios::app);
		
		if (file2.is_open())
		{
			if (this->durataExp < 10)
			{
				
				file2 << "\nMateria prima care expira in mai putin de 10 zile este: " << this->numeMateriep<<" avand termenul de valabilitate de: "<<this->durataExp<<" zile";
				cout << "\nMateria care expira in mai putin de 10 zile este: " << this->numeMateriep << " avand termenul de valabilitate de: " << this->durataExp << " zile";

				file2.close();
			}
			
		}
	}




	//functia pentru transformare
	void salveazaDinTextinBinar(fstream& file)
	{
		int lg = strlen(this->numeMateriep) + 1;
		file.write((char*)&lg, sizeof(int));
		file.write(this->numeMateriep, lg);
		file.write((char*)&this->cantitateStocTotal, sizeof(int));
		file.write((char*)&this->durataExp, sizeof(int));
	}

	//FCT SAVETOFILE
	void saveToFile(fstream& file) 
	{
		
		int lg = strlen(this->numeMateriep) + 1;
		file.write((char*)&lg, sizeof(int));
		file.write(this->numeMateriep, lg);
		file.write((char*)&this->cantitateStocTotal, sizeof(int));
		file.write((char*)&this->durataExp, sizeof(int));
	}

	
	//restoreFromFile
	void restoreFromFile(fstream& file) 
	{
        

		int lg;
		file.read((char*)&lg, sizeof(int));

		char* buffer = new char[lg];
		file.read(buffer, lg);

		delete[]this->numeMateriep;

		this->numeMateriep = new char[lg+1];
		strcpy(this->numeMateriep, buffer);
		delete[]buffer;

		file.read((char*)&this->cantitateStocTotal, sizeof(float));
		file.read((char*)&this->durataExp, sizeof(int));

		
	}
	
	


	friend istream& operator>>(istream& in, MateriePrima& m)
	{
		delete[]m.numeMateriep;
		m.numeMateriep = nullptr;
		char buffer[100];
		in.getline(buffer, sizeof(buffer));
		m.numeMateriep = new char[strlen(buffer) + 1];
		strcpy(m.numeMateriep, buffer);

		in >> m.cantitateStocTotal;
		in >> m.durataExp;

		return in;
	}
	//DESTRUCTOR
	~MateriePrima()
	{
		delete[]this->numeMateriep;
		this->numeMateriep = nullptr;
	}


};

//CLASA INGREDIENT 
class Ingredient :IFile
{
private:

	MateriePrima ingredient;
	//char* furnizor = nullptr;
	int cantitateNecesara = 0; //in grame
public:

	//constructor fara parametrii
	Ingredient()
	{

	}

	void setIngredient(MateriePrima& ingredient)
	{
		if (ingredient.getNumeMateriep() != nullptr)
		{
			this->ingredient = ingredient;

		}
	}

	MateriePrima& getIngredient()
	{
		return this->ingredient;
	}



	void setCantitateNecesara(int cantitateNouaNecesara)
	{
		if (cantitateNouaNecesara > 0)
			this->cantitateNecesara = cantitateNouaNecesara;
	}

	int& getCantitateNecesara()
	{
		return this->cantitateNecesara;
	}

	//constructor cu 2 parametrii 1.
	Ingredient(MateriePrima& ingredient, int cantitateNecesara)
	{

		this->ingredient = ingredient;
		if (cantitateNecesara > 0)
		{
			this->cantitateNecesara = cantitateNecesara;
		}

	}

	Ingredient(MateriePrima& ingredient)
	{
		this->ingredient = ingredient;
	}




	//savetofile
	void saveToFile(fstream& file)
	{
		this->ingredient.saveToFile(file);
		file.write((char*)&this->cantitateNecesara, sizeof(int));
	}

	void restoreFromFile(fstream& file)
	{
		this->ingredient.restoreFromFile(file);
		file.read((char*)&this->cantitateNecesara, sizeof(int));
	}




	//metoda generica de afisare a celor 2 atributelor
	void afisare2()
	{
		cout << "\nNumele ingredientului:";
		ingredient.afisareMateriePrima();

	
		if (this->cantitateNecesara != 0)
		{
			cout << "\nCantitate Necesara: " << this->cantitateNecesara;

		}
		else
		{
			cout << "\nCantitate Necesara:-";
		}

	}

	//metoda generica de prelucare a cantitatii
	void prelucrareCantitateNecesara()
	{
		if (this->cantitateNecesara > 0)
			this->cantitateNecesara = 2 * this->cantitateNecesara;
	}

	//constructorul de copiere
	//Ingredient i4(i3)
	Ingredient(const Ingredient& i)
	{

		this->ingredient = i.ingredient;
		this->cantitateNecesara = i.cantitateNecesara;

	}

	//op =    this i1=i2 
	Ingredient& operator=(const Ingredient& i)
	{
		if (this != &i)
		{

			this->ingredient = i.ingredient;
			this->cantitateNecesara = i.cantitateNecesara;
		}
		return *this;
	}

	//operatorul <<(cout<<i4)
	friend ostream& operator<<(ostream& out, const Ingredient& i)
	{
		out << "\nINGREDIENT: ";
		out  << i.ingredient;
		out << "\nCantitate necesara: " << i.cantitateNecesara <<" grame"<< endl;

		//out << "\n===================================================";

		return out;
	}

	//operator >> cin>>i1
	friend istream& operator>>(istream& in, Ingredient& i) //sa pun si pt ingrediente
	{
		
		in.ignore();
		in >> i.ingredient;

		cout << "\nIntroduceti furnizorul ingredientului(LIDL SAU KAUFLAND): ";
		char buffer[100];
		in.ignore();
		//in.ignore();
		cout << "\nIntroduceti cantitatea necesara a acestui ingredient pentru preparat: ";
		in >> i.cantitateNecesara;
		//in.ignore();
		return in;
	}

	~Ingredient()
	{
		
	}
};

//Produsul meu din meniu de exemplu PIZZA
class Produs
{
private:
	static int kilocaloriiMaxime; //maximul pe care il poate avea fiecare produs
	string nume = "-"; //numele produsului
	float pret = 0; //in lei
	int numarIngrediente = 0;//nr actual de ingrediente in lista
	Ingredient* listaIngrediente = nullptr;       //vector alocat dinamic de ingrediente



public:
	
	
	void salveazaDinTextinBinar2(fstream& file)
	{
		int lg = this->nume.length() + 1;
		file.write((char*)&lg, sizeof(int));
		file.write(this->nume.data(), lg);
		file.write((char*)&this->pret, sizeof(float));
		file.write((char*)&this->numarIngrediente, sizeof(int));
	}
	
	
	static void setKilocaloriiMaxime(int kilocaloriiMaxime)
	{
		if (kilocaloriiMaxime > 0)
		{
			Produs::kilocaloriiMaxime = kilocaloriiMaxime;
		}
	}

	static int getKilocaloriiMaxime()
	{
		return Produs::kilocaloriiMaxime;
	}

	bool operator>(const Produs& p)
	{
		if (this->pret > 0 && p.pret > 0)
		{
			return true;
			return false;
		}


	}


	void setNume(string numeNou)
	{
		if (!numeNou.empty())
		{
			this->nume = numeNou;
		}
	}

	string getNume()
	{
		return this->nume;
	}


	//pret set si get
	void setPret(float pret)
	{
		if (pret > 1)
		{
			this->pret = pret;
		}
	}

	float getPret()
	{
		return this->pret;
	}

	//numar ingrediente
	void setNumarIngrediente(int numarIngredienteNou)
	{
		if (numarIngredienteNou > 0)
		{
			this->numarIngrediente = numarIngredienteNou;
		}
	}

	int getNumarIngrediente()
	{
		return this->numarIngrediente;
	}


	//RAPORT PRODUSE CARE AU PRETUL SUB 40 DE LEI
	void Raport3(string numeFisier)
	{
		
			ofstream file3(numeFisier, ios::in | ios::app);

			if (file3.is_open())
			{
				if (this->pret< 40)
				{
					file3 << "\nProdusul care are pretul sub 40 de lei este " << this->nume << " avand pretul de  " << this->pret;
					cout<<"\nProdusul care are pretul sub 40 de lei este " << this->nume << " avand pretul de  " << this->pret;
					file3.close();
				}
			}
		
	}

	

	//lista ingrediente
	void setListaIngrediente(Ingredient* listaIngredienteNoua, int numarIngredienteNoi)
	{
		delete[]this->listaIngrediente;
		this->listaIngrediente = nullptr;
		if (listaIngredienteNoua != nullptr && numarIngredienteNoi > 0)
		{
			//eliberez memoria alocata anterior pentru lista veche


			this->numarIngrediente = numarIngredienteNoi;
			this->listaIngrediente = new Ingredient[this->numarIngrediente];
			for (int i = 0; i < this->numarIngrediente; i++)
			{
				this->listaIngrediente[i] = listaIngredienteNoua[i];
			}


		}

		else
		{
			this->listaIngrediente = nullptr;
			this->numarIngrediente = 0;
		}
	}


	void ListaIngrediente2(vector<Ingredient>& listaIngredienteNoua, int numarIngredienteNoi)
	{
		delete[]this->listaIngrediente;
		this->numarIngrediente = numarIngredienteNoi;
		this->listaIngrediente = new Ingredient[this->numarIngrediente];
		for (int i = 0; i < this->numarIngrediente; i++)
		{
			this->listaIngrediente[i] = listaIngredienteNoua[i];
		}
	}
	



	Ingredient* getListaIngrediente()
	{
		return this->listaIngrediente;//returneaz o adresa
	}



	//metoda de afisare  p2.afisareLista()
	void afisareLista()
	{
		//cout << "\nLista ingrediente produs: " << this->nume;
		if (this->numarIngrediente > 0)
		{
			if (this->listaIngrediente != nullptr)
			{
				cout << "\nLista ingrediente produs: " << this->nume << endl;
				for (int i = 0; i < this->numarIngrediente; i++)
					cout << this->listaIngrediente[i].getIngredient().getNumeMateriep() << " ";
			}
			else
			{
				cout << "Lista ingrediente produs:-";
			}
		}

	}

	//metoda de prelucrare
	void aplicareDiscount(float discount)
	{
		if (discount >= 0 && discount <= this->pret)
		{
			this->pret = this->pret - discount;
		}
	}


	//verificare cantitatea stocului daca este mai mare decat cantitatea necesara

	bool verificaCantitateaStoculuiCuCeaNecesara()
	{
		//bool k = false;
		for (int i = 0; i < this->numarIngrediente ; i++)
		{
			int cantitateStocTotal = this->listaIngrediente[i].getIngredient().getCantitateStocTotal();
			int cantitateNecesar = this->listaIngrediente[i].getCantitateNecesara();

			if ( cantitateNecesar > cantitateStocTotal )
			{
				
				return false;

			}
			
		}
		return true;


	}




	void actualizeazaStoc()
	{
		for (int i = 0; i < this->numarIngrediente; i++)
		{
			

			int cantitateStocTotal = this->listaIngrediente[i].getIngredient().getCantitateStocTotal();
			
			int cantitateNecesar = this->listaIngrediente[i].getCantitateNecesara();

			//if (cantitateStocTotal < cantitateNecesar && cantitateStocTotal>0)
			//{


				int stocActualizat = cantitateStocTotal - cantitateNecesar;
				this->listaIngrediente[i].getIngredient().setCantitateStocTotal(stocActualizat);
				cout << "Stocul total actualizat pentru ingredientul " << i + 1 << " este ";
				cout << stocActualizat << "\n";
		//	}
			
		}


	}

	//op+
	Produs operator+(int pretNou)
	{
		if (pretNou > 0)
		{
			Produs rez = *this;
			rez.pret += pretNou;
			return rez;
		}
	}

	//op++

	Produs& operator++()
	{
		this->numarIngrediente++;
		return *this;
	}



	//constructor  fara parametrii
	Produs()
	{

	}




	//constructor cu toti par
	Produs(string nume, float pret, int numarIngrediente, Ingredient* listaIngrediente)
	{
		if (!nume.empty())
			this->nume = nume;

		this->pret = pret;
		if (numarIngrediente > 0 && listaIngrediente != nullptr)
		{
			this->numarIngrediente = numarIngrediente;
			this->listaIngrediente = new Ingredient[this->numarIngrediente];

			for (int i = 0; i < this->numarIngrediente; i++)
			{

				this->listaIngrediente[i] = listaIngrediente[i];
			}

		}
		else
		{
			this->numarIngrediente = 0;
			this->listaIngrediente = nullptr;

		}

	}

	//constr cu un par
	Produs(string nume, float pret)
	{
		if (!nume.empty())
		{
			this->nume = nume;
		}
		if (pret > 0)
		{
			this->pret = pret;
		}
	}



	//constructor de copiere
	Produs(const Produs& p)
	{
		if (!p.nume.empty())
			this->nume = p.nume;

		this->pret = p.pret;
		if (p.numarIngrediente > 0 && p.listaIngrediente != nullptr)
		{
			this->numarIngrediente = p.numarIngrediente;
			this->listaIngrediente = new Ingredient[this->numarIngrediente];


			for (int i = 0; i < this->numarIngrediente; i++)
			{

				this->listaIngrediente[i] = p.listaIngrediente[i];
			}


		}
		else
		{
			this->numarIngrediente = 0;
			this->listaIngrediente = nullptr;

		}

	}

	//operatorul =
	Produs& operator=(const Produs& p)
	{

		//testam daca obiectele au aceeasi adresa
		if (this != &p)
		{
			delete[]this->listaIngrediente;
			this->listaIngrediente = nullptr;

			if (!p.nume.empty())
			{
				this->nume = p.nume;
			}

			this->pret = p.pret;
			if (p.numarIngrediente > 0 && p.listaIngrediente != nullptr)
			{
				this->numarIngrediente = p.numarIngrediente;
				this->listaIngrediente = new Ingredient[this->numarIngrediente];


				for (int i = 0; i < this->numarIngrediente; i++)
				{

					this->listaIngrediente[i] = p.listaIngrediente[i];
				}

			}
			else
			{
				this->numarIngrediente = 0;
				this->listaIngrediente = nullptr;

			}
		}
		return *this;
	}

	//cout<< p
	friend ostream& operator<<(ostream& out, const Produs& p)
	{

		out << "\n***************************PRODUS****************************";

		if (!p.nume.empty())
		{
			out << "\nProdusul este: " << p.nume;
		}
		else
		{
			out << "\nProdusul este:-";
		}

		out << "\nNumarul de kilocalorii maxime este: " << Produs::kilocaloriiMaxime;
		out << "\nPretul este: " << p.pret;
		out << "\nNumar ingrediente: " << p.numarIngrediente;
		out << "\nLista ingrediente: ";
		if (p.numarIngrediente > 0)
		{
			for (int i = 0; i < p.numarIngrediente; i++)
			{
				out << endl;
				out << p.listaIngrediente[i].getIngredient().getNumeMateriep() << "->";
				out << "Cantitate necesara: " << p.listaIngrediente[i].getCantitateNecesara() << " grame";
			}

		}
		else
		{
			out << "Lista ingrediente:-";
		}
		out << "\n*****************************************************************";
		return out;


	}

	friend istream& operator>>(istream& in, Produs& p)
	{


		cout << "\nIntroduceti numele produsului: ";
		getline(in, p.nume);

		cout << "\nIntroduceti pretul produsului: ";
		in >> p.pret;

		cout << "\nIntroduceti numar ingrediente: ";
		in >> p.numarIngrediente;



		if (p.numarIngrediente > 0)
		{

			p.listaIngrediente = new Ingredient[p.numarIngrediente];
			cout << "\nIntroduceti ingrediente necesare: ";
			for (int i = 0; i < p.numarIngrediente; i++)
			{
				in >> p.listaIngrediente[i];
				//in.ignore();
			}
		}
		else

		{
			p.numarIngrediente = 0;
			p.listaIngrediente = nullptr;


		}

		return in;
	}

	bool operator==(const Produs& p) const
	{
		return this->pret == p.pret;

	}


	~Produs()
	{
		delete[]this->listaIngrediente;
		this->listaIngrediente = nullptr;

	}

};
int Produs::kilocaloriiMaxime = 2000;



//CLASA MENIU
class Meniu
{
private:

	const float rating;
	int nrProduse = 0;
	Produs* listaProduse = nullptr;
	bool contineProduseVegane = false;

public:

	void setListaProduse(Produs* listaProduseNoua, int nrProduse)
	{
		delete[]this->listaProduse;
		this->listaProduse = nullptr;

		if (listaProduseNoua != nullptr && nrProduse > 0)
		{
			this->nrProduse = nrProduse;
			this->listaProduse = new Produs[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->listaProduse[i] = listaProduseNoua[i];
			}

		}
		else
		{
			this->nrProduse = 0;
			this->listaProduse = nullptr;
		}
	}
	Produs* getListaProduse()
	{
		return this->listaProduse;
	}

	//pt bool 
	void setContineProduseVegane(bool contineProduseVegane)
	{
		if (contineProduseVegane == true)
		{
			this->contineProduseVegane = contineProduseVegane;
		}
	}

	bool getContineProduseVegane()
	{
		if (this->contineProduseVegane == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}






	//op []
	Produs& operator[](int pozitie)
	{
		if (pozitie >= 0 && pozitie < this->nrProduse)
			return this->listaProduse[pozitie];
	}

	//nr produse
	void setNrProduse(int nrProduse)
	{
		if (nrProduse >= 1)
		{
			this->nrProduse = nrProduse;
		}
	}

	int getNrproduse()
	{
		return this->nrProduse;
	}


	//MIN 2 METODE GENERICE DE PRELUCRARE/AFISARE
	void afisareMeniu()
	{
		if (this->nrProduse > 0)
		{
			cout << "Numarul produselor din meniu:" << this->nrProduse;
			if (this->listaProduse != nullptr)
			{
				cout << "\nLista produse:";
				for (int i = 0; i < this->nrProduse; i++)
				{
					cout << this->listaProduse[i].getNume() << " ";
				}
			}
			else
			{
				cout << "Lista Produse:-";
			}
		}

	}

	//!
	bool operator!()
	{
		return !this->contineProduseVegane;
	}

	void AdaugaProdusMeniu(Produs& produs) //adaug un nou produs in lista
	{
		int noulNrProduse = this->nrProduse + 1;
		Produs* nouaListaProduse = new Produs[noulNrProduse];
		for (int i = 0; i < this->nrProduse; i++)
		{
			nouaListaProduse[i] = this->listaProduse[i];
		}

		nouaListaProduse[this->nrProduse] = produs;

		delete[]this->listaProduse;
		this->listaProduse = nouaListaProduse;
		this->nrProduse = noulNrProduse;




	}
	//CONSTRUCTOR FARA PARAMETRII
	Meniu() :rating(0)
	{

	}

	//constructor cu un par
	Meniu(float rating) :rating(rating)
	{

	}
	//constr cu toti parametrii
	Meniu(float rating, int nrProduse, Produs* listaProduse, bool contineProduseVegane) :rating(rating)
	{
		if (nrProduse > 0 && nrProduse <= 10)
		{
			this->nrProduse = nrProduse;
			if (listaProduse != nullptr)
			{
				this->listaProduse = new Produs[this->nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					this->listaProduse[i] = listaProduse[i];
				}
			}
		}
		else
		{
			this->nrProduse = 0;
			this->listaProduse = nullptr;
		}

	}

	//constr copy Meniu m3=m1
	Meniu(const Meniu& me) :rating(me.rating)
	{
		if (me.nrProduse > 0 && me.nrProduse <= 10)
		{
			this->nrProduse = me.nrProduse;
			if (me.listaProduse != nullptr)
			{
				this->listaProduse = new Produs[this->nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					this->listaProduse[i] = me.listaProduse[i];
				}
			}
		}
		else
		{
			this->nrProduse = 0;
			this->listaProduse = nullptr;
		}

	}

	Meniu& operator=(const Meniu& me)
	{
		if (this != &me)
		{
			delete[]this->listaProduse;
			this->listaProduse = nullptr;

			if (me.nrProduse > 0 && me.nrProduse <= 10)
			{
				this->nrProduse = me.nrProduse;
				if (me.listaProduse != nullptr)
				{
					this->listaProduse = new Produs[this->nrProduse];
					for (int i = 0; i < this->nrProduse; i++)
					{
						this->listaProduse[i] = me.listaProduse[i];
					}
				}
			}
			else
			{
				this->nrProduse = 0;
				this->listaProduse = nullptr;
			}
		}
		return *this;
	}


	//OSTREAM MENIU
	friend ostream& operator<<(ostream& out, const Meniu& me)
	{
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~MENIUL RESTAURANTULUI~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		out << "\nRATING OFERIT DE CLIENTI: " << me.rating;
		out << "\nMENIUL CONTINE URMATORUL NUMAR DE PRODUSE: " << me.nrProduse;
		out << "\nPRODUSELE SUNT: ";
		if (me.nrProduse > 0 && me.nrProduse < 10)
		{
			for (int i = 0; i < me.nrProduse; i++)
			{
				cout <<"\n";
				out << me.listaProduse[i].getNume() << " ";
				out << "PRETUL PRODUSULUI ESTE: " << me.listaProduse[i].getPret() << " lei";

			}
		}


		else
		{
			cout << "\nNU EXISTA PRODUSE: ";
		}
		out << "\nMENIUL CONTINE/NU CONTINE PRODUSE VEGANE (1-Da)/(0-Nu): " << me.contineProduseVegane;
		out << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		return out;
	}

	//ISTREAM MENIU
	friend istream& operator>>(istream& in, Meniu& me)
	{
		cout << "\nIntroduceti numarul produselor: ";
		in >> me.nrProduse;


		return in;
	}





	//DESTRUCTOR
	~Meniu()
	{
		delete[]this->listaProduse;
		this->listaProduse = nullptr;
	}

};


class Comanda
{
private:

	Produs* listaProduseComandate = nullptr;
	int nrProduseComandate = 0;
	static Meniu meniu;


public:

	 static void setMeniu(Meniu meniu)
	{
		if (meniu.getListaProduse() != nullptr)
		{
			Comanda::meniu = meniu;
		}

	}

	static Meniu getMeniu()
	{
		return Comanda::meniu;
	}



	void setListaProduseComandate(Produs* listaProduseComandate, int nrProduseComandate)
	{
		delete[]this->listaProduseComandate;
		this->listaProduseComandate = nullptr;

		if (listaProduseComandate != nullptr && nrProduseComandate > 0)
		{
			this->nrProduseComandate = nrProduseComandate;
			this->listaProduseComandate = new Produs[this->nrProduseComandate];
			for (int i = 0; i < this->nrProduseComandate; i++)
			{
				this->listaProduseComandate[i] = listaProduseComandate[i];
			}

		}
		else
		{
			this->nrProduseComandate = 0;
			this->listaProduseComandate = nullptr;
		}
	}



	Produs* getListaProduseComandate()
	{
		return this->listaProduseComandate;
	}

	//nr produseComandate
	void setNrProduseComandate(int nrProduseComandate)
	{
		if (nrProduseComandate > 0)
		{
			this->nrProduseComandate = nrProduseComandate;
		}
	}

	int getNrproduseComandate()
	{
		return this->nrProduseComandate;
	}



	float pretTotalComanda()
	{
		float pretc = 0;
		if (this->nrProduseComandate > 0)
		{
			for (int i = 0; i < this->nrProduseComandate; i++)
			{
				pretc += listaProduseComandate[i].getPret();
			}

			ofstream RaportTotalComenzi("RaportTotalComenzi", ios::app);
			{
				if (RaportTotalComenzi.is_open())
				{
					RaportTotalComenzi << "\n Pret Total comanda: " << pretc << " lei";
					RaportTotalComenzi.close();
				}

			}
		}
		return pretc;
	}


	void afisareProduseComandate()
	{
		if (this->nrProduseComandate > 0)
		{
			cout << "Numarul produselor comandate este :" << this->nrProduseComandate;
			if (this->listaProduseComandate != nullptr)
			{
				cout << "\nLista produse comandate:";
				for (int i = 0; i < this->nrProduseComandate; i++)
				{
					cout << this->listaProduseComandate[i].getNume() << " ";
				}
			}
			else
			{
				cout << "Nu s-au comandat produse: ";
			}
		}

	}

	//ADAUGARE PRODUS IN COMANDA
	void AdaugaProdusComandate(Produs& produs)
	{
		int noulNrProduseComandate = this->nrProduseComandate + 1;
		Produs* nouaListaProduseComandate = new Produs[noulNrProduseComandate];
		for (int i = 0; i < this->nrProduseComandate; i++)
		{
			nouaListaProduseComandate[i] = this->listaProduseComandate[i];
		}

		nouaListaProduseComandate[this->nrProduseComandate] = produs;

		delete[]this->listaProduseComandate;
		this->listaProduseComandate = nouaListaProduseComandate;
		this->nrProduseComandate = noulNrProduseComandate;

	}

	//CONSTRUCTOR FARA PARAMETRII
	Comanda()
	{

	}



	//CONSTRUCTOR CU TOTI PARAMETRII
	Comanda(Produs* listaProduseComandate, int nrProduseComandate)
	{
		if (nrProduseComandate > 0)
		{
			this->nrProduseComandate = nrProduseComandate;
			if (listaProduseComandate != nullptr)
			{
				this->listaProduseComandate = new Produs[this->nrProduseComandate];
				for (int i = 0; i < this->nrProduseComandate; i++)
				{
					this->listaProduseComandate[i] = listaProduseComandate[i];
				}
			}
		}
		else
		{
			this->nrProduseComandate = 0;
			this->listaProduseComandate = nullptr;
		}
		
	}

	

	//CONSTRUCTORUL DE COPIERE
	Comanda(const Comanda& c)
	{
		if (c.nrProduseComandate > 0)
		{
			this->nrProduseComandate = c.nrProduseComandate;
			if (c.listaProduseComandate != nullptr)
			{
				this->listaProduseComandate = new Produs[this->nrProduseComandate];
				for (int i = 0; i < this->nrProduseComandate; i++)
				{
					this->listaProduseComandate[i] = c.listaProduseComandate[i];
				}
			}
		}
		else
		{
			this->nrProduseComandate = 0;
			this->listaProduseComandate = nullptr;
		}

		

	}

	//OPERATORUL =
	Comanda& operator=(const Comanda& c)
	{
		if (this != &c)
		{
			delete[]this->listaProduseComandate;
			this->listaProduseComandate = nullptr;

			if (c.nrProduseComandate > 0)
			{
				this->nrProduseComandate = c.nrProduseComandate;
				if (c.listaProduseComandate != nullptr)
				{
					this->listaProduseComandate = new Produs[this->nrProduseComandate];
					for (int i = 0; i < this->nrProduseComandate; i++)
					{
						this->listaProduseComandate[i] = c.listaProduseComandate[i];
					}
				}
			}
			else
			{
				this->nrProduseComandate = 0;
				this->listaProduseComandate = nullptr;
			}
			
		}
		return *this;
	}

	//OSTREAM COMANDA
	friend ostream& operator<<(ostream& out, const Comanda& c)
	{
		out << "\n**************** COMANDA *****************";
		//out << "\nComanda dumneavoastra contine : " << c.nrProduseComandate << " " << "produse";
		out << "\nProdusele sunt: ";
		if (c.nrProduseComandate > 0)
		{
			for (int i = 0; i < c.nrProduseComandate; i++)
			{
				cout << endl;
				out << c.listaProduseComandate[i].getNume() << "====> ";
				out << "Pretul este : " << c.listaProduseComandate[i].getPret() << " lei";
			
			}
			
		}

		else
		{
			cout << "\nNu exista produse in comanda:- ";
			cout << endl;
		}

		return out;
	}


	//raport nr ap
	


	//ISTREAM COMANDA
	friend istream& operator>>(istream& in, Comanda& c)
	{
		delete[]c.listaProduseComandate;
		c.listaProduseComandate = nullptr;
		int k = 0;
		cout << endl;
		cout << "\n             $$ COMANDA $$       ";
		cout << "\n NUMARUL DE PREPARATE PE CARE DORITI SA LE COMANDATI: ";

		in >> c.nrProduseComandate; //3 produse comandate
		if (c.nrProduseComandate > 0)
		{
			c.listaProduseComandate = new Produs[c.nrProduseComandate];//lista


			//cout << "INTRODUCETI DENUMIREA PRRODUSELOR: ";
			in.ignore();
			for (int i = 0; i < c.nrProduseComandate; i++)
			{

				string denumireprodus;
				cout << "\nProdusul " << i + 1 << " ";
				//in.ignore();
				getline(in, denumireprodus);

				bool produsgasit = false;
				int ok = 0;

				//Produs* listaProduseMeniu = c.meniu.getListaProduse(); //lista este o copie la pointerul getlistaproduse din MENIU

				for (int j = 0; j < c.meniu.getNrproduse(); j++) //3 in meniu
				{
					if (denumireprodus == c.meniu.getListaProduse()[j].getNume()) //este egal cu unul din produsele din meniu
					{
						
						if (!c.meniu.getListaProduse()[j].verificaCantitateaStoculuiCuCeaNecesara())
						{

							cout << "Nu exista suficient stoc total pentru produsul comandat " << denumireprodus;
						    	

						}

						else
						{
							
							c.listaProduseComandate[i] = c.meniu.getListaProduse()[j]; //in lista comandata am salvat produsul din meniu cu cantiate corecta

							c.meniu.getListaProduse()[j].actualizeazaStoc();
							cout << "\nComanda inregistrata cu succes ";
							cout << endl;

							
							
							
						}
						produsgasit = true;


					}

				}


				if (!produsgasit)
				{
					cout << "\nNu exista produsul " << denumireprodus << " in meniu";
					i--;
				}

			}



		}

		else
		{
			c.listaProduseComandate = nullptr;
		}

	  



		return in;

	}

	

	//DESTRUCTOR

	~Comanda() {
		delete[]this->listaProduseComandate;
		this->listaProduseComandate = nullptr;
	}


};
Meniu Comanda::meniu;

//Clasa activitateUtilizator

class Client {
private:
	string nume;
	int nrVizite;
	bool existaRecenzie;

public:
	Client()
	{

	}

	Client(string nume, int nrVizite,bool existaRecenzie)
	{
		if (!nume.empty())
		{
			this->nume = nume;
		}

		this->nrVizite = nrVizite;
		this->existaRecenzie = existaRecenzie;
	}

	Client(const Client& c)
	{
		if (!c.nume.empty())
		{
			this->nume = c.nume;
		}
		
		this->nrVizite = c.nrVizite;
		this->existaRecenzie = c.existaRecenzie;
	}

	Client& operator=(const Client c)
	{
		if (this != &c)
		{
			if (!c.nume.empty())
			{
				this->nume = c.nume;
			}
			this->nrVizite = c.nrVizite;
			this->existaRecenzie = c.existaRecenzie;
		}
		return *this;
	}
	

	void afisare()
	{
		cout << "\nClient: " << this->nume;
		cout << "\nNumar Vizite " << this->nrVizite;
		cout << "\nA lasat recenzie: " << (this->existaRecenzie ? "Da": "Nu")<<"\n";
	}

	friend ostream& operator<<(ostream& out, const Client& a)
	{
		
		out << "\nClientul:" << a.nume;
		out << "\nA venit la restaurant de: " << a.nrVizite <<" ori";
		out << "\nA lasat recenzie: " << (a.existaRecenzie ? "Da" : "Nu") << "\n";

		return out;
	}

	int getNrVizite()
	{
		return this->nrVizite;
	}

	string& getClient()
	{
		return this->nume;
	}



	bool recenzielasata()
	{
		return this->existaRecenzie;
	}


	//RAPORT NUMAR DE vizite
	string Raport_NumarVizite()
	{
		if (this->nrVizite > 2)
		{
			
			return  this->nume + "\na venit la restaurant de " + to_string(this->nrVizite) + " ori\n";//returneaza un sir de caractere
		}
		else
			return "";
	}

	//raport cu clienti care au lasat recenzii
	void ExistaRecenzii(string numeFisier)
	{
		ofstream file(numeFisier, ios::in | ios::app);
		
			if (file.is_open())
			{


				if (this->existaRecenzie == true)
				{   
					file << "\nClientul cu numele " << this->nume << " a lasat recenzie restaurantului";
					cout << "\nClientul cu numele " << this->nume << " a lasat recenzie restaurantului";
					file.close();
				}
			}
	}


	~Client()
		{

		}

};


int main(int argc, char* argv[])
{ //1

	cout << argv[1] << argv[2];
	string materiiPrimeFileName = argv[1];
	string produseFileName = argv[2];
	ifstream f(materiiPrimeFileName);
	ifstream Prod(produseFileName);

	int numarMaterii;
	f >> numarMaterii;
	f.ignore();

	vector<Ingredient> listaIngrediente1; //FOLOSIT PT LISTA 
	vector<MateriePrima> vectorMaterii; //FOLOSIT

	int cantitateNecesara[] = { 20,30,40,20,100,40,200,50,10,200,200,10,100,20,350,200,25};
	for (int i = 0; i < numarMaterii; i++)
	{
		char* denumire;
		int stocTotal;
		int durata;
		char buffer[100];

		f >> buffer;
		denumire = new char[strlen(buffer) + 1];
		strcpy(denumire, buffer);
		f >> stocTotal >> durata;

		MateriePrima materiePrima(denumire, stocTotal, durata); //crearea obj de tip materie prima

		vectorMaterii.push_back(materiePrima);//am creat un vector de materii prime

		Ingredient ingredient(vectorMaterii[i], cantitateNecesara[i]);//am creat obj ingredient 
		listaIngrediente1.push_back(ingredient);//am creat o lista cu TOATE INGREDIENTELE
		

		delete[]denumire;
	}
	f.close();
	

	int numarProd;
	Prod >> numarProd;
	//AM CREAT LISTA DE INGREDIENTE PENTRU FIECARE PREPARAT
	vector<Ingredient> listaIngredienteProdus1;
	vector<Produs> listaProduse;
    int k = 0;
	Meniu meniu(4.9);
	
    for (int i = 0; i < numarProd; i++)
	{

		string denumireProd;
		float pret;
		int numarIngrediente;

		Prod >> denumireProd;
		Prod >> pret;
		Prod >> numarIngrediente;

		Ingredient* listaNoua = new Ingredient[listaIngrediente1.size()]; //pointer catre o noua lista cu dimensiunea nr de ingrediente totale

		for (int i = 0; i < numarIngrediente; i++)
		{
			listaNoua[i] = listaIngrediente1[k];
			k++;
			
		}

		Produs produs(denumireProd, pret, numarIngrediente, listaNoua);
		
		listaProduse.push_back(produs);  //folosita la fisierul binar
		meniu.AdaugaProdusMeniu(produs);
		delete[]listaNoua;
	}

	Prod.close();
	cout << meniu << " ";
	

	//COMANDA
	Comanda comanda;
	comanda.setMeniu(meniu);
	cin >> comanda;
	cout << comanda;
    cout << "\nPretul total al comenzii este " << comanda.pretTotalComanda() << " lei" << endl; //RAPORT FISIER TXT CU TOTALURILE COMENZILOR
	

       
	//     2.  FISIERE  BINARE FUNCTII DE TRANSFORMARE

   /*
    fstream file("Materii_prime1.bin", ios::out | ios::binary);
	for (MateriePrima& materie : vectorMaterii)
	{
			materie.salveazaDinTextinBinar(file);
	}

   
   
    fstream file2("Produse1.bin", ios::out | ios::binary);
	for ( Produs& produs : listaProduse)
	{
	 produs.salveazaDinTextinBinar2(file2);
	 cout << produs << " ";
	}

  */
		


	//        3. RAPOARTE   
	
	cout << "\n************RAPORT MATERII PRIME CU STOCUL MAI MARE DE 100 DE GRAME***************:";
	for (auto& materie:vectorMaterii)
		{
			materie.Raport1("Raport_materii_prime_stoc.txt");
		}
    
	

			      
	cout << "\n**********RAPORT MATERII PRIME CE AU TERMENUL DE VALABILITATE MAI MIC DE 10 ZILE*************";
	
	for (auto& materie : vectorMaterii)
			{
			   materie.Raport2("Raport_materii_termen_val.txt");
			}
    
		        
	cout << endl;
	cout << "\n************RAPORT PRODUSE SUB 40 DE LEI*******";
	for (auto& produs : listaProduse)
	 {
			produs.Raport3("Raport_produse_sub_40lei.txt");
	 }
	

		
		//Map pentru a organiza datele clientilor in fct de nume
	map<string, Client> clientMap;

	//Lista pentru a pastra o lista a clientilor in ordinea  adaugarii
	list<string> clientList;

	//Set pentru a gestiona un set de clienti distincti //ord alf
	set<string> uniqClienti;

	//adaugareclienti
	clientMap["Alexandra-Baicu"] = Client("Alexandra-Baicu", 5, true); //chei sunt string
	clientMap["Stefan-Hertig"] = Client("Stefan-Hertig", 10, false);
	clientMap["Catalina-Ionascu"] = Client("Catalina-Ionascu", 3, true);
	clientMap["Ana-Babes"] = Client("Ana-Babes", 4, true);
	clientMap["Andreea-Andrei"] = Client("Andreea-Andrei", 2, false);


	//adaug clienti si in lista si in set
	for ( auto& p : clientMap)
	{
		clientList.push_back(p.first); // retine in lista numele
		uniqClienti.insert(p.first);  ////FARA DUBLICARI
	}

	//afisare informatii clienti in ordinea adaugarii
	/*
	for (auto& NumeClient : clientList) 
	{
		cout << clientMap[NumeClient]<<" ";
	}
	*/


	//afisare in ord alfabetica
	/*cout << "\n Afisare clienti in ordinea cheilor: ";
	for(auto& NumeClient: uniqClienti)
	{
	   cout<<clientMap[NumeClient]<<" ";
	
	}
	*/
	


	//RAPOARTE DESPRE CLIENTI   1
	
	/*
	cout << endl;
	cout << "\n************RAPORT CLIENTI CE NE-AU VIZITAT DE MAI MULTE DE 2 ORI********\n";
	for (const auto& NumeClient : clientList)
	{
	 cout << clientMap[NumeClient].Raport_NumarVizite();
	}
	*/
	


	//RAPORT CLIENTI RECENZII
	/*
    cout << "\n***********RAPORT CLIENTI CARE AU LASAT RECENZII**************\n";
	for (const auto& NumeClient : clientList)
	{

		clientMap[NumeClient].ExistaRecenzii("Raport_existenta_recenzii");

	}

	*/
	

	//CSV
	/*
   cout << "\n PRELUARE DIN FISIER CSV ";
	
   ifstream fisierCSV("fisier.csv");
   if (fisierCSV.is_open())
   {
	   vector<Client> listaClienti;

	   string linieCSV; //getline-pt a citi o linie intreaga dintr-un fisiee
	   int k = 0;
	   while (getline(fisierCSV, linieCSV))
	   {
		   if (linieCSV.empty())
		   {
			   break;//daca linia este goala restul codului din bucla pt iteratia curenta nu este executata
		   }
		   string nume2;
		   int nrVizite2;
		   bool existaRecenzie2;

		   istringstream linieStream(linieCSV);
		   getline(linieStream, nume2, ',');
		   linieStream >> nrVizite2;
		   linieStream.ignore();
		   linieStream >> existaRecenzie2;

		   //creare obj
		   listaClienti.push_back(Client(nume2, nrVizite2, existaRecenzie2));
		   cout << listaClienti[k++];

	   }
	   fisierCSV.close();


   }

   
   */
   

   //VIRTUALIZARE MATERII PRIME

  /*  //save
  
  fstream fileBinar3("fisierBinar3", ios::out | ios::binary);
   int numarMateriiPrime = vectorMaterii.size();
   fileBinar3.write((char*)&numarMateriiPrime, sizeof(int));

   for (int i = 0; i < numarMateriiPrime; i++)
	   {
		   vectorMaterii[i].saveToFile(fileBinar3);
	   }
   fileBinar3.close();

   */

	//  restore
   /*
   fstream fileBinar4("fisierBinar3", ios::in | ios::binary);
    int nrMateriiPrimeFisier;
    fileBinar4.read((char*)&nrMateriiPrimeFisier, sizeof(int));


    for (int i = 0; i <nrMateriiPrimeFisier; i++)
    {
	   //trb sa creez obj noi cu elementele citite din fisier
	    MateriePrima materie;
	    materie.restoreFromFile(fileBinar4);
	   cout << "\n" << materie;

   }
   fileBinar4.close();
   */

   

   //VIRTUALIZARE CLASA INGREDIENT CE CONTINE UN OBJ DE TIP MATERIEPRIMA
   
  /*  save
  fstream fisierB("Ingrediente.bin", ios::out | ios::binary);
   int numarIngrediente = listaIngrediente1.size();
   if (fisierB.is_open())
   {   

	   fisierB.write((char*)&numarIngrediente, sizeof(int));
	   for (int i = 0; i < listaIngrediente1.size(); i++)
	   {
		   listaIngrediente1[i].saveToFile(fisierB);
		   
	   }
	   fisierB.close();

   }
   else {
	   cout << " Eroare la deschiderea fisierului";
   }

   
   */

   //restore
   /*
  
  fstream fisierB2("Ingrediente.bin", ios::in | ios::binary);
   int nrIngredientePreluate;
   cout << "\nPreluare din fisier binar pentru clasa ingrediente: ";
	 if (fisierB2.is_open())
	 {
		  fisierB2.read((char*)&nrIngredientePreluate, sizeof(int));//citeste nr de ingr
		  
		  cout << "\nNumarul de ingrediente din fisierul binar: " << nrIngredientePreluate;
		  for (int i = 0; i < nrIngredientePreluate; i++)
		  {


			  Ingredient ingredient;
			  ingredient.restoreFromFile(fisierB2);
			 
			  cout  << ingredient << "\n";
		  }
		  fisierB2.close();
	  }
	 
   
	*/
  

	return 0;

}