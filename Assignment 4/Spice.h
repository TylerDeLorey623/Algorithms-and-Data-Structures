#ifndef SPICE_H
#define SPICE_H

#include <iostream>

using namespace std;

// Public Spice class for Fractional Knapsack
class Spice 
{
    public:
        // Members of Spice Class
        string name;
        float price;
        int qty;
        float unitPrice;

        // Declares parameterized constructor
        Spice(string newName, float newPrice, int newQty)
        {
            this->name = newName;
            this->price = newPrice;
            this->qty = newQty;
            this->unitPrice = newPrice / newQty;
        }

        // Getters for Spice
        float getUnitPrice()
        {
            return this->unitPrice;
        }

        int getQuantity()
        {
            return this->qty;
        }

        string getName()
        {
            return this->name;
        }

        // This one is not needed, but here just in case for future work
        float getPrice()
        {
            return this->price;
        }
};

#endif