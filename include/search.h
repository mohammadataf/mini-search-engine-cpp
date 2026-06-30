#pragma once

#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <utility>

std::set<std::string> searchWord(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index,
    std::string query
);

std::set<std::string> searchWordsOR(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index,
    const std::string& query
);

std::set<std::string> searchWordsAND(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index,
    const std::string& query
);

std::vector<std::pair<std::string,int>> rankDocuments(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index,
    const std::string& query
);

void displayRankedResults(
    const std::vector<std::pair<std::string,int>>& results,
    int totalKeywords
);

void runSearchEngine(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index
);