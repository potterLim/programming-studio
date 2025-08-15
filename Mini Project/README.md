# RPG Hero Manager

A console-based Java application for creating, managing, and saving RPG characters.  
The program supports CRUD operations, class-based stat growth, and file persistence using CSV.

## Directory Structure

```
Mini Project/
├─ src/              # Java source code
└─ Data/             # Character data file (characters.csv)
```

* Startup: Reads `Data/characters.csv` to load saved characters.
* Save: Overwrites the CSV file with the current character list.

## Features

* Create, view, update, and delete RPG characters.
* Choose from four job classes: Warrior, Mage, Archer, Thief.
* Automatic stat recalculation based on class-specific growth formulas.
* Save and load characters from a CSV file.
* Search characters by name (case-insensitive partial match).

## Purpose

Inspired by *MapleStory*, this project recreates a simplified version of its character management system. The goal was to:

* Practice implementing CRUD functionality.
* Handle data relationships and state changes.
* Apply object-oriented principles like inheritance and method overriding.
* Work with file I/O for data persistence.

## Program Flow

1. `GameCharacterApp` → creates `CharacterManagerImpl` → calls `loadFromFile()`.
2. User selects a menu option → `switch` statement → calls the matching method in `CharacterManagerImpl`.
3. “Save” → `saveToFile()` writes to `characters.csv`.
4. “Exit” → program terminates.

## Class Design

| Class / Interface                                                        | Role                                                                       |
| ------------------------------------------------------------------------ | -------------------------------------------------------------------------- |
| `ICharacterManager`                                                      | Interface declaring required methods                                       |
| `CharacterManagerImpl`                                                   | Implements interface, handles file I/O, manages `ArrayList<CharacterBase>` |
| `CharacterBase`                                                          | Defines common fields and methods                                          |
| `WarriorCharacter`,<br> `MageCharacter`,<br> `ArcherCharacter`,<br> `ThiefCharacter` | Extend `CharacterBase`, override stat growth rules                         |
| `Job`                                                                    | Enum for type-safe job management                                          |

## Menu Options & Error Handling

| Menu Option         | Description                                                | Error Handling                                                                     |
| ------------------- | ---------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| Create Character    | Enter name, job, and level; add to list                    | Duplicate name, invalid job, or invalid level (< 1 / non-numeric) prompts re-entry |
| View All Characters | Display a summary of all characters                        | If none exist, display a notice                                                    |
| View Details        | Show full details for a given character                    | If not found, display a notice                                                     |
| Update Level        | Change the level of a specific character                   | If not found or invalid level, display a notice                                    |
| Delete Character    | Remove a character from the list                           | If not found, display a notice                                                     |
| Search by Name      | Filter characters by partial name match (case-insensitive) | If no matches, display a notice                                                    |
| Save to File        | Overwrite `characters.csv` with current list               | If saving fails, display a notice                                                  |
| Load on Startup     | Load characters from `characters.csv` at program start     | If reading fails, display a notice; skip duplicate names                           |

