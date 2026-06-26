## Development Progress

### ✅ Day 1 – Document Reader

- Read multiple text documents
- File handling using `ifstream`
- Error handling
- Load documents into memory

### ✅ Day 2 – Text Preprocessing

- Tokenization using `stringstream`
- Case normalization
- Punctuation removal
- Stop-word filtering

### ✅ Day 3 – Inverted Index

- Built inverted index using `unordered_map`
- Mapped each word to the documents containing it
- Eliminated duplicate document entries using `set`
- Displayed searchable index

---

## Current Search Pipeline

```
Documents
      │
      ▼
Read Documents
      │
      ▼
Preprocess Text
      │
      ▼
Build Inverted Index
```

### Upcoming Features

- Keyword Search
- Multi-keyword Search
- Document Ranking
- TF-IDF Scoring
- Phrase Search
- Persistent Index Storage