#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "shared.h"

int calc_score(Shape first_elf, Shape second_elf) {
    int score = 0;

    switch (second_elf)
    {
    case ROCK:
        if (first_elf == SCISSORS) {
            score += 6;
        } else if (first_elf == ROCK) {
            score += 3;
        }
        score += 1;
        break;
    case PAPER:
        if (first_elf == ROCK) {
            score += 6;
        } else if (first_elf == PAPER) {
            score += 3;
        }
        score += 2;
        break;
    case SCISSORS:
        if (first_elf == PAPER) {
            score += 6;
        } else if (first_elf == SCISSORS) {
            score += 3;
        }
        score += 3;
        break;
    default:
        break;
    }
        
    return score;
}

int main() {
    std::ifstream file("input.txt");
    int score = 0;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string first_elf;
            std::string second_elf;
            std::stringstream stream(line);
            std::getline(stream, first_elf, ' ');
            std::getline(stream, second_elf, ' ');

            auto first_elf_shape = shape_parser(first_elf);
            auto second_elf_shape = shape_parser(second_elf);

            int round_score = calc_score(first_elf_shape, second_elf_shape);
            score += round_score;
        }
    }
    file.close();

    std::cout << score << std::endl;

    return 0;
}