#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

// Public Node class for Binary Search Tree
class Node 
{
    public:
        // Holds a string as the Node's data
        string data;

        // Pointers that point to the left and right child Nodes
        Node* left;
        Node* right;

        // Declares parameterized constructor
        Node(string value)
        {
            this->data = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

#endif