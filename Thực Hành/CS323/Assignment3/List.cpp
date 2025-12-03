#include "list.h"
#include <iostream>

// --- Constructor (Ex 19) ---
list::list() {
    this->mySize = 0;
    this->first = 0;
}

// --- Destructor (Ex 19) ---
list::~list() {
    Node *current = first;
    while (current != 0) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    first = 0;
    mySize = 0;
}

// --- Copy Constructor (Ex 19) ---
list::list(list &original) {
    this->first = 0;
    this->mySize = 0;
    Node *curr = original.first;
    int index = 0;
    while (curr != 0) {
        this->insert(index++, curr->value); // Re-use insert to copy
        curr = curr->next;
    }
}

// --- Helper: Index2Pointer ---
// Returns pointer to the node at a specific index (0-based)
list::Node* list::Index2Pointer(int index) {
    if (index < 0 || index >= mySize) return 0;
    Node *curr = first;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr;
}

// --- Insert (Ex 19) ---
// Insert val at index position
void list::insert(int index, const datatype &val) {
    if (index < 0 || index > mySize) {
        cerr << "Invalid position!" << endl;
        return;
    }

    Node *newNode = new Node(val);

    if (index == 0) { // Insert at head
        newNode->next = first;
        first = newNode;
    } else { // Insert at middle or end
        Node *prev = Index2Pointer(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
    }
    mySize++;
}

// --- Erase (Ex 19) ---
// Remove node at index position
void list::erase(int index) {
    if (index < 0 || index >= mySize) return;

    Node *toDelete;
    if (index == 0) {
        toDelete = first;
        first = first->next;
    } else {
        Node *prev = Index2Pointer(index - 1);
        toDelete = prev->next;
        prev->next = toDelete->next;
    }
    delete toDelete;
    mySize--;
}

// --- Empty & ReturnSize (Ex 18 & 19) ---
bool list::empty() {
    return mySize == 0;
}

// Ex 18: Count nodes. Since we maintain 'mySize', complexity is O(1).
// Without 'mySize', we would need to traverse while(curr!=0) count++.
int list::returnSize() {
    return mySize;
}

datatype list::readithValue(int index) {
    Node *node = Index2Pointer(index);
    if (node) return node->value;
    throw "Index out of range";
}

// --- Assignment Operator (Ex 19) ---
list& list::operator=(list &original) {
    if (this != &original) {
        // 1. Clean up old data
        Node *curr = first;
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        first = 0;
        mySize = 0;

        // 2. Copy new data
        Node *origCurr = original.first;
        int idx = 0;
        while (origCurr) {
            insert(idx++, origCurr->value);
            origCurr = origCurr->next;
        }
    }
    return *this;
}

// --- Output Operator ---
ostream& operator<<(ostream &out, list &L) {
    list::Node *curr = L.first;
    while (curr != 0) {
        out << curr->value << " -> ";
        curr = curr->next;
    }
    out << "NULL";
    return out;
}


// --- Ex 19: Linear Search ---
// Search for item, return pointer to Node containing item or NULL
list::Node* list::linearSearch(datatype item) {
    Node *curr = first;
    while (curr != 0) {
        if (curr->value == item) {
            return curr; // Found
        }
        curr = curr->next;
    }
    return 0; // Not found
}

// --- Ex 20: Reverse Linked List ---
// Reverse the linked list
void list::reverse() {
    if (mySize <= 1) return; // Empty or single node needs no reversal

    Node *prev = 0;
    Node *current = first;
    Node *next = 0;

    while (current != 0) {
        next = current->next; // Save the next node
        current->next = prev; // Reverse the arrow to the previous node

        // Move pointers forward
        prev = current;
        current = next;
    }
    first = prev; // Update first to point to the last node (which is now first)
}

// --- Ex 21: Is Ascending ---
// Determine if data items are arranged in ascending order
bool list::isAscending() {
    if (mySize <= 1) return true; // Empty or single node is considered sorted

    Node *curr = first;
    while (curr->next != 0) {
        if (curr->value > curr->next->value) {
            return false; // If current is greater than next -> False
        }
        curr = curr->next;
    }
    return true;
}