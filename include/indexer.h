#pragma once

#include <string>
#include <vector>
#include <set>
#include <unordered_map>

std::unordered_map<std::string, std::set<std::string>>
buildIndex(const std::vector<std::string>& files);

void displayIndex(
    const std::unordered_map<
        std::string,
        std::set<std::string>>& index);