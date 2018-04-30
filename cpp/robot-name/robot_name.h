#pragma once

#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

namespace robot_name {


    const char randLetter()
    {
        string letters{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        return letters.at(rand() / (RAND_MAX / letters.size() + 1));
    }

    const char randDigit()
    {
        string digits{"0123456789"};
        return digits.at(rand() / (RAND_MAX / digits.size() + 1));
    }

    class robot {
        public:
            robot() 
            {
                reset();
            };

            void reset()
            {
                m_name.clear();
                string letters{"", 2};
                string digits{"", 3};

                generate_n(letters.begin(), 2, randLetter);
                generate_n(digits.begin(), 3, randDigit);

                m_name.append(letters).append(digits);
            }

            const string name() const { return m_name; }

        private:
            string m_name;
    };
}