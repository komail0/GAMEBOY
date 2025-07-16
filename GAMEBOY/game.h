#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include "hangman.h"  // Ensure this file defines HangmanGame properly
//#include "snake.h"    // Ensure this file defines SnakeGame properly
//#include "wordle.h"   // Ensure this file defines WordleGame properly
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
using namespace sf;


#ifndef GAMEBOY_H
#define GAMEBOY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Game;  // Forward declaration of Game class
class Player;
class Screen;
class SoundSystem;
class Menu;
class HangmanGame;  // Assuming this exists
class SnakeGame;    // Assuming this exists
class WordleGame;   // Assuming this exists

class Player
{
private:
    string name;
    int totalScore;

public:
    Player() : totalScore(0) {}

    void setName(const std::string& playerName);
    string getName() const;
    void addScore(int score);
    int getScore() const;
};

class Screen
{
private:
    RenderWindow window;

public:
    void initWindow(const string& title, int width, int height);
    RenderWindow& getWindow();
    void closeWindow();
};

class SoundSystem
{
private:
    SoundBuffer buffer;
    Sound sound;

public:
    bool loadSound(const std::string& filepath);
    void playSound();
    void setVolume(int volume);
};

class Menu
{
private:      // Separate window for the menu
    RenderWindow menuWindow;
    Texture playSnakeTexture, playWordleTexture, playHangmanTexture, exitTexture, achTexture;
    Sprite playSnakeButton, playWordleButton, playHangmanButton, exitButton, Ach;
    Font font;
    Sprite backgroundSprite;
    Texture backgroundTexture;
    Sprite gameSprite;
    Texture gameTexture;
    std::string userName;          // To store the user's name
    Text promptText;               // Text to prompt user input
    Text userNameText;
    Sprite welcome;
    Text wel;
    Texture welcomeTexture;
    Sprite game;
    Texture gamepng;
    Sprite Settings;
    Texture settingTexture;
    SoundSystem soundSystem;
    Text songPrompt;
    Text song1;
    Text song2;
    Text song3;
    Text control1;
    Sprite Back;
    Texture backTexture;
    Text back;
    Text control;
    Sprite gold;
    Sprite silver;
    Sprite bronze;
    Texture goldtexture;
    Texture silvertexture;
    Texture bronzetexture;


public:
    Menu();

   
    int display();
    void getUserName();
    void saveScore(int score);
    void displaySettings();
    void saveUserNameToFile();
    RenderWindow& getWindow();
    void displaySortedScores();
    void displayAchievements();
	void close();
};

class Game
{
protected:
    std::string name;
    int score;

public:
    Game(const std::string& gameName);
    virtual ~Game() = default;
    virtual void startGame(RenderWindow& window) = 0;
    void setScore(int newScore);
    int getScore() const;
};

class GameBoy
{
private:
    Player player;
    Screen screen;
    SoundSystem soundSystem;
    Menu menu;
    bool isRunning;

public:
    GameBoy();
    void start();
    void playHangman();
    void playSnake();
    void playWordle();
    void shutdown();
    void appendGameNameToScoreFile(const std::string& gameName);
};

#endif






class HangManFigure
{
private:
    int parts; //There are 6 parts, 1 Head, 1 Body, 2 Arms, 2 Legs

    sf::CircleShape head;
    sf::RectangleShape body, leftArm, rightArm, leftLeg, rightLeg;
    sf::RectangleShape gallowsBase, gallowsPole, gallowsBeam, rope;
    sf::Texture heartT;
    sf::Sprite hearts[6];

    void initializeShapes(); // To initialize the dimensions of the segments

public:
    HangManFigure(); // Constructor
    void setPosition(float offsetX, float offsetY); // Set position of the Hangman figure
    void draw(sf::RenderWindow& window); // Draw the hangman figure on the screen
    void addPart(); // To add a part (decrease life)
    void reset(); // Reset the hangman figure to its initial state
};



class LetterTracker
{
private:
    char correctLetters[26];   // 26 letters can be correct
    char incorrectLetters[10]; // Max 10 incorrect letters can be tracked
    int correctCount;
    int incorrectCount;



public:
    bool isLetterInArray(char letter, const char* array);
    LetterTracker(); // Constructor

    void trackCorrectLetter(const std::string& letter); // Track correct letters
    void trackIncorrectLetter(const std::string& letter); // Track incorrect letters

