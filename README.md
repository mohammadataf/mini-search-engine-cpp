# Mini Search Engine (C++)

A simple search engine built completely in C++ using an **Inverted Index** for fast document retrieval.

The project demonstrates important Information Retrieval concepts such as indexing, preprocessing, keyword searching, Boolean search, and ranked document retrieval.

---

## Features

- Read multiple text documents
- Text preprocessing
    - Lowercase conversion
    - Remove punctuation
- Build an Inverted Index
- Fast keyword lookup
- Single keyword search
- OR Search
- AND Search
- Ranked search
- Duplicate query handling
- Modular project structure
- Interactive command line interface

---

## Project Structure

```
mini-search-engine-cpp/
│
├── documents/
│   ├── doc1.txt
│   ├── doc2.txt
│   └── doc3.txt
│
├── include/
│   ├── reader.h
│   ├── preprocess.h
│   ├── indexer.h
│   └── search.h
│
├── src/
│   ├── main.cpp
│   ├── reader.cpp
│   ├── preprocess.cpp
│   ├── indexer.cpp
│   └── search.cpp
│
└── README.md
```

---

## How It Works

### Step 1

Read all text documents.

↓

### Step 2

Preprocess every word

- Convert to lowercase
- Remove punctuation

↓

### Step 3

Build an Inverted Index

Example

```
programming

↓

doc1.txt

doc2.txt
```

↓

### Step 4

User enters a query

```
Search > programming c
```

↓

### Step 5

Search Engine retrieves matching documents

↓

### Step 6

Documents are ranked according to the number of matched keywords.

---

## Example

Input

```
Search > programming c
```

Output

```
========== RESULTS ==========

1. documents/doc1.txt
Matched Keywords : 2/2

2. documents/doc2.txt
Matched Keywords : 1/2
```

---

## Concepts Used

- C++
- STL
- Vector
- Set
- Unordered Map
- Pair
- File Handling
- Modular Programming
- Inverted Index
- Boolean Search
- Ranked Retrieval

---

## Current Progress

- ✅ Document Reader
- ✅ Text Preprocessing
- ✅ Inverted Index
- ✅ Single Keyword Search
- ✅ OR Search
- ✅ AND Search
- ✅ Ranked Search

---

## Future Improvements

- Phrase Search

- Boolean Query Parser

- TF-IDF Ranking

- Wildcard Search

- Auto Complete

- Search Suggestions

- Search Statistics

- GUI Version

---

## Learning Outcomes

This project helped me understand

- File Handling
- Data Structures
- Modular Software Design
- Information Retrieval
- Search Engine Fundamentals
- C++ STL
- Git & GitHub Workflow

---

## Author

Mohammad Ataf

B.Tech CSE

National Institute of Technology Srinagar