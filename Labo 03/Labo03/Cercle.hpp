class Cercle
{
public:
	Cercle();
	Cercle(double val_x, double val_y, double val_r = 0);

	void setCenter(double x, double y){ this->x = x; this->y = y; };
	void setRayon(double r){ rayon = r; };
	double Surface();

	void getCenter(double &x, double &y);
	double getRayon(){ return rayon; };
	int estInterieur(double x, double y);

	~Cercle();

private:
	double x;
	double y;
	double rayon;
};
