#include "../include/reader.h"

#include <fstream>
#include <iostream>

using namespace std;

string readFile(const string& filePath)
{
    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Cannot open " << filePath << endl;
        return "";
    }

    string content;
    string line;

    while (getline(file, line))
    {
        content += line;
        content += " ";
    }

    file.close();

    return content;
}