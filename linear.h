#pragma once
#include "equation.h"
using namespace std;
class Linear : public Equation {
public:
	virtual ~Linear() = default;
	virtual void PrintFromFile();
	virtual void PrintToFile(std::fstream&, double a, double b, double c);
	virtual void Roots(double b, double c);
};