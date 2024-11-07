#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "BST.h"
#include "Graph.h"
#include "Matrix.h"

using namespace std;

int main()
{
    // BST Declaration
    BST myTree;

    // Vector of Graphs Declaration
    vector<Graph*> myGraphs;
    vector<Matrix*> myMatrices;
    int curIndex = -1;

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
    //myTree.inorderTrav();

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

    // Read each line from file and set up the Graphs and Matrices
    while (getline(file, command))
    {
        istringstream currentWord(command);
        string word, nextWord, vertexID, vertex1, vertex2;
        int vertex1Index = 0, vertex2Index = 0;

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
                    myGraphs.push_back(new Graph());
                    curIndex++;
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
                    myGraphs[curIndex]->addVertex(vertexID);
                }
                // If command starts with "add edge", add an edge to current Graph that connects the two Vertices
                else if (nextWord == "edge")
                {
                    // Creates Matrix for Graph if it hasn't been created already (ASSUMES ALL VERTICES WERE ALREADY DEFINED IN FILE BEFORE THE EDGES)
                    if (int(myMatrices.size()) <= curIndex)
                    {
                        myMatrices.push_back(new Matrix(myGraphs[curIndex]->verticesSize(), myGraphs[curIndex]));
                    }

                    // Gets connecting first and second vertex ID 
                    currentWord >> vertex1;
                    currentWord >> vertex2 >> vertex2;

                    // Gets the index of these Vertices in the vertices array
                    vertex1Index = myGraphs[curIndex]->findVertexIndex(vertex1);
                    vertex2Index = myGraphs[curIndex]->findVertexIndex(vertex2);

                    // Sets matrix value to 1 at these indices
                    myMatrices[curIndex]->addValue(vertex1Index, vertex2Index);

                    // Adds edge linking each Vertex together using these indices
                    myGraphs[curIndex]->addEdge(vertex1Index, vertex2Index);
                }
            }
        }
    }

    file.close();

    // Print matrix for each Graph
    cout << endl;
    for (int curMatrix = 0, matrixCount = myMatrices.size(); curMatrix < matrixCount; curMatrix++)
    {
        cout << "MATRIX FOR GRAPH #" << curMatrix + 1 << ": " << endl;
        myMatrices[curMatrix]->printMatrix();
        cout << endl;
    }

    // Unloading each Graph and Matrix
    for (int curGraph = 0, graphCount = myGraphs.size(); curGraph < graphCount; curGraph++)
    {
        myGraphs[curGraph]->unloadGraph();
        delete(myGraphs[curGraph]);
        delete(myMatrices[curGraph]);
    }
    myGraphs.clear();
    myMatrices.clear();
}