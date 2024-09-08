#include "Node.h"

// Empty constructor that initializes a node to NULL
Node::Node()
{
    this->data = nullptr;
    this->next = nullptr;
}

// Parameterized constructor that initializes a node with data
Node::Node(string value)
{
    this->data = value;
    this->next = nullptr;
} 