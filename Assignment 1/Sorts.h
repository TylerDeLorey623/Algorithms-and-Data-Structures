#ifndef SORTS_H
#define SORTS_H

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
        }

        // Swap minimum element with element at i
        if (minIndex != i)
        {
            temp = myItems[minIndex];
            myItems[minIndex] = myItems[i];
            myItems[i] = temp;
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

        comparisonNum++;

        // Find place for the current key value
        while (end >= 0 && myItems[end] > key)
        {
            // Shift element to the right if not correct position
            myItems[end + 1] = myItems[end];
            end--;

            comparisonNum++;
        }

        // Insert the key into correct position
        myItems[end + 1] = key;
    }

    return comparisonNum;
}

// Merges left and right arrays into a larger sorted array
int merge(vector <string> &myItems, int begin, int mid, int end)
{
    int comparisonNum = 0;

    // Tracks both sides of the array (index and size)
    int lIndex = begin, rIndex = mid + 1;
    int lSize = mid - begin + 1;
    int rSize = end - mid;

    // Size of merged array
    int n = lSize + rSize;

    vector<string> tempItems(n);

    // Merges items into temp array
    for (int k = 0; k < n; k++)
    {
        comparisonNum++;

        // If right side has been completely traversed, copy remaining left half items into tempItems 
        if (rIndex > end)
        {
            tempItems[k] = myItems[lIndex];
            lIndex++;
        }
        // If left side has been completely traversed, copy remaining right half items into tempItems 
        else if (lIndex > mid)
        {
            tempItems[k] = myItems[rIndex];
            rIndex++;
        }
        // If current element in left half is less than current element in right half, copy left element into tempItems
        else if (myItems[lIndex] < myItems[rIndex])
        {
            tempItems[k] = myItems[lIndex];
            lIndex++;
        }
        // If current element in right half is less than or equal to current element in left half, copy right element into tempItems
        else
        {
            tempItems[k] = myItems[rIndex];
            rIndex++;
        }
    }

    // Copies sorted tempItems to myItems
    for (int k = 0; k < n; k++)
    {
        myItems[begin + k] = tempItems[k];
    }

    return comparisonNum;
}

// Returns number of comparisons
// Pass by reference (changes to myItems affects magicItems)
int mergeSort(vector<string> &myItems, int begin = 0, int end = INT_MIN)
{
    int comparisonNum = 0;

    // If end parameter wasn't clarified, set it to the last index of the array (myItems[end] returns last element)
    // This means the function is dealing with the entire list
    if (end == INT_MIN)
    {
        end = myItems.size() - 1;
    }
    // Base case
    else if (begin >= end)
    {
        return comparisonNum;
    }

    // Gets the mid point for splitting the array
    int mid = (begin + end) / 2;

    // Divides array into left and right sides
    comparisonNum += mergeSort(myItems, begin, mid);
    comparisonNum += mergeSort(myItems, mid + 1, end);

    // Conquers each section
    comparisonNum += merge(myItems, begin, mid, end);

    return comparisonNum;
}

// Returns both the partition point and the comparison count in a pair
pair<int, int> partition(vector<string> &myItems, int p, int begin, int end)
{
    int comparisonNum = 0;

    // Indicates the currently found pivot position 
    int l = begin - 1;

    // Swap myItems[p] and myItems[end] (moves pivot value to the end)
    string temp = myItems[p];
    myItems[p] = myItems[end];
    myItems[end] = temp;

    for (int i = begin; i < end; i++)
    {
        comparisonNum++;

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

    return make_pair(l + 1, comparisonNum);
}

// Returns number of comparisons
// Pass by reference (changes to myItems affects magicItems)
int quickSort(vector<string> &myItems, int begin = 0, int end = INT_MIN)
{
    int comparisonNum = 0;

    // If end parameter wasn't clarified, set it to the last index of the array (myItems[end] returns last element)
    // This means the function is dealing with the entire list
    if (end == INT_MIN)
    {
        end = myItems.size() - 1;
    }
    // Base case
    else if (begin >= end)
    {
        return comparisonNum;
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

    // Choosing the pivot element to be myItems[randomPivot]
    auto parResult = partition(myItems, pivotValue, begin, end);

    // Gets pivot index and comparison num
    int r = parResult.first;
    comparisonNum += parResult.second;

    // Runs quick sort on first and second parts of the array
    comparisonNum += quickSort(myItems, begin, r - 1);
    comparisonNum += quickSort(myItems, r + 1, end);

    return comparisonNum;
}

#endif