    void clear(); // Reset counts and arrays

    std::string getCorrectLetters(); // Get a string of correct letters
    std::string getIncorrectLetters(); // Get a string of incorrect letters
};




class WordCategory
{
private:
    std::string currentCategory;
    const char* wordsCar[7] = { "lamborghini", "ferrari", "pagani", "mercedes", "buggati", "toyota", "honda" };
    const char* wordsAnimal[7] = { "cat", "dog", "toad", "lion", "jaguar", "sheep", "human" };
    const char* wordsProgramming[7] = { "inheritance", "polymorphism", "abstraction", "composition", "encapsulation", "classes", "structures" };
    const char* randomWord;
    int randomIndex1;  // Category index
    int randomIndex2;  // Word index
    int* ptr;          // Pointer for random index

public:
    WordCategory(); // Constructor

    void setRandomWord(); // Set a random word from a random category

    std::string getRandomWord(); // Get the random word
    std::string getCategory();   // Get the current category
};








class HangmanGame : public Game
{
private:
    WordCategory wordCategory;
    HangManFigure hangmanFigure;
    LetterTracker letterTracker;
    std::string currentWord;
    int lives;
    int selectedOption;


    sf::Font font;
    sf::Font font2;
    sf::Text wordText;
    sf::Text incorrectGuessesText;
    sf::Text errorMessageText;
    sf::Text guessText;
    sf::Text welcomeText;
    sf::Text menuText[2];
    sf::Text hangmanText;
    sf::Text hintText;
    sf::Text scoreText;
    sf::Sprite pauseSprite;
    sf::Text pauseMessageText;
    sf::Texture pauseTexture;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    bool gameStarted;

    bool isPaused;
    sf::Text pauseText;

public:
    HangmanGame();

    void startGame(sf::RenderWindow& window) override;  // Implement the startGame method
    void run(sf::RenderWindow& window); // Add a run method to control the game loop
    void togglePause();
    void displayPauseText(sf::RenderWindow& window);

    void runSinglePlayerMode(sf::RenderWindow& window);
    void runTwoPlayerMode(sf::RenderWindow& window);
    void displayMessage(sf::RenderWindow& window, const std::string& message, const sf::Color& color);
    void guessLetter(const std::string& guess);
    void updateGuessText(const std::string& guess);
    void drawWord(sf::RenderWindow& window);
    void drawHangman(sf::RenderWindow& window);
    void updateLives();
    bool checkVictory();
    void updateIncorrectGuessesText();
    bool replayGame(sf::RenderWindow& window);
    void resetGame();

    void updateScoreText();
};











class MenuS
{
private:
    RenderWindow& window;
    Sprite Snake;
    Sprite backgroundSprite;
    Texture backgroundTexture;
    Texture snakeTexture;

    Sprite Instruction;
    Texture instructionTexture;
    Sprite Hard;
    Texture hardTexture;
    Sprite Normal;
    Texture normalTexture;
    Sprite Quit;
    Texture quitTexture;
    Sprite back;
    Texture backTexture;
    Sprite inst;
    Texture instTexture;

    Sprite over;
    Texture overTexture;

public:
    // Constructor that accepts the RenderWindow reference
    MenuS(RenderWindow& win);

    // Methods for displaying various parts of the menu
    void displayInstruction();
    void displayMenu();
    void gameOver();

    // Main method to handle menu interaction and return appropriate choices
    int show();
};



class GameUI
{
private:
    Font font;

    Text livesText;
    Text pauseText;
    Sprite heart;
    Texture heartTexture;

public:
    // Constructor
    GameUI();

    // Display method to render score, lives, and pause text
    void display(RenderWindow& window, int lives, bool isPaused);
};




class Grid
{
public:
    // Method to draw the grid
    void draw(RenderWindow& window);
};











class Snake {
private:
    RenderWindow& window;
    Sprite headSprite, tailSprite;
    Texture headTextureUp, headTextureDown, headTextureLeft, headTextureRight;
    Texture tailTextureUp, tailTextureDown, tailTextureLeft, tailTextureRight;

    const int segmentSize = 50;
    const int maxLength = 200;
    int bodyX[200], bodyY[200];
    int length;
    Vector2i direction;
    Vector2i lastDirection;
    Vector2i tailDirection;
    CircleShape bodySegment;
    bool isStarted = false;

public:
    // Constructor
    Snake(RenderWindow& win);

