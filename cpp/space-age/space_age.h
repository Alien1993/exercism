#pragma once

using namespace std;

namespace space_age {
    class space_age {
        public:
            space_age(const long s) : m_seconds{s} {}

            long seconds() const { return m_seconds; }

            double on_earth() const { return m_seconds / (60 * 60 * 24 * 365.25); }
            double on_mercury() const { return on_earth() / 0.2408467; }
            double on_venus() const { return on_earth() / 0.61519726; }
            double on_mars() const { return on_earth() / 1.8808158; }
            double on_jupiter() const { return on_earth() / 11.862615; }
            double on_saturn() const { return on_earth() / 29.447498; }
            double on_uranus() const { return on_earth() / 84.016846; }
            double on_neptune() const { return on_earth() / 164.79132; }
            
        private:
            long m_seconds;
    };
}