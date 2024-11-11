#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

#include "Vertex.h"
#include "Queue.h"

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

        // Does a Depth First Traversal of the graph
        void DFS(Vertex* v)
        {
            if (!v->processed)
            {
                outFile << v->id << " ";
                v->processed = true;
            }

            for (int i = 0, n = v->neighbors.size(); i < n; i++)
            {
                if (!v->neighbors[i]->processed)
                {
                    DFS(v->neighbors[i]);
                }
            }
        }

        // Does a Breadth First Traversal of the graph
        void BFS(Vertex* vertex)
        {
            Vertex* currentVertex;
            Vertex* currentNeighbor;

            Queue* q = new Queue();
            q->enqueue(vertex);
            vertex->processed = true;

            while (!q->isEmpty())
            {
                currentVertex = q->dequeue();
                outFile << currentVertex->id << " ";
                for (int i = 0, n = currentVertex->neighbors.size(); i < n; i++)
                {
                    currentNeighbor = currentVertex->neighbors[i];

                    if (!currentNeighbor->processed)
                    {
                        q->enqueue(currentNeighbor);
                        currentNeighbor->processed = true;
                    }   
                }
            }
            delete(q);
        }

        void resetProcessed()
        {
            for (int i = 0, n = vertices.size(); i < n; i++)
            {
                vertices[i]->processed = false;
            }
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