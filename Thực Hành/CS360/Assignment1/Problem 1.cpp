/*
 Dam Quang Trung
 1694454
 Assignment1
 */

#include <iostream>

using namespace std;

class complexNumber {
private:
    static int numCount;
    int Re, Imag;

public:
    // Constructor with no argument
    complexNumber(){numCount++;}

    // Constructor with arguments
    complexNumber(int Real, int Imaginary){
        numCount++;
        cout << "constructor with argument is called" << endl;
        Re = Real;
        Imag = Imaginary;
    }

    // Destructor
    ~complexNumber(){
        cout << "destructor is called" <<endl;
        numCount--;
    }

    // Copy constructor
    complexNumber (complexNumber &anycomplex) {
        numCount++;
        cout <<endl;
        cout <<"Copy constructor called" << endl;
        Re = anycomplex.Re;
        Imag = anycomplex.Imag;
    }

    void printComplex(){
        cout <<"number of active complex numbers= " << numCount
             << " and present number.....= " << Re <<" + j" << Imag << endl;
    }

    // Overloaded + operator
    complexNumber operator+(complexNumber &b){
        complexNumber temp;
        cout << "overloaded + is called" << endl;
        temp.Re = Re + b.Re;
        temp.Imag = Imag + b.Imag;
        return temp;
    }

    // Overloaded pre-increment operator
    complexNumber operator++(){
        complexNumber temp;
        cout << "overloaded ++(pre) called" << endl;
        temp.Re = ++Re;
        temp.Imag = ++Imag;
        return temp;
    }

    // Overloaded post-increment operator
    complexNumber operator++(int){
        complexNumber temp;
        cout << "overloaded ++(post) called" << endl;
        temp.Re = Re++;
        temp.Imag = Imag++;
        return temp;
    }

    // *** NEW: Overloaded == operator (Boolean comparison) ***
    bool operator==(complexNumber &b){
        cout << "overloaded == called" << endl;
        return (Re == b.Re && Imag == b.Imag);
    }

    // *** NEW: Overloaded * operator (Multiplication) ***
    // Formula: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
    complexNumber operator*(complexNumber &b){
        complexNumber temp;
        cout << "overloaded * called" << endl;
        temp.Re = (Re * b.Re) - (Imag * b.Imag);      // Real part
        temp.Imag = (Re * b.Imag) + (Imag * b.Re);    // Imaginary part
        return temp;
    }

    // *** NEW: Overloaded = operator (Assignment) ***
    complexNumber& operator=(const complexNumber &b){
        cout << "overloaded = called" << endl;
        if(this != &b){  // Check for self-assignment
            Re = b.Re;
            Imag = b.Imag;
        }
        return *this;  // Return reference for chained assignments
    }

    // Overloaded << operator (output stream)
    friend ostream & operator<< (ostream &out, complexNumber &somecomplex){
        cout << "overloaded << called" <<endl;
        out << somecomplex.Re<<"+ j" << somecomplex.Imag;
        return out;
    }

    // *** NEW: Overloaded >> operator (input stream) ***
    // Must be friend to access private members
    friend istream & operator>> (istream &in, complexNumber &somecomplex){
        cout << "overloaded >> called" << endl;
        cout << "Enter real part: ";
        in >> somecomplex.Re;
        cout << "Enter imaginary part: ";
        in >> somecomplex.Imag;
        return in;
    }

    // *** NEW: Static function to initialize numCount ***
    static void initializeCount(int count){
        cout << "Static function initializeCount called" << endl;
        numCount = count;
    }

    // Static function to get current count (utility function)
    static int getCount(){
        return numCount;
    }
};

// Initialize static member
int complexNumber::numCount = 0;

void printC(complexNumber a) {
    a.printComplex();
}

int main (){
    // Test static function
    cout << "=== Testing Static Function ===" << endl;
    complexNumber::initializeCount(10);
    cout << "Current count: " << complexNumber::getCount() << endl << endl;

    // Original code
    cout << "=== Original Operations ===" << endl;
    complexNumber A, B(1,2), C(2,3);
    B.printComplex();
    ++B;
    printC(C);
    A = B + C;
    A = B++;
    A.printComplex();
    B.printComplex();
    cout << A << B;

    // Test new operators
    cout << "\n\n=== Testing New Operators ===" << endl;

    // Test == operator
    cout << "\n1. Testing == operator:" << endl;
    complexNumber X(5, 3), Y(5, 3), Z(4, 2);
    if(X == Y){
        cout << "X and Y are equal" << endl;
    } else {
        cout << "X and Y are not equal" << endl;
    }

    if(X == Z){
        cout << "X and Z are equal" << endl;
    } else {
        cout << "X and Z are not equal" << endl;
    }

    // Test * operator
    cout << "\n2. Testing * operator:" << endl;
    complexNumber M(2, 3), N(4, 5), P;
    P = M * N;  // (2+3i) * (4+5i) = (8-15) + (10+12)i = -7 + 22i
    cout << "M * N = " << P << endl;

    // Test = operator
    cout << "\n3. Testing = operator:" << endl;
    complexNumber Q(7, 8), R;
    R = Q;
    cout << "After R = Q, R = " << R << endl;

    // Test >> operator
    cout << "\n4. Testing >> operator (input):" << endl;
    complexNumber Input1, Input2;
    cout << "Enter first complex number:" << endl;
    cin >> Input1;
    cout << "Enter second complex number:" << endl;
    cin >> Input2;
    cout << "You entered: " << Input1 << " and " << Input2 << endl;

    cin.get();
    cin.get();

    return 0;
}