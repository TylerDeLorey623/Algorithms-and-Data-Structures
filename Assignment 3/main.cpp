#include <iostream>
#include <fstream>
#include <iomanip>

#include "BST.h"

using namespace std;

int main()
{
    // BST Declaration
    BST myTree;

    int comparisonNum = 0;
    float avg = 0;
    int itemCount = 0;

    // File IO
    string item;
    ifstream file;

    // Open magicitems file
    file.open("magicitems.txt");
    if (!file.is_open())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    // Read each line from file and insert it into the BST
    while (getline(file, item))
    {
        myTree.insert(item);
    }

    // Close magicitems file
    file.close();

    // Prints out entire BST with an in-order traversal
    cout << endl << "INORDER TRAVERSAL OF BST:" << endl;
    myTree.inorderTrav();

    // Finding magicitems-find-in-bst.txt in the BST
    file.open("magicitems-find-in-bst.txt");
    if (!file.is_open())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    // Read each line from file and search for it in the BST
    while (getline(file, item))
    {
        cout << "Comparisons to find \"" << item << "\": ";
        comparisonNum = myTree.search(item);
        cout << "(" << comparisonNum << ")" << endl;
        avg += comparisonNum;
        itemCount++;
    }

    // Calculate average comparisons
    avg = avg / itemCount;
    cout << endl << "Average Number of Comparisons for BST Search: " << fixed << setprecision(2) << avg << endl << endl;

}