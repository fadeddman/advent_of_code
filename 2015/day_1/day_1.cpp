// Advent of Code 2015 - Day 1
#include "aoc.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    const auto lines = aoc::read_lines(argv[1]);

    // Part 1
    {
        int total = 0;
        for (const std::string& line : lines){
            for (char c : line){
                if (c == '('){
                    total++;
                }
                else if (c == ')')
                {
                    total--;
                }
            }
        }
        std::cout << "Part 1: " << total << '\n';
    }

    // Part 2
    {
        int total_p2 = 0;
        int index = 0;
        for (const std::string& line : lines){
            for (char c : line){
                if (c == '(')
                {
                    total_p2++;
                }
                else if (c == ')')
                {
                    total_p2--;
                }
                index++;
                if (total_p2 == -1)
                {
                    std::cout << "Part 2: " << index << '\n';                
                    return 0;
                }
            }
        }   
        std::cout << "Part 2: " << 0 << '\n';
    }
}
