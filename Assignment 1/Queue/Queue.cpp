#include "../Queue/Queue.h"

// Push
void Queue::enqueue(string item)
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

// Pop O(1)
string Queue::dequeue()
{
    string dequeuedItem = NULL;

    if (!isEmpty())
    {
        dequeuedItem = head->data;
        head = head->next;
    }

    return dequeuedItem;
}

// isEmpty
bool Queue::isEmpty()
{
    return (head == NULL);
}