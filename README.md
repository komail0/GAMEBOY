# 🎮 GameBoy: Arcade Game Hub (Visual Studio + SFML)
**OBJECT ORIENTED PROGRAMMING**

Welcome to **GameBoy**, a retro-inspired game hub featuring three classic arcade games—**Hangman**, **Snake**, and **Wordle**—developed as a semester project using **C++** and the **SFML** library. Packaged as a Visual Studio project, this hub provides a seamless menu-driven experience to play these games with score tracking and customizable audio settings.

---

## 🌟 Features

- 🕹️ **Three Classic Games**:
  - **Hangman**: Guess a word letter by letter, with single-player (random word) and two-player modes. Features a hangman figure, hints, and lives system.
  - **Snake**: Navigate a snake to eat food, grow, and avoid collisions. Includes normal and hard modes with power-ups (hard mode only).
  - **Wordle**: Guess a five-letter word within six attempts, with visual feedback and hints for strategic play.
- 🖱️ **Interactive Menu**: Navigate through a main menu to select games, view achievements, or adjust settings (music and volume).
- 🎯 **Scoring System**: Earn points in each game (e.g., +100 for correct Hangman guesses, +10/+20 for Snake food, +100 for valid Wordle guesses). Scores are saved and sorted in `sorted_scores.txt`.
- 🎵 **Audio System**: Background music selection (three tracks) and volume control via the settings menu.
- 🏆 **Achievements**: View top scores with player names and games played, displayed with gold, silver, and bronze medals.
- 🧠 **Procedural Programming**: Built primarily using procedural programming principles, with minimal use of OOP (only where necessary for SFML integration).
- 🖼️ **Visuals**: Rich SFML-based graphics for sprites, backgrounds, and UI elements, with assets stored in the `assets/` folder.

---

## 🛠️ Installation

1. 📥 **Clone the Repository**:
   ```bash
   git clone https://github.com/komail0/GAMEBOY.git
   cd GAMEBOY
   ```

2. 📂 **Open the Project**:
   - Open the Visual Studio solution file (e.g., `GameBoy.sln`) in **Visual Studio** (2019 or later).

3. 🗂️ **Verify Assets**:
   - Ensure the `assets/` folder is in the same directory as the executable (or project directory if running from Visual Studio). The folder should contain:
     ```
     assets/
     ├── 1.ogg                 # Background music (Travis Scott - FE!N)
     ├── 2.ogg                 # Background music (Kar Har Maidaan Fateh)
     ├── 3.ogg                 # Background music (Believer)
     ├── apple.png             # Snake food (apple)
     ├── back.png              # Back button
     ├── background.png        # Snake background
     ├── backgroundimage.png   # Main menu background
     ├── bk1.jpg               # Hangman background
     ├── b2.jpg                # Wordle game background
     ├── bb.jpg                # Wordle welcome background
     ├── bronze.png            # Bronze medal (achievements)
     ├── enter.jpg             # Wordle enter key
     ├── exit.png              # Exit button
     ├── game.png              # Game logo
     ├── gamezone.png          # Game zone logo
     ├── gold.png              # Gold medal (achievements)
     ├── hard.png              # Snake hard mode button
     ├── head_up.png           # Snake head (up)
     ├── head_down.png         # Snake head (down)
     ├── head_left.png         # Snake head (left)
     ├── head_right.png        # Snake head (right)
     ├── heart.png             # Wordle heart (lives)
     ├── heart1-.png           # Hangman heart (lives)
     ├── heartk.png            # Snake heart (lives)
     ├── hint.png              # Wordle hint (random word)
     ├── hint2.png             # Wordle hint (single letter)
     ├── image.png             # Snake instructions background
     ├── instructions.png      # Snake instructions button
     ├── lose1.png             # Wordle lose screen
     ├── minus.png             # Snake power-up (minus)
     ├── mushroom.png          # Snake food (mushroom)
     ├── normal.png            # Snake normal mode button
     ├── PAUSE.png             # Pause screen image
     ├── play3.png             # Wordle play button
     ├── playhangman.png       # Hangman button
     ├── playsnake.png         # Snake button
     ├── playwordle.png        # Wordle button
     ├── plus.png              # Snake power-up (plus)
     ├── quit.png              # Snake quit button
     ├── rules.png             # Wordle rules screen
     ├── settings.png          # Settings button
     ├── silver.png            # Silver medal (achievements)
     ├── tail_up.png           # Snake tail (up)
     ├── tail_down.png         # Snake tail (down)
     ├── tail_left.png         # Snake tail (left)
     ├── tail_right.png        # Snake tail (right)
     ├── welcome.png           # Main menu welcome image
     ├── A.png                 # Wordle key (A)
     ├── Q.jpg, W.jpg, ..., M.jpg  # Wordle keyboard keys (26 letters)
     ├── Bodoni MT Black.ttf   # Menu and Snake font
     ├── arial.ttf             # General font
     ├── Roboto-Black.ttf      # Wordle font
     ├── sewer.ttf             # Hangman title font
     ```

4. ▶️ **Build & Run**:
   - Build the solution in Visual Studio (Debug or Release mode).
   - Run the executable directly or via Visual Studio.
   - If assets fail to load, ensure the `assets/` folder is in the correct directory relative to the executable.

---

## 🕹️ How to Play

### Main Menu
- **Objective**: Select a game, view achievements, or adjust settings.
- **Controls**:
  - 🖱️ **Mouse**: Click buttons for **Hangman**, **Snake**, **Wordle**, **Settings**, **Achievements**, or **Exit**.
  - ✍️ **Text Input**: Enter your name at the start (saved with scores).
