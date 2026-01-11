#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <cstdlib>

using namespace std;

// Helper function to clear screen
void clear_screen() {
    system("clear");
}

// Helper function to get positive input
double get_positive_input(const string& prompt) {
    double value;
    while (true) {
        cout << prompt << endl << endl;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Nieprawidłowa wartość. Spróbuj ponownie.\n" << endl;
        } else if (value <= 0) {
            cout << endl << (prompt.find("promień") != string::npos ?
                "promień nie może być mniejszy lub równy 0" :
                (prompt.find("wysokość") != string::npos ? "wysokość nie może być mniejsza lub równa 0" :
                "bok/wartość nie może być mniejszy lub równy 0"))
                << endl << endl;
        } else {
            return value;
        }
    }
}

// --- 2D Figures ---

void kwadrat_menu() {
    int wybor;
    do {
        // Square Menu: Perimeter, Area, Side Calculation
        cout << "[1]obwód [2]pole [3]bok [4]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Square Perimeter Calculation: P = 4 * a
            double a = get_positive_input("wprowadź bok kwadratu");
            cout << endl << "obwód kwdrtu o boku " << a << endl << " wynosi " << a * 4 << endl << endl;
        } else if (wybor == 2) {
            // Square Area Calculation: A = a^2
            double a = get_positive_input("wprowadź bok kwadratu");
            cout << endl << "pole kwadratu o boku " << a << endl << " wynosi " << pow(a, 2) << endl << endl;
        } else if (wybor == 3) {
             // Calculate side from Area or Perimeter
             int sub_wybor;
             cout << "[1]bok z pola [2]bok z obwodu [3]powót\n" << endl;
             cin >> sub_wybor;
             if (sub_wybor == 1) {
                 // Side from Area: a = sqrt(A)
                 double area = get_positive_input("wprowadz pole kwdratu");
                 cout << "bok kwdratu o polu " << area << " wynosi " << sqrt(area) << endl << endl;
             } else if (sub_wybor == 2) {
                 // Side from Perimeter: a = P / 4
                 double perim = get_positive_input("wprowadz obwód kwdratu");
                 cout << "bok kwdratu o obwodzie " << perim << " wynosi " << perim / 4.0 << endl << endl;
             }
        }
    } while (wybor != 4);
}

void prostokat_menu() {
    int wybor;
    do {
        // Rectangle Menu: Perimeter, Area
        cout << "[1]obwód [2]pole [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Rectangle Perimeter Calculation: P = 2 * (a + b)
            cout << "wprowadź boki prostokątu\n" << endl;
            double a, b;
            cin >> a >> b; // Keeping original simple input style for pairs, but checking validty
            if (a <= 0 || b <= 0) {
                 cout << endl << "żaden z boków nie może być mniejszy lub równy 0\n" << endl;
                 continue;
            }
            double result = 2 * (a + b);
            cout << endl << "obwód prostokątu o bokach " << a << " " << b << endl << " wynosi " << result << endl << endl;
        } else if (wybor == 2) {
            // Rectangle Area Calculation: A = a * b
            cout << "wprowadź boki prostokątu\n" << endl;
            double a, b;
            cin >> a >> b;
            if (a <= 0 || b <= 0) {
                 cout << endl << "żaden z boków nie może być mniejszy lub równy 0\n" << endl;
                 continue;
            }
            double result = a * b;
            cout << endl << "pole prostokątu o bokach " << a << " " << b << endl << " wynosi " << result << endl << endl;
        }
    } while (wybor != 3);
}

