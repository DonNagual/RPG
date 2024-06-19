#include <iostream>
#include <fstream>
#include <string>
#include <json/json.h> // Requires the JSON for Modern C++ library

void updateCharacterSheet(const std::string& filepath, const std::string& levelUpDataPath) {
    std::ifstream inFile(filepath);
    std::ifstream levelUpFile(levelUpDataPath);
    Json::Value characterData;
    Json::Value levelUpData;

    inFile >> characterData;
    levelUpFile >> levelUpData;

    // Update character attributes based on level up data
    for (const auto& key : levelUpData.getMemberNames()) {
        characterData[key] = levelUpData[key];
    }

    std::ofstream outFile(filepath);
    outFile << characterData;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <character_file.json> <level_up_data.json>" << std::endl;
        return 1;
    }

    updateCharacterSheet(argv[1], argv[2]);
    return 0;
}
