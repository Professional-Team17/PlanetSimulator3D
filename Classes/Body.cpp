#include "Body.h"

double _cbrt(double x)
{
	double x0 = 1, x1 = x0 - (x0 * x0 * x0 - x) / (3 * x0 * x0);
	while (x0 - x1 > 0.00000000000001 || x0 - x1 < -0.00000000000001)
	{
		x0 = x1 - (x1 * x1 * x1 - x) / (3 * x1 * x1);
		x1 = x0 - (x0 * x0 * x0 - x) / (3 * x0 * x0);
	}
	return x1;
}
Body::Body()
{
	x = rand() % GENERATE_WIDTH;
	y = rand() % GENERATE_HEIGHT;
	z = rand() % GENERATE_LENTH;
	m = rand() % 500 + 10.;
	r = _cbrt(m * SK);
	vx = (rand() & 1 ? 1 : -1) * (rand() % 401 / 200.);
	vy = (rand() & 1 ? 1 : -1) * (rand() % 401 / 200.);
	vz = (rand() & 1 ? 1 : -1) * (rand() % 401 / 200.);
	for (int i = 0; i < MAXLENGTH; i++)
	{
		listx.push_back(x);
		listy.push_back(y);
		listz.push_back(z);
	}
	planet = Build_Planet();
	planet->setPosition3D(Vec3(x, y, z));
	scene->addChild(planet);
}
void Body::move()
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
void Body::show()
{
	if (m > 0)
	{
		seq.(MoveTo::create(T, Vec3(x, y, z)));
		std::list<int>::iterator itx1 = listx.begin(), itx2 = itx1, ity1 = listy.begin(), ity2 = ity1, itz1 = listz.begin(), itz2 = itz1;
		++itx2;
		++ity2;
		++itz2;
		while (itx2 != listx.end())
		{
			
			++itx1;
			++itx2;
			++ity1;
			++ity2;
			++itz1;
			++itz2;
		}
	}
}
void Body::gravitation(Body& a, Body& b)
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
				a.r = _cbrt(a.m * SK);
				b.m = 0;
				b.r = 0;
				b.vx = 0;
				b.vy = 0;
				b.vz = 0;
				//scene->removeChild(b.planet);
			}
			else
			{
				b.vx = (a.m * a.vx + b.m * b.vx) / (a.m + b.m);
				b.vy = (a.m * a.vy + b.m * b.vy) / (a.m + b.m);
				b.vz = (a.m * a.vz + b.m * b.vz) / (a.m + b.m);
				b.m += a.m;
				b.r = _cbrt(b.m * SK);
				a.m = 0;
				a.r = 0;
				a.vx = 0;
				a.vy = 0;
				a.vz = 0;
				//scene->removeChild(a.planet);
			}
		}
	}
}
Sprite3D* Body::Build_Planet() {
	auto sprite = Sprite3D::create("Sprite3DTest/sphere.c3b");
	sprite->setScale(r/ 100 / sprite->getContentSize().width);
	return sprite;
}