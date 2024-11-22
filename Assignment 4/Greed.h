#ifndef GREED_H
#define GREED_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Determines if fKnapsack output should say "scoops" or "scoop" depending on the quantity
string scoopOrScoops(int num)
{
    string returnVal;

    if (num == 1)
    {
        returnVal = "scoop";
    }
    else
    {
        returnVal = "scoops";
    }
    return returnVal;
}

// Greedy algorithm that returns as many scoops of the most valuable Spice as it can hold
void fKnapsack(vector<Spice*> myItems, int capacity)
{
    // Variable declaration and initializations
    int curVal = 0;
    int quantity = 0;

    int curIndex = 0;
    int quatloos = 0;

    int spiceSize = myItems.size();
    bool breakOut = false;

    Spice* currentSpice = myItems[curIndex];
    vector<string> output;
    string punctuation;

    // Iterates while not at full capacity and if there are more spices to consider
    while ((curVal < capacity) && (!breakOut))
    {
        // Add unit price to current sum
        quatloos += currentSpice->getUnitPrice();

        quantity++;

        // If current quantity count is equal to the Spice's quantity
        if (quantity == currentSpice->getQuantity())
        {
            // Add output to the vector
            output.push_back(to_string(quantity) + " " + scoopOrScoops(quantity) + " of " + currentSpice->getName());

            // Reset quantity count
            quantity = 0;

            // Skip to next spice (if there is one)
            curIndex++;
            if (curIndex != spiceSize)
            {
                currentSpice = myItems[curIndex];
            }
            else
            {
                // If no more spices left in the vector, end loop
                breakOut = true;
            }
        }

        curVal++;
    }

    // Adds any more neccesary data to output
    if ((!breakOut) && (quantity != 0))
    {
        output.push_back(to_string(quantity) + " " + scoopOrScoops(quantity) + " of " + currentSpice->getName());
    }

    // Print results
    cout << "Knapsack of capacity " << capacity << " is worth " << quatloos << " quatloos and contains ";

    // If there was no output, it's empty (capacity is 0, edge case)
    if (output.empty())
    {
        cout << "NOTHING!";
    }

    // Printing all values from output vector
    for (int index = 0, size = output.size(); index < size; index++)
    {
        // Determines if comma or period should be used for its section
        if (index != size - 1)
        {
            punctuation = ", "; 
        }
        else
        {
            punctuation = ".";
        }

        // Print output with punctuation on the line
        cout << output[index] << punctuation;
    }

    cout << endl;
}

#endif