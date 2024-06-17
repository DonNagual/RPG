def scale_npc_to_character(npc, character_level):
    npc['level'] = character_level
    npc['stärke'] += character_level // 2
    npc['geschicklichkeit'] += character_level // 2
    npc['intelligenz'] += character_level // 3
    npc['charisma'] += character_level // 4
    return npc

# Beispiel-NPC
npc = {
    'name': 'Goblin',
    'level': 1,
    'stärke': 5,
    'geschicklichkeit': 7,
    'intelligenz': 4,
    'charisma': 3
}

# Anpassen des NPC an den Level des Charakters
character_level = 5
scaled_npc = scale_npc_to_character(npc, character_level)

print(scaled_npc)
