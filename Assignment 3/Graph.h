#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

#include "Vertex.h"
#include "Edge.h"

using namespace std;

// Undirected Graph Class 
class Graph 
{
    public:
        // Vectors of the Graph's Vertices and Edges
        vector<Vertex> vertices;
        vector<Edge> edges;

        void addVertex(string vertexID)
        {
            Vertex newVertex = Vertex(vertexID);
            vertices.push_back(newVertex);
        }

        Vertex* findVertex(string vertexID)
        {
            for (int i = 0, n = vertices.size(); i < n; i++)
            {
                if (vertices[i].id == vertexID)
                {
                    return &vertices[i];
                }
            }

            throw runtime_error("Vertex not found: " + vertexID);
        }

        void addEdge(string v1, string v2)
        {
            Vertex* vertex1 = findVertex(v1);
            Vertex* vertex2 = findVertex(v2);

            Edge newEdge = Edge(vertex1, vertex2);
            edges.push_back(newEdge);
            vertex1->addEdgeToVertex(&newEdge);
            vertex2->addEdgeToVertex(&newEdge);
        }
};

#endif