#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "Spice.h"
#include "Sort.h"
#include "Greed.h"
#include "Graph.h"

using namespace std;

int main()
{
    // Used for File Input
    ifstream file;
    string line;

    // For Graph class and Output
    Graph* myGraph;
    bool check = false;

    // Indices for each word in the line
    int commandIndex = 0, typeIndex = 1, vertexIndex = 2, v1Index = 2, v2Index = 4, weightIndex = 5;

    // Open Graphs file
    file.open("graphs2.txt");
    if (!file.is_open())
    {
        cerr << "File failed to open." << endl;
        return 1;
    }

    // Read each line from Graph file
    while (getline(file, line))
    {
        istringstream stream(line);
        string word;
        vector<string> words;

        int vertex1Index, vertex2Index;

        // Split each word of each line in the file
        while (stream >> word)
        {
            // Skip to next line if it is a comment or a blank line
            if ((word == "--") || (word.empty()))
            {
                break;
            }
    
            // Removes semicolons
            if (word.back() == ';')
            {
                word.pop_back();
            }

            // Adds each word to the words vector
            words.push_back(word);
        }

        if (!words.empty())
        {
            // If it was a "new graph" command, create a new Graph
            if ((words[commandIndex] == "new") && (words[typeIndex] == "graph"))
            {
                // Run SSSP and outputs results
                /* ENTER SSSP FUNCTION CALL HERE */
                if (check)
                {
                    myGraph->unloadGraph();
                    delete(myGraph);
                }
                check = true;
                
                myGraph = new Graph();
            }
            // If it was an "add" command, check if it was for adding a vertex or adding an edge
            else if (words[commandIndex] == "add")
            {
                // If command was "add vertex", add a Vertex to Graph
                if (words[typeIndex] == "vertex")
                {
                    myGraph->addVertex(words[vertexIndex]);
                }
                // If command was "add edge", add an edge to current Graph that connects the two Vertices
                else if (words[typeIndex] == "edge")
                {
                    // Gets the index of these Vertices in the vertices array
                    vertex1Index = myGraph->findVertexIndex(words[v1Index]);
                    vertex2Index = myGraph->findVertexIndex(words[v2Index]);

                    // Adds a directed edge with weight linking Vertex 1 to Vertex 2 using those indices
                    myGraph->addEdge(vertex1Index, vertex2Index, stoi(words[weightIndex]));
                }
            }
        }
    }

    if (check)
    {
        myGraph->unloadGraph();
        delete(myGraph);
    }

    file.close();

    // Spices Vector
    vector<Spice*> mySpices;
    bool sortSpices = false;

    // Indices for each word in the line
    commandIndex = 0; 
    int nameIndex = 3, priceIndex = 6, qtyIndex = 9, capacityIndex = 3;

    // Open spice file
    file.open("spice.txt");
    if (!file.is_open())
    {
        cerr << "File failed to open." << endl;
        return 1;
    }

    // Read each line from spice file
    while (getline(file, line))
    {
        istringstream stream(line);
        string word;
        vector<string> words;

        // For Spice Object
        Spice* newSpice;
        string name;
        float price;
        int qty;

        // Split each word of each line in the file
        while (stream >> word)
        {
            // Skip to next line if it is a comment or a blank line
            if ((word == "--") || (word.empty()))
            {
                break;
            }
    
            // Removes semicolons
            if (word.back() == ';')
            {
                word.pop_back();
            }

            // Adds each word to the words vector
            words.push_back(word);
        }

        if (!words.empty())
        {
            // If it was a spice command, create a new Spice object
            if (words[commandIndex] == "spice")
            {
                // Gets name, price, and quantity values
                name = words[nameIndex];
                price = stof(words[priceIndex]);
                qty = stoi(words[qtyIndex]);

                // Creates new Spice object (including its unit price)
                newSpice = new Spice(name, price, qty);
                mySpices.push_back(newSpice);
            }
            else if (words[commandIndex] == "knapsack")
            {
                // Sort spices vector by unit price
                if (!sortSpices)
                {
                    sort(mySpices);
                    sortSpices = true;
                }

                // Performs greedy algorithm and prints results
                fKnapsack(mySpices, stoi(words[capacityIndex]));
            }
        }
    }

    // Unloads Spices
    for (int i = 0, n = mySpices.size(); i < n; i++)
    {
        delete(mySpices[i]);
    }

    file.close();
}