- **Settings**:
  - Press **1**, **2**, or **3** to select background music.
  - Press **+** or **-** to adjust volume.
  - Press **ESC** to return to the main menu.
- **Achievements**: View top scores sorted by highest score, with player names and games played.

### Hangman
- **Objective**: Guess a word letter by letter before losing all 6 lives.
- **Modes**:
  - **Single Player**: Guess a random word from categories (cars, animals, programming). Hints show the category.
  - **Two Player**: Player 1 enters a word; Player 2 guesses it.
- **Controls**:
  - ✍️ **Keyboard**: Type letters to guess (A-Z).
  - **Spacebar**: Pause/resume the game.
  - 🖱️ **Mouse**: Select game mode (1 Player/2 Player) and replay options (Yes/No).
- **Scoring**:
  - +100 points per correct letter.
  - -50 points per incorrect letter.
- **Gameplay**:
  - A hangman figure updates with each incorrect guess.
  - Win by guessing the word; lose if lives reach 0.

### Snake
- **Objective**: Grow the snake by eating food while avoiding collisions.
- **Modes**:
  - **Normal**: 3 lives, standard speed.
  - **Hard**: 1 life, faster speed, includes power-ups (+1 life or -1 life).
- **Controls**:
  - ⬆️⬇️⬅️➡️ **Arrow Keys/WASD**: Move the snake.
  - **Spacebar**: Pause/resume.
  - 🖱️ **Mouse**: Select difficulty, instructions, or quit.
  - **+ Key**: Cheat to gain 500 points, +1 life, and grow 5 segments (for testing).
- **Scoring**:
  - +10 points for apples, +20 for mushrooms (grow snake).
  - +100 for plus power-up, -100 for minus power-up (hard mode).
- **Gameplay**:
  - Eat food to grow and score points.
  - Avoid hitting walls or the snake's body.
  - Power-ups spawn every 10 seconds in hard mode (last 5 seconds).

### Wordle
- **Objective**: Guess a five-letter word in 6 attempts.
- **Controls**:
  - 🖱️ **Mouse**: Click virtual keyboard letters, Enter, Backspace, or hints.
  - **Enter Key**: Submit a guess.
  - **Spacebar**: Pause/resume.
- **Scoring**:
  - +100 points for a valid word.
  - +10 points per correct letter in the correct position.
  - -10 points per letter not in the word.
  - +150 points for winning.
- **Gameplay**:
  - Green tiles indicate correct letters in the correct position; yellow indicates correct letters in the wrong position.
  - Use hints: one fills a row with a random valid word, another reveals a single letter.
  - Win by guessing the word; lose after 6 failed attempts.

---

## ⚙️ Development Details

- 💬 **Language**: C++
- 🧰 **Library**: SFML (Simple and Fast Multimedia Library)
  - 🎨 **Graphics**: Sprites for game elements, UI, and backgrounds.
  - 🔊 **Audio**: Background music and sound effects (configurable).
  - 🪟 **Windows**: 1200x800 (main menu), 800x600 (Hangman/Wordle), 1300x900 (Snake).
  - ⚙️ **System**: Clock-based timing for movement and power-ups.
  - 🎮 **Events**: Keyboard and mouse input handling.
- 🧱 **Programming Paradigm**: Primarily procedural, with minimal classes for SFML integration.
- 💻 **IDE**: Visual Studio (solution file: `GameBoy.sln`)
- 📂 **Files**:
  - `game.h`: Class declarations for game components.
  - `game.cpp`: Implementation of game logic, UI, and mechanics.
  - `scores.txt`: Stores player names and scores.
  - `sorted_scores.txt`: Stores sorted high scores with game names.

---

## 👥 Credits

- 🎮 **Game Concept**: Inspired by classic arcade games (Hangman, Snake, Wordle).
- 👨‍💻 **Developer**: Komail Raza, M.Waqas,Burhan Ahmed
- 🎼 **Music & Art**: Custom and royalty-free assets in the `assets/` folder.
- 🖌️ **Fonts**:
  - Bodoni MT Black: Menu and Snake UI.
  - Arial: General text.
  - Roboto Black: Wordle UI.
  - Sewer: Hangman title.

---

## 📬 Contact

For feedback, bug reports, or questions, reach out to:
- 📧 **Email**: [komailraza448@gmail.com](mailto:komailraza448@gmail.com)
- 🐙 **GitHub**: [komail0](https://github.com/komail0)

---

## 📸 Gameplay



<img width="604" height="424" alt="image" src="https://github.com/user-attachments/assets/9a0f72f3-bf61-4646-ae30-1434f0d47ed8" />
<img width="653" height="469" alt="image" src="https://github.com/user-attachments/assets/79a6ef1c-c0a0-4291-b780-77b5e0eae1b1" />
<img width="649" height="467" alt="image" src="https://github.com/user-attachments/assets/26052cff-07ff-4b59-9af9-fabbd969bc21" />
<img width="604" height="410" alt="image" src="https://github.com/user-attachments/assets/17144b1a-7cc9-4d6c-a5e6-e4bb5cd9076a" />
<img width="398" height="326" alt="image" src="https://github.com/user-attachments/assets/67358403-f763-44f9-b723-c2992462b237" />
<img width="407" height="332" alt="image" src="https://github.com/user-attachments/assets/cd00562e-0416-49a6-bc78-5a10b86083af" />

```
```
