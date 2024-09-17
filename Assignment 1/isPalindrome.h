#ifndef ISPALINDROME_H
#define ISPALINDROME_H

#include <iostream>
#include "./Stack.h"
#include "./Queue.h"

using namespace std;

bool isPalindrome(string word)
{
    // Create Stack and Queue for the word
    Stack myStack;
    Queue myQueue;

    char sLetter;
    char qLetter;

    char letter;
    int wordSize = word.size();

    bool palindrome = true;

    // Add each letter of word to a Stack and Queue (ignoring spaces and capitalization)
    for (int index = 0; index < wordSize; index++)
    {
        letter = toupper(word[index]);

        if (letter != ' ')
        {
            myStack.push(letter);
            myQueue.enqueue(letter);
        }
    }

    // Pop from Stack, dequeue from Queue, compare letters to check if its palindromic
    for (int index = 0; index < wordSize; index++)
    {
        sLetter = myStack.pop();
        qLetter = myQueue.dequeue();

        if (sLetter != qLetter)
        {
            palindrome = false;
            break;
        }
    }

    return palindrome;
}

#endif