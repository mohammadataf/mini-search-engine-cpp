#pragma once

#include <string>
#include <set>
#include <unordered_map>

std::set<std::string> searchWord(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index,
    std::string query
);

void runSearchEngine(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index
);