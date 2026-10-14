#include <iostream>
#include <string.h>
using namespace std;

class SessioUsuari {
private:
	string nomUsuari;
	int tempsLimitSegons;
	bool activa; 

	void tancarSessio()
	{
		activa = false;
	}

public:
	//Constructor per defecte
	//cal inicialitzar activa en true --> quan es crea una sessió aquesta esta activa
	SessioUsuari() : nomUsuari("convidat"), tempsLimitSegons(300), activa(true) {}

	//Constructor amb paràmetres (1 paràmetre)	
	explicit SessioUsuari(string nom) : nomUsuari(nom), tempsLimitSegons(600), activa(true) {};

	//Cosntructor parametritzat complet
	SessioUsuari(string nom, int temps) : nomUsuari(nom), tempsLimitSegons(temps ), activa(true) {
	
		if (tempsLimitSegons <= 0)
		{
			tempsLimitSegons = 60;
		}

	};

//posem el const pq nomes llegeix el nom
		string getNomUsuari() const 
		{
			return nomUsuari;
		}

		bool isActiva() const
		{
			return activa;
		}

		void ampliarTemps(int segons)
		{
			if (segons > 0)
			{
				tempsLimitSegons = tempsLimitSegons + segons;
			}
			else
			{
				cout << "el valor introduit es erroni" << endl;
			}
		}

		~SessioUsuari() {
			if (activa == true)
			{
				tancarSessio();
				cout << "[AUDITORIA] La sessió de " << nomUsuari << " s'ha tancat automàticament en sortir d'àmbit." << endl;
			}
}
};
