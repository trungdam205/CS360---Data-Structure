/*
 Dam Quang Trung
 1694454
 Assignment1
 */

#include <iostream>
#include <cstring>
using namespace std;

// ============ ABSTRACT BASE CLASS ============
class Employee {
protected:
    char *name;
    long int ID;

public:
    // Default constructor
    Employee() {
        cout << "Employee default constructor called" << endl;
        name = new char[1];
        name[0] = '\0';  // Empty string
        ID = 0;
    }

    // Copy constructor
    Employee(const Employee &emp) {
        cout << "Employee copy constructor called" << endl;
        // Deep copy for name
        name = new char[strlen(emp.name) + 1];
        strcpy(name, emp.name);
        ID = emp.ID;
    }

    // Virtual destructor (important for polymorphism!)
    virtual ~Employee() {
        cout << "Employee destructor called for: " << name << endl;
        delete[] name;
    }

    // Set person information
    virtual void setPerson(char *n, long int id) {
        cout << "Employee setPerson called" << endl;
        // Delete old name
        delete[] name;
        // Allocate new memory and copy
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        ID = id;
    }

    // Pure virtual function makes this an abstract class
    virtual void print() = 0;
};

// ============ MANAGER CLASS (Derived) ============
class Manager : public Employee {
private:
    char *degree;  // Degree: diploma, bachelor, master, doctor

public:
    // Default constructor
    Manager() : Employee() {
        cout << "Manager default constructor called" << endl;
        degree = new char[1];
        degree[0] = '\0';
    }

    // Parameterized constructor
    Manager(char *n, long int id, char *deg) : Employee() {
        cout << "Manager parameterized constructor called" << endl;
        // Set name and ID
        delete[] name;  // Delete the empty string from Employee()
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        ID = id;

        // Set degree
        degree = new char[strlen(deg) + 1];
        strcpy(degree, deg);
    }

    // Copy constructor
    Manager(const Manager &mgr) : Employee(mgr) {
        cout << "Manager copy constructor called" << endl;
        degree = new char[strlen(mgr.degree) + 1];
        strcpy(degree, mgr.degree);
    }

    // Destructor
    ~Manager() {
        cout << "Manager destructor called" << endl;
        delete[] degree;
    }

    // Override setPerson
    void setPerson(char *n, long int id) override {
        cout << "Manager setPerson called" << endl;
        Employee::setPerson(n, id);  // Call base class method
    }

    // Overloaded setPerson for Manager with degree
    void setPerson(char *n, long int id, char *deg) {
        cout << "Manager setPerson (with degree) called" << endl;
        Employee::setPerson(n, id);
        delete[] degree;
        degree = new char[strlen(deg) + 1];
        strcpy(degree, deg);
    }

    // Override print - implementation of pure virtual function
    void print() override {
        cout << "\n===== MANAGER INFORMATION =====" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Degree: " << degree << endl;
        cout << "==============================\n" << endl;
    }
};

// ============ SECRETARY CLASS (Derived) ============
class Secretary : public Employee {
private:
    bool contract;  // 1 = permanent, 0 = temporary

public:
    // Default constructor
    Secretary() : Employee() {
        cout << "Secretary default constructor called" << endl;
        contract = false;  // Default to temporary
    }

    // Parameterized constructor
    Secretary(char *n, long int id, bool cont) : Employee() {
        cout << "Secretary parameterized constructor called" << endl;
        // Set name and ID
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        ID = id;

        contract = cont;
    }

    // Copy constructor
    Secretary(const Secretary &sec) : Employee(sec) {
        cout << "Secretary copy constructor called" << endl;
        contract = sec.contract;
    }

    // Destructor
    ~Secretary() {
        cout << "Secretary destructor called" << endl;
    }

    // Override setPerson
    void setPerson(char *n, long int id) override {
        cout << "Secretary setPerson called" << endl;
        Employee::setPerson(n, id);
    }

    // Overloaded setPerson for Secretary with contract
    void setPerson(char *n, long int id, char *contractType) {
        cout << "Secretary setPerson (with contract) called" << endl;
        Employee::setPerson(n, id);

        // Convert string to boolean
        if (strcmp(contractType, "permanent") == 0 || strcmp(contractType, "1") == 0) {
            contract = true;
        } else {
            contract = false;
        }
    }

    // Override print - implementation of pure virtual function
    void print() override {
        cout << "\n===== SECRETARY INFORMATION =====" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Contract: " << (contract ? "Permanent" : "Temporary") << endl;
        cout << "=================================\n" << endl;
    }
};

// ============ MAIN FUNCTION ============
int main() {
    cout << "========== TESTING EMPLOYEE HIERARCHY ==========\n" << endl;

    // Create a Manager using polymorphism
    Employee *p = new Manager("Bruce Lee", 234567, "Dr.");
    p->print();

    // Create a Secretary object
    Secretary p2;
    p2.setPerson("Wilma Jones", 341256, "permanent");

    // Delete the Manager
    delete p;

    // Point to Secretary (polymorphism)
    p = &p2;
    p->print();

    cout << "\n========== ADDITIONAL TESTS ==========\n" << endl;

    // Test more objects
    Manager m1("John Smith", 111222, "Master");
    m1.print();

    Secretary s1("Jane Doe", 333444, false);
    s1.print();

    // Test polymorphism with array
    cout << "\n--- Testing Polymorphic Array ---" << endl;
    Employee *employees[3];
    employees[0] = new Manager("Alice Wang", 555666, "Bachelor");
    employees[1] = new Secretary("Bob Johnson", 777888, true);
    employees[2] = new Manager("Carol Davis", 999000, "PhD");

    for (int i = 0; i < 3; i++) {
        employees[i]->print();
    }

    // Clean up
    for (int i = 0; i < 3; i++) {
        delete employees[i];
    }

    cout << "\n========== PROGRAM ENDING ==========\n" << endl;

    return 0;
}