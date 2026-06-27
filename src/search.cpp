#include "../include/search.h"
#include "../include/preprocess.h"

#include <iostream>

using namespace std;

// Search for a single keyword
set<string> searchWord(
    const unordered_map<string, set<string>>& index,
    string query)
{
    // Clean the user query
    query = cleanWord(query);

    // Search in the inverted index
    auto it = index.find(query);

    // Keyword not found
    if (it == index.end())
    {
        return {};
    }

    // Return matching documents
    return it->second;
}

// Interactive search engine
void runSearchEngine(
    const unordered_map<string, set<string>>& index)
{
    string query;

    cout << "->->->->->->->->->->->->->->->->->->->\n";
    cout << "      MINI SEARCH ENGINE\n";
    cout << "<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<\n";

    while (true)
    {
        cout << "\nSearch > ";

       getline(cin, query);

        if (query == "exit")
        {
            cout << "\nThank you for using Mini Search Engine!\n";
            break;
        }

        set<string> result = searchWord(index, query);

        if (result.empty())
        {
            cout << "\nNo documents found.\n";
        }
        else
        {
            cout << "\nFound in:\n\n";

            for (const string& doc : result)
            {
                cout << doc << endl;
            }
        }
    }
}