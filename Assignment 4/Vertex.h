#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>

using namespace std;

class Vertex
{
    public:
        // Members of Vertex class
        string id;
        bool processed = false;
        vector<Vertex*> neighbors;
        vector<int> weights;

        // Parameterized constructor for Vertex class
        Vertex(string ID)
        {
            this->id = ID;
        }

        // Connects a Vertex to this Vertex (adding an Edge) and a weight for that Edge
        void addNeighbor(Vertex* addedVertex, int weight)
        {
            neighbors.push_back(addedVertex);
            weights.push_back(weight);
        }
};

#endif