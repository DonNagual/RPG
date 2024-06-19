# Tools

Dieser Ordner enthält nützliche C++-Programme, um Charakter- und NPC-Daten zu verwalten.

## Inhaltsverzeichnis

- [Charakterupdate](Charakterupdate.cpp)
- [NPCupdate](NPCupdate.cpp)

## Charakterupdate.cpp

Dieses Programm aktualisiert den Charakterbogen eines Spielers, wenn der Charakter einen Levelaufstieg hat und der Spieler seine Punkte verteilt hat.

### Nutzung

```bash
g++ -o Charakterupdate Charakterupdate.cpp -ljsoncpp
./Charakterupdate <character_file.json> <level_up_data.json>
```

## NPCupdate.cpp

Dieses Programm passt die Level und Attribute der NPCs an den Level des Spielercharakters an, um die Schwierigkeit des Spiels gleichbleibend zu halten.

### Nutzung

```bash
g++ -o NPCupdate NPCupdate.cpp -ljsoncpp
./NPCupdate <npc_file.json> <player_level>
```

