#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cmath>

const double SK = 0.23873241463784;
const double G = 0.1;
const double T = 0.5;
const int GENERATE_WIDTH = 960;
const int GENERATE_HEIGHT = 960;
const int GENERATE_LENTH = 960;
const int BODYNUMS = 800;
const int MAXLENGTH = 100;

double cbrt(double x)
{
	double x0 = 1, x1 = x0 - (x0 * x0 * x0 - x) / (3 * x0 * x0);
	while (x0 - x1 > 0.00000000000001 || x0 - x1 < -0.00000000000001)
	{
		x0 = x1 - (x1 * x1 * x1 - x) / (3 * x1 * x1);
		x1 = x0 - (x0 * x0 * x0 - x) / (3 * x0 * x0);
	}
	return x1;
}


class Body
{
	public:
		Body()
		{
			x = rand() % GENERATE_WIDTH;
			y = rand() % GENERATE_HEIGHT;
			z = rand() % GENERATE_LENTH;
			m = rand() % 500 + 10.;
			r = cbrt(m * SK);
			vx = (rand() & 1 ? 1 : -1) * (rand() % 401 / 200.);
			vy = (rand() & 1 ? 1 : -1) * (rand() % 401 / 200.);
			vz = (rand() & 1 ? 1 : -1) * (rand() % 401 / 200.);
			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;
			for (int i = 0; i < MAXLENGTH; i++)
			{
				listx.push_back(x);
				listy.push_back(y);
				listz.push_back(z);
			}
		}
		void move()
		{
			if (m > 0)
			{
				x += vx * T;
				y += vy * T;
				z += vz * T;
				listx.push_back(x);
				listy.push_back(y);
				listz.push_back(z);
				listx.pop_front();
				listy.pop_front();
				listz.pop_front();
			}
		}
		void show()
		{
			if (m > 0)
			{
				std::list<int>::iterator itx1 = listx.begin(), itx2 = itx1, ity1 = listy.begin(), ity2 = ity1,itz1 = listz.begin(), itz2 = itz1;
				++itx2;
				++ity2;
				++itz2;
				while (itx2 != listx.end())
				{
					//////
					++itx1;
					++itx2;
					++ity1;
					++ity2;
					++itz1;
					++itz2;
				}
			}
		}
		static void gravitation(Body &a, Body &b)
		{
			double tmp1, tmp2;
			if (a.m > 0 && b.m > 0)
			{
				if ((a.r + b.r) * (a.r + b.r) < (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z))
				{
					tmp1 = G * b.m / ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z));
					tmp2 = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z));
					a.vx += tmp1 * ((b.x - a.x) / tmp2);
					a.vy += tmp1 * ((b.y - a.y) / tmp2);
					a.vz += tmp1 * ((b.z - a.z) / tmp2);
				}
				else
				{
					if (a.m >= b.m)
					{
						a.vx = (a.m * a.vx + b.m * b.vx) / (a.m + b.m);
						a.vy = (a.m * a.vy + b.m * b.vy) / (a.m + b.m);
						a.vz = (a.m * a.vz + b.m * b.vz) / (a.m + b.m);
						a.m += b.m;
						a.r = cbrt(a.m * SK);
						b.m = 0;
						b.r = 0;
						b.vx = 0;
						b.vy = 0;
						b.vz = 0;
					}
					else
					{
						b.vx = (a.m * a.vx + b.m * b.vx) / (a.m + b.m);
						b.vy = (a.m * a.vy + b.m * b.vy) / (a.m + b.m);
						b.vz = (a.m * a.vz + b.m * b.vz) / (a.m + b.m);
						b.m += a.m;
						b.r = cbrt(b.m * SK);
						a.m = 0;
						a.r = 0;
						a.vx = 0;
						a.vy = 0;
						a.vz = 0;
					}
				}
			}
		}
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

int main(int argc, char *argv[])
{
	srand(time(NULL));
	Body bodys[BODYNUMS];


	/*
	while ()
	{
		for (int i = 0; i < BODYNUMS; i++)
		{
			bodys[i].move();
			for (int j = 0; j < BODYNUMS; j++)
			{
				if (i != j) Body::gravitation(bodys[i], bodys[j]);
			}
			bodys[i].show();
		}
	}
*/
	return 0;
}