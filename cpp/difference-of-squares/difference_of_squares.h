#pragma once

#include <algorithm>
#include <cmath>

using namespace std;

namespace squares {

    int square_of_sums(int to) {
        auto sum = 0;
        for (auto i = 1; i <= to; i++) {
            sum += i;
        }
        return pow(sum, 2);
    }

    int sum_of_squares(int to) {
        auto sum = 0;
        for (auto i = 1; i <= to; i++) {
            sum += pow(i, 2);
        }
        return sum;
    }

    int difference(int to) {
        return square_of_sums(to) - sum_of_squares(to);
    }
}
