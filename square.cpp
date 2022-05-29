#include "square.h"
using namespace std;
void Square::Roots(double a, double b, double c) {
	system("cls");
	Equation::Roots(a, b, c);
	double d = b * b - 4 * a * c;
	if (d > 0) {
		d = sqrt(d);
		double x1 = (-b + d) / (2 * a);
		double x2 = (-b - d) / (2 * a);
		cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	}
	else if (d == 0) {
		double x1 = (-b) / (2 * a);
		double x2 = x1;
		cout << "x1 = x2 = " << x1 << endl;
	}
	else if (d < 0) {
		cout << "There are no solutions" << endl;
	}
}
void Square::PrintFromFile() {
	Equation::PrintFromFile();
}
void Square::PrintToFile(std::fstream& out, double a, double b, double c) {
	out << "s ";
	Equation::PrintToFile(out, a, b, c);
}