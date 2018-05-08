#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

namespace triangle {
    enum type {
        equilateral,
        isosceles,
        scalene
    };

    type kind(float l1, float l2, float l3)
    {
        vector<float> e{{l1, l2, l3}};
        sort(e.begin(), e.end());
        
        if (e.at(0) + e.at(1) + e.at(2) == 0 ||
            e.at(0) + e.at(1) < e.at(2) ||
            signbit(e.at(0)) || signbit(e.at(1)) || signbit(e.at(2))) {
            throw domain_error{"Bad triangle"};
        }
        
        if (e.at(0) == e.at(1) && e.at(1) == e.at(2)) {
            return type::equilateral;
        }

        if (e.at(0) == e.at(1) || e.at(1) == e.at(2)) {
            return type::isosceles;
        }
        return type::scalene;
    }
}