#include <iostream>
#include <cmath>
#include <limits>
#include <string>

// Function declarations
void handleSquare();
void handleRectangle();
void handleTriangle();
void handleCircle();
void handleRhombus();
void handleParallelogram();
void handleTrapezoid();
void handleCube();
void handleCuboid();
void handleCone();
void handlePyramid();
void handleCylinder();
void handleSphere();
void clearScreen();
double getPositiveNumber(const std::string& prompt);

// Helper function to get a positive number from the user
double getPositiveNumber(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value <= 0) {
            std::cout << "Invalid input. Please enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return value;
        }
    }
}

// Function to clear the screen
void clearScreen() {
    // A simple cross-platform way to add newlines to "clear" the screen
    std::cout << std::string(50, '\n');
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        std::cout << "---------------------\n";
        std::cout << "Select a shape:\n";
        std::cout << "---------------------\n";
        std::cout << "[1] Square\n[2] Rectangle\n[3] Triangle\n[4] Circle\n";
        std::cout << "[5] Rhombus\n[6] Parallelogram\n[7] Trapezoid\n[8] Cube\n";
        std::cout << "[9] Cuboid\n[10] Cone\n[11] Pyramid\n[12] Cylinder\n";
        std::cout << "[13] Sphere\n\n";
        std::cout << "[14] Exit\n[15] Clear Screen\n";
        std::cout << "---------------------\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "\nInvalid input. Please enter a number.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << std::endl;

        switch (choice) {
            case 1: handleSquare(); break;
            case 2: handleRectangle(); break;
            case 3: handleTriangle(); break;
            case 4: handleCircle(); break;
            case 5: handleRhombus(); break;
            case 6: handleParallelogram(); break;
            case 7: handleTrapezoid(); break;
            case 8: handleCube(); break;
            case 9: handleCuboid(); break;
            case 10: handleCone(); break;
            case 11: handlePyramid(); break;
            case 12: handleCylinder(); break;
            case 13: handleSphere(); break;
            case 14:
                running = false;
                std::cout << "Exiting program.\n";
                break;
            case 15:
                clearScreen();
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    }

    return 0;
}

void handleSquare() {
    int choice;
    double side, area, perimeter;

    while (true) {
        std::cout << "\n--- Square ---\n";
        std::cout << "[1] Perimeter\n[2] Area\n[3] Find side\n[4] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                side = getPositiveNumber("Enter the side of the square: ");
                perimeter = 4 * side;
                std::cout << "The perimeter of the square is: " << perimeter << std::endl;
                break;
            case 2:
                side = getPositiveNumber("Enter the side of the square: ");
                area = pow(side, 2);
                std::cout << "The area of the square is: " << area << std::endl;
                break;
            case 3:
                int sub_choice;
                std::cout << "\n--- Find Side ---\n[1] From area\n[2] From perimeter\n[3] Back\n";
                std::cout << "Enter your choice: ";
                std::cin >> sub_choice;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                if (sub_choice == 1) {
                    area = getPositiveNumber("Enter the area of the square: ");
                    side = sqrt(area);
                    std::cout << "The side of the square is: " << side << std::endl;
                } else if (sub_choice == 2) {
                    perimeter = getPositiveNumber("Enter the perimeter of the square: ");
                    side = perimeter / 4;
                    std::cout << "The side of the square is: " << side << std::endl;
                } else if (sub_choice != 3) {
                    std::cout << "Invalid choice, please try again.\n";
                }
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    }
}

void handleRectangle() {
    int choice;
    double a, b;

    while (true) {
        std::cout << "\n--- Rectangle ---\n";
        std::cout << "[1] Perimeter\n[2] Area\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                a = getPositiveNumber("Enter the first side: ");
                b = getPositiveNumber("Enter the second side: ");
                std::cout << "The perimeter of the rectangle is: " << 2 * (a + b) << std::endl;
                break;
            case 2:
                a = getPositiveNumber("Enter the first side: ");
                b = getPositiveNumber("Enter the second side: ");
                std::cout << "The area of the rectangle is: " << a * b << std::endl;
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    }
}

