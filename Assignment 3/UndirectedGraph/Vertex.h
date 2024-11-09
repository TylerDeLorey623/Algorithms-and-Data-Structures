#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>

#include "Graph.h"

class Vertex
{
    public:
        // Members of Vertex class
        string id;
        bool processed = false;
        vector<Vertex*> neighbors;

        // Member used for BFS Queue
        Vertex* next = nullptr;

        // Parameterized constructor for Vertex class
        Vertex(string ID)
        {
            this->id = ID;
        }

        // Connects a Vertex to this Vertex (adding an Edge)
        void addNeighbor(Vertex* addedVertex)
        {
            neighbors.push_back(addedVertex);
        }
};

#endif