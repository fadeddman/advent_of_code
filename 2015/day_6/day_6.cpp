// Advent of Code 2015 - Day 6
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
        class LightGrid
        {
            private:
                int lights_on_count = 0;
                int light_grid[999][999] = {0};

            public:
                void turn_on_lights(int start_x, int start_y, int end_x, int end_y)
                {
                    for (int i = start_x; i <= end_x; i++)
                    {
                        for (int j = start_y; j <= end_y; j++)
                        {
                            light_grid[i][j] = 1;
                        }
                    }
                }
                
                void turn_off_lights(int start_x, int start_y, int end_x, int end_y)
                {
                    for (int i = start_x; i <= end_x; i++)
                    {
                        for (int j = start_y; j <= end_y; j++)
                        {
                            light_grid[i][j] = 0;
                        }
                    }
                }
                
                void toggle_lights(int start_x, int start_y, int end_x, int end_y)
                {
                    for (int i = start_x; i <= end_x; i++)
                    {
                        for (int j = start_y; j <= end_y; j++)
                        {
                            light_grid[i][j] ^= 1;
                        }
                    }
                }

                int count_lights()
                {
                    int count = 0;
                    for (int i = 0; i < 999; i++)
                    {
                        for (int j = 0; j <999; j++)
                        {
                            if (light_grid[i][j] == 1)
                            {
                                count++;
                            }
                        }
                    }
                    return count;
                }
        };

        LightGrid lights;
        for (auto line: lines)
        {
            std::vector<std::string> word_array;
            std::vector<std::string> start;
            std::vector<std::string> end;
            if (line.starts_with("turn on"))
            {
                word_array = aoc::split(line, ' ');
                start = aoc::split(word_array[2], ',');
                end = aoc::split(word_array[4], ',');
                lights.turn_on_lights(std::stoi(start[0]), std::stoi(start[1]), std::stoi(end[0]), std::stoi(end[1]));

            }
            else if (line.starts_with("turn off"))
            {
                word_array = aoc::split(line, ' ');
                start = aoc::split(word_array[2], ',');
                end = aoc::split(word_array[4], ',');
                lights.turn_off_lights(std::stoi(start[0]), std::stoi(start[1]), std::stoi(end[0]), std::stoi(end[1]));
            }
            else if (line.starts_with("toggle"))
            {
                word_array = aoc::split(line, ' ');
                word_array = aoc::split(line, ' ');
                start = aoc::split(word_array[1], ',');
                end = aoc::split(word_array[3], ',');
                lights.toggle_lights(std::stoi(start[0]), std::stoi(start[1]), std::stoi(end[0]), std::stoi(end[1]));
            }
            else
            {
                std::cout << "INVALID INPUT\n";
            }
        }

        std::cout << "Part 1: " << lights.count_lights() << '\n';
    }

    // Part 2
    {
        std::cout << "Part 2: " << 0 << '\n';
    }
}
