#include "../include/search.h"
#include "../include/preprocess.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

using namespace std;
bool compareDocuments(
    const pair<string,int>& a,
    const pair<string,int>& b)
{
    // Higher score comes first
    if(a.second != b.second)
    {
        return a.second > b.second;
    }

    // If scores are equal,
    // sort alphabetically by filename
    return a.first < b.first;
}

//-----------------------------------------------------
// OR Search
//-----------------------------------------------------

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

//-----------------------------------------------------
// AND Search
//-----------------------------------------------------

set<string> searchWordsAND(
    const unordered_map<string, set<string>>& index,
    const string& query)
{
    vector<string> keywords = tokenize(query);

    if(keywords.empty())
    {
        return {};
    }

    set<string> result = searchWord(index, keywords[0]);

    for(size_t i = 1; i < keywords.size(); i++)
    {
        set<string> documents = searchWord(index, keywords[i]);

        set<string> intersection;

        set_intersection(
            result.begin(),
            result.end(),
            documents.begin(),
            documents.end(),
            inserter(intersection, intersection.begin())
        );

        result = intersection;

        if(result.empty())
        {
            break;
        }
    }

    return result;
}

//-----------------------------------------------------
// Ranked Search
//-----------------------------------------------------

vector<pair<string,int>> rankDocuments(
    const unordered_map<string,set<string>>& index,
    const string& query)
{
    vector<string> keywords = tokenize(query);

    // Remove duplicate query words
    set<string> uniqueWords(
        keywords.begin(),
        keywords.end()
    );

    unordered_map<string,int> scores;

    for(const string& word : uniqueWords)
    {
        set<string> documents = searchWord(index, word);

        for(const string& doc : documents)
        {
            scores[doc]++;
        }
    }

  vector<pair<string,int>> rankedResults;

for(const auto& entry : scores)
{
    rankedResults.push_back(entry);
}

// Sort results
sort(
    rankedResults.begin(),
    rankedResults.end(),
    compareDocuments
);

return rankedResults;
}

//-----------------------------------------------------
// Display Ranked Results
//-----------------------------------------------------

void displayRankedResults(
    const vector<pair<string,int>>& results,
    int totalKeywords)
{
    if(results.empty())
    {
        cout << "\nNo documents found.\n";
        return;
    }

    cout << "\n========== RESULTS ==========\n\n";

    int rank = 1;

    for(const auto& result : results)
    {
        cout << rank << ". "
             << result.first << "\n";

        cout << "   Matched Keywords : "
             << result.second
             << "/"
             << totalKeywords
             << "\n\n";

        rank++;
    }
}

//-----------------------------------------------------
// Single Keyword Search
//-----------------------------------------------------

set<string> searchWord(
    const unordered_map<string,set<string>>& index,
    string query)
{
    query = cleanWord(query);

    auto it = index.find(query);

    if(it == index.end())
    {
        return {};
    }

    return it->second;
}

set<string> searchPhrase(
    const unordered_map<string, set<string>>& index,
    const string& phrase)
{
    set<string> result;
    set<string> allDocuments;

    // Collect all unique document names
    for(const auto& entry : index)
    {
        allDocuments.insert(
            entry.second.begin(),
            entry.second.end()
        );
    }

    // Check every document
    for(const string& document : allDocuments)
    {
        string content = readFile(document);

        transform(
            content.begin(),
            content.end(),
            content.begin(),
            ::tolower
        );

        if(content.find(phrase) != string::npos)
        {
            result.insert(document);
        }
    }

    return result;
}

//-----------------------------------------------------
// Interactive Search Engine
//-----------------------------------------------------

void runSearchEngine(
    const unordered_map<string,set<string>>& index)
{
    string query;

    cout << "=====================================\n";
    cout << "      MINI SEARCH ENGINE\n";
    cout << "=====================================\n";

    while(true)
    {
        cout << "\nSearch > ";

        getline(cin, query);

        if(query == "exit")
        {
            cout << "\nThank you for using Mini Search Engine!\n";
            break;
        }

        vector<string> keywords = tokenize(query);

        set<string> uniqueWords(
            keywords.begin(),
            keywords.end()
        );

      if(query.size() >= 2 &&
   query.front() == '"' &&
   query.back() == '"')
{
    string phrase = query.substr(1, query.length() - 2);

   set<string> results = searchPhrase(index, phrase);

if(results.empty())
{
    cout << "\nNo documents found.\n";
}
else
{
    cout << "\n========== RESULTS ==========\n\n";

    int rank = 1;

    for(const string& document : results)
    {
        cout << rank << ". "
             << document
             << "\n\n";

        rank++;
    }
}
}
else
{
    vector<string> keywords = tokenize(query);

    set<string> uniqueWords(
        keywords.begin(),
        keywords.end()
    );

    vector<pair<string,int>> results =
        rankDocuments(index, query);

    displayRankedResults(
        results,
        uniqueWords.size()
    );
}
    }
}