#pragma once

#include <vector>

using namespace std;

namespace sum_of_multiples {

    int to(vector<int> numbers, int to) {
        auto sum = 0;
        for (auto i = 0; i < to; i++) {
            for (auto n : numbers) {
                if (i % n == 0) {
                    sum += i;
                    break;
                }
            }
        }
        return sum;
    }
}
