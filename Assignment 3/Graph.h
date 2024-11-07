#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

#include "Vertex.h"

using namespace std;

// Undirected Graph Class 
class Graph 
{
    public:
        // Vectors of the Graph's Vertices
        vector<Vertex*> vertices;

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

        // Adds an edge between two Vertices (parameters are indices in vertices Array)
        void addEdge(int vertex1, int vertex2)
        {
            vertices[vertex1]->addNeighbor(vertices[vertex2]);
            vertices[vertex2]->addNeighbor(vertices[vertex1]);
        }

        // Gets the size of the vertices Array
        int verticesSize()
        {
            return vertices.size();
        }

        // Unloads each Vertex in the Graph
        void unloadGraph()
        {
            // Deletes each Vertex in the Graph
            for (int i = 0, n = vertices.size(); i < n; i++)
            {
                delete(vertices[i]);
            }

            // Clears the Vertices Array
            vertices.clear();
        }
};

#endif