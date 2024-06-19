#include <iostream>
#include <fstream>
#include <string>
#include <json/json.h> // Requires the JSON for Modern C++ library

void scaleNPCToCharacter(Json::Value& npc, int characterLevel) {
    npc["level"] = characterLevel;
    npc["stärke"] = npc["base_stärke"].asInt() + characterLevel / 2;
    npc["geschicklichkeit"] = npc["base_geschicklichkeit"].asInt() + characterLevel / 2;
    npc["intelligenz"] = npc["base_intelligenz"].asInt() + characterLevel / 3;
    npc["charisma"] = npc["base_charisma"].asInt() + characterLevel / 4;
}

void updateNPC(const std::string& npcFilePath, int playerLevel) {
    std::ifstream inFile(npcFilePath);
    Json::Value npcData;
    inFile >> npcData;

    scaleNPCToCharacter(npcData, playerLevel);

    std::ofstream outFile(npcFilePath);
    outFile << npcData;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <npc_file.json> <player_level>" << std::endl;
        return 1;
    }

    int playerLevel = std::stoi(argv[2]);
    updateNPC(argv[1], playerLevel);
    return 0;
}
