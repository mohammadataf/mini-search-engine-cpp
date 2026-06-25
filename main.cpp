#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <cctype>

using namespace std;

unordered_set<string> stopWords =
{
    "the",
    "is",
    "a",
    "an",
    "and",
    "of",
    "to",
    "in"
};

string readFile(const string& filePath)
{
    ifstream file(filePath);

    if(!file.is_open())
    {
        cout << "Cannot open "
             << filePath << endl;

        return "";
    }

    string content;
    string line;

    while(getline(file,line))
    {
        content += line;
        content += " ";
    }

    file.close();

    return content;
}

string cleanWord(string word)
{
    string result;

    for(char ch : word)
    {
        if(isalnum(ch))
        {
            result += tolower(ch);
        }
    }

    return result;
}

vector<string> tokenize(string content)
{
    vector<string> words;

    stringstream ss(content);

    string word;

    while(ss >> word)
    {
        word = cleanWord(word);

        if(word.empty())
            continue;

        if(stopWords.count(word))
            continue;

        words.push_back(word);
    }

    return words;
}

int main()
{
    vector<string> files =
    {
        "documents/doc1.txt",
        "documents/doc2.txt",
        "documents/doc3.txt"
    };

    for(const string& file : files)
    {
        cout << "=========================\n";
        cout << "Document : " << file << "\n\n";

        string content = readFile(file);

        vector<string> tokens =
            tokenize(content);

        cout << "Tokens:\n\n";

        for(const string& token : tokens)
        {
            cout << token << endl;
        }

        cout << "\n";
    }

    return 0;
}