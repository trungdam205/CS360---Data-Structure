#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    cout << "=== Polynomial Class Test Program ===" << endl << endl;

    // Test 1: Input and Output
    cout << "Test 1: Input and Output" << endl;
    Polynomial p1;
    p1.input();
    cout << "Polynomial p1: ";
    p1.output();
    cout << endl;

    // Test 2: Create another polynomial
    cout << "Test 2: Create second polynomial" << endl;
    Polynomial p2;
    p2.input();
    cout << "Polynomial p2: ";
    p2.output();
    cout << endl;

    // Test 3: Evaluate
    cout << "Test 3: Evaluate p1" << endl;
    double x;
    cout << "Enter a value for x: ";
    cin >> x;
    cout << "p1(" << x << ") = " << p1.evaluate(x) << endl << endl;

    // Test 4: Addition
    cout << "Test 4: Addition" << endl;
    Polynomial p3 = p1 + p2;
    cout << "p1 + p2 = ";
    p3.output();
    cout << endl;

    // Test 5: Multiplication
    cout << "Test 5: Multiplication" << endl;
    Polynomial p4 = p1 * p2;
    cout << "p1 * p2 = ";
    p4.output();
    cout << endl;

    return 0;
}