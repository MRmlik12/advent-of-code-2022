#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "shared.h"

int calc_score(Shape first_elf, End second_elf) {
    int score = 0;
    switch (second_elf)
    {
    case WIN:
        if (first_elf == ROCK) {
            score += 2;
        } else if (first_elf == PAPER) {
            score += 3;
        } else if (first_elf == SCISSORS) {
            score += 1;
        }
        score += 6;
        break;
    case DRAW:
        if (first_elf == ROCK) {
            score += 1;
        } else if (first_elf == PAPER) {
            score += 2;
        } else if (first_elf == SCISSORS) {
            score += 3;
        }
        score += 3;
        break;
    case LOSE:
        if (first_elf == ROCK) {
            score += 3;
        } else if (first_elf == PAPER) {
            score += 1;
        } else if (first_elf == SCISSORS) {
            score += 2;
        }
        score += 0;
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
            std::string round_result;
            std::stringstream stream(line);
            std::getline(stream, first_elf, ' ');
            std::getline(stream, round_result, ' ');

            auto first_elf_shape = shape_parser(first_elf);
            auto round_end_result = round_result_parser(round_result);

            int round_score = calc_score(first_elf_shape, round_end_result);
            score += round_score;
        }
    }
    file.close();

    std::cout << score << std::endl;

    return 0;
}