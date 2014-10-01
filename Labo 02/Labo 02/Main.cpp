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
#include  <iomanip>

using namespace std;
void prog();
string enlever_espace(string chaine1);
int verif(string chaine);
int decodage(string chaine, int &x2,int &x,int c);
int signe(string chaine);

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
			prog();
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
	cout << "|1 - Resolution de polynome                         |\n" ;
	cout << "|0 - Quitter                                        |\n" ;
	cout << "====================================================\n" ;

	cout << "Choix : ";
	cin >> choix;
	cin.clear();
	cin.sync();
	cout << endl << endl;
	return choix;
}
void prog()
{
	string commande;

	int x=0, x2=0, c=0; 

	cout << "Rentrer un polynome sous la forme \
	       \nAx + B = 0 ou Ax2 + Bx + C = 0" << endl;
	getline(cin, commande);
	commande = enlever_espace(commande);

	if (verif(commande) == -1)
	{
		cout << "Une commande est incorrect dans la chaine" << endl;
		return;
	}
	
	decodage(commande, x2, x, c);
   	//int taille_str = commande.length();
    //int pos_eg = commande.find_last_of("=");

	/*Recherche des coefficient*/

	//int pos_x = commande.find_first_of("x");

	//tmp = commande.substr(0, pos_x);
	stoi(commande);
}
string enlever_espace( string chaine1)
{
    string ChaineSansEspace = "";
    unsigned int i;

	for (i = 0; i < chaine1.length(); i++) {
		if (chaine1[i] != ' ')
		{
			ChaineSansEspace += chaine1[i];
		}
	}
	return ChaineSansEspace;
}

int decodage(string chaine,int &x2,int &x, int c)
{
	int i, pos;
	string tmp = "";

	for (i = 0; i < chaine.length(); i++)
	{
		if (chaine[i] == '+' || 
			chaine[i] == '-' || 
			chaine[i] == '=' /*|| 
			( tmp != "" && i == chaine.length())*/)
		{
			if ((pos = tmp.find("x2",0)) >= 0 )
			{
				tmp.erase(pos,2);
				//x2 = signe(tmp);
				x2 = stoi(tmp);
				tmp = chaine[i];
			}
			else if ((pos = tmp.find("x",0)) >= 0)
			{
				tmp.erase(pos, 1);
				//x = signe(tmp);
				x = stoi(tmp);
				tmp = chaine[i];
			}
			else
			{
				if (i > 1)
				{
					//c = signe(tmp);
					c = stoi(tmp);
					tmp = chaine[i];
				}
				else
				{
					tmp += chaine[i];
				}
			}
		}
		else
		{
			tmp += chaine[i];
		}
	}

	return 0;
}

int verif(string chaine)
{
	int i;
	int retour;
	for (i = 0; i < chaine.length(); i++)
	{
		if (isdigit(chaine[i]) != 0 || 
					chaine[i] == '+' || 
					chaine[i] == '-' || 
					chaine[i] == 'x' || 
					chaine[i] == '=')
		{
			continue;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}

int signe(string chaine)
{
	int pos;
	if ((pos = chaine.find("-", 0)) >= 0)
	{
		return -1;
		chaine.erase(pos, 1);
	}
	else if ((pos = chaine.find("+", 0)) >= 0)
	{
		return 1;
		chaine.erase(pos, 1);
	}
	else
	{
		return 1;
	}
}