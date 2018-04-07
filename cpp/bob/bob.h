#pragma once

#include <string>


using namespace std;

namespace bob {

    string hey(const string& sentence)
    {
        auto silent = false;
        for (auto c : sentence) {
            silent = isspace(c) && true;
            if (!silent) {
                break;
            }
        }

        if (silent || sentence.size() == 0) {
            return "Fine. Be that way!";
        }

        auto yelling = false;
        for (auto c : sentence) {
            if (isalpha(c) ) {
                yelling = isupper(c) && true;
                if (!yelling) {
                    break;
                }
            }
        }

        if (yelling) {
            return "Whoa, chill out!";
        }

        auto question = false;
        for (auto i = sentence.size() - 1; i >= 0; i--) {
            if (isspace(sentence.at(i))) {
                continue;
            }
            if (sentence.at(i) == '?') {
                question = true;
            }
            break;
        }

        if (question) {
            return "Sure.";
        }

        return "Whatever.";
    }
}
