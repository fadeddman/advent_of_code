// Advent of Code 2015 - Day 4
#include "aoc.hpp"
#include "md5.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    const auto lines = aoc::read_lines(argv[1]);
    int n = 0;

    // Part 1
    {
        std::string input = lines[0];
        while (1)
        {
            n++;
            std::string hash = aoc::md5(input + std::to_string(n));
            if (hash.substr(0,5) == "00000")
            {
                break;
            }
        }
        std::cout << "Part 1: " << n << '\n';

    }

    // Part 2
    {
        std::string input = lines[0];
        int p = n;
        while (1)
        {
            p++;
            std::string hash = aoc::md5(input + std::to_string(p));
            if (hash.substr(0,6) == "000000")
            {
                break;
            }
        }
        std::cout << "Part 2: " << p << '\n';
    }
}
