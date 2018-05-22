#pragma once

#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

namespace crypto_square {
    class cipher {
        public:
            cipher(string word) 
                : m_word(word) 
            { }

            const string normalize_plain_text() const
            {
                stringstream s;
                for (const auto& c : m_word) {
                    if (isalnum(c)) {
                        s.put(tolower(c));
                    }
                }
                return s.str();
            }

            const vector<string> plain_text_segments() const
            {
                vector<string> segments;

                auto normalized = normalize_plain_text();
                int columnSize = sqrt(normalized.size());
                int rowSize = round(float(normalized.size()) / float(columnSize));
                auto segmentsIndex = 0;

                for (auto i = 0; i < normalized.size(); i++) {
                    if (i % rowSize == 0) {
                        segments.push_back("");
                    }
                    segments[segmentsIndex].push_back(normalized.at(i));

                    if (segments[segmentsIndex].size() == rowSize) {
                        segmentsIndex++;
                    }
                }

                return segments;
            }

            const string cipher_text() const
            {
                auto segments = plain_text_segments();
                if (segments.empty()) {
                    return "";
                }

                string cipher;
                auto r = 0;
                auto c = 0;
                while (c <= segments.at(0).size() - 1) {
                    while (r <= segments.size() - 1) {
                        auto row = segments.at(r);
                        if (c <= row.size() - 1) {
                            cipher.push_back(row.at(c));
                        }
                        r++;
                    }
                    c++;
                    r = 0;
                }

                return cipher;
            }

            const string normalized_cipher_text() const
            {
                auto segments = plain_text_segments();
                if (segments.empty()) {
                    return "";
                }

                string cipher;
                auto r = 0;
                auto c = 0;
                while (c <= segments.at(0).size() - 1) {
                    while (r <= segments.size() - 1) {
                        auto row = segments.at(r);
                        if (c <= row.size() - 1) {
                            cipher.push_back(row.at(c));
                        } else {
                            cipher.push_back(' ');
                        }
                        r++;
                    }
                    c++;
                    r = 0;
                    if (c <= segments.at(0).size() - 1) {
                        cipher.push_back(' ');
                    }
                }

                return cipher;
            }

        private:
            string m_word;
    };
}