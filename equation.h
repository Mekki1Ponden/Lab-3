#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Equation {
private:
	int a, b, c;
public:
	virtual ~Equation() = 0 {};
	Equation() { a = 0; b = 0; c = 0; };
	virtual void PrintFromFile();
	virtual void PrintToFile(std::fstream&, double a, double b, double c);
	virtual void Solutions(std::fstream&, double a, double b, double c, double x1, double x2);
	virtual void Roots(double a, double b, double c);
};