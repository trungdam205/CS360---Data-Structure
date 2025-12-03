#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;
typedef int datatype;

class list {
    class Node{
    public:
        datatype value;
        Node *next;
        Node():next(0){}
        Node(datatype val):value(val),next(0){}
    } ;

    int mySize;
    Node *first;
public:

    list(); // constructor
    ~list(); // destructor
    list(list &);// copy constructor

    void insert(int , const datatype &);// insert the value at ith position
    void erase(int ); // erase the item indexed by the argument
// some helping functions
    Node * Index2Pointer(int );
    bool empty(); // checks if list is empty
    datatype readithValue(int);// read the ith value where is is passed as argument
// Overloaded operator
    list & operator=(list &);// overloaded assignment operator
    friend ostream & operator<< ( ostream & , list &);

    //Ex18:
    int returnSize(); // returns the current size of the list

    //Ex19: LinearSearch
    Node *linearSearch(datatype item);

    //Ex20: Reverse list
    void reverse();

    //Ex21: Check ascending order
    bool isAscending();
};
#endif
