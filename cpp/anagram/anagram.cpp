#include "anagram.h"


namespace anagram {

    anagram::anagram(string word)
        : m_word{word}
    {
        for (const auto& c : word) {
            m_letters[tolower(c)]++;
        }
    }

    const vector<string> anagram::matches(const vector<string>& words) const
    {

        vector<string> result;

        for (const auto& w : words) {
            if (w.size() != m_word.size()) {
                continue;
            }
            auto areEqual = true;
            auto letters = m_letters;
            for (auto i = 0; i < w.size(); i++) {
                const auto& c = tolower(w.at(i));

                areEqual &= c == tolower(m_word.at(i));

                letters[c]--;
                if (letters[c] < 0) {
                    break;
                } else if (letters[c] == 0) {
                    letters.erase(c);
                }
            }

            if (letters.size() == 0 && !areEqual) {
                result.push_back(w);
            }
        }

        return result;
    }

}