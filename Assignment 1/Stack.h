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

        // Push O(1)
        void push(string item)
        {
            Node* newNode = new Node(item);
            newNode->next = top;
            top = newNode;
            return;
        }

        // Pop O(1)
        string pop()
        {
            string poppedItem;

            if (!isEmpty())
            {
                poppedItem = top->data;
                Node *temp = top;
                top = top->next;

                // Free memory when dequeuing the Node
                delete(temp);
            }
            return poppedItem;
        }

        // isEmpty O(1)
        bool isEmpty()
        {
            return (top == nullptr);
        }

        // Temp display O(n)
        void display()
        {
            Node* curr = top;
            while (curr != NULL)
            {
                cout << curr->data + " ";
                curr = curr->next;
            }
            cout << endl;
        }

};

#endif