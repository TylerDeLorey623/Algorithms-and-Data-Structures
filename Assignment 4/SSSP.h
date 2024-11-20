#ifndef SSSP_H
#define SSSP_H

#include <iostream>
#include <vector>

#include "Stack.h"

using namespace std;

// Prototype for upcoming functions
void relax(Vertex* v1, Vertex* v2, int weight);
void SSSPresults(Graph* graph, Vertex* source);
int findWeight(Graph* graph, Vertex* v1, Vertex* v2);

// Does the Bellman-Ford Single-Source Shortest Path (SSSP) Algorithm for the Graph
void bellmanFord(Graph* graph, Vertex* source, int curGraphNum)
{
    // Gets sizes of vertices and edges vectors
    int vertSize = graph->vertices.size();
    int edgeSize = graph->edges.size();

    // Declares variables for algorithm
    Vertex* v1;
    Vertex* v2;
    int weight;
    bool worked = true;

    // Source is starting point, so the distance would be 0
    source->distance = 0;

    // Relaxes edges |vertices| times to find shortest path
    for (int i = 1; i < vertSize; i++)
    {
        for (int j = 0; j < edgeSize; j++)
        {
            v1 = graph->edges[j].first.first;
            v2 = graph->edges[j].first.second;
            weight = graph->edges[j].second;

            relax(v1, v2, weight);
        }
    }

    // Check for negative cycles
    for (int iter = 0; iter < edgeSize; iter++)
    {
        v1 = graph->edges[iter].first.first;
        v2 = graph->edges[iter].first.second;
        weight = graph->edges[iter].second;

        // If this succeeds, that means a negative cycle exists and algorithm fails
        if (v2->distance > (v1->distance + weight))
        {
            worked = false;
            break;
        }
    }

    // Output results based on success or failure
    if (worked)
    {
        cout << "RESULTS FOR GRAPH #" << curGraphNum << endl;
        SSSPresults(graph, source);
    }
    else
    {
        cout << "Bellman Ford Algorithm did not work for Graph #" << curGraphNum << endl;
    }
}

// Checks if a better path was found to "toVertex"
void relax(Vertex* fromVertex, Vertex* toVertex, int weight)
{
    // Updates distance and predecessor if a shorter path was found
    if (toVertex->distance > (fromVertex->distance + weight))
    {
        toVertex->distance = fromVertex->distance + weight;
        toVertex->predecessor = fromVertex;
    }
}

// Prints results of the algorithm
void SSSPresults(Graph* graph, Vertex* source)
{
    Stack myStack;
    int totalWeight;

    Vertex* dest;
    Vertex* curVertex;
    Vertex* poppedVertex;

    // Iterates through all vertices in Graph
    for (int i = 0, size = graph->vertices.size(); i < size; i++)
    {
        dest = graph->vertices[i];

        // Skip iteration if the destination is the source (output is obviously 0)
        if (dest != source)
        {
            curVertex = dest;
            totalWeight = 0;

            // Trace path from destination to source using the Stack data structure
            while (curVertex != source)
            {
                myStack.push(curVertex);
                totalWeight += findWeight(graph, curVertex->predecessor, curVertex);
                curVertex = curVertex->predecessor;
            }

            // Prints results of SSSP and the total cost
            cout << source->id << " --> " << dest->id << " cost is " << totalWeight << "; path: " << source->id;
            while (!myStack.isEmpty())
            {
                poppedVertex = myStack.pop();
                cout << " --> " << poppedVertex->id;
            }
            cout << endl;
        }
    }
}

// Returns the weight of a specific Edge between two Vertices
int findWeight(Graph* graph, Vertex* v1, Vertex* v2)
{
    // Iterate through all edges to find the weight of edge v1 - v2
    for (int i = 0, size = graph->edges.size(); i < size; i++)
    {
        if ((v1 == graph->edges[i].first.first) && (v2 == graph->edges[i].first.second))
        {
            return graph->edges[i].second;
        }
    }

    // Throw error if edge was not found
    throw runtime_error("Something went wrong with printing SSSP results");
}

#endif