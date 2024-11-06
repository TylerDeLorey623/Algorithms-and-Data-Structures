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

        // Add a Vertex to the Graph
        void addVertex(string vertexID)
        {
            Vertex newVertex = Vertex(vertexID);
            vertices.push_back(newVertex);
        }

        // Finds a specific Vertex based on its ID
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

        // Adds an edge between two Vertices
        void addEdge(string v1, string v2)
        {
            Vertex* vertex1 = findVertex(v1);
            Vertex* vertex2 = findVertex(v2);

            Edge newEdge = Edge(vertex1, vertex2);
            edges.push_back(newEdge);
            vertex1->addEdgeToVertex(&newEdge);
            vertex2->addEdgeToVertex(&newEdge);
        }

        // Prints a matrix for the Graph
        void printMatrix()
        {
            // Initialize matrix variables
            int vertSize = vertices.size();
            int edgeCount = edges.size();
            string firstVertex, secondVertex;
            int first = 0, second = 0;

            // Initialize matrix 2D array
            int matrix[vertSize][vertSize];

            // Finds connected vertices
            for (int iter = 0; iter < edgeCount; iter++)
            {
                firstVertex = edges[iter].vertex1->id;
                secondVertex = edges[iter].vertex2->id;
                first = stoi(firstVertex) - 1;
                second = stoi(secondVertex) - 1;

                matrix[first][second] = 1;
                matrix[second][first] = 1;
            }

            // Prints entire Matrix
            cout << "M ";
            for (int i = 0; i < vertSize; i++)
            {
                cout << vertices[i].id << " ";
            }
            cout << endl;

            for (int i = 0; i < vertSize; i++)
            {
                cout << vertices[i].id << " ";
                for (int j = 0; j < vertSize; j++)
                {
                    if (matrix[i][j] != 1)
                    {
                        matrix[i][j] = 0;
                    }
                    
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }

        }
};

#endif