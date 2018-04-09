#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

namespace anagram {

    class anagram {
        public: 
            anagram(string word);
            const vector<string> matches(const vector<string>& words) const;

        private:
            string m_word;
            unordered_map<char, int> m_letters;
    };
}
