# Mini Search Engine (C++)

A simple search engine built in C++ that indexes multiple text documents and supports fast keyword-based search using an inverted index.

The project started as a way to understand how search engines work internally and gradually evolved into a modular application with separate components for reading documents, preprocessing text, indexing, and searching.

## Features

* Reads multiple text documents from disk.
* Cleans and tokenizes text.
* Removes common stop words.
* Builds an inverted index for fast lookups.
* Supports single-keyword search.
* Supports multi-keyword **OR** search.
* Supports multi-keyword **AND** search.
* Interactive command-line interface.
* Modular project structure using separate header and source files.

## Project Structure

```
MiniSearchEngine/
│
├── documents/
├── include/
├── src/
└── README.md
```

## Technologies

* C++17
* Standard Template Library (STL)
* File Handling
* Hash Maps (`unordered_map`)
* Sets
* Modular Programming

## Future Improvements

* Document ranking based on relevance
* Phrase search
* TF-IDF scoring
* GUI version
* Web interface
