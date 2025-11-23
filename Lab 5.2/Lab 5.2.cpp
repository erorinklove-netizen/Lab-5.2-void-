// Lab 5.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// < Якимів Наталія > 
// Лабораторна робота № 5.2
// Варіант 7
// void-версія
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

// друк горизонтальної лінії (довжини підібрані під setw у рядку виводу)
void line() {
    cout << "+----------+-------------+-------------+-------+\n";
}

int main() {
    double xp, xk, x, dx, eps, s = 0.0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;

    line();
    cout << "|    x     |   atan(x)   |      S      |   n   |\n";
    line();

    x = xp;
    // невеликий запас для порівняння double
    while (x <= xk + 1e-12) {
        S(x, eps, n, s);

        cout << "| " << setw(8) << setprecision(6) << x
            << " | " << setw(11) << setprecision(6) << atan(x)
            << " | " << setw(11) << setprecision(6) << s
            << " | " << setw(5) << n << " |\n";

        line();
        x += dx;
    }

    return 0;
}

void S(const double x, const double eps, int& n, double& s) {
    // Початковий член ряду arctan: a0 = x
    double a = x;
    s = a;
    n = 0;

    do {
        n++;            // тепер n = 1 при першому переході
        A(x, n, a);     // A використовує (2n-1)/(2n+1) всередині
        s += a;
    } while (fabs(a) >= eps);
}

void A(const double x, const int n, double& a) {
    // При виклику n це індекс нового члена (тобто попередній індекс = n-1)
    // Рекурентний множник: -x^2 * (2*(n-1)+1)/(2*(n-1)+3) = -x^2*(2n-1)/(2n+1)
    double R = -x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0);
    a *= R;
}
