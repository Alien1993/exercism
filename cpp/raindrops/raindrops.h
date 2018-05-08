#pragma once

#include <string>

using namespace std;

namespace raindrops {
    string convert(const int n)
    {
        string s;
        if (n % 3 == 0) {
            s.append("Pling");
        }
        if (n % 5 == 0) {
            s.append("Plang");
        }
        if (n % 7 == 0) {
            s.append("Plong");
        }
        if (s.empty()) {
            s.append(to_string(n));
        }
        return s;
    }
}