void trojkat_menu() {
    int wybor;
    do {
        // Triangle Menu: Perimeter, Area, Pythagoras
        cout << "[1]obwod [2]pole [3]pitagoras [4]pitagoras_odwrotność [5]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
        cout << endl;

        if (wybor == 1) {
            int sub;
            cout << "[1]t_rownoboczny [2]t_rownoramienny [3]t_roznoboczny\n" << endl;
            cin >> sub;
            cout << endl;
            if (sub == 1) {
                // Equilateral Triangle Perimeter: P = 3 * a
                double a = get_positive_input("wprowadź bok");
                cout << "obwot tróąta równobocznego o boku " << a << " wynosi " << 3 * a << endl;
            } else if (sub == 2) {
                // Isosceles Triangle Perimeter: P = a + 2 * b
                double a = get_positive_input("wprowadź podstawe");
                double b = get_positive_input("wprowadź bok");
                if (2 * b <= a) {
                    cout << "dum ramion nie może byc mniejsza lub równa podstawie\n" << endl;
                } else {
                    cout << endl << "obwód trujkąta o podstawie " << a << " i bokach " << b << " wynosi " << a + 2 * b << endl << endl;
                }
            } else if (sub == 3) {
                 // Scalene Triangle Perimeter: P = a + b + c
                 double a = get_positive_input("wprowadź pierwszy bok");
                 double b = get_positive_input("wprowadź drugi bok");
                 double c = get_positive_input("wprowadź trzeci bok");
                 if (a + b <= c || a + c <= b || b + c <= a) {
                     cout << "wprowadź inną wartość boku/boków\nsuma dwóch boków trójkąta musi być większa od trezeciego\n" << endl;
                 } else {
                     cout << " obwód trojkt różnobocznego o bokach " << a << " " << b << " i " << c << " wynosi " << a + b + c << endl << endl;
                 }
            }
        } else if (wybor == 2) {
             int sub;
             cout << "[1]dowolny trojkąt [2]trójkąt równobozcny [3]powrót\n" << endl;
             cin >> sub;
             cout << endl;
             if (sub == 1) {
                 // Triangle Area: A = (a * h) / 2
                 double a = get_positive_input("wprowadź podstawę");
                 double h = get_positive_input("wprowadź wysokość");
                 cout << endl << "pole trojkąta o podstawie " << a << " i wysokości " << h << " wynosi " << (a * h) / 2 << endl << endl;
             } else if (sub == 2) {
                 // Equilateral Triangle Area: A = (a^2 * sqrt(3)) / 4
                 double a = get_positive_input("wprowadź bok trójkąt");
                 double area = (a * a * sqrt(3)) / 4;
                 cout << endl << "pole trójkąta o boku " << a << " wynosi " << area << endl << endl;
             }
        } else if (wybor == 3) {
             // Pythagorean Theorem: a^2 + b^2 = c^2 (Calculate c)
             double a = get_positive_input("wprowadź pierwszy bok");
             double b = get_positive_input("wprowadź drugi bok");
             cout << "przeciwprostokątna trójkąta o bokach " << a << " i " << b << " wynosi " << sqrt(a*a + b*b) << endl;
        } else if (wybor == 4) {
             // Inverse Pythagoras
             double c2 = get_positive_input("wrowadź kwadrat przeciwprostokątnej(dowolna liczba)");
             double leg = sqrt(c2 / 2.0);
             cout << "dwie przyprostokątne równe są po " << leg << " każda\n" << endl;
        }

    } while (wybor != 5);
}

void kolo_menu() {
    int wybor;
    do {
        // Circle Menu: Perimeter (Circumference), Area
        cout << "[1]obwód [2]pole [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Circle Circumference: L = 2 * Pi * r
            double r = get_positive_input("wprowadź promień");
            cout << "obwód koła o promieniu " << r << " wynosi " << 2 * M_PI * r << endl << endl;
        } else if (wybor == 2) {
            // Circle Area: A = Pi * r^2
            double r = get_positive_input("wprowadź promień");
            cout << endl << "pole koła o promieniu " << r << " wynosi " << M_PI * r * r << endl << endl;
        }
    } while (wybor != 3);
}

void rab_menu() {
    int wybor;
    do {
        // Rhombus (Rąb) Menu: Perimeter, Area
        cout << "[1]obwód [2]pole [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Rhombus Perimeter: P = 4 * a
            double a = get_positive_input("wprowadź bok");
            cout << endl << "obwod rąbu o boku " << a << " wynosi " << a * 4 << endl << endl;
        } else if (wybor == 2) {
            // Rhombus Area: A = a * h
            double a = get_positive_input("wprowadź bok");
            double h = get_positive_input("wprowadź wysokość");
            cout << endl << "pole rąbu o boku <<" << a << " i wysokości " << h << " wynosi " << a * h << endl << endl;
        }
    } while (wybor != 3);
}

void rownoleglobok_menu() {
    int wybor;
    do {
        // Parallelogram Menu: Perimeter, Area
        cout << "[1]obwód [2]pole [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Parallelogram Perimeter: P = 2 * (a + b)
            double a = get_positive_input("wprowadź bok");
            double b = get_positive_input("wprowadź drugi bok");
            cout << endl << "obwod równoległoboku o boku " << a << " i " << b << " wynosi " << 2 * (a + b) << endl << endl;
        } else if (wybor == 2) {
            // Parallelogram Area: A = a * h
            double a = get_positive_input("wprowadź bok");
            double h = get_positive_input("wprowadź wysokość");
            cout << endl << "pole rąbu o boku <<" << a << " i wysokości " << h << " wynosi " << a * h << endl << endl;
        }
    } while (wybor != 3);
}