void handleTriangle() {
    int choice;

    while (true) {
        std::cout << "\n--- Triangle ---\n";
        std::cout << "[1] Perimeter\n[2] Area\n[3] Pythagorean theorem\n[4] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: // Perimeter
                {
                    int sub_choice;
                    std::cout << "\n--- Triangle Perimeter ---\n[1] Equilateral\n[2] Isosceles\n[3] Scalene\n[4] Back\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> sub_choice;

                    if (std::cin.fail()) {
                        std::cout << "Invalid input. Please enter a number.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }

                    if (sub_choice == 1) {
                        double a = getPositiveNumber("Enter the side: ");
                        std::cout << "The perimeter is: " << 3 * a << std::endl;
                    } else if (sub_choice == 2) {
                        double a = getPositiveNumber("Enter the base: ");
                        double b = getPositiveNumber("Enter the side: ");
                        if (2 * b <= a) {
                            std::cout << "The sum of the two sides must be greater than the base.\n";
                        } else {
                            std::cout << "The perimeter is: " << a + 2 * b << std::endl;
                        }
                    } else if (sub_choice == 3) {
                        double a = getPositiveNumber("Enter the first side: ");
                        double b = getPositiveNumber("Enter the second side: ");
                        double c = getPositiveNumber("Enter the third side: ");
                        if (a + b <= c || a + c <= b || b + c <= a) {
                            std::cout << "The sum of any two sides must be greater than the third.\n";
                        } else {
                            std::cout << "The perimeter is: " << a + b + c << std::endl;
                        }
                    } else if (sub_choice != 4) {
                        std::cout << "Invalid choice.\n";
                    }
                }
                break;
            case 2: // Area
                {
                    int sub_choice;
                    std::cout << "\n--- Triangle Area ---\n[1] From base and height\n[2] Equilateral\n[3] Back\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> sub_choice;

                    if (std::cin.fail()) {
                        std::cout << "Invalid input. Please enter a number.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }

                    if (sub_choice == 1) {
                        double a = getPositiveNumber("Enter the base: ");
                        double h = getPositiveNumber("Enter the height: ");
                        std::cout << "The area is: " << (a * h) / 2 << std::endl;
                    } else if (sub_choice == 2) {
                        double a = getPositiveNumber("Enter the side: ");
                        std::cout << "The area is: " << (pow(a, 2) * sqrt(3)) / 4 << std::endl;
                    } else if (sub_choice != 3) {
                        std::cout << "Invalid choice.\n";
                    }
                }
                break;
            case 3: // Pythagorean theorem
                {
                    double a = getPositiveNumber("Enter the first leg: ");
                    double b = getPositiveNumber("Enter the second leg: ");
                    std::cout << "The hypotenuse is: " << sqrt(pow(a, 2) + pow(b, 2)) << std::endl;
                }
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    }
}

void handleCircle() {
    int choice;
    while (true) {
        std::cout << "\n--- Circle ---\n";
        std::cout << "[1] Circumference\n[2] Area\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double radius = getPositiveNumber("Enter the radius: ");
            std::cout << "The circumference is: " << 2 * M_PI * radius << std::endl;
        } else if (choice == 2) {
            double radius = getPositiveNumber("Enter the radius: ");
            std::cout << "The area is: " << M_PI * pow(radius, 2) << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleRhombus() {
    int choice;
    while (true) {
        std::cout << "\n--- Rhombus ---\n";
        std::cout << "[1] Perimeter\n[2] Area\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double side = getPositiveNumber("Enter the side: ");
            std::cout << "The perimeter is: " << 4 * side << std::endl;
        } else if (choice == 2) {
            double side = getPositiveNumber("Enter the side: ");
            double height = getPositiveNumber("Enter the height: ");
            std::cout << "The area is: " << side * height << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleParallelogram() {
    int choice;
    while (true) {
        std::cout << "\n--- Parallelogram ---\n";
        std::cout << "[1] Perimeter\n[2] Area\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double a = getPositiveNumber("Enter the first side: ");
            double b = getPositiveNumber("Enter the second side: ");
            std::cout << "The perimeter is: " << 2 * (a + b) << std::endl;
        } else if (choice == 2) {
            double a = getPositiveNumber("Enter the base: ");
            double height = getPositiveNumber("Enter the height: ");
            std::cout << "The area is: " << a * height << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleTrapezoid() {
    int choice;
    while (true) {
        std::cout << "\n--- Trapezoid ---\n";
        std::cout << "[1] Perimeter\n[2] Area\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double a = getPositiveNumber("Enter the first base: ");
            double b = getPositiveNumber("Enter the second base: ");
            double c = getPositiveNumber("Enter the first side: ");
            double d = getPositiveNumber("Enter the second side: ");
            std::cout << "The perimeter is: " << a + b + c + d << std::endl;
        } else if (choice == 2) {
            double a = getPositiveNumber("Enter the first base: ");
            double b = getPositiveNumber("Enter the second base: ");
            double height = getPositiveNumber("Enter the height: ");
            std::cout << "The area is: " << ((a + b) * height) / 2 << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleCube() {
    int choice;
    while (true) {
        std::cout << "\n--- Cube ---\n";
        std::cout << "[1] Surface Area\n[2] Volume\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double side = getPositiveNumber("Enter the side: ");
            std::cout << "The surface area is: " << 6 * pow(side, 2) << std::endl;
        } else if (choice == 2) {
            double side = getPositiveNumber("Enter the side: ");
            std::cout << "The volume is: " << pow(side, 3) << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleCuboid() {
    int choice;
    while (true) {
        std::cout << "\n--- Cuboid ---\n";
        std::cout << "[1] Surface Area\n[2] Volume\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double a = getPositiveNumber("Enter the first side: ");
            double b = getPositiveNumber("Enter the second side: ");
            double c = getPositiveNumber("Enter the third side: ");
            std::cout << "The surface area is: " << 2 * (a * b + b * c + c * a) << std::endl;
        } else if (choice == 2) {
            double a = getPositiveNumber("Enter the first side: ");
            double b = getPositiveNumber("Enter the second side: ");
            double c = getPositiveNumber("Enter the third side: ");
            std::cout << "The volume is: " << a * b * c << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleCone() {
    int choice;
    while (true) {
        std::cout << "\n--- Cone ---\n";
        std::cout << "[1] Surface Area\n[2] Volume\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double radius = getPositiveNumber("Enter the radius: ");
            double height = getPositiveNumber("Enter the height: ");
            double slant_height = sqrt(pow(height, 2) + pow(radius, 2));
            std::cout << "The surface area is: " << M_PI * radius * (radius + slant_height) << std::endl;
        } else if (choice == 2) {
            double radius = getPositiveNumber("Enter the radius: ");
            double height = getPositiveNumber("Enter the height: ");
            std::cout << "The volume is: " << (M_PI * pow(radius, 2) * height) / 3 << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handlePyramid() {
    int choice;
    while (true) {
        std::cout << "\n--- Pyramid (Square Base) ---\n";
        std::cout << "[1] Surface Area\n[2] Volume\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double base_side = getPositiveNumber("Enter the base side: ");
            double height = getPositiveNumber("Enter the height: ");
            double slant_height = sqrt(pow(base_side / 2, 2) + pow(height, 2));
            double base_area = pow(base_side, 2);
            double lateral_area = 2 * base_side * slant_height;
            std::cout << "The surface area is: " << base_area + lateral_area << std::endl;
        } else if (choice == 2) {
            double base_side = getPositiveNumber("Enter the base side: ");
            double height = getPositiveNumber("Enter the height: ");
            std::cout << "The volume is: " << (pow(base_side, 2) * height) / 3 << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleCylinder() {
    int choice;
    while (true) {
        std::cout << "\n--- Cylinder ---\n";
        std::cout << "[1] Surface Area\n[2] Volume\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double radius = getPositiveNumber("Enter the radius: ");
            double height = getPositiveNumber("Enter the height: ");
            std::cout << "The surface area is: " << 2 * M_PI * radius * (radius + height) << std::endl;
        } else if (choice == 2) {
            double radius = getPositiveNumber("Enter the radius: ");
            double height = getPositiveNumber("Enter the height: ");
            std::cout << "The volume is: " << M_PI * pow(radius, 2) * height << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

void handleSphere() {
    int choice;
    while (true) {
        std::cout << "\n--- Sphere ---\n";
        std::cout << "[1] Surface Area\n[2] Volume\n[3] Back\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            double radius = getPositiveNumber("Enter the radius: ");
            std::cout << "The surface area is: " << 4 * M_PI * pow(radius, 2) << std::endl;
        } else if (choice == 2) {
            double radius = getPositiveNumber("Enter the radius: ");
            std::cout << "The volume is: " << (4.0 / 3.0) * M_PI * pow(radius, 3) << std::endl;
        } else if (choice == 3) {
            return;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}