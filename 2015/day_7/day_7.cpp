// Advent of Code 2015 - Day 7
#include "aoc.hpp"

#include <iostream>
#include <unordered_map>
#include <string>

uint16_t get_value(std::string wire, std::string rule, std::unordered_map<std::string, std::string> rules);

// A gate operand is either a literal number ("1") or a wire name ("fi").
// This figures out which and returns its value either way.
uint16_t resolve(std::string token, std::unordered_map<std::string, std::string> rules)
{
    if (token[0] >= '0' && token[0] <= '9')
    {
        return (uint16_t) stoi(token);
    }
    return get_value(token, rules[token], rules);
}

uint16_t get_value(std::string wire, std::string rule, std::unordered_map<std::string, std::string> rules)
{
    if (rule.contains("NOT"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        return ~resolve(rule_split[1], rules);
    }
    else if (rule.contains("LSHIFT"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        return resolve(rule_split[0], rules) << stoi(rule_split[2]);
    }
    else if (rule.contains("RSHIFT"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        return resolve(rule_split[0], rules) >> stoi(rule_split[2]);
    }
    else if (rule.contains("AND"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        return resolve(rule_split[0], rules) & resolve(rule_split[2], rules);
    }
    else if (rule.contains("OR"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        return resolve(rule_split[0], rules) | resolve(rule_split[2], rules);
    }
    else
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        return resolve(rule_split[0], rules);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    const auto lines = aoc::read_lines(argv[1]);

    // Part 1
    {
        std::unordered_map<std::string, std::string> rules;
        std::unordered_map<std::string, uint16_t> cache;

        //populate the rules map
        for (auto line : lines)
        {
            std::vector<std::string> line_split = aoc::split(line, ' ');
            std::string wire = line_split[line_split.size() - 1];

            std::string rule = "";
            int i = 0;
            while (i < line_split.size() && line_split[i] != "->")
            {
                rule += line_split[i] + " ";
                i++;
            }
            rules[wire] = rule;
        }

        //search for a recursively filling up cache
        uint16_t a = get_value("a", rules["a"], rules);
        

        std::cout << "Part 1: " << a << '\n';
    }

    // Part 2
    {
        std::cout << "Part 2: " << 0 << '\n';
    }
}
