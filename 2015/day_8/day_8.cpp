// Advent of Code 2015 - Day 8
#include "aoc.hpp"

#include <iostream>
#include <string>
#include <vector>

int count_characters(std::string input_string) { return input_string.length(); }

char decimal_to_ascii(char msb, char lsb) { return (msb - '0') * 10 + lsb; }

std::string strip_string(std::string input_string)
{
    std::string to_return;
    for (size_t i = 1; i < input_string.length() - 1; i++)
    {
        if (input_string[i] == '\\')
        {
            i++;
            // bound check
            if (i >= input_string.length() - 1)
            {
                std::cerr << "Invalid input";
                return "";
            }
            // backslash case
            if (input_string[i] == '\\')
            {
                to_return.push_back('\\');
            }
            // lone quote
            else if (input_string[i] == '"')
            {
                to_return.push_back('"');
            }
            else if (input_string[i] == 'x')
            {
                to_return.push_back(decimal_to_ascii(input_string[i + 1], input_string[i + 2]));
                i += 2;
            }
        }
        else
        {
            to_return.push_back(input_string[i]);
        }
    }
    return to_return;
}

std::string expand_string(std::string input_string)
{
    std::string to_return;
    to_return.push_back('"');
    for (size_t i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == '"')
        {
            to_return.push_back('\\');
            to_return.push_back('"');
        }
        else if (input_string[i] == '\\')
        {
            to_return.push_back('\\');
            to_return.push_back('\\');
        }
        else
        {
            to_return.push_back(input_string[i]);
        }
    }
    to_return.push_back('"');
    return to_return;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    const auto lines = aoc::read_lines(argv[1]);

    // Part 1
    {
        int initial_count = 0;
        int second_count = 0;

        for (auto s : lines)
        {
            initial_count += count_characters(s);
            second_count += count_characters(strip_string(s));
        }
        std::cout << "Part 1: " << initial_count - second_count << '\n';
    }

    // Part 2
    {
        int initial_count = 0;
        int second_count = 0;

        for (auto s : lines)
        {
            initial_count += count_characters(s);
            second_count += count_characters(expand_string(s));
        }
        std::cout << "Part 2: " << second_count - initial_count << '\n';
    }
}
