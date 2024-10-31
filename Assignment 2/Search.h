#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Linear search to find the 42 items in the entire array
// Returns comparison count
int linearSearch(vector<string> myItems, string target)
{
    int comparisonNum = 0;
    
    int size = myItems.size();

    // Finding target in the myItems array
    for (int i = 0; i < size; i++)
    {
        comparisonNum++;

        if (myItems[i] == target)
        {
            break;
        }
    }

    return comparisonNum;
}

// Binary search to find the 42 items in the entire array
// Returns comparison count
int binarySearch(vector<string> myItems, string target, int comparisonNum = 0, int begin = 0, int end = INT_MIN)
{
    // If end parameter wasn't clarified, set it to the last index of the array (myItems[end] returns last element)
    // This means the function is dealing with the entire list for the binary search
    if (end == INT_MIN)
    {
        end = myItems.size() - 1;
    }
    int returnValue = 0;
    int midPoint = int((begin + end)/2);

    comparisonNum++;

    // If the array has no more items to search OR it was found, the function finished
    if ((begin > end) || (myItems[midPoint] == target))
    {
        returnValue = comparisonNum;
    }
    // If target is smaller than the midpoint (in ASCII terms)
    else if (target < myItems[midPoint])
    {
        returnValue = binarySearch(myItems, target, comparisonNum, begin, midPoint - 1);
    }
    // If target is larger than the midpoint (in ASCII terms)
    else
    {
        returnValue = binarySearch(myItems, target, comparisonNum, midPoint + 1, end);
    }

    return returnValue;
}

#endif