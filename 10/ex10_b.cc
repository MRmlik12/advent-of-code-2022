#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> SIGNALS = { 40, 80, 120, 160, 200, 240 };

void print_sprites(int& cycle, int& x, std::string& buffer) {
    std::vector<int> registers = { x -1, x, x+1 };

    if (std::find(registers.begin(), registers.end(), (cycle - 1) % 40) != registers.end()) {
        buffer += "##";
    } else {
       buffer += "  ";
    }

    if (std::find(SIGNALS.begin(), SIGNALS.end(), cycle) != SIGNALS.end()) {
        buffer += "\n";
    }
}

int main() {
    std::ifstream file("input.txt");
    int x = 1;
    int cycle = 0;
    std::string result = "";

    if (file.is_open()) {
        std::string line;
        std::string command;
        std::string argument;
        
        while (std::getline(file, line)) {
            
            std::stringstream stream(line);
            std::getline(stream, command, ' ');
            std::getline(stream, argument, ' ');

            cycle++;
            print_sprites(cycle, x, result);
            if (command == "addx") {
                cycle++;
                print_sprites(cycle, x, result);
                x += std::stoi(argument);
            }
        }
    }
    file.close();

    std::cout << result << std::endl;

    return 0;
}