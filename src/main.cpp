#include "../include/reader.h"
#include "../include/preprocess.h"
#include "../include/indexer.h"

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

    displayIndex(index);

    return 0;
}