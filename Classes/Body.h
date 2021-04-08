#pragma once
#include<list>
#include"cocos2d.h"
USING_NS_CC;

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
	Sprite3D* Build_Planet();
	auto seq = Sequence::create(nullptr);
private:
	double x;
	double y;
	double z;
	double m;
	double r;
	double vx;
	double vy;
	double vz;
	std::list<int> listx;
	std::list<int> listy;
	std::list<int> listz;
	Sprite3D* planet;
};
