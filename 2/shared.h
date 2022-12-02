#ifndef SHARED_H_
#define SHARED_H_
#include <string>

enum Shape {
    ROCK,
    PAPER,
    SCISSORS
};

enum End {
    WIN,
    DRAW,
    LOSE
};

End round_result_parser(std::string a) {
    if (a == "X") {
        return LOSE;
    } else if (a == "Y") {
        return DRAW;
    } else if (a == "Z") {
        return WIN;
    }
}

Shape shape_parser(std::string c) {
    if (c == "A") {
        return ROCK;
    } else if (c == "B") {
        return PAPER;
    } else if (c == "C") {
        return SCISSORS;
    }
}

#endif