#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "BST.h"
#include "Graph.h"

using namespace std;

int main()
{
    // BST Declaration
    BST myTree;

    // Vector of Graphs Declaration
    vector<Graph> myGraphs;
    int curGraphIndex = -1;

    int comparisonNum = 0;
    float avg = 0;
    int itemCount = 0;

    // File IO
    string item;
    ifstream file;

    string command;

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
        //myTree.insert(item);
    }

    // Close magicitems file
    file.close();

    // Prints out entire BST with an in-order traversal
    cout << endl << "INORDER TRAVERSAL OF BST:" << endl;
    myTree.inorderTrav();

    // Opening another file
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

    file.close();

    // Calculate average comparisons
    avg = avg / itemCount;
    cout << endl << "Average Number of Comparisons for BST Search: " << fixed << setprecision(2) << avg << endl << endl;

    // Open graph file
    file.open("graphs1.txt");
    if (!file.is_open())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    // Read each line from file and set up the Graphs
    while (getline(file, command))
    {
        istringstream currentWord(command);
        string word, nextWord, vertexID, vertex1, vertex2;

        // Gets the current word in the command line
        while (currentWord >> word)
        {
            // If it is a comment, skip to next line in file 
            if (word == "--")
            {
                break;
            }
            // If command starts with "new"
            else if (word == "new")
            {
                // If command starts with "new graph", create a new Graph
                currentWord >> nextWord;
                if (nextWord == "graph")
                {
                    cout << "GRAPH CREATION" << endl;
                    myGraphs.push_back(Graph());
                    curGraphIndex++;
                }
            }
            // If command starts with "add"
            else if (word == "add")
            {
                // If command starts with "add vertex", add a Vertex to current Graph
                currentWord >> nextWord;
                if (nextWord == "vertex")
                {
                    currentWord >> vertexID;
                    cout << "ADDING VERTEX " << vertexID << endl;
                    myGraphs[curGraphIndex].addVertex(vertexID);
                }
                // If command starts with "add edge", add an edge to current Graph that connects the two Vertices
                else if (nextWord == "edge")
                {
                    currentWord >> vertex1;
                    currentWord >> vertex2 >> vertex2;
                    cout << "EDGE ADDING " << vertex1 << " to " << vertex2 << endl;
                    myGraphs[curGraphIndex].addEdge(vertex1, vertex2);
                }
            }
        }
    }

    cout << endl;

    // Print matrix for each Graph
    for (int curGraph = 0, graphCount = myGraphs.size(); curGraph < graphCount; curGraph++)
    {
        cout << "MATRIX FOR GRAPH #" << curGraph + 1 << ": " << endl;
        myGraphs[curGraph].printMatrix();
        cout << endl;
    }

    file.close();
}