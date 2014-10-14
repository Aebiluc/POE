
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

using namespace std;

/*************************************************************************/
//-------------------------------  Planet  ------------------------------//
/*************************************************************************/

class Planet
{
private:


public:

	static const int X_WINDOS_SIZE = 640;
	static const int Y_WINDOS_SIZE = 480;
	static const int X_MIDDLE = X_WINDOS_SIZE / 2;
	static const int Y_MIDDLE = Y_WINDOS_SIZE / 2;
	static const int DEGRE_MAX = 360;
};

/*************************************************************************/
//-----------------------------  Planet( )  -----------------------------//
/*************************************************************************/



/*************************************************************************/
//----------------------------  ShowOrbit( )  ---------------------------//
/*************************************************************************/



/*************************************************************************/
//--------------------------------  Show( )  ----------------------------//
/*************************************************************************/



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

	// Dessine un rectangle autour de la fen�tre principale
	setlinestyle(0, 0, 3);
	setcolor(7);
	rectangle(0, 0, getmaxx(), getmaxy());
	setlinestyle(0, 0, 0);

	// Remplir le ciel de 5000 �toiles 
	// (g�n�rer 5000 positions al�atoirement avec des couleurs al�atoires entre 0 et 14


	// Ecrit quelques textes dans la fen�tre
	settextstyle(1, 0, 1);
	setcolor(9);
	outtextxy(15, 10, "Simulation");


	// Dessin le soleil
	setcolor(14);
	setfillstyle(1, 14);
	pieslice(Planet::X_MIDDLE, Planet::Y_MIDDLE, 0, Planet::DEGRE_MAX, 12);
	// dessine 2 petits cercles autour du soleil (juste pour faire joli) 
	setcolor(12);
	circle(Planet::X_MIDDLE, Planet::Y_MIDDLE, 12);
	setcolor(4);
	circle(Planet::X_MIDDLE, Planet::Y_MIDDLE, 13);

	// cr�e les plan�tes


	// cr�e les orbites


	// d�placement des plan�tes
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