#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>
#include <random>

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

// Returns number of comparisons 
// Pass by reference (changes to myItems affects magicItems)
int selectionSort(vector<string> &myItems)
{
    int comparisonNum = 0;
    int size = myItems.size();
    string temp;
 
    // Array from 0 to i is sorted
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        // Find minimum element in array
        for (int j = i + 1; j < size; j++)
        {
            // Checks if current word is less than the current smallest word
            if (myItems[j] < myItems[minIndex])
            {
                minIndex = j;
            }
            comparisonNum++;

            // Swap minimum element with element at i
            if (minIndex != i)
            {
                temp = myItems[minIndex];
                myItems[minIndex] = myItems[i];
                myItems[i] = temp;
            }
        }
    }

    return comparisonNum;
}

// Returns number of comparisons 
// Pass by reference (changes to myItems affects magicItems)
int insertionSort(vector<string> &myItems)
{
    int comparisonNum = 0;
    int size = myItems.size();

    // Traverses array from second element to last element (first element is sorted in an array of size 1)
    for (int i = 1; i < size; i++)
    {
        string key = myItems[i];

        int end = i - 1;

        // Find place for the current key value
        while (end >= 0 && myItems[end] > key)
        {
            comparisonNum++;

            // Shift element to the right
            myItems[end + 1] = myItems[end];
            end--;
        }

        // Insert the key into correct position
        myItems[end + 1] = key;
    }

    return comparisonNum;
}



#endif