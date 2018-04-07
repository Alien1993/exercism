#pragma once

#include <string>
#include <stdexcept>

using namespace std;

namespace hamming {

int compute(string s1, string s2)
{
    if (s1.size() != s2.size()) {
        throw domain_error{"Strands have different length"};
    }

    int distance = 0;
    for (auto i = 0; i < s1.size(); i++) {
        if (s1.at(i) != s2.at(i)) {
            distance++;
        }
    }

    return distance;
}

}
