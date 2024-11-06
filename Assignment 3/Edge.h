#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <vector>

#include "Graph.h"

class Vertex;

class Edge
{
    public:
        Vertex* vertex1;
        Vertex* vertex2;

        Edge(Vertex* firstVertex, Vertex* secondVertex)
        {
            this->vertex1 = firstVertex;
            this->vertex2 = secondVertex;
        }
};

#endif