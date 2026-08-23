// Advent of Code 2015 - Day 2
#include "aoc.hpp"

#include <iostream>

class Rectangle
{
public:
    Rectangle(int l, int w, int h) : length(l), height(h), width(w) {}

    int surface_area()
    {
        return 2 * length * height + 2 * height * width + 2 * width * length; 
    }
    
    int min_side()
    {
        int min_1 = (length * height < height * width) ? length * height: height * width;
        return (min_1 < width * length) ? min_1 : width * length;

    }

    int min_perimeter()
    {
        int min_1 = (length < width) ? length : width;
        int min_2 = 0;
        if (min_1 == length){
            min_2 = (width < height) ? width : height;
        }
        else {
            min_2 = (length < height) ? length : height;
        }
        return min_1 * 2 + min_2 * 2;
    }

    int volume()
    {
        return length * width * height;
    }

private:
    int length = 0;
    int height = 0;
    int width = 0;
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    const auto lines = aoc::read_lines(argv[1]);

    // Part 1
    {
        unsigned long total = 0;
        for (unsigned long i = 0; i < lines.size(); i++)
        {
            auto parts = aoc::split(lines[i], 'x');
            if (parts.size() < 3) continue;
            Rectangle box(std::stoi(parts[0]), std::stoi(parts[1]), std::stoi(parts[2]));
            total += box.min_side();       
            total += box.surface_area(); 
        }
        std::cout << "Part 1: " << total << '\n';

    }

    // Part 2
    {
        unsigned long ribbon_total = 0;
        for (unsigned long i = 0; i < lines.size(); i++)
        {
            auto parts = aoc::split(lines[i], 'x');
            if (parts.size() < 3 ) continue;
            Rectangle box(std::stoi(parts[0]), std::stoi(parts[1]), std::stoi(parts[2]));
            ribbon_total += box.min_perimeter();
            ribbon_total += box.volume();
        }
        std::cout << "Part 2: " << ribbon_total << '\n';
    }
}
