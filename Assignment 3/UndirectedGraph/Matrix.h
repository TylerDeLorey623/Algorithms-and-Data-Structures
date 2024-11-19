#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    public:
        // Members of Matrix class
        vector< vector<int> > matrix;
        vector<string> vertexIDs;

        // Increment size of Matrix by 1 and add ID to vector
        void incrementSize(string ID)
        {
            vertexIDs.push_back(ID);
            int size = vertexIDs.size();

            this->matrix.resize(size);
            for (int i = 0; i < size; i++)
            {
                this->matrix[i].resize(size, 0);
            }
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
            bool displayIDs = true;
            int size = vertexIDs.size();

            // Print first row of IDs
            if (displayIDs)
            {
                outFile << "  ";
                for (int i = 0; i < size; i++)
                {
                    outFile << vertexIDs[i] << " ";
                }
                outFile << endl;
            }

            // Prints matrix information with vertex ID in first column
            for (int i = 0; i < size; i++)
            {
                if (displayIDs)
                {
                    outFile << vertexIDs[i] << " ";
                }
                for (int j = 0; j < size; j++)
                {
                    if ((displayIDs) && (vertexIDs[j].size() > 1))
                    {
                        outFile << " ";
                    }
                    outFile << matrix[i][j] << " ";
                }
                outFile << endl;
            }
        }
};

#endif