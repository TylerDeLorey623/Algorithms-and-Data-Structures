#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>

#include "./Node.h"

using namespace std;

const int HASH_TABLE_SIZE = 250;
Node *hashTable[HASH_TABLE_SIZE];

// Finds index for current item
int hashIndex(string item)
{
    // Unsigned cannot represent negative numbers, fixes overflow
    unsigned long total = 0;

    // Calculates index based on adding ASCII values of characters in the string
    // Multiplies by 13 each time to reduce collision chance
    for (int i = 0, wordSize = item.size(); i < wordSize; i++)
    {
        total = total * 13 + item[i];
    }
    
    return total % HASH_TABLE_SIZE;
}

// Loads hash table with the magic items
void hashPut(vector<string> myItems)
{
    int size = myItems.size();
    int value = 0;
    string curItem;

    for (int i = 0; i < size; i++)
    {
        curItem = myItems[i];
        value = hashIndex(curItem);
        
        Node* newItem = new Node(curItem);
        newItem->next = hashTable[value];
        hashTable[value] = newItem;
    }
}

// Find target item in the hash table
// Returns number of comparisons
int hashGet(string target)
{
    int comparisonNum = 0;
    int value = hashIndex(target);

    comparisonNum++;

    // Iterates through the linked list at that index
    for (Node *ptr = hashTable[value]; ptr != NULL; ptr = ptr->next)
    {
        comparisonNum++;
        if (ptr->data == target)
        {
            break;
        }
    }

    return comparisonNum;
}

// Unloads each index of hash table (including all linked Nodes at that index)
void hashUnloadIndex(Node *hash)
{
    if (hash == NULL)
    {
        return;
    }
    hashUnloadIndex(hash->next);
    delete(hash);
}

// Unloads hash table to avoid memory leaks
void hashUnload()
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        if (hashTable[i] != NULL)
        {
            hashUnloadIndex(hashTable[i]);
        }
    }
}

#endif