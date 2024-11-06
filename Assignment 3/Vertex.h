#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>

#include "Graph.h"

class Edge;

class Vertex
{
    public:
        string id;
        vector<Edge*> edges;

        Vertex(string ID)
        {
            this->id = ID;
        }

        void addEdgeToVertex(Edge* addedEdge)
        {
            edges.push_back(addedEdge);
        }
};

#endif