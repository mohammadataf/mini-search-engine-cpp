#include "../include/indexer.h"
#include "../include/reader.h"
#include "../include/preprocess.h"

#include <iostream>

using namespace std;

unordered_map<string, set<string>>
buildIndex(const vector<string>& files)
{
    unordered_map<string, set<string>> index;

    for(const string& file : files)
    {
        string content = readFile(file);

        vector<string> words = tokenize(content);

        for(const string& word : words)
        {
            index[word].insert(file);
        }
    }

    return index;
}

void displayIndex(
    const unordered_map<
        string,
        set<string>>& index)
{
    cout << "\n========== INVERTED INDEX ==========\n\n";

    for(const auto& entry : index)
    {
        cout << entry.first << " --> ";

        for(const string& document : entry.second)
        {
            cout << document << " ";
        }

        cout << endl;
    }
}