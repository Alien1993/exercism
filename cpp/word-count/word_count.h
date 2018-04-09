#pragma once

#include <map>
#include <string>
#include <sstream>

#include <iostream>

using namespace std;

namespace word_count {
    const map<string, int> words(const string& book)
    {
        map<string, int> words;

        stringstream word;
        for (auto i = 0; i < book.size(); i++) {
            const auto& c = book.at(i);
            
            if (i + 1 != book.size()) {
                // Handles apostrophes
                if ((c == '\'' && isalpha(book.at(i - 1)) 
                    && isalpha(book.at(i + 1)))) {
                    word << c;
                    continue;
                }
            }
            
            if ((ispunct(c) || isspace(c)) && word.str().size() > 0) {
                words[word.str()]++;
                word = stringstream{};
            } else if (isalnum(c)) {
                if (isdigit(c)) {
                    word << c;
                } else {
                    word << char(tolower(c));
                }
            }
        }

        // Handles last word
        if ((!ispunct(book.back()) || !isspace(book.back())) 
            && word.str().size() > 0) {
            words[word.str()]++;
        }

        return words;
    }
}
