#include <iostream>
#include <fstream>
#include <vector>

#include "./Sort.h"

using namespace std;

int main()
{
    // Variable declaration
    vector<string> magicItems;

    const int ITEM_COUNT = 42;
    string randomItems[ITEM_COUNT];

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
}