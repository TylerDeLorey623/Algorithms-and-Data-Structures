#include <iostream>
#include <fstream>
#include <vector>

#include "./Node/Node.h"
#include "./Stack/Stack.h"
#include "./Queue/Queue.h"

using namespace std;

int main() 
{
    // Variable declaration
    vector<string> magicItems;
    string line;
    
    // File IO
    ifstream file;

    // Open file
    file.open("magicitems.txt");
    if (!file.is_open())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    // Read from file
    for (int i = 0; getline(file, line); i++)
    {
        magicItems.push_back(line);
    }

    // Close file
    file.close();

    // Print vector (ArrayList)
    cout << magicItems[0] << endl;

    // Stack testing
    Stack testStack;
    testStack.push("Hopefully");
    testStack.push("this");
    testStack.push("ends");
    testStack.push("up");
    testStack.push("working");

    // Pop testing
    for (int i = 0; i < 10; i++)
    {
        string result = testStack.pop();

        if (result.empty())
        {
            cout << "Couldn't pop" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    // isEmpty testing
    cout << testStack.isEmpty() << endl;

    testStack.push("Hello");
    testStack.push("world");

    cout << testStack.isEmpty() << endl;

    testStack.display();

    // Queue testing
    Queue testQueue;

    cout << testQueue.isEmpty() << endl;

    testQueue.enqueue("Hopefully");
    testQueue.enqueue("this");
    testQueue.enqueue("ends");
    testQueue.enqueue("up");
    testQueue.enqueue("working");
    string result = testQueue.dequeue();

    // Head and tail pointer testing
    cout << "Head: " + testQueue.head->data << endl;
    cout << "Tail: " + testQueue.tail->data << endl;

    cout << testQueue.isEmpty() << endl;

    testQueue.display();

}