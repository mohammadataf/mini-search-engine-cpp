#include "../include/indexer.h"
#include "../include/search.h"

#include <vector>

using namespace std;

int main()
{
    vector<string> files =
    {
        "documents/doc1.txt",
        "documents/doc2.txt",
        "documents/doc3.txt"
    };

    auto index = buildIndex(files);

    runSearchEngine(index);

    return 0;
}