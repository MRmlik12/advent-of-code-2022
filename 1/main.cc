#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

bool sort_to_greatest(int i, int j) {
    return i > j;
}

int main() {
    std::ifstream file("input.txt");
    std::vector<int> elfs;

    if (file.is_open()) {
        int elfCaloriesCount = 0;
        std::string line;

        while (std::getline(file, line)) {
            if (line == "") {
                elfs.push_back(elfCaloriesCount);
                elfCaloriesCount = 0;
                continue;
            }

            elfCaloriesCount += std::stoi(line);
        }
    }
    file.close();

    std::sort(elfs.begin(), elfs.end(), sort_to_greatest);
    std::cout << elfs[0] << std::endl;
    std::cout << elfs[0] + elfs[1] + elfs[2] << std::endl;

    return 0;
}