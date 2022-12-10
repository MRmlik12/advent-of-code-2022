#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> SIGNALS = { 20, 60, 100, 140, 180, 220 };

void calc_sum(int& cycle, int& x, int& sum) {
    if (std::find(SIGNALS.begin(), SIGNALS.end(), cycle) != SIGNALS.end()) {
        sum += x * cycle;
    }
}

int main() {
    std::ifstream file("input.txt");
    int x = 1;
    int cycle = 0;
    int result = 0;

    if (file.is_open()) {
        std::string line;
        std::string command;
        std::string argument;
    
        while (std::getline(file, line)) {
            std::stringstream stream(line);
            std::getline(stream, command, ' ');
            std::getline(stream, argument, ' ');

            cycle++;
            calc_sum(cycle, x, result);
            if (command == "addx") {
                cycle++;
                calc_sum(cycle, x, result);
                x += std::stoi(argument);
            }
        }
    }
    file.close();

    std::cout << result << std::endl;

    return 0;
}