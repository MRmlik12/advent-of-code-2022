#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("input.txt");
    auto countPairs = 0;

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            std::string first;
            std::string second;

            std::string firstAssignmentA;
            std::string firstAssignmentB;
            std::string secondAssignmentA;
            std::string secondAssignmentB;

            std::stringstream stream(line);

            std::getline(stream, first, ',');
            std::getline(stream, second, ',');

            std::stringstream firstStream(first);

            std::getline(firstStream, firstAssignmentA, '-');
            std::getline(firstStream, firstAssignmentB, '-');

            std::stringstream secondStream(second);

            std::getline(secondStream, secondAssignmentA, '-');
            std::getline(secondStream, secondAssignmentB, '-');
            
            auto firstAssignmentNumberA = std::stoi(firstAssignmentA);
            auto firstAssignmentNumberB = std::stoi(firstAssignmentB);
            auto secondAssignmentNumberA = std::stoi(secondAssignmentA);
            auto secondAssignmentNumberB = std::stoi(secondAssignmentB);

            if ((firstAssignmentNumberA <= secondAssignmentNumberA && firstAssignmentNumberB >= secondAssignmentNumberB)
                || (secondAssignmentNumberA <= firstAssignmentNumberA && secondAssignmentNumberB >= firstAssignmentNumberB)) {
                countPairs++;
            }
        }
    }
    file.close();

    std::cout << countPairs << std::endl;

    return 0;
}