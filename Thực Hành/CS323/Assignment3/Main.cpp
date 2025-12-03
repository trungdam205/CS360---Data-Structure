#include <iostream>
#include "list.h"
using namespace std;

int main() {
    list myList;

    // Test Insert (Ex 19)
    cout << "\n1. Insert data: 10, 20, 15, 5, 30" << endl;
    myList.insert(0, 10);
    myList.insert(1, 20);
    myList.insert(2, 15);
    myList.insert(0, 5);  // Insert at head
    myList.insert(4, 30); // Insert at tail

    cout << "Current List: " << myList << endl;

    // Test Count Nodes (Ex 18)
    cout << "Node Count (Size): " << myList.returnSize() << endl;

    // Test Search (Ex 19)
    cout << "\n2. Linear Search:" << endl;
    int val = 20;
    if (myList.linearSearch(val))
        cout << "Found value " << val << " in the list." << endl;
    else
        cout << "Value " << val << " not found." << endl;

    // Test Check Ascending (Ex 21)
    cout << "\n3. Check Ascending Order:" << endl;
    if (myList.isAscending()) cout << "-> List IS ascending." << endl;
    else cout << "-> List is NOT ascending." << endl;

    // Test Reverse (Ex 20)
    cout << "\n4. Reverse List:" << endl;
    myList.reverse();
    cout << "List after reverse: " << myList << endl;

    // Test Destructor implicitly called at end of scope
    cout << "\n=== End of Program ===" << endl;
    return 0;
}