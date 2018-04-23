#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace food_chain {
    
    auto ANIMALS = vector<string>{"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};

    const string verse(int v) {
        v--;
        stringstream song;

        song << "I know an old lady who swallowed a " << ANIMALS[v] << "." << endl;
        switch (v) {
            case 1: {
                song << "It wriggled and jiggled and tickled inside her." << endl;
                break;
            }
            case 2: {
                song << "How absurd to swallow a bird!" << endl;
                break;
            }
            case 3: {
                song << "Imagine that, to swallow a cat!" << endl;
                break;
            }
            case 4: {
                song << "What a hog, to swallow a dog!" << endl;
                break;
            }
            case 5: {
                song << "Just opened her throat and swallowed a goat!" << endl;
                break;
            }
            case 6: {
                song << "I don't know how she swallowed a cow!" << endl;
                break;
            }
            case 7: {
                song << "She's dead, of course!" << endl;
                return song.str();
            }
        }

        for (; v > 0; v--) {
            switch (v) {
                case 1:
                case 3:
                case 4:
                case 5:
                case 6:
                {
                    song << "She swallowed the " << ANIMALS[v]
                        << " to catch the " << ANIMALS[v - 1] << "." << endl;
                    break;
                }
                case 2: {
                    song << "She swallowed the bird to catch the spider that wriggled and "
                        << "jiggled and tickled inside her." << endl;
                    break;
                }
            }
        }

        song << "I don't know why she swallowed the fly. Perhaps she'll die." << endl;

        return song.str();
    }

    const string verses(int from, int to) {
        stringstream song;
        for (; from <= to; from++) {
            song << verse(from) << endl;
        }
        return song.str();
    }

    const string sing() {
        return verses(1, 8);
    }
}