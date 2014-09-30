/* Fichier : Main.c
* Auteur  : Luc Aebischer
* Date    : 18.09.2014
*
* But     : Mini dictionnaire
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
#include <iomanip>

using namespace std;

const int taille_tab = 100;
const int taille_nom = 20;
const int taille_def = 40;

typedef struct {
	string francais;
	string definition;
	string anglais;
} MOT;

void lister(MOT *tab);
void inserer(MOT *tab);
void supprimer(MOT *tab);
void rechercher(MOT *tab);
void afficher_entete();
void afficher_mot(MOT mot);

int Menu(void);
/*----------------------------------------------------------------------------*/
int main(void)
{

	int choix;
	MOT *tab_struc = new MOT[taille_tab];

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
			lister(tab_struc);
			break;
		case 2:
			inserer(tab_struc);
			break;
		case 3:
			supprimer(tab_struc);
			break;
		case 4:
			rechercher(tab_struc);
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

void lister(MOT *tab)
{
	int i = 0;
	afficher_entete();
	cout << endl;
	while (tab[i].francais != "")
	{
		afficher_mot(tab[i]);
		i++;
	}
	cout << endl << endl;
}

void inserer(MOT *tab)
{
	MOT new_mot;
	int i = 0;

	cout << "Nouveau mot a inserer : ";
	cin >> new_mot.francais;

	cout << "Definition :  ";
	cin.sync();
	getline(cin,new_mot.definition);

	cout << "Traduction anglaise :  ";
	cin >> new_mot.anglais;

		
	while (tab[i].francais.compare(new_mot.francais) < 0 && tab[i].francais != "")
	{
		i++;
	}

	if (tab[i].francais != "")
	{
		int j;
		//decalage du tableau
		for (j = taille_tab - 1; j > i; j--)
		{
			tab[j] = tab[j - 1];
		}
		tab[i] = new_mot;
	}
	else if (tab[i].francais == "")
	{
		tab[i] = new_mot;
	}
	else
	{
		tab[i+1] = new_mot;
	}
	
}

void supprimer(MOT *tab)
{
	int i = 0;
	string mot_supp;
	cout << "Mot à supprimer : ";
	cin >> mot_supp;

	while (i < taille_tab - 1)
	{		
		if (tab[i].francais.compare(mot_supp) == 0)
			break;
		i++;
	}

	//decalage du tableau
	if (tab[i].francais.compare(mot_supp) == 0)
	{
		while (i < taille_tab-1)
		{
			tab[i] = tab[i + 1];
			i++;
		}
		tab[taille_tab-1].anglais = "";
		tab[taille_tab-1].definition = "";
		tab[taille_tab-1].francais = "";
	}
	else
	{
		cout << " Aucun mot trouver dans la base"<< endl;
	}
}

void rechercher(MOT *tab)
{
	string mot_recherche;
	cout << "Mot a rechercher : ";
	cin >> mot_recherche;

	int i = 0;
	while ( i < taille_tab)
	{
		if (tab[i].francais.compare(mot_recherche) == 0)
			break;
		i++;
	}

	if (i == taille_tab)
	{
		cout << "Aucun mot trouve";
	}
	else
	{
		afficher_entete();
		cout << endl;
		afficher_mot(tab[i]);
	}
	cout << endl << endl;
}

void afficher_entete()
{
	cout << left << setw(20) << "FRANCAIS" << setw(40) << "DESCRIPTION" << setw(20) << "ENGLISH";
}

void afficher_mot(MOT mot)
{
	cout << left << setw(20) << mot.francais << setw(40) << mot.definition << setw(20) << mot.anglais;
}