    // Restart the snake
    void restart();

    // Load textures for snake parts
    void loadTextures();

    // Handle input from the user
    void handleInput();

    // Update snake's position
    void update();

    // Draw the snake
    void draw();

    // Set the tail sprite based on direction
    void setTailSprite();

    // Getters
    int getHeadX() const;
    int getHeadY() const;
    int* getBodyX();
    int* getBodyY();

    // Grow the snake by one segment
    void grow();

    // Get the length of the snake
    int getLength() const;
};




class Food {
private:
    RenderWindow& window;
    Sprite foodSprite;
    Texture appleTexture;
    Texture mushroomTexture;
    int foodX, foodY;
    const int gridSize = 50;
    Snake& snake;
    int FoodType;

public:
    // Constructor
    Food(RenderWindow& win, Snake& snk);

    // Check if a given cell is occupied by the snake
    bool checkIfCellOccupiedBySnake(int x, int y);

    // Spawn food in a random location
    void spawnFood();

    // Check if the snake has collided with food
    bool checkCollision(int snakeX, int snakeY);

    // Draw the food
    void draw();

    // Get the position of the food
    Vector2i getPosition();

    // Get the type of food (apple or mushroom)
    int getFoodType();
};




class Collision
{
public:
    // Check if the snake's head collides with the walls of the grid
    bool checkWallCollision(int headX, int headY);

    // Check if the snake's head collides with its own body
    bool checkSelfCollision(int headX, int headY, int bodyX[], int bodyY[], int length);
};








class PowerUp
{
private:
    RenderWindow& window;
    Sprite powerUpSprite;
    Texture plusTexture;
    Texture minusTexture;
    int powerUpX, powerUpY;
    const int gridSize = 50;
    Clock powerUpClock;
    bool isActive;
    int powerUpType;
    Snake& snake;

public:
    // Constructor
    PowerUp(RenderWindow& win, Snake& snk);

    // Spawn a new power-up
    void spawnPowerUp(Vector2i food);

    // Check if the snake's head has collided with the power-up
    bool checkCollision(int snakeX, int snakeY);

    // Update the state of the power-up (e.g., expire after 5 seconds)
    void update();

    // Draw the power-up on the window
    void draw();

    // Check if a cell is occupied by the snake
    bool checkIfCellOccupiedBySnake(int x, int y);

    // Get the position of the power-up
    Vector2i getPosition();

    // Get the type of the power-up (plus or minus)
    int getPowerUpType();

    // Check if the power-up is active
    bool isPowerUpActive();
};





class SnakeGame : public Game
{
private:
    RenderWindow& window;
    Snake snake;
    Food food;
    PowerUp powerUp;
    int lives;
    bool isPaused;
    Grid grid;
    GameUI gameUI;
    Clock clock;
    float moveInterval;
    float elapsedTime;
    Collision collision;

    Clock powerUpSpawnClock;
    bool isPowerUpActive;
    int difficulty;
    MenuS menu;
    Text scoreText;
    Font font;

public:
    // Constructor
    SnakeGame(RenderWindow& win, const std::string& gameName = "Snake Game");
    void showPauseScreen();
    // Public methods
    void drawUI();
    void handleInput();
    void showGameOver();
    void run(); // Keep run in the header file
    void startGame(RenderWindow& window) override;  // Override startGame from Game class
};














class Dictionary
{
private:
    static const int MAX_WORDS = 10;         // Maximum number of valid words
    static const int WORD_LENGTH = 6;        // Max length of each word (5 letters + null terminator)
    char validWords[MAX_WORDS][WORD_LENGTH]; // Array to store valid words
    int wordCount;                           // Count of valid words

public:
    Dictionary(); // Constructor to initialize wordCount and load words

    // Function to load words into the dictionary (hardcoded for simplicity)
    void loadWords();

    // Check if a word exists in the dictionary
    bool isValidWord(const char* word);

    // Getter function to access valid words at a specific index
    const char* getValidWord(int index) const;

    // Getter function to return the number of words in the dictionary
    int getWordCount() const;

    // Getter function to return a random valid word
    const char* getRandomValidWord() const;
};






class Button
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    // Constructor to initialize the button with position, texture, and scale
    Button(float x, float y, const char* texturePath, float scaleX = 0.5f, float scaleY = 0.5f);

    // Method to draw the button
    void draw(sf::RenderWindow& window);

    // Method to check if the button is clicked
    bool isClicked(sf::Vector2i mousePos);
};




