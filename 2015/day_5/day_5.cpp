// Advent of Code 2015 - Day 5
#include "aoc.hpp"
#include <set>
#include <unordered_map>

#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    const auto lines = aoc::read_lines(argv[1]);

    // Part 1
    {
        std::set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        std::unordered_map<char, char> illegal_map;
        illegal_map['a'] = 'b';
        illegal_map['c'] = 'd';
        illegal_map['p'] = 'q';
        illegal_map['x'] = 'y';

        int legal_strings = 0;

        for (auto s : lines)
        {
            //first check for vowels
            int vowels_count = 0;
            bool illegal_string = false;
            bool first_illegal = false;
            bool has_doubles = false;
            char prev_key;
            std::set<char>visited;
            for (char c : s)
            {
                if (vowels.contains(c))
                {
                    vowels_count++;
                }
                if (visited.contains(c))
                {
                    has_doubles = true;
                }
                else
                {
                    visited.clear();
                }
                visited.insert(c);
                if (first_illegal)
                {
                    if (illegal_map[prev_key] == c)
                    {
                        illegal_string = true;
                    }
                }
                if (illegal_map.contains(c))
                {
                    prev_key = c;
                    first_illegal = true;
                }
                else
                {
                    first_illegal = false;
                }
            }
            if (vowels_count >= 3 && has_doubles && !illegal_string)
            {
                legal_strings++;
                
            }
        }


        std::cout << "Part 1: " << legal_strings << '\n';
    }

    // Part 2
    {
        int nice_strings = 0;
        for (auto s : lines)
        {
            if (s.size() < 4) continue;

            bool has_pair = false;
            bool has_repeat = false;
            //go for brute force
            for (size_t i = 0; i < s.size() - 1; i++)
            {
                char first_letter = s[i];
                char second_letter = s[i + 1];

                for (size_t j = i + 2; j < s.size() - 1; j++)
                {
                    if (s[j] == first_letter && s[j + 1] == second_letter)
                    {
                        has_pair = true;
                        break;
                    }
                }
                if (has_pair)
                {
                    break;
                }
            }

            //second i feel like can use a hashmap but lets brute force for now
            for (size_t i = 0; i < s.size() - 2; i++)
            {
                if (s[i] == s[i + 2])
                {
                    has_repeat = true;
                    break;
                }
            }
            if (has_pair && has_repeat)
            {
                nice_strings++;
            }
        }

        std::cout << "Part 2: " << nice_strings << '\n';
    }
}
