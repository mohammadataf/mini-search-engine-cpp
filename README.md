# Mini Search Engine (C++)

A modular command-line search engine built completely in **C++** using the **Inverted Index** data structure for fast document retrieval.

The project demonstrates the core concepts behind modern search engines, including document preprocessing, indexing, keyword search, Boolean search, phrase search, and document ranking.

This project was built as a learning project to understand how search engines work internally while improving C++ programming, STL usage, and software design.

---

## Features

- Read multiple text documents
- Text preprocessing
  - Convert text to lowercase
  - Remove punctuation
- Build an Inverted Index
- Fast single keyword search
- OR Search
- AND Search
- Ranked document retrieval
- Exact Phrase Search using quotation marks
- Duplicate query handling
- Interactive command-line interface
- Modular project architecture

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
├── README.md
└── .gitignore
```

---

# How the Search Engine Works

```
                Documents
                     │
                     ▼
             Read File Contents
                     │
                     ▼
             Text Preprocessing
      (Lowercase + Remove Punctuation)
                     │
                     ▼
            Build Inverted Index
                     │
                     ▼
              User Search Query
                     │
          ┌──────────┴──────────┐
          ▼                     ▼
    Phrase Search         Ranked Search
          │                     │
          └──────────┬──────────┘
                     ▼
              Display Results
```

---

# Inverted Index

Instead of storing

```
Document
    ↓
Words
```

the search engine stores

```
Word
    ↓
Documents
```

Example

```
programming

↓

doc1.txt

doc2.txt
```

This allows searching documents in constant average lookup time using an `unordered_map`.

---

# Implemented Modules

## Module 1 — Document Reader

- Read text files using `ifstream`
- Return complete document content as a string

---

## Module 2 — Text Preprocessing

- Convert text to lowercase
- Remove punctuation
- Split text into words (tokenization)

---

## Module 3 — Inverted Index

Build an inverted index using

```cpp
unordered_map<string, set<string>>
```

where

```
Word
↓

Set of Documents
```

The `set` automatically removes duplicate document entries.

---

## Module 4 — Single Keyword Search

Example

```
Search > programming
```

Output

```
documents/doc1.txt

documents/doc2.txt
```

---

## Module 5 — Boolean Search

### OR Search

```
programming OR java
```

Returns documents containing **either** keyword.

---

### AND Search

```
programming AND c
```

Returns only documents containing **both** keywords.

---

## Module 6 — Ranked Search

Instead of simply returning matching documents, documents are ranked according to the number of matched query keywords.

Example

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

Duplicate query words are ignored while calculating the total number of keywords.

---

## Module 7 — Phrase Search

Supports exact phrase matching using quotation marks.

Example

Input

```
Search > "competitive programming"
```

Output

```
========== RESULTS ==========

1. documents/doc2.txt
```

The search engine searches for the complete phrase instead of individual words.

---

# Data Structures Used

| Data Structure | Purpose |
|---------------|---------|
| vector | Store tokenized words and ranked results |
| set | Remove duplicate documents and keep them sorted |
| unordered_map | Build the inverted index and ranking scores |
| pair | Store document-score pairs |

---

# C++ Concepts Used

- File Handling (`ifstream`)
- Header Files
- Source Files
- Modular Programming
- Functions
- References (`const &`)
- STL Containers
- `vector`
- `set`
- `unordered_map`
- `pair`
- `sort()`
- `set_intersection()`
- `transform()`
- `string::find()`
- `substr()`

---

# Sample Execution

```
=====================================
      MINI SEARCH ENGINE
=====================================

Search > programming c

========== RESULTS ==========

1. documents/doc1.txt
Matched Keywords : 2/2

2. documents/doc2.txt
Matched Keywords : 1/2

Search > "competitive programming"

========== RESULTS ==========

1. documents/doc2.txt

Search > exit

Thank you for using Mini Search Engine!
```

---

# Current Progress

- ✅ Document Reader
- ✅ Text Preprocessing
- ✅ Inverted Index
- ✅ Single Keyword Search
- ✅ OR Search
- ✅ AND Search
- ✅ Ranked Search
- ✅ Phrase Search

---

# Future Improvements

- TF-IDF Ranking
- Boolean Query Parser
- Wildcard Search
- Auto Complete
- Search Suggestions
- Search Statistics
- Positional Inverted Index
- GUI Version

---

# Learning Outcomes

This project helped me understand

- Search Engine Fundamentals
- Information Retrieval
- Inverted Index
- C++ STL
- Modular Programming
- File Handling
- Data Structures
- Git & GitHub Workflow
- Software Design

---

# Build & Run

Compile

```bash
g++ src/main.cpp src/reader.cpp src/preprocess.cpp src/indexer.cpp src/search.cpp -o search.exe
```

Run

```bash
./search.exe
```

On Windows PowerShell

```powershell
.\search.exe
```

---

# Git Workflow

Check Status

```bash
git status
```

Stage Changes

```bash
git add .
```

Commit

```bash
git commit -m "Add phrase search and improve search capabilities"
```

Push

```bash
git push origin main
```

---

## Author

**Mohammad Ataf**

B.Tech Computer Science & Engineering

National Institute of Technology Srinagar
