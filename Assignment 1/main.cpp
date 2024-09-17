#include <iostream>
#include <fstream>
#include <vector>

#include "./isPalindrome.h"

using namespace std;

int main() 
{
    // Variable declaration
    vector<string> magicItems;
    string line;

    string word;
    char letter;
    
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
    for (int i = 0, arraySize = magicItems.size(); i < arraySize; i++)
    {
        word = magicItems[i];
        
        if (isPalindrome(word))
        {
            cout << word << endl;
        }
    }
}