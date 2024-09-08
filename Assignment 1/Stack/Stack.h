#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "../Node/Node.h"

using namespace std;

// Public Stack class for linked list implementation of a stack
class Stack 
{
    public:
        Node* head;

        // Push declaration
        void push(string item);

        // Pop declaration
        string pop();

        // isEmpty declaration
        bool isEmpty();

        // Temporary display function
        void display();

};

#endif