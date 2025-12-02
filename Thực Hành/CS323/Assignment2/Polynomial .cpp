// Polynomial.cpp
#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

// Default constructor
Polynomial::Polynomial() : degree(0), coefficients(1, 0.0) {}

// Constructor with degree
Polynomial::Polynomial(int deg) : degree(deg), coefficients(deg + 1, 0.0) {}

// Exercise 2: Input operation
void Polynomial::input() {
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    coefficients.resize(degree + 1);

    cout << "Enter " << (degree + 1) << " coefficients (from a0 to a" << degree << "):\n";
    for (int i = 0; i <= degree; i++) {
        cout << "a" << i << ": ";
        cin >> coefficients[i];
    }

    // Adjust degree if leading coefficient is zero
    while (degree > 0 && coefficients[degree] == 0) {
        degree--;
        coefficients.pop_back();
    }
}

// Exercise 3: Output operation
void Polynomial::output() const {
    if (degree == 0 && coefficients[0] == 0) {
        cout << "0" << endl;
        return;
    }

    bool firstTerm = true;

    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] == 0) continue;

        // Print sign
        if (!firstTerm) {
            cout << (coefficients[i] > 0 ? " + " : " - ");
        } else if (coefficients[i] < 0) {
            cout << "-";
        }

        // Print coefficient (if not 1 or if it's the constant term)
        double absCoeff = abs(coefficients[i]);
        if (absCoeff != 1 || i == 0) {
            cout << absCoeff;
        }

        // Print variable and exponent
        if (i > 0) {
            cout << "x";
            if (i > 1) {
                cout << "^" << i;
            }
        }

        firstTerm = false;
    }
    cout << endl;
}

// Exercise 4: Evaluate operation
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    double xPower = 1.0;

    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * xPower;
        xPower *= x;
    }

    return result;
}

// Exercise 5: Addition operation
Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxDegree = max(degree, other.degree);
    Polynomial result(maxDegree);

    for (int i = 0; i <= maxDegree; i++) {
        double coeff1 = (i <= degree) ? coefficients[i] : 0;
        double coeff2 = (i <= other.degree) ? other.coefficients[i] : 0;
        result.coefficients[i] = coeff1 + coeff2;
    }

    // Adjust degree if leading coefficient is zero
    while (result.degree > 0 && result.coefficients[result.degree] == 0) {
        result.degree--;
        result.coefficients.pop_back();
    }

    return result;
}

// Exercise 6: Multiplication operation
Polynomial Polynomial::operator*(const Polynomial& other) const {
    int resultDegree = degree + other.degree;
    Polynomial result(resultDegree);

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= other.degree; j++) {
            result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    // Adjust degree if leading coefficient is zero
    while (result.degree > 0 && result.coefficients[result.degree] == 0) {
        result.degree--;
        result.coefficients.pop_back();
    }

    return result;
}

// Accessor methods
int Polynomial::getDegree() const {
    return degree;
}

double Polynomial::getCoefficient(int i) const {
    if (i >= 0 && i <= degree)
        return coefficients[i];
    return 0;
}
