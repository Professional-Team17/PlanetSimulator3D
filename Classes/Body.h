#pragma once
#include<list>
const double SK = 0.23873241463784;
const double G = 0.1;
const double T = 0.5;
const int GENERATE_WIDTH = 960;
const int GENERATE_HEIGHT = 960;
const int GENERATE_LENTH = 960;
const int BODYNUMS = 800;
const int MAXLENGTH = 100;

class Body
{
public:
	Body();
	void move();
	void show();
	static void gravitation(Body& a, Body& b);
private:
	double x;
	double y;
	double z;
	double m;
	double r;
	double vx;
	double vy;
	double vz;
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	std::list<int> listx;
	std::list<int> listy;
	std::list<int> listz;
};
