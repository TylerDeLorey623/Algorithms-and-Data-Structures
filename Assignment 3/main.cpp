#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "GlobalOutput.h"
#include "./BinarySearchTree/BST.h"
#include "./UndirectedGraph/Graph.h"
#include "./UndirectedGraph/Matrix.h"
#include "./UndirectedGraph/AdjacencyList.h"

using namespace std;

// Prototype for printInformation function
void printInformation(bool needToPrint, int& graphNum, Matrix* matrix, Graph* graph);

int main()
{
    // If output file isn't valid, end program
    if (!outFile.is_open()) 
    {
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    // BST Declaration
    BST myTree;

    // Graph and Matrix Declaration
    Graph* myGraph;
    Matrix* myMatrix;
    bool check = false;
    int curGraphNum = 0;

    int comparisonNum = 0;
    float avg = 0;
    int itemCount = 0;

    /*
        BINARY SEARCH TREE IMPLEMENTATION
     */

    // File IO
    string item;
    ifstream file;

    string command;

    // Open magicitems file
    file.open("./BinarySearchTree/magicitems.txt");
    if (!file.is_open())
    {
        cerr << "File failed to open." << endl;
        return 1;
    }

    // Read each line from file and insert it into the BST
    outFile << "INSERTING INTO BST" << endl << endl;
    while (getline(file, item))
    {
        myTree.insert(item);
    }

    // Close magicitems file
    file.close();

    // Prints out entire BST with an in-order traversal
    outFile << endl << "INORDER TRAVERSAL OF BST:" << endl;
    myTree.inorderTrav();

    // Opening another file
    file.open("./BinarySearchTree/magicitems-find-in-bst.txt");
    if (!file.is_open())
    {
        cerr << "File failed to open." << endl;
        return 1;
    }

    outFile << endl;

    // Read each line from file and search for it in the BST
    while (getline(file, item))
    {
        outFile << "Comparisons to find \"" << item << "\": ";
        comparisonNum = myTree.search(item);
        outFile << "(" << comparisonNum << ")" << endl;
        avg += comparisonNum;
        itemCount++;
    }

    file.close();

    // Calculate average comparisons
    avg = avg / itemCount;
    outFile << endl << "Average Number of Comparisons for BST Search: " << fixed << setprecision(2) << avg << endl << endl;

    // Unload BST
    myTree.unloadTree();

    /*
        UNDIRECTED GRAPH IMPLEMENTATION
     */

    // Open graph file
    file.open("./UndirectedGraph/graphs1.txt");
    if (!file.is_open())
    {
        cerr << "File failed to open." << endl;
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
                    printInformation(check, curGraphNum, myMatrix, myGraph);
                    check = true;

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
    printInformation(check, curGraphNum, myMatrix, myGraph);

    cout << "All output is in the output.txt file" << endl;
    outFile.close();
}

void printInformation(bool needToPrint, int& graphNum, Matrix* matrix, Graph* graph)
{
    if (needToPrint)
    {
        graphNum++;

        // Print Matrix
        outFile << endl;
        outFile << "MATRIX FOR GRAPH #" << graphNum << ": " << endl;
        matrix->printMatrix();

        // Print Adjacency List
        outFile << endl;
        outFile << "ADJACENCY LIST FOR GRAPH #" << graphNum << ": " << endl;
        printAdjacencyList(graph);

        // Depth first traversal starting from first Vertex
        outFile << endl;
        outFile << "DEPTH-FIRST TRAVERSAL FOR GRAPH #" << graphNum << ": " << endl;
        graph->DFS(graph->vertices[0]);

        // Reset processed values
        graph->resetProcessed();

        // Breadth first traversal starting from first Vertex
        outFile << endl;
        outFile << "BREADTH-FIRST TRAVERSAL FOR GRAPH #" << graphNum << ": " << endl;
        graph->BFS(graph->vertices[0]);

        outFile << endl;

        graph->unloadGraph();
        delete(matrix);
        delete(graph);
    }
}