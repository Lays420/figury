#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cmath>
int wybor;
double a, a2, b, ab2, ab;
using namespace std;

int main()
{
	setlocale(LC_ALL, "polish");
kwdrat:
	cout << "[1]kwadrat [2]prostokąt [3]trójkąt [4]koło [5]rąb [6]\n" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		goto label2;
	label2:
		cout << "[1]obwód [2]pole [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto label2a;
		label2a:
			cout << "wprowadź bok kwadratu\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << endl << "bok nie może być mniejszy lub równy 0\n";
				cout << endl;
			}
			else {}
			cout << endl << "obwód kwdrtu o boku " << a << endl << " wynosi " << a * 4;
			cout << endl;
			goto label2;
		case 2:
			goto label2b;
		label2b:
			cout << "wprowadź bok kwadratu\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << endl << "bok nie może być mniejszy lub równy 0\n";
				cout << endl;
			}
			else{}
			cout << endl << "pole kwadratu o boku " << a << endl << " wynosi " << pow(a, 2);
			cout << endl;
			goto label2;
		case 3:
			goto kwdrat;
		}
	case 2:
		goto label3;
	label3:
		cout << "[1]obwód [2]pole [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto label3a;
		label3a:
			cout << "wprowadź boki prostokątu\n" << endl;
			cin >> a;
			cin >> b;
			if (a <= 0 || b <= 0)
			{
				cout << endl << "żaden z boków nie może być mniejszy lub równy 0\n";
				cout << endl;
			}
			ab2 = 2 * (a + b);
			cout << endl << "obwód prostokątu o bokach " << a << " " << b << endl << " wynosi " << ab2;
			cout << endl;
			goto label3;
		case 2:
			goto label3b;
		label3b:
			cout << "wprowadź boki prostokątu\n" << endl;
			cin >> a;
			cin >> b;
			if (a <= 0 || b <= 0)
			{
				cout << endl << "żaden z boków nie może być mniejszy lub równy 0\n";
				cout << endl;
			}
			ab = a * b;
			cout << endl << "pole prostokątu o bokach " << a << " " << b << endl << " wynosi " << ab;
			cout << endl;
			goto label3;
		case 3:
			goto label1;
		}
	}
}