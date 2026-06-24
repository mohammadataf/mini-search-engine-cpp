#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string readFile(const string& filePath)
{
    ifstream file(filePath);

    if(!file.is_open())
    {
        cout << "Cannot open: "
             << filePath << endl;

        return "";
    }

    string content;
    string line;

    while(getline(file, line))
    {
        content += line;
        content += " ";
    }

    file.close();

    return content;
}

int main()
{
    vector<string> files =
    {
        "documents/doc1.txt",
        "documents/doc2.txt",
        "documents/doc3.txt"
    };

    cout << "Total Files: "
         << files.size()
         << "\n\n";

    for(const string& file : files)
    {
        string content =
            readFile(file);

        cout << "=====================\n";
        cout << "File: " << file << "\n";
        cout << "Characters: "
             << content.length()
             << "\n\n";

        cout << content << "\n";

        cout << "=====================\n\n";
    }

    return 0;
}