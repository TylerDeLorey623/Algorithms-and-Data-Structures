#include <iostream>
#include "Node.h"

using namespace std;

// Public Stack class for linked list implementation of a stack
class Stack 
{
    public:
        Node* myHead = nullptr;

        // Push declaration
        void push(string item);

        // Pop declaration
        string pop();

        // isEmpty declaration
        bool isEmpty();

};