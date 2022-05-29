#include <iostream>
#include <cmath>
#include "equation.h"
using namespace std;
void Equation::PrintFromFile() {
	cout << a << "x^2+" << b << "x+" << c << "=0" << endl;
}
void Equation::PrintToFile(std::fstream& out, double a, double b, double c) {
	out << a << " " << b << " " << c << endl;
}
void Equation::Roots(double a, double b, double c) {
	if ((a == 0) && (b == 0) && (c == 0))
		cout << "There are an infinite number of solutions" << endl;
	else if ((a == 0) && (b == 0) && (c != 0))
		cout << "There are no solutions" << endl;
}
void Equation::Solutions(std::fstream& out, double a, double b, double c, double x1, double x2) {
	out << "Roots of" << a << "x^2+(" << b << ")*x+(" << c << ") = 0 : " << x1 << "and" << x2<< endl;
}