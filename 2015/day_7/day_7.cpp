// Advent of Code 2015 - Day 7
#include "aoc.hpp"

#include <iostream>
#include <unordered_map>
#include <string>

uint16_t get_value(std::string wire, std::string rule, std::unordered_map<std::string, std::string>& rules,
                    std::unordered_map<std::string, uint16_t>& cache);

// A gate operand is either a literal number ("1") or a wire name ("fi").
// This figures out which and returns its value either way.
uint16_t resolve(std::string token, std::unordered_map<std::string, std::string>& rules,  std::unordered_map<std::string, uint16_t>& cache)
{
    if (token[0] >= '0' && token[0] <= '9')
    {
        return (uint16_t) stoi(token);
    }
    return get_value(token, rules[token], rules, cache);
}

uint16_t get_value(std::string wire, std::string rule, std::unordered_map<std::string, std::string>& rules,
                    std::unordered_map<std::string, uint16_t>& cache)
{
    auto it = cache.find(wire);
    if (it != cache.end())
    {
        return it->second;
    }
    if (rule.contains("NOT"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        uint16_t result = ~resolve(rule_split[1], rules, cache);
        cache[wire] = result;
        return result;
    }
    else if (rule.contains("LSHIFT"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        uint16_t result = resolve(rule_split[0], rules, cache) << stoi(rule_split[2]);
        cache[wire] = result;
        return result;
    }
    else if (rule.contains("RSHIFT"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        uint16_t result = resolve(rule_split[0], rules, cache) >> stoi(rule_split[2]);
        cache[wire] = result;
        return result;
    }
    else if (rule.contains("AND"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        uint16_t result = resolve(rule_split[0], rules, cache) & resolve(rule_split[2], rules, cache);
        cache[wire] = result;
        return result;
    }
    else if (rule.contains("OR"))
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        uint16_t result = resolve(rule_split[0], rules, cache) | resolve(rule_split[2], rules, cache);
        cache[wire] = result;
        return result;
    }
    else
    {
        std::vector<std::string> rule_split = aoc::split(rule, ' ');
        uint16_t result = resolve(rule_split[0], rules, cache);
        cache[wire] = result;
        return result;
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
        uint16_t a = get_value("a", rules["a"], rules, cache);
        

        std::cout << "Part 1: " << a << '\n';

        rules["b"] = "3176";
        cache.clear();

        uint16_t b = get_value("a", rules["a"], rules, cache);


        std::cout << "Part 2: " << b << '\n';
    }

    // Part 2
    {

    }
}
