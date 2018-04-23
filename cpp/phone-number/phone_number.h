#pragma once

#include <string>
#include <sstream>

using namespace std;

class phone_number {
public:

    phone_number(const string& phone)
        : m_phone{phone}
    {
    }

    const string number() const 
    { 
        stringstream builder;

        for (const auto& d : m_phone) {
            if (isdigit(d)) {
                builder << d;
            }
        }

        auto cleaned = builder.str();
    
        
        if (cleaned.size() > 10 && cleaned.front() != '1' || cleaned.size() < 10) {
            return "0000000000";
        } else if (cleaned.size() > 10 && cleaned.front() == '1') {
            return cleaned.substr(1);
        }

        return cleaned; 
    }
    
    const string area_code() const
    {
        return number().substr(0, 3);
    }

    operator string() const
    {
        stringstream builder;
        auto cleaned = number();
        builder << '(' << cleaned.substr(0, 3) << ") " 
                << cleaned.substr(3, 3) 
                << '-' 
                << cleaned.substr(6);
        return builder.str();
    }

private:
    string m_phone;
};
