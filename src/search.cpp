#include "../include/search.h"
#include "../include/preprocess.h"

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

set<string> searchWordsOR(
    const unordered_map<string, set<string>>& index,
    const string& query)
{
    vector<string> keywords = tokenize(query);

    set<string> result;

    for(const string& word : keywords)
    {
        set<string> documents = searchWord(index, word);

        result.insert(documents.begin(), documents.end());
    }

    return result;
}
set<string> searchWordsAND(
    const unordered_map<string, set<string>>& index,
    const string& query)
{
    vector<string> keywords = tokenize(query);

    // Empty query
    if (keywords.empty())
    {
        return {};
    }

    // Start with documents of first keyword
    set<string> result = searchWord(index, keywords[0]);

    // Intersect with remaining keywords
    for (size_t i = 1; i < keywords.size(); i++)
    {
        set<string> documents = searchWord(index, keywords[i]);

        set<string> intersection;

        set_intersection(
            result.begin(), result.end(),
            documents.begin(), documents.end(),
            inserter(intersection, intersection.begin())
        );

        result = intersection;

        // Early exit if no common documents remain
        if (result.empty())
        {
            break;
        }
    }

    return result;
}
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
    int choice;

    cout << "=====================================\n";
    cout << "       MINI SEARCH ENGINE\n";
    cout << "=====================================\n";

    // Keep asking until the user enters a valid choice
    while (true)
    {
        cout << "\nChoose Search Mode\n";
        cout << "1. OR Search\n";
        cout << "2. AND Search\n";
        cout << "\nChoice: ";

        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            cin.ignore();
            break;
        }

        cout << "\nInvalid Choice! Please enter 1 or 2.\n";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    string query;

    while (true)
    {
        cout << "\nSearch > ";

        getline(cin, query);

        if (query == "exit")
        {
            cout << "\nThank you for using Mini Search Engine!\n";
            break;
        }

        set<string> result;

        if (choice == 1)
        {
            result = searchWordsOR(index, query);
        }
        else
        {
            result = searchWordsAND(index, query);
        }

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