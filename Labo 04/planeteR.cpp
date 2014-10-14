
/*************************************************************************/
/*************************************************************************

A C++ Program to show the simulation of the Solar System.

*************************************************************************/
/*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "graphics.h"
#include <time.h>

const int NB_ETOILE = 5000;
using namespace std;

/*************************************************************************/
//-------------------------------  Planet  ------------------------------//
/*************************************************************************/

class Planet
{
private:
	int maxX, maxY, rayon;
	double deplacement;

public:

	static const int X_WINDOS_SIZE = 640;
	static const int Y_WINDOS_SIZE = 480;
	static const int X_MIDDLE = X_WINDOS_SIZE / 2;
	static const int Y_MIDDLE = Y_WINDOS_SIZE / 2;
	static const int DEGRE_MAX = 360;

	Planet::Planet(int x, int y, int ray, double dep);

	void Planet::Show();
	void Planet::ShowOrbit();

};

/*************************************************************************/
//-----------------------------  Planet( )  -----------------------------//
/*************************************************************************/

Planet::Planet(int x, int y, int ray, double dep)
{
	maxX = x;
	maxY = y;
	rayon = ray;
	deplacement = dep;
	ShowOrbit();
	Show();
}


/*************************************************************************/
//----------------------------  ShowOrbit( )  ---------------------------//
/*************************************************************************/
void Planet::ShowOrbit()
{
	ellipse(X_MIDDLE, Y_MIDDLE, 0, DEGRE_MAX, maxX, maxY);
}


/*************************************************************************/
//--------------------------------  Show( )  ----------------------------//
/*************************************************************************/
void Planet::Show()
{
	pieslice(X_MIDDLE + maxX , Y_MIDDLE, 0, DEGRE_MAX, rayon);
}


/*************************************************************************/
//--------------------------------  Move  -------------------------------//
/*************************************************************************/



/*************************************************************************/
//-------------------------  GetNextPosition( )  ------------------------//
/*************************************************************************/



/*************************************************************************/
/*************************************************************************/
/*******************************  main( )  *******************************/
/*************************************************************************/
/*************************************************************************/

int main(void)
{
	int driver = VGA;
	int mode = VGAHI;
	int error_code;
	srand((unsigned int)time(NULL));

	initgraph(&driver, &mode, "..\\Bgi");

	error_code = graphresult();

	if (error_code != grOk)
	{
		restorecrtmode();
		//textmode(BW80);
		//clrscr();

		cout << " \n Fatal Error  : Graphic Driver not initialized" << endl;
		cout << " Error Reason : " << grapherrormsg(error_code) << endl;
		cout << " \n Press any key to exit...";

		system("PAUSE");
		return EXIT_FAILURE;
	}

	// Dessine un rectangle autour de la fenêtre principale
	setlinestyle(0, 0, 3);
	setcolor(7);
	rectangle(0, 0, getmaxx(), getmaxy());
	setlinestyle(0, 0, 0);

	// Remplir le ciel de 5000 étoiles 
	// (générer 5000 positions aléatoirement avec des couleurs aléatoires entre 0 et 14
	srand(10);
	int i, couleur = 14;
	for (i = 0; i < NB_ETOILE; i++)
	{
		putpixel(rand() % Planet::X_WINDOS_SIZE, rand() % Planet::Y_WINDOS_SIZE, rand() % 14);
	}

	// Ecrit quelques textes dans la fenêtre
	settextstyle(1, 0, 1);
	setcolor(9);
	outtextxy(15, 10, "Simulation");
	settextstyle(3, 0, 1);
	setcolor(7);
	outtextxy(15, 450, "Presser une touche pour quitter");

	// Dessin le soleil
	setcolor(14);
	setfillstyle(1, 14);
	pieslice(Planet::X_MIDDLE, Planet::Y_MIDDLE, 0, Planet::DEGRE_MAX, 12);
	// dessine 2 petits cercles autour du soleil (juste pour faire joli) 
	setcolor(12);
	circle(Planet::X_MIDDLE, Planet::Y_MIDDLE, 12);
	setcolor(4);
	circle(Planet::X_MIDDLE, Planet::Y_MIDDLE, 13);

	// crée les planètes

	Planet Mercury(50, 30, 8, 0.0175);
	Planet Venus(80, 55, 8, 0.0155);
	Planet Earth(110, 80, 8, 0.0135);
	Planet Mars(140, 105, 8, 0.0115);
	Planet Jupiter(170, 130, 8, 0.0095);
	Planet Saturn(200, 155, 8, 0.0075);
	Planet Uranus(230, 180, 8, 0.0055);
	Planet Neptune(60, 205, 8, 0.0035);
	Planet Pluto(290, 230, 8, 0.0015);

	/*
	Mercury.Show();
	Venus.Show();
	Earth.Show();
	Mars.Show();
	Jupiter.Show();
	Saturn.Show();
	Uranus.Show();
	Neptune.Show();
	Pluto.Show();*/

	// crée les orbites


	// déplacement des planètes
	do
	{
		delay(25);
		// Mercury.Move();
		// ...
	} while (!kbhit());

	system("PAUSE");
	closegraph();
	return EXIT_SUCCESS;
}
