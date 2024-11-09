#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <vector>

#include "Graph.h"

using namespace std;

// Prints adjacency list for current graph
void printAdjacencyList(Graph* currentGraph)
{
    vector<Vertex*> graphVertices = currentGraph->vertices;
    int size = graphVertices.size();
    int neighborSize = 0;

    Vertex* currentVertex;
    string currentNeighborID;

    // Iterates through each Vertex in the Graph
    for (int index = 0; index < size; index++)
    {
        currentVertex = graphVertices[index];
        neighborSize = currentVertex->neighbors.size();

        // Prints the ID of each Vertex
        cout << "[" << currentVertex->id << "] ";
        
        // Prints the neighbors of each Vertex
        for (int neighborIndex = 0; neighborIndex < neighborSize; neighborIndex++)
        {
            currentNeighborID = currentVertex->neighbors[neighborIndex]->id;
            cout << currentNeighborID << " ";
        }

        cout << endl;
    }
}

#endif