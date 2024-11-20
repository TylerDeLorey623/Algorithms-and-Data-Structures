#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

#include "Vertex.h"

using namespace std;

// Directed and Weighted Graph Class 
class Graph 
{
    public:
        // Vectors of the Graph's Vertices and Edges
        vector<Vertex*> vertices;
        vector< pair < pair < Vertex*, Vertex*>, int> > edges;

        // Add a Vertex to the Graph
        void addVertex(string vertexID)
        {
            Vertex* newVertex = new Vertex(vertexID);
            vertices.push_back(newVertex);
        }

        // Finds a specific Vertex index in Vertices Array based on its ID
        int findVertexIndex(string vertexID)
        {
            for (int index = 0, n = vertices.size(); index < n; index++)
            {
                if (vertices[index]->id == vertexID)
                {
                    return index;
                }
            }

            throw runtime_error("Vertex not found: " + vertexID);
        }

        // Adds an edge from Vertex 1 to Vertex 2
        void addEdge(string vertex1, string vertex2, int weight)
        {
            // Gets the index of these Vertices in the vertices array
            int vertex1Index = findVertexIndex(vertex1);
            int vertex2Index = findVertexIndex(vertex2);

            Vertex* v1 = vertices[vertex1Index];
            Vertex* v2 = vertices[vertex2Index];

            // Adds an edge to the edges vector (including the weight)
            edges.push_back({{v1, v2}, weight});
        }

        // Unloads each Vertex in the Graph
        void unloadGraph()
        {
            // Deletes each Vertex in the Graph
            for (int i = 0, n = vertices.size(); i < n; i++)
            {
                delete(vertices[i]);
            }
        }
};

#endif