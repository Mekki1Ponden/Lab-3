#include "linear.h"
using namespace std;
void Linear::Roots(double b, double c) {
	system("cls");
	Equation::Roots(0, b, c);
	double x = -c / b;
	cout << "x = " << x << endl;
}
void Linear::PrintFromFile() {
	Equation::PrintFromFile();
}
void Linear::PrintToFile(std::fstream& out, double a, double b, double c) {
	out << "l ";
	Equation::PrintToFile(out, a, b, c);
}