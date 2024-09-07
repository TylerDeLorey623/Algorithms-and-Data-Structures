#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
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

    // Print array
    cout << magicItems[51] << endl;
    cout << magicItems.size() << endl;
}