void trapez_menu() {
    int wybor;
    do {
        // Trapezoid Menu: Perimeter, Area
        cout << "[1]obwód [2]pole [3]powrót\n" << endl;
        cin >> wybor;
        cout << endl;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Trapezoid Perimeter: P = a + b + c + d
            double a = get_positive_input("wprowadź pierwszą podstwę");
            double b = get_positive_input("wprowadź drugą podstwę");
            double c = get_positive_input("wprowadź pierwszy bok");
            double d = get_positive_input("wprowadź drugi bok");
            cout << endl << "obwód trapezu o bokach " << c << " i " << d << " oraz podstawach" << a << " i " << b << " wynosi " << a + b + c + d << endl << endl;
        } else if (wybor == 2) {
            // Trapezoid Area: A = ((a + b) * h) / 2
            double a = get_positive_input("wprowadź pierwszą podstwę");
            double b = get_positive_input("wprowadź drugą podstwę");
            double h = get_positive_input("wprowadź wyokość");
            double area = (a + b) * h / 2.0;
            cout << endl << "pole trpezu o podstawach " << a << " i " << b << " oraz wysokości " << h << " wynosi " << area << endl << endl;
        }
    } while (wybor != 3);
}

// --- 3D Figures ---

void szescian_menu() {
    int wybor;
    do {
        // Cube Menu: Surface Area, Volume
        cout << "[1]pole [2]objętość [3]powrót\n" << endl;
        cin >> wybor;
        cout << endl;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Cube Surface Area: A = 6 * a^2
            double a = get_positive_input("wprowadź krawędź");
            cout << "pole powierzchni sześcianu o boku " << a << " wynosi " << 6 * a * a << endl << endl;
        } else if (wybor == 2) {
            // Cube Volume: V = a^3
            double a = get_positive_input("wprowadź krawędź");
            cout << endl << "objętość sześcianu o krawędzi " << a << " wynosi " << a * a * a << endl << endl;
        }
    } while (wybor != 3);
}

void prostopadloscian_menu() {
    int wybor;
    do {
        // Cuboid Menu: Surface Area, Volume
        cout << "[1]pole [2]objętość [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Cuboid Surface Area: A = 2 * (a*b + b*c + c*a)
            double a = get_positive_input("wprowadź pierwszą krawędź");
            double b = get_positive_input("wprowadź drugą krawędź");
            double c = get_positive_input("wprowadź trzecią krawędź");
            double area = 2 * (a * b + b * c + c * a);
            cout << endl << "pole prostopadłościnu o krawędziach " << a << " " << b << " oraz " << c << " wynosi " << area << endl << endl;
        } else if (wybor == 2) {
             // Cuboid Volume: V = a * b * c
             double a = get_positive_input("wprowadź pierwszą krawędź");
             double b = get_positive_input("wprowadź drugą krawędź");
             double c = get_positive_input("wprowadź trzecią krawędź");
             cout << endl << "objętość prostopadłościanu o krawędziach " << a << " " << b << " oraz " << c << " wynosi " << a * b * c << endl << endl;
        }
    } while (wybor != 3);
}

void stozek_menu() {
    int wybor;
    do {
        // Cone Menu: Surface Area, Volume
        cout << "[1]pole [2]objętość [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Cone Total Surface Area: Pc = Pi * r * (r + l)
            double r = get_positive_input("wprowadź promień podstawy");
            double l = get_positive_input("wprowadź tworzącą stożka");
            double area = M_PI * r * (r + l);
            cout << endl << "pole powierzchni całkowitej stożka o promieniu " << r << " i tworzącej " << l << " wynosi " << area << endl << endl;
        } else if (wybor == 2) {
            // Cone Volume: V = (1/3) * Pi * r^2 * H
            double r = get_positive_input("wprowadź promień podstawy");
            double h = get_positive_input("wprowadź wysokość stożka");
            double vol = (M_PI * r * r * h) / 3.0;
            cout << endl << "objętość stożka o promieniu " << r << " i wysokości " << h << " wynosi " << vol << endl << endl;
        }
    } while (wybor != 3);
}

