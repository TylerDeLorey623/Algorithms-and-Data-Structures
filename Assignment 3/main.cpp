#include <iostream>
#include <fstream>

#include "BST.h"

using namespace std;

int main()
{
    // BST Declaration
    BST myTree; 

    // File IO
    string line;
    ifstream file;

    // Open magicitems file
    file.open("magicitems.txt");
    if (!file.is_open())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    // Read each line from file and insert it into the BST
    while (getline(file, line))
    {
        myTree.insert(line);
    }

    // Close magicitems file
    file.close();

    // Prints out entire BST with an in-order traversal
    cout << endl << "INORDER TRAVERSAL OF BST:" << endl;
    myTree.inorderBST(myTree.root);
}