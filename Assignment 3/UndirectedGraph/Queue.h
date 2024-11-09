#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "./Vertex.h"

using namespace std;

// Public Queue class for Breadth First Search
class Queue 
{
    public:
        Vertex* head = nullptr;
        Vertex* tail = nullptr;

        // Enqueue O(1)
        void enqueue(Vertex* newVertex)
        {
            if (isEmpty())
            {
                head = newVertex;
            }
            else
            {
                tail->next = newVertex;
            }

            tail = newVertex;
            return;
        }

        // Dequeue O(1)
        Vertex* dequeue()
        {
            if (isEmpty())
            {
                throw runtime_error("Attempted to dequeue empty queue");
            }

            Vertex* dequeuedItem = head;
            head = head->next;

            return dequeuedItem;
        }

        // isEmpty O(1)
        bool isEmpty()
        {
            return (head == nullptr);
        }
};

#endif