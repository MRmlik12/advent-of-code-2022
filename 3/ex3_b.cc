#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int calc_piorities(std::vector<std::string> lines) {
    auto firstLine = lines[0];
    auto secondLine = lines[1];
    auto thirdLine = lines[2];

    int calculatedPiorities = 0;
    for (auto i = 0; i < firstLine.length(); i++) {
        auto secondCharFound = secondLine.find(firstLine[i]);
        auto thirdCharFound = thirdLine.find(firstLine[i]);
        if (secondCharFound != std::string::npos && thirdCharFound != std::string::npos) {
                auto letter = secondLine[secondCharFound];
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

    return calculatedPiorities;
}

int main() {
    std::ifstream file("input.txt");
    int calculatedPiorities = 0;
    std::vector<std::string> groupLines;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            groupLines.push_back(line);

            if (groupLines.size() == 3) {
                calculatedPiorities += calc_piorities(groupLines);
                groupLines.clear();
            }

        }
    }
    file.close();

    std::cout << calculatedPiorities << std::endl;

    return 0;
}