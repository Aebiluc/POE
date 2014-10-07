/* Fichier : Main.cpp
* Auteur  : Luc Aebischer
* Date    : 18.09.2014
*
* But     : 
*
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*
* Compilateur : Visual Studio 2013
*/
# define _CRT_SECURE_NO_WARNINGS

# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <string>
#include  <iomanip>

using namespace std;


int Menu(void);
/*----------------------------------------------------------------------------*/
int main(void)
{

	int choix;

	cout << "Labo 1 \n";
	cout << "Luc Aebischer\n\n";
	
	do
	{
		choix = Menu();
		switch (choix)
		{
		case 0:
			break;
		case 1:

			break;
		default:
			printf("Choix incorrect\n");
			break;
		}
	} while (choix != 0);
	return EXIT_SUCCESS;
}
int Menu(void)
{
	int choix;
	cout << "========================MENU========================\n" ;
	cout << "|1 - Lister les mots du dictionnaire                |\n" ;
	cout << "|2 - Inserer un mot                                 |\n" ;
	cout << "|3 - Supprimer un mot                               |\n" ;
	cout << "|4 - Rechercher un mot francais	                    |\n" ;
	cout << "|0 - Quitter                                        |\n" ;
	cout << "====================================================\n" ;

	cout << "Choix : ";
	cin >> choix;
	cin.clear();
	cin.sync();
	cout << endl << endl;
	return choix;
}

