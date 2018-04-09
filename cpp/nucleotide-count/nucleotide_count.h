#pragma once

#include <map>
#include <string>

using namespace std;

namespace dna {
    class counter {
        public:
            counter(string dna);

            const map<char, int> nucleotide_counts() const;
            int count(const char& nucleotide) const;

        private:
            string m_dna;
            map<char, int> m_count;
    };
}
