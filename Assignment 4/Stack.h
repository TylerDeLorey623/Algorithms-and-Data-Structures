#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Vertex.h"

using namespace std;

// Public Stack class for print SSSP algorithm results
class Stack 
{
    public:
        Vertex* top = nullptr;

        // Push O(1)
        void push(Vertex* newVertex)
        {
            newVertex->next = top;
            top = newVertex;
            return;
        }

        // Pop O(1)
        Vertex* pop()
        {
            if (isEmpty())
            {
                throw runtime_error("Attempted to pop empty stack");
            }

            Vertex* poppedItem = top;
            top = top->next;

            return poppedItem;
        }

        // isEmpty O(1)
        bool isEmpty()
        {
            return (top == nullptr);
        }
};

#endif