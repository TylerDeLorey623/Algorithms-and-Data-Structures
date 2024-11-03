#ifndef BST_H
#define BST_H

#include <iostream>
#include "Node.h"

using namespace std;

class BST 
{
    public:
        // Keeps track of root of the BST
        Node* root = nullptr;

        // Inserts the item into the correct position in BST
        void insert(string item)
        {
            // Declaration and initialization of Nodes and variables
            // newNode is the Node that will eventually be inserted into BST
            Node *newNode = new Node(item);
            Node *prev = nullptr;
            Node *curNode = nullptr;
            bool lessThan = false;

            cout << item << ": ";
            
            // Traverses BST to find correct insertion position
            curNode = root;
            while (curNode != NULL)
            {
                // Keeps track of the previous Node when exiting the loop
                // Either left or right child of this Node will be the new inserted Node
                prev = curNode;

                if (curNode != root)
                {
                    cout << ", ";
                }

                // If item belongs to the left subtree of the current Node, traverse through that subtree
                if (item < curNode->data)
                {
                    cout << "L";
                    lessThan = true;
                    curNode = curNode->left;
                }
                // If item belongs to the right subtree of the current Node, traverse through that subtree
                else
                {
                    cout << "R";
                    lessThan = false;
                    curNode = curNode->right;
                }
            }

            // If the parent Node is NULL, set it to the root of the BST    
            if (prev == nullptr)
            {
                root = newNode;
            }
            // If the new inserted Node should be the left child of its parent, set it to its left child
            else if (lessThan)
            {
                prev->left = newNode;
            }
            // If the new inserted Node should be the right child of its parent, set it its right child
            else
            {
                prev->right = newNode;
            }

            cout << endl;
        }

        void inorderBST(Node* curNode)
        {
            if (curNode != nullptr)
            {
                inorderBST(curNode->left);
                cout << curNode->data << endl;
                inorderBST(curNode->right);
            }
        }
};

#endif