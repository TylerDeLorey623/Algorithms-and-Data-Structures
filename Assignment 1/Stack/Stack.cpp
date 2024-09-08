#include "../Stack/Stack.h"

// Push O(1)
void Stack::push(string item)
{
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;
    return;
}

// Pop O(1)
string Stack::pop()
{
    string poppedItem;

    if (!isEmpty())
    {
        poppedItem = head->data;
        head = head->next;
    }
    return poppedItem;
}

// isEmpty O(1)
bool Stack::isEmpty()
{
    return (head == nullptr);
}

// Display
void Stack::display()
{
    Node* curr = head;
    while (curr != NULL)
    {
        cout << curr->data + " ";
        curr = curr->next;
    }
    cout << endl;
}