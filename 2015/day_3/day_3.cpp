// Advent of Code 2015 - Day 3
#include "aoc.hpp"

#include <iostream>
#include <map>
#include <tuple>

class Point{
public:
    Point(int x, int y) : x(x), y(y) {}

    bool operator<(const Point& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    } 

    void goLeft()
    {
        x = x - 1;
    }

    void goRight()
    {
        x = x + 1;
    }

    void goUp()
    {
        y = y + 1;
    }

    void goDown()
    {
        y = y - 1;
    }

private:
    int x;
    int y;
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    const auto lines = aoc::read_lines(argv[1]);

    // Part 1
    {
        Point santa(0,0);
        std::map<Point, int> delivered;
        delivered[santa] = 1;
        int total_visited = 1;
        for (unsigned long i = 0; i < lines.size(); i++)
        {
            for (char c : lines[i])
            {
                switch (c){
                    case '>':
                        santa.goLeft();
                        break;
                    case '<':
                        santa.goRight();
                        break;
                    case '^':
                        santa.goUp();
                        break;
                    case 'v':
                        santa.goDown();
                        break;
                    default:
                        break;
                }
                if (!delivered.contains(santa))
                {
                    delivered[santa] = 1;
                    total_visited++;
                }
            }
        }
        std::cout << "Part 1: " << total_visited << '\n';
    }

    // Part 2
    {
        Point santa_2(0,0);
        Point robot(0,0);
        std::map<Point, int> delivered_2;
        delivered_2[santa_2] = 1;
        int total_visited_2 = 1;
        unsigned long move_count = 0;
        for (unsigned long i = 0; i < lines.size(); i++)
        {
            for (char c : lines[i])
            {
                Point& mover = (move_count % 2 == 0) ? santa_2 : robot;
                switch (c){
                    case '>':
                        mover.goLeft();
                        break;
                    case '<':
                        mover.goRight();
                        break;
                    case '^':
                        mover.goUp();
                        break;
                    case 'v':
                        mover.goDown();
                        break;
                    default:
                        break;
                }
                move_count++;
                if (!delivered_2.contains(mover))
                {
                    delivered_2[mover] = 1;
                    total_visited_2++;
                }
            }
        }

        std::cout << "Part 2: " << total_visited_2 << '\n';
    }
}
