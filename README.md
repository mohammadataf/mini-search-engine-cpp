## 🚀 Features

### ✅ Module 1 – Document Reader

* Reads multiple text documents from the `documents/` directory.
* Uses `ifstream` for efficient file handling.

### ✅ Module 2 – Text Preprocessing

* Converts all words to lowercase.
* Removes punctuation and special characters.
* Removes common stop words.
* Tokenizes text into searchable keywords.

### ✅ Module 3 – Inverted Index

* Builds an inverted index using `unordered_map<string, set<string>>`.
* Maps every keyword to the documents that contain it.
* Enables fast keyword lookup.

### ✅ Module 4 – Interactive Search Engine

* Interactive command-line interface.
* Single keyword search.
* Handles invalid queries gracefully.
* Continuous searching until the user exits.

### ✅ Module 5 – Advanced Multi-Keyword Search

* Supports multi-word queries.
* OR Search (documents containing any keyword).
* AND Search (documents containing all keywords).
* Automatic duplicate removal using `std::set`.
* Uses `std::set_intersection()` for efficient AND search.
* Robust input validation for search mode selection.

---

## 🏗️ Project Structure

```
MiniSearchEngine/
│
├── documents/
│
├── include/
│   ├── reader.h
│   ├── preprocess.h
│   ├── indexer.h
│   └── search.h
│
├── src/
│   ├── reader.cpp
│   ├── preprocess.cpp
│   ├── indexer.cpp
│   ├── search.cpp
│   └── main.cpp
│
└── README.md
```

---

## 🛠️ Technologies Used

* C++17
* STL (`unordered_map`, `set`, `vector`)
* File Handling (`ifstream`)
* Modular Project Architecture
* Inverted Index
* Set Union
* Set Intersection
