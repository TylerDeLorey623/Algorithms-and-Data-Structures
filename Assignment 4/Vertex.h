#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Vertex
{
    public:
        // Member of Vertex class
        string id;
        float distance;
        Vertex* predecessor;

        // Used for Stack to print SSSP results
        Vertex* next = nullptr;

        // Parameterized constructor for Vertex class
        Vertex(string ID)
        {
            this->id = ID;
            this->distance = INFINITY;
            this->predecessor = nullptr;
        }
};

#endif