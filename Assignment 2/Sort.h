// Uses SHUFFLE, PARTITION, and QUICKSORT (renamed SORT) functions from Assignment 1's Sorts.h
// Removed calculating the comparison number from the PARTITION and SORT functions

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <random>
#include <climits>

using namespace std;

// Shuffles array based on Knuth shuffle
// Pass by reference (changes to myItems affects magicItems)
void shuffle(vector<string> &myItems)
{
    int size = myItems.size();
    int randomIndex = 0;
    string temp;

    for (int i = size - 1; i > 0; i--)
    {
        // Picks random index with random number generation
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, i);

        randomIndex = distrib(gen);

        // Swaps current value with random index value
        temp = myItems[i];
        myItems[i] = myItems[randomIndex];
        myItems[randomIndex] = temp;
    }
}

// Returns the partition index
int partition(vector<string> &myItems, int p, int begin, int end)
{
    // Indicates the currently found pivot position 
    int l = begin - 1;

    // Swap myItems[p] and myItems[end] (moves pivot value to the end)
    string temp = myItems[p];
    myItems[p] = myItems[end];
    myItems[end] = temp;

    for (int i = begin; i < end; i++)
    {
        // If current element is less than pivot element
        if (myItems[i] < myItems[end])
        {
            // Swap myItems[l] and myItems[i] to move smaller element to the left partition
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

// Pass by reference (changes to myItems affects magicItems)
void sort(vector<string> &myItems, int begin = 0, int end = INT_MIN)
{
    // If end parameter wasn't clarified, set it to the last index of the array (myItems[end] returns last element)
    // This means the function is dealing with the entire list
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

    // Runs quick sort on first and second parts of the array
    sort(myItems, begin, r - 1);
    sort(myItems, r + 1, end);
}

#endif