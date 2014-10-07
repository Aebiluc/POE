#include "Cercle.hpp"

#define _USE_MATH_DEFINES
#include <math.h>


Cercle::Cercle()
{
	x = 0;
	y = 0;
	rayon = 0;
}

Cercle::Cercle(double val_x, double val_y, double val_r)
{
	x = val_x;
	y = val_y;
	rayon = val_r;
}

void Cercle::getCenter(double &x , double &y)
{
	x = this->x;
	y = this->y;
}

int Cercle::estInterieur(double x, double y)
{
	return 0;
}

double Cercle::Surface()
{
	return M_PI * pow(rayon, 2);
}

Cercle::~Cercle()
{
}