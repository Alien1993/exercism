#include <string>
#include <cmath>
#include <iostream>

using namespace std;

namespace binary {
    int convert(string bin)
    {
        int num = 0;

        for (int i = bin.length() - 1; i >= 0; i--) {
            if (!isdigit(bin.at(i))) {
                return 0;
            }
            num += int(bin.at(i) - '0') * pow(2, bin.length() - 1 - i);
        }

        return num;
    }
}