class WordDisplay
{
private:
    sf::Text letters[6];
    sf::Font font;

public:
    // Constructor to initialize letters
    WordDisplay();

    // Method to draw the word and set colors and positions
    void draw(sf::RenderWindow& window, bool inGame);
};



//class GameBoard; // Forward declaration of GameBoard class
namespace key {
    class Keyboard;  // Forward declaration
}

class GameBoard;  // Forward declaration

namespace key {

    class Keyboard
    {
    private:
        sf::Sprite keys[28];        // 26 letters + 1 backspace + 1 enter key
        sf::Texture textures[28];   // Corresponding textures
        sf::Text keyTexts[26];      // Text for displaying green/red letters
        sf::Font font;              // Font for colored letters
        char keyLetters[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
                               'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
                               'X', 'C', 'V', 'B', 'N', 'M' };

        enum KeyState { Default, Green, Red }; // Tracks key states
        KeyState keyStates[26] = { Default };  // Initialize all keys to default state

    public:
        // Constructor to initialize the keyboard keys and their states
        Keyboard(const char* keyPaths[26], float startX, float startY, float scale = 0.1f);

        // Method to draw the keyboard on the screen
        void draw(sf::RenderWindow& window);

        // Handle key click events
        void handleKeyClick(sf::Vector2i mousePos, GameBoard& gameBoard, bool& playerWon);

        // Update the key state (green/red)
        void updateKeyState(char letter, const std::string& state);
    };

}





class GameBoard {
private:
    char board[6][5]; // 6 rows for attempts, 5 columns for letters
    int currentRow = 0;
    int currentCol = 0;
    bool rowCompleted[6] = { false }; // Flag array to check if a row is completed
    Dictionary dictionary;          // Define dictionary object
    char secretWord[6];             // Secret word for the game
    int lives = 6;
    int score = 0;
    bool hintFilled[5] = { false }; // Tracks whether a position in the current row is filled by a hint

    // Hint image attributes
    sf::Texture hintTexture1;
    sf::Texture hintTexture2;
    sf::Sprite hintSprite1;
    sf::Sprite hintSprite2;

public:
    GameBoard();
    void loadSecretWord();
    void initializeHints(const std::string& hint1Path, const std::string& hint2Path, float x1, float y1, float scaleX1, float scaleY1, float x2, float y2, float scaleX2, float scaleY2);
    void handleHintClick(sf::Vector2i mousePos);
    void insertLetter(char letter);
    bool submitRow(key::Keyboard& keyboard);
    void draw(sf::RenderWindow& window);
    void resetCurrentRow();
    void deleteLastLetter();
    bool isWin() const;
    void decrementLives();
    int getLives() const;
    int getscore() const;
};






class WelcomeScreen
{
private:
    sf::Text welcomeText;
    sf::Text rulesButtonText; // Text for the "Rules" button
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    WelcomeScreen();

    void draw(sf::RenderWindow& window);
    bool isRulesClicked(const sf::Vector2i& mousePos) const;
};






class WordleGame : public Game  // Inherit from Game
{
private:
    sf::RenderWindow window;
    WordDisplay wordDisplay;
    GameBoard gameBoard;
    key::Keyboard keyboard;
    WelcomeScreen welcomeScreen;
    Button playButton;

    sf::Texture heartTexture;
    sf::Sprite hearts[6];
    sf::Texture loseTexture;
    sf::Sprite loseSprite;
    sf::Texture gameBackgroundTexture;  // Background texture for game screen
    sf::Sprite gameBackgroundSprite;    // Background sprite for game screen
    sf::Texture rulesTexture;           // Texture for the rules screen
    sf::Sprite rulesSprite;             // Sprite for the rules screen
    Text scoreText;

    bool isPaused = false;  // Track the pause state

    bool inGame;
    bool playerWon;
    bool showRules;
    sf::Clock clock;  // Clock to track the time since the win/lose screen is shown
    bool gameOverScreenShown = false;
    // Helper methods
    void initializeHearts(float loseX, float loseY, float loseScaleX, float loseScaleY);
    void processEvents();
    void render();

public:
    void showPauseScreen();


    WordleGame(const std::string& gameName = "Wordle Game");  // Constructor
    void startGame(sf::RenderWindow& window) override;       // Override startGame method from Game
    void run();
};



















