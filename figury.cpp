#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
int wybor;
double a, a2, a3, b, b2, ab2, ab, c, c2, abc, d;
using namespace std;

int main()
{
	setlocale(LC_ALL, "polish");
figury:
	cout << "[1]kwadrat [2]prostokąt [3]trójkąt [4]koło [5]rąb [6]równoległobok [7]trapez\n[8]sześcian [9]prostopadłościan [10]stożek\n" << endl;
	cout << "[11]ostrosłup [12]walec [13]kula [14]opuść [15]wyczyść ekran\n" << endl;
	cin >> wybor;
	cout << endl;
	switch (wybor)
	{
	case 1:
		goto kwadrat;
	kwadrat:
		// Square Menu: Perimeter, Area, Side Calculation
		cout << "[1]obwód [2]pole [3]bok [4]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto kwadrat_obwod;        //   obwod kwadrat
		kwadrat_obwod:
			// Square Perimeter Calculation: P = 4 * a
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
			goto kwadrat;              //   obwod kwadrat
		case 2:
			goto kwadrat_pole;         //   pole kwadrat
		kwadrat_pole:
			// Square Area Calculation: A = a^2
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
			goto figury;               //   pole kwadrat
		case 3:
			goto kwadrat_bok;
		kwadrat_bok:
			// Calculate side from Area or Perimeter
			cout << "[1]bok z pola [2]bok z obwodu [3]powót\n" << endl;
			cin >> wybor;
			switch (wybor)
			{
			case 1:
				goto bok_pole;
			bok_pole:
				// Side from Area: a = sqrt(A)
				cout << "wprowadz pole kwdratu\n" << endl;
				cin >> a;
				cout << "bok kwdratu o polu " << a << " wynosi " << sqrt(a) << endl;
				cout << endl;
				goto kwadrat_pole;
			case 2:
				goto bok_obw;
			bok_obw:
				// Side from Perimeter: a = P / 4
				cout << "wprowadz obwód kwdratu\n" << endl;
				cin >> a;
				cout << "bok kwdratu o obwodzie " << a << " wynosi " << a / 4 << endl;
				cout << endl;
				goto kwadrat_pole;
			case 3:
				goto kwadrat;
			}
		case 4:
			goto kwadrat;
		default:
			goto figury;;
		}
	case 2:
		goto prostokat;
	prostokat:
		// Rectangle Menu: Perimeter, Area
		cout << "[1]obwód [2]pole [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto prostokat_obwod;
		prostokat_obwod:
			// Rectangle Perimeter Calculation: P = 2 * (a + b)
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
			goto prostokat;
		case 2:
			goto prostokat_pole;
		prostokat_pole:
			// Rectangle Area Calculation: A = a * b
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
			goto prostokat;
		case 3:
			goto figury;
		}
	case 3:
		goto trojkat;
	trojkat:
		// Triangle Menu: Perimeter, Area, Pythagoras
		cout << "[1]obwod [2]pole [3]pitagoras [4]pitagoras_odwrotność [5]powrót\n" << endl;
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{
		case 1:
			goto trojkat_obwod;
		trojkat_obwod:
			cout << "[1]t_rownoboczny [2]t_rownoramienny [3]t_roznoboczny\n" << endl;
			cin >> wybor;
			cout << endl;
			switch (wybor)
			{
			case 1:
				goto rownoboczny;
			rownoboczny:
				// Equilateral Triangle Perimeter: P = 3 * a
				cout << "wprowadź bok\n" << endl;
			cin >> a;
				if (a <= 0)
				{
					cout << "bok nie moze być mniejszy lub równy 0\n" << endl;
					goto rownoboczny;
				}
				a2 = 3 * a;
				cout << "obwot tróąta równobocznego o boku " << a << " wynosi " << a2;
				goto trojkat_obwod;
			case 2:
				goto rownoramienny;
			rownoramienny:
				// Isosceles Triangle Perimeter: P = a + 2 * b
				cout << "wprowadź podstawe\n" << endl;
				cin >> a;
				if (a <= 0) {
					cout << "podstawa nie może być mniejsza lub równa 0\n" << endl;
					goto rownoramienny;
				}
				cout << "wprowadź bok\n" << endl;
				cin >> b;
				b2 = 2 * b;
				if (b <= 0) {
					cout << "bok nie może być mniejzsy lub równy 0\n" << endl;
					goto rownoramienny;
				}
				if (b2 <= a)
				{
					cout << "dum ramion nie może byc mniejsza lub równa podstawie\n" << endl;
					goto rownoramienny;
				}
				ab2 = a + (2 * b);
				cout << endl << "obwód trujkąta o podstawie " << a << " i bokach " << b << " wynosi " << ab2 << endl;
				cout << endl;
				goto trojkat_obwod;
			case 3:
				goto roznoramienny;
			roznoramienny:
				// Scalene Triangle Perimeter: P = a + b + c
				cout << "wprowadź pierwszy bok\n" << endl;
				cin >> a;
				if (a <= 0)
				{
					cout << "bok nie może być mniejszy lub równy 0\n" << endl;
					goto roznoramienny;
				}
				cout << endl;
				cout << "wprowadź drugi bok\n" << endl;
				cin >> b;
				if (b <= 0)
				{
					cout << "bok nie może być mniejszy lub równy 0\n" << endl;
					goto roznoramienny;
				}
				cout << endl;
				cout << "wprowadź trzeci bok\n" << endl;
				cin >> c;
				if (c <= 0)
				{
					cout << "bok nie może być mniejszy lub równy 0\n" << endl;
					goto roznoramienny;
				}
				if (a + b <= c || a + c <= b || b + c <= a)
				{
					cout << "wprowadź inną wartość boku/boków\nsuma dwóch boków trójkąta musi być większa od trezeciego\n" << endl;
					goto roznoramienny;
				}
				abc = a + b + c;
				cout << " obwód trojkt różnobocznego o bokach " << a << " " << b << " i " << c << " wynosi " << abc;
				cout << endl;
				goto trojkat_pole;
			case 4:
				goto trojkat;
			}
		case 2:
			goto trojkat_pole;
		trojkat_pole:
			cout << "[1]dowolny trojkąt [2]trójkąt równobozcny [3]powrót\n" << endl;
			cin >> wybor;
			cout << endl;
			switch (wybor)
			{
			case 1:
				goto dowolny;
			dowolny:
			// Triangle Area: A = (a * h) / 2
			cout << endl << "wprowadź podstawę\n";
			cin >> a;
			if (a <= 0)
			{
				cout << "podstawa nie może być mniejsza lub równa 0\n" << endl;
				goto trojkat_pole;
			}
			cout << endl << "wprowadź wysokość\n";
			cin >> b;
				if (b <= 0)
				{
					cout << "wysokość nie może być mniejsza lub równa 0\n" << endl;
					goto trojkat_pole;
				}
			ab = (a * b) / 2;
			cout << endl;
			cout << "pole trojkąta o podstawie " << a << " i wysokości " << b << " wynosi " << ab;
			cout << endl;
				goto trojkat_pole;
			case 2:
				goto pole_rownoboczny;
			pole_rownoboczny:
				// Equilateral Triangle Area: A = (a^2 * sqrt(3)) / 4
				cout << "wprowadź bok trójkąt\n" << endl;
				cin >> a;
				a2 = a * a;
				b = sqrt(3);
				c = (a2 * b) / 4;
				cout << endl << "pole trójkąta o boku " << a << " wynosi " << c << endl;
				goto trojkat_pole;
			case 3:
				goto trojkat;
			}
		case 3:
			goto pitagoras;
		pitagoras:
			// Pythagorean Theorem: a^2 + b^2 = c^2 (Calculate c)
			cout << "wprowadź pierwszy bok\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "bok nie może byc mniejszy lub równy 0\n" << endl;
				goto pitagoras;
			}
			a2 = a * a;
			cout << "wprowadź drugi bok\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "bok nie może byc mniejszy lub równy 0\n" << endl;
				goto pitagoras;
			}
			b2 = b * b;
			c2 = a2 + b2;
			c = sqrt(c2);
			cout << "przeciwprostokątna trójkąta o bokach " << a << " i " << b << " wynosi " << c << endl;
			goto trojkat;
		case 4:
			goto pitagoras_2;
		pitagoras_2:
			// Inverse Pythagoras: Given c^2 (approx), find legs assuming isosceles right triangle?
			// The logic assumes a = b = c_input / 2, then legs = sqrt(a) which implies c_input was c^2/2?
			// Wait, the code says "kwadrat przeciwprostokątnej". If input is c^2.
			// Then legs a=b. a^2 + a^2 = c^2 => 2a^2 = c^2 => a^2 = c^2/2.
			// Code: b = a/2. (input a is c^2). so b = c^2/2 = leg^2.
			// b2 = sqrt(b) => leg. Correct.
			cout << endl << "wrowadź kwadrat przeciwprostokątnej(dowolna liczba)\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto pitagoras_2;
			}
			b = a / 2;
			b2 = sqrt(b);
			cout << "dwie przyprostokątne równe są po " << b2 << " każda\n" << endl;
			goto trojkat;
		case 5:
			goto figury;
		}
	case 4:
		goto kolo;
	kolo:
		// Circle Menu: Perimeter (Circumference), Area
		cout << "[1]obwód [2]pole [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto kolo_obwod;
		kolo_obwod:
			// Circle Circumference: L = 2 * Pi * r
			cout << "wprowadź promień\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto kolo_obwod;
			}
			b = 2 * M_PI * a;
			cout << "obwód koła o promieniu " << a << " wynosi " << b << endl;
			goto kolo;
		case 2:
			goto kolo_pole;
		kolo_pole:
			// Circle Area: A = Pi * r^2
			cout << "wprowadź promień\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto kolo_pole;
			}
			a2 = a * a;
			b = M_PI * a2;
			cout << endl << "pole koła o promieniu " << a << " wynosi " << b << endl;
			goto kolo;
		case 3:
			goto figury;
		defalut:
			goto kolo;
		}
	case 5:
		goto rab;
	rab:
		// Rhombus (Rąb) Menu: Perimeter, Area
		cout << "[1]obwód [2]pole [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto obwod_rab;
		obwod_rab:
			// Rhombus Perimeter: P = 4 * a
			cout << "wprowadź bok\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto obwod_rab;
			}
			a2 = a * 4;
			cout << endl << "obwod rąbu o boku " << a << " wynosi " << a2 << endl;
			goto rab;
		case 2:
			goto rab_pole;
		rab_pole:
			// Rhombus Area: A = a * h
			cout << "wprowadź bok\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto rab_pole;
			}
			cout << "wprowadź wysokość\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto rab_pole;
			}
			c = a * b;
			cout << endl << "pole rąbu o boku <<" << a << " i wysokości " << b << " wynosi " << c << endl;
			goto rab;
		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 6:
		goto rownoleglobok;
	rownoleglobok:
		// Parallelogram Menu: Perimeter, Area
		cout << "[1]obwód [2]pole [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto obwod_rownoleglobok;
		obwod_rownoleglobok:
			// Parallelogram Perimeter: P = 2 * (a + b)
			cout << "wprowadź bok\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto obwod_rownoleglobok;
			}
			cout << "wprowadź drugi bok\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto obwod_rownoleglobok;
			}
			a2 =  (a + b) * 2;
			cout << endl << "obwod równoległoboku o boku " << a << " i " << b << " wynosi " << a2 << endl;
			goto rownoleglobok;
		case 2:
			goto rownoleglobok_pole;
		rownoleglobok_pole:
			// Parallelogram Area: A = a * h
			cout << "wprowadź bok\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto rownoleglobok_pole;
			}
			cout << "wprowadź wysokość\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto rownoleglobok_pole;
			}
			c = a * b;
			cout << endl << "pole rąbu o boku <<" << a << " i wysokości " << b << " wynosi " << c << endl;
			goto rownoleglobok;
		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 7:
		goto trapez;
	trapez:
		// Trapezoid Menu: Perimeter, Area
		cout << "[1]obwód [2]pole [3]powrót\n" << endl;
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{
		case 1:
			goto trapez_obwod;
		trapez_obwod:
			// Trapezoid Perimeter: P = a + b + c + d
			cout << "wprowadź pierwszą podstwę\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto trapez_obwod;
			}
			cout << "wprowadź drugą podstwę\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto trapez_obwod;
			}
			cout << "wprowadź pierwszy bok\n" << endl;
			cin >> c;
			if (c <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto trapez_obwod;
			}
			cout << "wprowadź drugi bok\n" << endl;
			cin >> d;
			if (d <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto trapez_obwod;
			}
			a2 = a + b + c + d;
			cout << endl << "obwód trapezu o bokach " << c << " i " << d << " oraz podstawach" << a << " i " << b << " wynosi " << a2;
			cout << endl;
			goto trapez;
		case 2:
			goto trapez_pole;
		trapez_pole:
			// Trapezoid Area: A = ((a + b) * h) / 2
			cout << "wprowadź pierwszą podstwę\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto trapez_pole;
			}
			cout << "wprowadź drugą podstwę\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto trapez_pole;
			}
			cout << "wprowadź wyokość\n" << endl;
			cin >> c;
			if (c <= 0)
			{
				cout << "wprowadzana liczba nie możę być równa lub mniejsza od 0\n" << endl;
				goto trapez_pole;
			}
			a2 = (a + b) * c;
			b2 = a2 / 2;
			cout << endl << "pole trpezu o podstawach " << a << " i " << b << " oraz wysokości " << c << " wynosi " << b2;
			cout << endl;
			goto trapez;
		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 8:
		goto szescian;
	szescian:
		// Cube Menu: Surface Area, Volume
		cout << "[1]pole [2]objętość [3]powrót\n" << endl;
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{
		case 1:
			goto szescian_pole;
			szescian_pole:
			// Cube Surface Area: A = 6 * a^2
			cout << endl << "wprowadź krawędź\n" << endl;
			cin >> a;
			a2 = a * a;
			a3 = a2 * 6;
			cout << "pole powierzchni sześcianu o boku " << a << " wynosi " << a3 << endl;
			cout << endl;
			goto szescian;
		case 2:
			goto szescian_objetosc;
		szescian_objetosc:
			// Cube Volume: V = a^3
			cout << endl << "wprowadź krawędź\n" << endl;
			cin >> a;
			a2 = a * a * a;
			cout << endl << "objętość sześcianu o krawędzi " << a << " wynosi " << a2 << endl;
			cout << endl;
			goto szescian;
		case 3:
			cout << endl;
			goto figury;
		default:
			goto figury;
		}
	case 9:
		goto prostopadloscian;
		prostopadloscian:
		// Cuboid Menu: Surface Area, Volume
		cout << "[1]pole [2]objętość [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto prostopadloscian_pole;
		prostopadloscian_pole:
			// Cuboid Surface Area: A = 2 * (a*b + b*c + c*a)
			cout << endl << "wprowadź pierwszą krawędź\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << endl << "krawędź nei może być mniejszaa lub równa zeru\n" << endl;
				goto prostopadloscian_pole;
			}
			cout << endl << "wprowadź drugą krawędź\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << endl << "krawędź nei może być mniejszaa lub równa zeru\n" << endl;
				goto prostopadloscian_pole;
			}
			cout << endl << "wprowadź trzecią krawędź\n" << endl;
			cin >> c;
			if (c <= 0)
			{
				cout << endl << "krawędź nei może być mniejszaa lub równa zeru\n" << endl;
				goto prostopadloscian_pole;
			}
			a2 = (a * b);
			b2 = (b * c);
			c2 = (c * a);
			abc = (a2 + b2 + c2) * 2;
			cout << endl << "pole prostopadłościnu o krawędziach " << a << " " << b << " oraz " << c << " wynosi " << abc;
			cout << endl;
			goto prostopadloscian;
		case 2:
			goto prostopadloscian_objetosc;
		prostopadloscian_objetosc:
			// Cuboid Volume: V = a * b * c
			cout << endl << "wprowadź pierwszą krawędź\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << endl << "krawędź nie może być mniejsza lub równa zeru\n" << endl;
				goto prostopadloscian_objetosc;
			}
			cout << endl << "wprowadź drugą krawędź\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << endl << "krawędź nie może być mniejsza lub równa zeru\n" << endl;
				goto prostopadloscian_objetosc;
			}
			cout << endl << "wprowadź trzecią krawędź\n" << endl;
			cin >> c;
			if (c <= 0)
			{
				cout << endl << "krawędź nie może być mniejsza lub równa zeru\n" << endl;
				goto prostopadloscian_objetosc;
			}
			abc = a * b * c;
			cout << endl << "objętość prostopadłościanu o krawędziach " << a << " " << b << " oraz " << c << " wynosi " << abc << endl;
			cout << endl;
			goto prostopadloscian;
		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 10:
		goto stozek;
	stozek:
		// Cone Menu: Surface Area, Volume
		cout << "[1]pole [2]objętość [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto stozek_pole;
		stozek_pole:
			// Cone Total Surface Area: Pc = Pi * r * (r + l)
			cout << "wprowadź promień podstawy\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "promień nie może być mniejszy lub równy 0\n" << endl;
				goto stozek_pole;
			}
			cout << "wprowadź tworzącą stożka\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "tworząca nie może być mniejsza lub równa 0\n" << endl;
				goto stozek_pole;
			}
			c = M_PI * a * (a + b);
			cout << endl << "pole powierzchni całkowitej stożka o promieniu " << a << " i tworzącej " << b << " wynosi " << c << endl;
			goto stozek;

		case 2:
			goto stozek_objetosc;
		stozek_objetosc:
			// Cone Volume: V = (1/3) * Pi * r^2 * H
			cout << "wprowadź promień podstawy\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "promień nie może być mniejszy lub równy 0\n" << endl;
				goto stozek_objetosc;
			}
			cout << "wprowadź wysokość stożka\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wysokość nie może być mniejsza lub równa 0\n" << endl;
				goto stozek_objetosc;
			}
			// V = 1/3 * Pi * r^2 * H
			c = (M_PI * pow(a, 2) * b) / 3.0;
			cout << endl << "objętość stożka o promieniu " << a << " i wysokości " << b << " wynosi " << c << endl;
			goto stozek;

		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 11:
		goto ostroslup;
	ostroslup:
		// Pyramid Menu: Surface Area, Volume
		cout << "[1]pole [2]objętość [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto ostroslup_pole;
		ostroslup_pole:
			// Regular Square Pyramid Surface Area: Pc = a^2 + 4 * (1/2 * a * h_s)
			cout << "Obliczanie pola ostrosłupa prawidłowego czworokątnego." << endl;
			cout << "wprowadź długość boku podstawy\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "bok nie może być mniejszy lub równy 0\n" << endl;
				goto ostroslup_pole;
			}
			cout << "wprowadź wysokość ostrosłupa\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wysokość nie może być mniejsza lub równa 0\n" << endl;
				goto ostroslup_pole;
			}
			// h_s = sqrt(H^2 + (a/2)^2)
			{
				double h_s = sqrt(pow(b, 2) + pow(a / 2.0, 2));
				c = pow(a, 2) + 2 * a * h_s;
			}
			cout << endl << "pole powierzchni całkowitej ostrosłupa prawidłowego czworokątnego o boku podstawy " << a << " i wysokości " << b << " wynosi " << c << endl;
			goto ostroslup;

		case 2:
			goto ostroslup_objetosc;
		ostroslup_objetosc:
			// Regular Square Pyramid Volume: V = (1/3) * a^2 * H
			cout << "Obliczanie objętości ostrosłupa prawidłowego czworokątnego." << endl;
			cout << "wprowadź długość boku podstawy\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "bok nie może być mniejszy lub równy 0\n" << endl;
				goto ostroslup_objetosc;
			}
			cout << "wprowadź wysokość ostrosłupa\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wysokość nie może być mniejsza lub równa 0\n" << endl;
				goto ostroslup_objetosc;
			}
			// V = 1/3 * Pp * H = 1/3 * a^2 * H
			c = (pow(a, 2) * b) / 3.0;
			cout << endl << "objętość ostrosłupa o boku podstawy " << a << " i wysokości " << b << " wynosi " << c << endl;
			goto ostroslup;

		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 12:
		goto walec;
	walec:
		// Cylinder Menu: Surface Area, Volume
		cout << "[1]pole [2]objętość [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto walec_pole;
		walec_pole:
			// Cylinder Total Surface Area: Pc = 2 * Pi * r * (r + H)
			cout << "wprowadź promień podstawy\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "promień nie może być mniejszy lub równy 0\n" << endl;
				goto walec_pole;
			}
			cout << "wprowadź wysokość walca\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wysokość nie może być mniejsza lub równa 0\n" << endl;
				goto walec_pole;
			}
			c = 2 * M_PI * a * (a + b);
			cout << endl << "pole powierzchni całkowitej walca o promieniu " << a << " i wysokości " << b << " wynosi " << c << endl;
			goto walec;

		case 2:
			goto walec_objetosc;
		walec_objetosc:
			// Cylinder Volume: V = Pi * r^2 * H
			cout << "wprowadź promień podstawy\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "promień nie może być mniejszy lub równy 0\n" << endl;
				goto walec_objetosc;
			}
			cout << "wprowadź wysokość walca\n" << endl;
			cin >> b;
			if (b <= 0)
			{
				cout << "wysokość nie może być mniejsza lub równa 0\n" << endl;
				goto walec_objetosc;
			}
			// V = Pi * r^2 * H
			c = M_PI * pow(a, 2) * b;
			cout << endl << "objętość walca o promieniu " << a << " i wysokości " << b << " wynosi " << c << endl;
			goto walec;

		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 13:
		goto kula;
	kula:
		// Sphere Menu: Surface Area, Volume
		cout << "[1]pole [2]objętość [3]powrót\n" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			goto kula_pole;
		kula_pole:
			// Sphere Surface Area: A = 4 * Pi * r^2
			cout << "wprowadź promień kuli\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "promień nie może być mniejszy lub równy 0\n" << endl;
				goto kula_pole;
			}
			c = 4 * M_PI * pow(a, 2);
			cout << endl << "pole powierzchni kuli o promieniu " << a << " wynosi " << c << endl;
			goto kula;

		case 2:
			goto kula_objetosc;
		kula_objetosc:
			// Sphere Volume: V = (4/3) * Pi * r^3
			cout << "wprowadź promień kuli\n" << endl;
			cin >> a;
			if (a <= 0)
			{
				cout << "promień nie może być mniejszy lub równy 0\n" << endl;
				goto kula_objetosc;
			}
			// V = 4/3 * Pi * r^3
			c = (4.0 / 3.0) * M_PI * pow(a, 3);
			cout << endl << "objętość kuli o promieniu " << a << " wynosi " << c << endl;
			goto kula;

		case 3:
			goto figury;
		default:
			goto figury;
		}
	case 15:
		system("clear");
		goto figury;
	case 14:
		exit(0);
	}
}