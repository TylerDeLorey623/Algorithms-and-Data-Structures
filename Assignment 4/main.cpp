#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "Spice.h"
#include "Sort.h"
#include "Greed.h"

using namespace std;

int main()
{
    // Spices Vector
    vector<Spice*> mySpices;
    bool sortSpices = false;

    // Used for File Input
    ifstream file;
    string line;

    // Open spice file
    file.open("spice.txt");
    if (!file.is_open())
    {
        cerr << "File failed to open." << endl;
        return 1;
    }

    // Read each line from spice file
    while (getline(file, line))
    {
        istringstream stream(line);
        string word;
        vector<string> words;

        // For Spice Object
        Spice* newSpice;
        int nameIndex = 3, priceIndex = 6, qtyIndex = 9, capacityIndex = 3;
        string name;
        float price;
        int qty;

        // Split each word of each line in the file
        while (stream >> word)
        {
            // Skip to next line if it is a comment or a blank line
            if ((word == "--") || (word.empty()))
            {
                break;
            }
    
            // Removes semicolons
            if (word.back() == ';')
            {
                word.pop_back();
            }

            // Adds each word to the words vector
            words.push_back(word);
        }

        if (!words.empty())
        {
            // If it was a spice command, create a new Spice object
            if (words[0] == "spice")
            {
                // Gets name, price, and quantity values
                name = words[nameIndex];
                price = stof(words[priceIndex]);
                qty = stoi(words[qtyIndex]);

                // Creates new Spice object (including its unit price)
                newSpice = new Spice(name, price, qty);
                mySpices.push_back(newSpice);
            }
            else if (words[0] == "knapsack")
            {
                // Sort spices vector by unit price
                if (!sortSpices)
                {
                    sort(mySpices);
                    sortSpices = true;
                }

                // Performs greedy algorithm and prints results
                fKnapsack(mySpices, stoi(words[capacityIndex]));
            }
        }
    }

    // Unloads Spices
    for (int i = 0, n = mySpices.size(); i < n; i++)
    {
        delete(mySpices[i]);
    }

    file.close();
}