#include "../include/preprocess.h"

#include <sstream>
#include <unordered_set>
#include <cctype>
#include <set>

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
