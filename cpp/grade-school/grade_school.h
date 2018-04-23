#pragma once

#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace grade_school {

    class school {
        
        public: 
            void add(string name, int grade)
            {
                m_grades[grade].push_back(name);
                sort(m_grades[grade].begin(), m_grades[grade].end());
            }
            
            const map<int, vector<string>> roster() const { return m_grades; }

            const vector<string> grade(int g) const 
            { 
                if (m_grades.count(g) > 0) {
                    return m_grades.at(g); 
                }
                return {};
            }

        private:
            map<int, vector<string>> m_grades;
    };
}