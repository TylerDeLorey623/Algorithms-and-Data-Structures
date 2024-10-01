#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "./Node.h"

using namespace std;

// Public Stack class for linked list implementation of a stack
class Stack 
{
    public:
        Node* top = nullptr;

        // Deconstructor for Stack
        ~Stack()
        {
            while (!isEmpty())
            {
                pop();
            }
        }

        // Push O(1)
        void push(char item)
        {
            Node* newNode = new Node(item);
            newNode->next = top;
            top = newNode;
            return;
        }

        // Pop O(1)
        char pop()
        {
            if (isEmpty())
            {
                throw runtime_error("Attempted to pop empty stack");
            }

            char poppedItem = top->data;
            Node* temp = top;
            top = top->next;

            // Free memory when popping the Node from the Stack
            delete(temp);

            return poppedItem;
        }

        // isEmpty O(1)
        bool isEmpty()
        {
            return (top == nullptr);
        }
};

#endif