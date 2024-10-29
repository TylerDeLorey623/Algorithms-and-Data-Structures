// COPIED FROM ASSIGNMENT 1 (Node.h)
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

// Public Node class for hash chaining
class Node 
{
    public:
        // Holds a string as the Node's data
        string data;

        // Pointer that points to the next node
        Node* next;

        // Declares parameterized constructor
        Node(string value)
        {
            this->data = value;
            this->next = nullptr;
        }
};

#endif