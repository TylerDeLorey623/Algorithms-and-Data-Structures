// Uses SORT.H from Assignment 2 (Quick Sort) 

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <random>
#include <vector>
#include <climits>

#include "Spice.h"

using namespace std;

// Returns the partition index
int partition(vector<Spice*> &myItems, int p, int begin, int end)
{
    // Indicates the currently found pivot position 
    int l = begin - 1;

    // Swap myItems[p] and myItems[end] (moves pivot value to the end)
    Spice* temp = myItems[p];
    myItems[p] = myItems[end];
    myItems[end] = temp;

    for (int i = begin; i < end; i++)
    {
        // If unit price is greater than pivot element
        if (myItems[i]->getUnitPrice() > myItems[end]->getUnitPrice())
        {
            // Swap myItems[l] and myItems[i] to move larger element to the left partition
            // This is because the vector is being sorted in descending order
            l++;

            temp = myItems[l];
            myItems[l] = myItems[i];
            myItems[i] = temp; 
        }
    }

    // Swap the pivot and partition indexes to put pivot in the correct position
    temp = myItems[end];
    myItems[end] = myItems[l + 1];
    myItems[l + 1] = temp; 

    return l + 1;
}

// Pass by reference
void sort(vector<Spice*> &myItems, int begin = 0, int end = INT_MIN)
{
    // If end parameter wasn't clarified, set it to the last index of the vector (myItems[end] returns last element)
    // This means the function is dealing with the entire vector
    if (end == INT_MIN)
    {
        end = myItems.size() - 1;
    }
    // Base case
    else if (begin >= end)
    {
        return;
    }

    // Selects random index for the contenders
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(begin, end);
    int contender1 = distrib(gen);
    int contender2 = distrib(gen);
    int contender3 = distrib(gen);

    // Find best pivot value out of the three contenders
    int pivotValue = 0;
    if ((contender1 > contender2 && contender2 > contender3) || (contender3 > contender2 && contender2 > contender1))
    {
        pivotValue = contender2;
    }
    else if ((contender2 > contender3 && contender3 > contender1) || (contender1 > contender3 && contender3 > contender2))
    {
        pivotValue = contender3;
    }
    else
    {
        pivotValue = contender1;
    }

    // Gets pivot index (Choosing the pivot element to be myItems[pivotValue])
    int r = partition(myItems, pivotValue, begin, end);

    // Runs quick sort on first and second parts of the vector
    sort(myItems, begin, r - 1);
    sort(myItems, r + 1, end);
}

#endif