#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "./Sort.h"
#include "./Search.h"

using namespace std;

int main()
{
    // Variable declaration
    vector<string> magicItems;

    const int ITEM_COUNT = 42;
    string randomItems[ITEM_COUNT];

    int comparisonNum = 0;
    float avg = 0.00f;

    // File IO (copied from Assignment 1)
    string line;
    ifstream file;

    // Open file
    file.open("magicitems.txt");
    if (!file.is_open())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    // Read each line from file and put it into the magicItems vector (ArrayList)
    for (int i = 0; getline(file, line); i++)
    {
        magicItems.push_back(line);
    }

    // Close file
    file.close();

    // Shuffles and adds first ITEM_COUNT (42) items to an array
    // These items are random since the array was shuffled
    shuffle(magicItems);
    for (int i = 0; i < ITEM_COUNT; i++)
    {
        randomItems[i] = magicItems[i];
    }

    // Sort array
    sort(magicItems);

    // Perform linear search to find each random item
    for (int i = 0; i < ITEM_COUNT; i++)
    {
        comparisonNum = linearSearch(magicItems, randomItems[i]);
        cout << "Comparisons to find \"" << randomItems[i] << "\": " << comparisonNum << endl;
        avg += comparisonNum;
    }

    // Find average comparisons for Linear Search
    avg = avg / ITEM_COUNT;
    cout << endl << "Average Number of Comparisons for Linear Search: " << setprecision(5) << avg << endl << endl;

    // Perform binary search to find each random item
    avg = 0;

    for (int i = 0; i < ITEM_COUNT; i++)
    {
        comparisonNum = binarySearch(magicItems, randomItems[i]);
        cout << "Comparisons to find \"" << randomItems[i] << "\": " << comparisonNum << endl;
        avg += comparisonNum;
    }

    // Find average comparisons for Binary Search
    avg = avg / ITEM_COUNT;
    cout << endl << "Average Number of Comparisons for Binary Search: " << setprecision(3) << avg << endl << endl;
}