# Car Game  
A simple car game where the player must dodge incoming cars.

## Features

- **Static Libraries**: Created static libraries to segregate functions into different categories based on their usage.
- **Score Management**: Used file handling to manage game scores.
- **Interactive GUI**: Implemented a text-based interface for better user interaction.
- **Challenging Gameplay**: As time passes, the speed of the incoming cars increases to make the game more challenging.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/aman1348/car-game-in-linux-using-c.git
   ```

2. Navigate to the project directory:

   ```bash
   cd "car-game-in-linux-using-c"
   ```

3. Build the game:

   ```bash
   ./build.sh
   ```

4. Run the game:

   ```bash
   ./game_runner.sh
   ```


## Game Controls

| Action | Key     |
|--------|---------|
| Up     | `W`     |
| Down   | `S`     |
| Left   | `A`     |
| Right  | `D`     |
| Back   | `X`     |
| Enter  | `ENTER` |

## Project Structure

```
car-game-in-linux-using-c/
├── car_game.c                
├── game_runner.sh          # Script to run the final game binary
├── resources/data/
│   └── score.txt
├── menu/
│   ├── menu.c
│   ├── menu.h
│   ├── menu.o
│   └── menu.a
├── utils/
│   ├── utils.c
│   ├── utils.h
│   ├── utils.o
│   └── utils.a
├── controls/
│   ├── controls.c
│   ├── controls.h
│   ├── controls.o
│   └── controls.a
├── scoreHandler/
│   ├── scoreHandler.c
│   ├── scoreHandler.h
│   ├── scoreHandler.o
│   └── scoreHandler.a
├── gameRunner/
│   ├── gameRunner.c
│   ├── gameRunner.h
│   ├── gameRunner.o
│   └── gameRunner.a
└── README.md               # You're here!
```

## Requirements

- GCC compiler (`gcc`)
- Unix/Linux terminal (for keyboard input handling)
- Basic terminal that supports ANSI escape sequences

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for feature suggestions or bug reports.

---
