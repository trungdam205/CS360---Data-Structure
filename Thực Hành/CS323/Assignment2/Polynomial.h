#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
using namespace std;

class Polynomial {
private:
    int degree;
    vector<double> coefficients;

public:
    // Constructors
    Polynomial();
    Polynomial(int deg);

    // Exercise 2: Input operation
    void input();

    // Exercise 3: Output operation
    void output() const;

    // Exercise 4: Evaluate operation
    double evaluate(double x) const;

    // Exercise 5: Addition operation
    Polynomial operator+(const Polynomial& other) const;

    // Exercise 6: Multiplication operation
    Polynomial operator*(const Polynomial& other) const;

    // Accessor methods
    int getDegree() const;
    double getCoefficient(int i) const;
};

#endif