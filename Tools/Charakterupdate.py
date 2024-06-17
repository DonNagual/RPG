import re

def update_character_sheet(filepath, updates):
    with open(filepath, 'r', encoding='utf-8') as file:
        content = file.read()

    for key, value in updates.items():
        content = re.sub(rf'\[{key}\]', str(value), content)

    with open(filepath, 'w', encoding='utf-8') as file:
        file.write(content)

# Beispiel: Update-Daten für einen Levelaufstieg
updates = {
    'Level': 2,
    'Stärke': 9,
    'Geschicklichkeit': 14,
    'Intelligenz': 19,
    'Charisma': 12,
    'Erfahrungspunkte': 100,
    'Fähigkeit 1': 'Feuerball (2)',
    'Fähigkeit 2': 'Teleporation (2)'
}

update_character_sheet('Charakterbogen.md', updates)
