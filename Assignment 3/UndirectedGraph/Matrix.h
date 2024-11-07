#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

#include "Graph.h"

using namespace std;

class Matrix
{
    public:
        // Members of Matrix class
        vector<vector<int>> matrix;
        int size;
        Graph* graph;

        // Parameterized constructor for Matrix class
        Matrix(int SIZE, Graph* GRAPH)
        {
            this->size = SIZE;
            matrix.resize(size, vector<int>(SIZE, 0));
            this->graph = GRAPH;
        }

        // Sets a value to 1
        void addValue(int i, int j)
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }

        // Prints Matrix
        void printMatrix()
        {
            // Print first row
            cout << "M ";
            for (int i = 0; i < size; i++)
            {
                cout << string(graph->vertices[i]->id) << " ";
            }
            cout << endl;

            for (int i = 0; i < size; i++)
            {
                cout << string(graph->vertices[i]->id) << " ";
                for (int j = 0; j < size; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

#endif