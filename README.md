
# 🗡️ Dungeon Explorer

A small terminal-based dungeon adventure game written in C.

Explore a grid-based dungeon, collect treasure, avoid walls, and find the exit to win.

## Features

- Grid-based dungeon exploration
- WASD movement controls
- Wall and boundary collision checks
- Treasure collection and score tracking
- Locked exit and win condition
- Simple Makefile-based build system

## Requirements

- GCC
- GNU Make
- Git (for cloning the repository)

## Getting Started

Clone the repository:

```bash
git clone https://github.com/bhavin-eternity/dungeon-explorer.git
cd dungeon-explorer
```

Build the game:

```bash
make
```

Run it:

```bash
./dungeon-explorer
```

Remove the compiled executable:

```bash
make clean
```

## Controls

| Key | Action |
|---|---|
| W | Move up |
| A | Move left |
| S | Move down |
| D | Move right |
| Q | Quit |

## Gameplay

Collect the treasure (`T`) to earn 10 points, then reach the exit (`E`) to win.

| Symbol | Meaning |
|---|---|
| P | Player |
| # | Wall |
| . | Empty floor |
| T | Treasure |
| E | Exit |

## Built With

- C (C11)
- GCC
- GNU Make
- Git

## What I Learned

- Working with 2D arrays
- Using loops and conditional statements
- Writing and organizing C functions
- Using pointers to modify variables
- Validating movement and managing game state
- Compiling and tracking changes with GCC, Make, and Git

## Future Improvements

- Multiple dungeon levels
- Random map generation
- Traps and enemies
- High-score saving
- Automated tests

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
