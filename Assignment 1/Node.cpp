#include "Node.h"

// Constructor that initializes a node with data
Node::Node(string value)
{
    this->data = value;
    this->next = nullptr;
} 