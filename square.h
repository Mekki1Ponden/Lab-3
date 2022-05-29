#pragma once
#include "equation.h"
using namespace std;
class Square : public Equation {
public:
	virtual ~Square() = default;
	virtual void PrintFromFile();
	virtual void PrintToFile(std::fstream&, double a, double b, double c);
	virtual void Roots(double a, double b, double c);
};
