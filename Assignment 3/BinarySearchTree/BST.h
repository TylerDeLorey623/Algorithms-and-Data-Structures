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

            outFile << item << ": ";
            
            // Traverses BST to find correct insertion position
            curNode = root;
            while (curNode != NULL)
            {
                // Keeps track of the previous Node when exiting the loop
                // Either left or right child of this Node will be the new inserted Node
                prev = curNode;

                if (curNode != root)
                {
                    outFile << ", ";
                }

                // If item belongs to the left subtree of the current Node, traverse through that subtree
                if (item < curNode->data)
                {
                    outFile << "L";
                    lessThan = true;
                    curNode = curNode->left;
                }
                // If item belongs to the right subtree of the current Node, traverse through that subtree
                else
                {
                    outFile << "R";
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

            outFile << endl;
        }

        // Function that programmers calls in main, traversal starts at the root Node
        void inorderTrav()
        {
            inorderBST(root);
        }

        // Does an inorder traversal of BST (Sorted Output)
        void inorderBST(Node* curNode)
        {
            if (curNode != nullptr)
            {
                inorderBST(curNode->left);
                outFile << curNode->data << endl;
                inorderBST(curNode->right);
            }
        }

        // Searches for target item in BST
        int search(string target)
        {
            int comparisonNum = 0;
            Node* curNode = root;
            string currentData;

            // Traverses BST until it ends up in correct position
            while (curNode != NULL)
            {
                currentData = curNode->data;

                comparisonNum++;
                
                // If target matches current Node data, it has been found
                if (target == currentData)
                {
                    outFile << "FOUND ";
                    break;
                }
                // If target is smaller than current Node data, traverse left subtree
                else if (target < currentData)
                {
                    outFile << "L ";
                    curNode = curNode->left;
                }
                // If target is greater than current Node data, traverse right subtree
                else
                {
                    outFile << "R ";
                    curNode = curNode->right;
                }
            }

            // If loop finishes and the current Node is NULL, means data has not been found
            if (curNode == NULL)
            {
                outFile << "NOT_FOUND ";
            }

            return comparisonNum;
        }
};

#endif