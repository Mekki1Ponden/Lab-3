#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "linear.h"
#include "square.h"
#include "equation.h"
using namespace std;
int main() {
	Linear L;
	Square S;
	string flag;
	string str;
	char* pch;
	string temp;
	char buff[100];
	double a, b, c, eror;
	int cnt = 0;
	int ind = 0;
	double acur, bcur, ccur;
	double choice = 0;
	int i, len = 0;
	acur = -100;
	bcur = -100;
	ccur = -100;
	ifstream input("input.txt");
	fstream input1("input.txt");
	fstream output("input.txt");
	
	
	for (;;) {
		eror = 0;
		cout << "Calculating Equations:" << endl;
		cout << "---------------------------" << endl;
		cout << "1 - Select the current equation" << endl;
		cout << "2 - Solve the current equation" << endl;
		cout << "3 - Add a new equation to the database" << endl;
		cout << "4 - Exit" << endl;
		cout << "---------------------------" << endl;
		cout << "Select an operation and type its number" << endl;
		cin >> flag;
		if (flag == "1") {
			cout << "---------------------------" << endl;
			cout << "1 - Enter the equation" << endl;
			cout << "2 - Select from the database" << endl;
			cout << "---------------------------" << endl;
			cout << "Select an operation and type its number" << endl;
			cin >> flag;
			if (flag == "1") {
				cout << "1 - Enter the square equation" << endl;
				cout << "2 - Enter a linear equation" << endl;
				cout << "Select an operation and type its n 3umber" << endl;
				cout << "---------------------------" << endl;
				cin >> flag;
				if (flag == "1") {
					eror = 0;
					cout << "The quadratic equation looks like: A*x^2 + B*x + C= 0" << endl;
						cout << "Enter A" << endl;
					cin >> temp;
					try {
						a = stoi(temp);
					}
					catch (std::invalid_argument e) {
						eror++;
					}
					cout << "Enter B" << endl;
					cin >> temp;
					try {
						b = stoi(temp);
					}
					catch (std::invalid_argument e) {
						eror++;
					}
					cout << "Enter C" << endl;
					cin >> temp;
					try {
						c = stoi(temp);
					}
					catch (std::invalid_argument e) {
						eror++;
					}
					if (eror > 0) {
						system("cls");
						cout << "An error occurred while writing the arguments, try entering them again" << endl;
					}
					else {
						system("cls");
						cout << "The operation completed successfully" <<
							endl;
						acur = a;
						bcur = b;
						ccur = c;
					}
				}
				else if (flag == "2") {
					cout << "The linear equation looks like: B*x + C = 0" << endl;
					a = 0;
					eror = 0;
					cout << "Enter B" << endl;
					cin >> temp;
					try {
						b = stoi(temp);
					}
					catch (std::invalid_argument e) {
						eror++;
					}
					cout << "Enter C" << endl;
					cin >> temp;
					try {
						c = stoi(temp);
					}
					catch (std::invalid_argument e) {
						eror++;
					}
					if (eror > 0) {
						system("cls");
						cout << "An error occurred while writing thearguments, try entering them again" << endl;
					}
					else {
						system("cls");
						cout << "The operation completed successfully" <<
							endl;
						acur = a;
						bcur = b;
						ccur = c;
					}
				}
				else {
					system("cls");
					cout << "An error occurred while writing the arguments, tryentering them again" << endl;
				}
			}
			else if (flag == "2") {
				cout << "---------------------------" << endl;
				cnt = 0;
				ifstream input("input.txt");
				if (input.eof())
					cout << "Database is empty" << endl;
				ind = 0;
				while (!input.eof()) {
					getline(input, str);
					ind++;
					cnt = 0;
					cnt++;
					for (i = 0; i < 100; i++)
						buff[i] = ' ';
					if (str[0] == 's') {
						for (i = 2; i < str.size(); i++) {
							buff[cnt] = str[i];
							cnt++;
						}
						pch = strtok(buff, " ");
						a = atoi(pch);
						pch = strtok(NULL, " ");
						b = atoi(pch);
						pch = strtok(NULL, " ");
						c = atoi(pch);
						cout << ind << ": " << a << "x^2+(" << b <<
							")*x+(" << c << ")=0 " << endl;
					}
					else if (str[0] == 'l') {
						for (i = 2; i < str.size(); i++) {
							buff[cnt] = str[i];
							cnt++;
						}
						pch = strtok(buff, " ");
						a = atoi(pch);
						pch = strtok(NULL, " ");
						b = atoi(pch);
						pch = strtok(NULL, " ");
						c = atoi(pch);
						cout << ind << ": " << b << "*x+(" << c <<
							")=0 " << endl;
					}
				}
				cout << "---------------------------" << endl;
				cout << "Select the equalization" << endl;
				cin >> temp;
				try {
					choice = stoi(temp);
					if ((choice > 0) && (choice <= ind)) {
						cnt = 0;
						ifstream input("input.txt");
						while (cnt != choice) {
							getline(input, str);
							cnt++;
						}
						for (i = 0; i < 100; i++)
							buff[i] = ' ';
						if (str[0] == 's') {
							for (i = 2; i < str.size(); i++) {
								buff[cnt] = str[i];
								cnt++;
							}
							pch = strtok(buff, " ");
							acur = atoi(pch);
							pch = strtok(NULL, " ");
							bcur = atoi(pch);
							pch = strtok(NULL, " ");
							ccur = atoi(pch);
						}
						else if (str[0] == 'l') {
							for (i = 2; i < str.size(); i++) {
								buff[cnt] = str[i];
								cnt++;
							}
							pch = strtok(buff, " ");
							acur = atoi(pch);
							pch = strtok(NULL, " ");
							bcur = atoi(pch);
							pch = strtok(NULL, " ");
							ccur = atoi(pch);
						}
						system("cls");
						cout << "The operation completed successfully" <<
							endl;
					}
					else {
						system("cls");
						cout << "An error occurred while writing thearguments, try entering them again" << endl;
					}
				}
				catch (std::invalid_argument e) {
					system("cls");
					cout << "An error occurred while writing the arguments, tryentering them again" << endl;
				}
}
			else {
			system("cls");
			cout << "An error occurred while writing the arguments, try entering them again" << endl;
}
}
else if (flag == "2") {
system("cls");
if ((acur != -100) && (bcur != -100) && (ccur != -100)) {
	if ((acur == 0) || (acur == -100))
		L.Roots(bcur, ccur);
	else
		S.Roots(acur, bcur, ccur);
}
else
cout << "Equation not selected" << endl;
}
else if (flag == "3") {
cout << "1 - Enter the square equation" << endl;
cout << "2 - Enter a linear equation" << endl;
cout << "Select an operation and type its number" << endl;
cout << "---------------------------" << endl;
cin >> flag;
if (flag == "1") {
	eror = 0;
	cout << "The quadratic equation looks like: A*x^2 + B*x + C = 0" << endl;
	cout << "Enter A" << endl;
	cin >> temp;
	try {
		a = stoi(temp);
	}
	catch (std::invalid_argument e) {
		eror++;
	}
	cout << "Enter B" << endl;
	cin >> temp;
	try {
		b = stoi(temp);
	}
	catch (std::invalid_argument e) {
		eror++;
	}
	cout << "Enter C" << endl;
	cin >> temp;
	try {
		c = stoi(temp);
	}
	catch (std::invalid_argument e) {
		eror++;
	}
	if (eror > 0) {
		system("cls");
		cout << "An error occurred while writing the arguments, try entering them again" << endl;
	}
	else {
		system("cls");
		cout << "The operation completed successfully" << endl;
		S.PrintToFile(input1, a, b, c);
	}
}
else if (flag == "2") {
	eror = 0;
	cout << "The linear equation looks like: B*x + C = 0" << endl;
	a = 0;
	cout << "Enter B" << endl;
	cin >> temp;
	try {
		b = stoi(temp);
	}
	catch (std::invalid_argument e) {
		eror++;
	}
	cout << "Enter C" << endl;
	cin >> temp;
	try {
		c = stoi(temp);
	}
	catch (std::invalid_argument e) {
		eror++;
	}
	if (eror > 0) {
		system("cls");
		cout << "An error occurred while writing the arguments, try entering them again" << endl;
	}
	else {
		system("cls");
		cout << "The operation completed successfully" << endl;
		acur = a;
		bcur = b;
		ccur = c;
		L.PrintToFile(input1, 0, b, c);
	}
}
else {
	system("cls");
	cout << "An error occurred while writing the arguments, try entering them again" << endl;
}
}
else if (flag == "4") {
system("cls");
break;
}
else {
system("cls");
cout << "The operation number is invalid" << endl;
}
cout << "---------------------------" << endl;
}
return 0;
input.close();
output.close();
}
