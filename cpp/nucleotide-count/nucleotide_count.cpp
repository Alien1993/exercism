#include <stdexcept>

#include "nucleotide_count.h"

namespace dna {

    counter::counter(string dna)
        : m_dna{dna}
        , m_count{map<char, int>{{'A', 0}, {'T', 0}, {'C', 0}, {'G', 0}}}
    {
        string nucleotides{"ATCG"};
        for (const auto& n : m_dna) {
            if (nucleotides.find(n) == string::npos) {
                throw invalid_argument{"Bad nucleotide"};
            }
            m_count[n]++;
        }
    }

    const map<char, int> counter::nucleotide_counts() const
    {
        return m_count;
    }

    int counter::count(const char& nucleotide) const
    {
        if (string("ATCG").find(nucleotide) == string::npos) {
            throw invalid_argument{"Bad nucleotide"};
        }
        return m_count.at(nucleotide);
    }
}