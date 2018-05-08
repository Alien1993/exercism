#pragma once

#include <cmath>
#include <iostream>

namespace grains {
    // Space efficient solution
    constexpr long long square(int s)
    {
        return s == 1 ? 1 : pow(2, s) / 2;
    }

    constexpr long long total()
    {
        return square(64) * 2 - 1;
    }
}