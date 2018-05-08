#pragma once

#include <string>

using namespace std;

namespace roman {
    const string units[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const string decimals[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string hundrends[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string thousands[4] = {"", "M", "MM", "MMM"};
    const string* numbers[4] = {units, decimals, hundrends, thousands};

    string convert(const int number)
    {
        string s;
        int n{number};
        auto c = 0;

        while (n > 0) {
            s.insert(0, numbers[c][n % 10]);
            n /= 10;
            c++;
        }
        return s;
    }
}