void ostroslup_menu() {
    int wybor;
    do {
        // Pyramid Menu: Surface Area, Volume
        cout << "[1]pole [2]objętość [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Regular Square Pyramid Surface Area: Pc = a^2 + 4 * (1/2 * a * h_s)
            cout << "Obliczanie pola ostrosłupa prawidłowego czworokątnego." << endl;
            double a = get_positive_input("wprowadź długość boku podstawy");
            double h = get_positive_input("wprowadź wysokość ostrosłupa");
            double h_s = sqrt(h * h + (a / 2.0) * (a / 2.0));
            double area = a * a + 2 * a * h_s;
            cout << endl << "pole powierzchni całkowitej ostrosłupa prawidłowego czworokątnego o boku podstawy " << a << " i wysokości " << h << " wynosi " << area << endl << endl;
        } else if (wybor == 2) {
            // Regular Square Pyramid Volume: V = (1/3) * a^2 * H
            cout << "Obliczanie objętości ostrosłupa prawidłowego czworokątnego." << endl;
            double a = get_positive_input("wprowadź długość boku podstawy");
            double h = get_positive_input("wprowadź wysokość ostrosłupa");
            double vol = (a * a * h) / 3.0;
            cout << endl << "objętość ostrosłupa o boku podstawy " << a << " i wysokości " << h << " wynosi " << vol << endl << endl;
        }
    } while (wybor != 3);
}

void walec_menu() {
    int wybor;
    do {
        // Cylinder Menu: Surface Area, Volume
        cout << "[1]pole [2]objętość [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Cylinder Total Surface Area: Pc = 2 * Pi * r * (r + H)
            double r = get_positive_input("wprowadź promień podstawy");
            double h = get_positive_input("wprowadź wysokość walca");
            double area = 2 * M_PI * r * (r + h);
            cout << endl << "pole powierzchni całkowitej walca o promieniu " << r << " i wysokości " << h << " wynosi " << area << endl << endl;
        } else if (wybor == 2) {
            // Cylinder Volume: V = Pi * r^2 * H
            double r = get_positive_input("wprowadź promień podstawy");
            double h = get_positive_input("wprowadź wysokość walca");
            double vol = M_PI * r * r * h;
            cout << endl << "objętość walca o promieniu " << r << " i wysokości " << h << " wynosi " << vol << endl << endl;
        }
    } while (wybor != 3);
}

void kula_menu() {
    int wybor;
    do {
        // Sphere Menu: Surface Area, Volume
        cout << "[1]pole [2]objętość [3]powrót\n" << endl;
        cin >> wybor;
        if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        if (wybor == 1) {
            // Sphere Surface Area: A = 4 * Pi * r^2
            double r = get_positive_input("wprowadź promień kuli");
            double area = 4 * M_PI * r * r;
            cout << endl << "pole powierzchni kuli o promieniu " << r << " wynosi " << area << endl << endl;
        } else if (wybor == 2) {
            // Sphere Volume: V = (4/3) * Pi * r^3
            double r = get_positive_input("wprowadź promień kuli");
            double vol = (4.0 / 3.0) * M_PI * pow(r, 3);
            cout << endl << "objętość kuli o promieniu " << r << " wynosi " << vol << endl << endl;
        }
    } while (wybor != 3);
}

int main()
{
    setlocale(LC_ALL, "polish");
    int wybor;

    do {
        cout << "[1]kwadrat [2]prostokąt [3]trójkąt [4]koło [5]rąb [6]równoległobok [7]trapez\n"
             << "[8]sześcian [9]prostopadłościan [10]stożek\n"
             << "[11]ostrosłup [12]walec [13]kula [14]opuść [15]wyczyść ekran\n" << endl;
        cin >> wybor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << endl;

        switch (wybor) {
            case 1: kwadrat_menu(); break;
            case 2: prostokat_menu(); break;
            case 3: trojkat_menu(); break;
            case 4: kolo_menu(); break;
            case 5: rab_menu(); break;
            case 6: rownoleglobok_menu(); break;
            case 7: trapez_menu(); break;
            case 8: szescian_menu(); break;
            case 9: prostopadloscian_menu(); break;
            case 10: stozek_menu(); break;
            case 11: ostroslup_menu(); break;
            case 12: walec_menu(); break;
            case 13: kula_menu(); break;
            case 14: exit(0);
            case 15: clear_screen(); break;
            default: break;
        }
    } while (true);

    return 0;
}
