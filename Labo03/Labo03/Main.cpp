/* Fichier : Main.cpp
* Auteur  : Luc Aebischer
* Date    : 18.09.2014
*
* But     : Orienté objet
*
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2013
*/
# define _CRT_SECURE_NO_WARNINGS

# include <iostream>
# include "Cercle.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/
/*Définition de l'objet Rectangle*/

class rectangle
{
public:
	rectangle();
	rectangle(double largeur, double longeur);

	double getLongeur(){ return Longeur; };
	double getLargeur(){ return Largeur; };

	void setLongeur(double longeur){ this->Longeur = longeur; };
	void setLargeur(double largeur){ this->Largeur = largeur; };

	double surface();
	~rectangle();

private:
	double Longeur;
	double Largeur;

};

rectangle::rectangle()
{
	Longeur = 0;
	Largeur = 0;
}

rectangle::rectangle(double largeur, double longeur)
{
	Longeur = longeur;
	Largeur = largeur;
}

double rectangle::surface()
{
	return Largeur*Longeur;
}

rectangle::~rectangle()
{
	;
}

void afficher_rectangle(rectangle a)
{
	cout << "Surface du rectangle de longeur " << a.getLongeur()
		<< " et de largeur " << a.getLargeur()
		<< " et de surface " << a.surface() << endl;
}

void afficher_cercle(Cercle a)
{
	double x, y;
	a.getCenter(x,y);
	cout << "Centre(" << x << "," << y << ") de rayon " << a.getRayon() << endl;
}
/*----------------------------------------------------------------------------*/
int main(void)
{

	rectangle a,b(2,5);
	Cercle c, d;
	cout << "Labo 3 \n";
	cout << "Luc Aebischer\n\n";
	
	afficher_rectangle(a);
	afficher_rectangle(b);
	b.setLargeur(3);
	b.setLongeur(4);
	afficher_rectangle(b);


	
	
	system("PAUSE");
	return EXIT_SUCCESS;
}


