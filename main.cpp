#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <cctype>

using namespace std;

// ---------------- STOP WORDS ----------------

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

// ---------------- READ FILE ----------------

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

// ---------------- CLEAN WORD ----------------

string cleanWord(string word)
{
    string result;

    for (char ch : word)
    {
        if (isalnum(ch))
        {
            result += tolower(ch);
        }
    }

    return result;
}

// ---------------- TOKENIZER ----------------

vector<string> tokenize(string content)
{
    vector<string> words;

    stringstream ss(content);

    string word;

    while (ss >> word)
    {
        word = cleanWord(word);

        if (word.empty())
            continue;

        if (stopWords.count(word))
            continue;

        words.push_back(word);
    }

    return words;
}

// ---------------- BUILD INVERTED INDEX ----------------

unordered_map<string, set<string>> buildIndex(const vector<string>& files)
{
    unordered_map<string, set<string>> index;

    for (const string& file : files)
    {
        string content = readFile(file);

        vector<string> words = tokenize(content);

        for (const string& word : words)
        {
            index[word].insert(file);
        }
    }

    return index;
}

// ---------------- DISPLAY INDEX ----------------

void displayIndex(const unordered_map<string, set<string>>& index)
{
    cout << "\n========== INVERTED INDEX ==========\n\n";

    for (const auto& entry : index)
    {
        cout << entry.first << " --> ";

        for (const string& document : entry.second)
        {
            cout << document << " ";
        }

        cout << endl;
    }
}

// ---------------- MAIN ----------------

int main()
{
    vector<string> files =
    {
        "documents/doc1.txt",
        "documents/doc2.txt",
        "documents/doc3.txt"
    };

    unordered_map<string, set<string>> index =
        buildIndex(files);

    displayIndex(index);

    return 0;
}