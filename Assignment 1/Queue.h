#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "./Node.h"

using namespace std;

// Public Queue class for linked list implementation of a queue
class Queue 
{
    public:
        Node* head = nullptr;
        Node* tail = nullptr;

        // Enqueue O(1)
        void enqueue(string item)
        {
            Node* newNode = new Node(item);

            if (isEmpty())
            {
                head = newNode;
            }
            else
            {
                tail->next = newNode;
            }

            tail = newNode;
        }

        // Dequeue O(1)
        string dequeue()
        {
            string dequeuedItem;
            if (!isEmpty())
            {
                dequeuedItem = head->data;
                head = head->next;
            }

            return dequeuedItem;
        }

        // isEmpty O(1)
        bool isEmpty()
        {
            return (head == nullptr);
        }

        // Temp display O(n)
        void display()
        {
            Node* curr = head;
            while (curr != NULL)
            {
                cout << curr->data + " ";
                curr = curr->next;
            }
            cout << endl;
        }
};

#endif