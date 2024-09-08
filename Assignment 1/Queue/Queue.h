#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "../Node/Node.h"

using namespace std;

// Public Queue class for linked list implementation of a queue
class Queue 
{
    public:
        Node* head = nullptr;
        Node* tail = nullptr;

        // Enqueue declaration
        void enqueue(string item);

        // Dequeue declaration
        string dequeue();

        // isEmpty declaration
        bool isEmpty();

        // Temporary display function
        void display();
};

#endif