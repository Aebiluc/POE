/* Fichier : Main.c
* Auteur  : Luc Aebischer
* Date    : 2.10.2014
*
* But     : Analyse de polynome
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
# include <iomanip>
# include <math.h>

using namespace std;
void prog();
string enlever_espace(string chaine1);
int verif(string chaine);
int decodage(string chaine, int &x2,int &x,int &c);
int signe(string chaine);

int resolution(int x2, int x, int c, double &resultat1, double &resultat2);
int resolution(int x, int c, double &resultat);
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
   	
	if (x2 != 0)
	{
		double resultat1, resultat2;
		int retour = resolution(x2, x, c, resultat1, resultat2);

		if (retour == 0)
		{
			cout << "x1 vaut : " << resultat1 << endl;
			cout << "x2 vaut : " << resultat2 << endl;
		}
		else
		{
			cout << "Impossible ! resolution dans les complexes" << endl;
		}
	}
	else if (x != 0)
	{
		double resultat;
		if (resolution(x, c, resultat) == 0)
		{
			cout << "x vaut : " << resultat << endl;
		}
		else
		{
			cout << "Erreur de divion par zero" << endl;
		}
	}
	else
	{
		cout << "Pas de x trouvé dans la chaine" << endl;
	}
	cout << endl << endl;
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

int decodage(string chaine,int &x2,int &x, int &c)
{
	int i = 0;
	int pos;
	int fin_chaine = 0;
	string tmp = "";
	c = 0;
	
	while (i < chaine.length() || fin_chaine)
	{
		if (chaine[i] == '+' || 
			chaine[i] == '-' || 
			chaine[i] == '=' ||
			fin_chaine == 1)
		{
			if ((pos = tmp.find("x2",0)) >= 0 )
			{
				tmp.erase(pos,2);
				x2 = stoi(tmp);
				tmp = chaine[i];
			}
			else if ((pos = tmp.find("x",0)) >= 0)
			{
				tmp.erase(pos, 1);
				x = stoi(tmp);
				tmp = chaine[i];
			}
			else
			{
				if (i > 1 && tmp != "")
				{
					if ((pos = tmp.find("=", 0)) >= 0)
					{
						tmp.erase(pos, 1);
						c -= stoi(tmp);
					}
					else
					{
						c += stoi(tmp);
					}
					tmp = chaine[i];
					fin_chaine = 0;
				}
				else //Signe au tout début de la chaine 
				{
					tmp += chaine[i];
				}
			}
		}
		else
		{
			tmp += chaine[i];
			if (i == chaine.length()-1)
				fin_chaine = 1;
		}

		if (!fin_chaine)
			i++;
	}

	return 0;
}

int verif(string chaine)
{
	unsigned int i;
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

int resolution(int x, int c, double &resultat)
{
	if (c != 0)
	{
		c = c *-1;
		resultat = (double)c / (double)x;
		return 0;
	}
	return 1;
}	

int resolution(int a, int b, int c, double &resultat1, double &resultat2)
{
	double racine;

	if ((racine = pow(b, 2) - 4*a*c) < 0)
	{
		return 1;
	}

	resultat1 = ((double)(-b) + sqrt(racine)) / (2 * (double)a);
	resultat2 = ((double)(-b) - sqrt(racine)) / (2 * (double)a);

	return 0;
}