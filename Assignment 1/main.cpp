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

    testStack.display();
}