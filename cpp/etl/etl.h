#pragma once

#include <map>
#include <vector>

using namespace std;

namespace etl {
    
    const map<char, int> transform(const map<int, vector<char>>& legacy)
    {
        map<char, int> scoring;

        for (const auto& pair : legacy) {
            for (const auto& letter : pair.second) {
                scoring.insert(make_pair(tolower(letter), pair.first));
            }
        }

        return scoring;
    }
}