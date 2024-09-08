#include <iostream>

using namespace std;

// Public Node class for the linked list implementation of a stack and a queue
class Node 
{
    public:
        // Holds the item name for this node
        string data;

        // Pointer that points to the next node
        Node* next;

        // Declares constructor (defined in Node.cpp)
        Node(string value);
};


