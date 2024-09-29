#include <iostream>
#include <fstream>
#include <vector>

#include "./isPalindrome.h"
#include "./Sorts.h"

using namespace std;

int main() 
{
    // Variable declaration
    vector<string> magicItems;
    string line;

    string word;

    int comparisonNum = 0;
    
    // File IO
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

    // Checking for palindromes in the magic items array
    cout << "PALINDROMES:" << endl;
    for (int i = 0, arraySize = magicItems.size(); i < arraySize; i++)
    {
        word = magicItems[i];
        
        if (isPalindrome(word))
        {
            cout << word << endl;
        }
    }
    cout << endl;

    // Performs Selection Sort O(n^2)
    comparisonNum = selectionSort(magicItems);
    cout << "Number of Comparisons doing Selection Sort: " << comparisonNum << endl;

    // Shuffles magic items
    shuffle(magicItems);

    // Performs Insertion Sort O(n^2)
    comparisonNum = insertionSort(magicItems);
    cout << "Number of Comparisons doing Insertion Sort: " << comparisonNum << endl;

    // Shuffles magic items
    shuffle(magicItems);

    // Performs Merge Sort O(n * log(n))
    comparisonNum = mergeSort(magicItems);
    cout << "Number of Comparisons doing Merge Sort: " << comparisonNum << endl;
}