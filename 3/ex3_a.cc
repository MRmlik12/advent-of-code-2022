#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("input.txt");
    int calculatedPiorities = 0;

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            int lineLenght = line.length() / 2;

            std::string firstHalf = line.substr(0, lineLenght);
            std::string secondHalf = line.substr(lineLenght);

            for (auto i = 0; i < lineLenght; i++) {
                auto found = secondHalf.find(firstHalf[i]);
                if (found != std::string::npos) {
                    auto letter = secondHalf[found];
                    int piority = 0;

                    if (letter >= 65 && letter <= 90) {
                        piority += abs(('A' - letter)) + 27;
                    } else if (letter >= 97 && letter <= 122) {
                        piority += abs(('a' - letter)) + 1;
                    }

                    calculatedPiorities += piority;

                    break;
                }
            }
            
        }
    }
    file.close();

    std::cout << calculatedPiorities << std::endl;

    return 0;
}