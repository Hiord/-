/**
 * Программа для работы с квадратным многочленом ax^2 + bx + c.
 * 
 * Логика работы:
 * 1. Считывает коэффициенты a, b, c.
 * 2. Считывает управляющий символ:
 *    - 'M': выводит имя и фамилию студента на английском.
 *    - 'h': вычисляет и выводит корни многочлена (с учётом всех вырожденных случаев).
 *    - 'v': запрашивает число и проверяет, делится ли оно на 25 без остатка.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вывода имени и фамилии студента
void printStudentName() {
    cout << "Student: Lungu Yaroslav" << endl;
}

// Функция для вычисления и вывода корней квадратного многочлена
void printRoots(double a, double b, double c) {
    // Случай: многочлен тождественно равен нулю (0 = 0)
    if (a == 0.0 && b == 0.0 && c == 0.0) {
        cout << "Result: The polynomial is identically zero. Any real number is a root." << endl;
        return;
    }

    // Случай: константа, не равная нулю (корней нет)
    if (a == 0.0 && b == 0.0) {
        cout << "Result: No roots exist (constant non-zero polynomial)." << endl;
        return;
    }

    // Случай: линейное уравнение (bx + c = 0)
    if (a == 0.0) {
        double x = -c / b;
        cout << "Result: Linear equation. One root found: x = " 
             << fixed << setprecision(4) << x << endl;
        return;
    }

    // Случай: квадратное уравнение (ax^2 + bx + c = 0)
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Два различных действительных корня
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Result: Two distinct real roots found:" << endl;
        cout << "x1 = " << fixed << setprecision(4) << x1 << endl;
        cout << "x2 = " << fixed << setprecision(4) << x2 << endl;
    } 
    else if (discriminant == 0) {
        // Один действительный корень (кратности 2)
        double x = -b / (2 * a);
        cout << "Result: One real root (double root): x = " 
             << fixed << setprecision(4) << x << endl;
    } 
    else {
        // Комплексные корни (действительных корней нет)
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        
        cout << "Result: No real roots. Complex roots found:" << endl;
        cout << "x1 = " << fixed << setprecision(4) << realPart << " + " 
             << imaginaryPart << "i" << endl;
        cout << "x2 = " << fixed << setprecision(4) << realPart << " - " 
             << imaginaryPart << "i" << endl;
    }
}

// Функция для проверки делимости числа на 25
void checkDivisibilityBy25() {
    long long number;
    cout << "Enter an integer to check divisibility by 25: ";
    
    if (!(cin >> number)) {
        cerr << "Error: Invalid input. Please enter a valid integer." << endl;
        return;
    }

    if (number % 25 == 0) {
        cout << "Result: " << number << " is divisible by 25 without remainder." << endl;
    } else {
        cout << "Result: " << number << " is NOT divisible by 25." << endl;
    }
}

int main() {
    // Настройка кодировки для корректного отображения кириллицы в консоли Windows
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

    double a, b, c;
    char command;

    // Ввод коэффициентов квадратного многочлена ax^2 + bx + c
    cout << "Enter coefficients a, b, c for the polynomial ax^2 + bx + c:" << endl;
    if (!(cin >> a >> b >> c)) {
        cerr << "Error: Failed to read coefficients. Please enter valid numbers." << endl;
        return 1;
    }

    // Ввод управляющего символа
    cout << "Enter command character (M, h, or v): ";
    if (!(cin >> command)) {
        cerr << "Error: Failed to read command character." << endl;
        return 1;
    }

    // Обработка команды
    switch (command) {
        case 'M':
            printStudentName();
            break;
        case 'h':
            printRoots(a, b, c);
            break;
        case 'v':
            checkDivisibilityBy25();
            break;
        default:
            cerr << "Error: Unknown command '" << command << "'. Please use 'M', 'h', or 'v'." << endl;
            return 1;
    }

    return 0;
}