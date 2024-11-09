#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "./BinarySearchTree/BST.h"
#include "./UndirectedGraph/Graph.h"
#include "./UndirectedGraph/Matrix.h"
#include "./UndirectedGraph/AdjacencyList.h"

using namespace std;

int main()
{
    // BST Declaration
    BST myTree;

    // Graph and Matrix Declaration
    Graph* myGraph;
    Matrix* myMatrix;
    bool needToPrint = false;
    int curGraphNum = 0;

    int comparisonNum = 0;
    float avg = 0;
    int itemCount = 0;

    // File IO
    string item;
    ifstream file;

    string command;

    // Open magicitems file
    file.open("./BinarySearchTree/magicitems.txt");
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

    // Opening another file
    file.open("./BinarySearchTree/magicitems-find-in-bst.txt");
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
    file.open("./UndirectedGraph/graphs1.txt");
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
                // If command starts with "new graph", create a new Graph and Matrix
                currentWord >> nextWord;
                if (nextWord == "graph")
                {
                    // Prints information on Graph before creating a new one (if there exists one)
                    if (needToPrint)
                    {
                        curGraphNum++;

                        cout << endl;
                        cout << "MATRIX FOR GRAPH #" << curGraphNum << ": " << endl;
                        myMatrix->printMatrix();

                        cout << endl;
                        cout << "ADJACENCY LIST FOR GRAPH #" << curGraphNum << ": " << endl;
                        printAdjacencyList(myGraph);

                        myGraph->unloadGraph();
                        delete(myMatrix);
                        delete(myGraph);
                    }

                    needToPrint = true;

                    // Creates new Graph and Matrix
                    myGraph = new Graph();
                    myMatrix = new Matrix();
                }
            }
            // If command starts with "add"
            else if (word == "add")
            {
                // If command starts with "add vertex", add a Vertex to Graph and increment size of Matrix
                currentWord >> nextWord;
                if (nextWord == "vertex")
                {
                    currentWord >> vertexID;
                    myGraph->addVertex(vertexID);
                    myMatrix->incrementSize(vertexID);
                }
                // If command starts with "add edge", add an edge to current Graph that connects the two Vertices
                else if (nextWord == "edge")
                {
                    // Gets connecting first and second vertex ID 
                    currentWord >> vertex1;
                    currentWord >> vertex2 >> vertex2;

                    // Gets the index of these Vertices in the vertices array
                    vertex1Index = myGraph->findVertexIndex(vertex1);
                    vertex2Index = myGraph->findVertexIndex(vertex2);

                    // Adds edge linking each Vertex together using these indices
                    myGraph->addEdge(vertex1Index, vertex2Index);

                    // Sets matrix value to 1 at these indices
                    myMatrix->addValue(vertex1Index, vertex2Index);
                }
            }
        }
    }

    file.close();

    // Prints information for the last Graph if it exists
    if (needToPrint)
    {
        curGraphNum++;

        cout << endl;
        cout << "MATRIX FOR GRAPH #" << curGraphNum << ": " << endl;
        myMatrix->printMatrix();

        cout << endl;
        cout << "ADJACENCY LIST FOR GRAPH #" << curGraphNum << ": " << endl;
        printAdjacencyList(myGraph);

        myGraph->unloadGraph();
        delete(myMatrix);
        delete(myGraph);
    }
}