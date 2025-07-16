#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
#include<fstream>

using namespace std;
using namespace sf;


// Player class definitions
void Player::setName(const string& playerName)
{
    name = playerName;
}

string Player::getName() const
{
    return name;
}

void Player::addScore(int score)
{
    totalScore += score;
}

int Player::getScore() const
{
    return totalScore;
}

// Screen class definitions
void Screen::initWindow(const string& title, int width, int height)
{
    window.create(VideoMode(width, height), title);
}

RenderWindow& Screen::getWindow()
{
    return window;
}

void Screen::closeWindow()
{
    if (window.isOpen())
    {
        window.close();
    }
}

// SoundSystem class definitions
bool SoundSystem::loadSound(const string& filepath)
{
    if (!buffer.loadFromFile(filepath))
    {
        cout << "Failed to load sound from " << filepath << "\n";
        return false;
    }
    sound.setBuffer(buffer);
    return true;
}

void SoundSystem::playSound()
{
    sound.play();
}
void SoundSystem::setVolume(int volume) 
{

    sound.setVolume(static_cast<float>(volume));
}
Menu::Menu()
{


    playSnakeTexture.loadFromFile("assets/playsnake.png");
    playWordleTexture.loadFromFile("assets/playwordle.png");
    playHangmanTexture.loadFromFile("assets/playhangman.png");
    exitTexture.loadFromFile("assets/exit.png");
    gameTexture.loadFromFile("assets/gamezone.png");
    achTexture.loadFromFile("assets/ach.png");
    Ach.setTexture(achTexture);
    Ach.setPosition(850, 350);


    settingTexture.loadFromFile("assets/settings.png");

    goldtexture.loadFromFile("assets/gold.png");
    silvertexture.loadFromFile("assets/silver.png");
    bronzetexture.loadFromFile("assets/bronze.png");
    gold.setTexture(goldtexture);
    silver.setTexture(silvertexture);
    bronze.setTexture(bronzetexture);

    gold.setPosition(900, 100);
    silver.setPosition(900, 150);
    bronze.setPosition(900, 200);

    playSnakeButton.setTexture(playSnakeTexture);
    playWordleButton.setTexture(playWordleTexture);
    playHangmanButton.setTexture(playHangmanTexture);
    exitButton.setTexture(exitTexture);

    Settings.setTexture(settingTexture);
    Settings.setPosition(50, 300);
 
    gameSprite.setTexture(gameTexture);
    gameSprite.setPosition(300, 100);
    playSnakeButton.setPosition(50, -20);
    playWordleButton.setPosition(750, -20);
    playHangmanButton.setPosition(50, 500);
    exitButton.setPosition(750, 500);
    backgroundTexture.loadFromFile("assets/backgroundimage.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);


    if (!font.loadFromFile("assets/Bodoni MT Black.ttf"))
    {
        cout << "Failed to load font.\n";
        exit(1);
    }

    promptText.setFont(font);
    promptText.setString("Enter your name: ");
    promptText.setCharacterSize(60);
    promptText.setFillColor(Color::Black);
    promptText.setPosition(70, 650);
    promptText.setOutlineThickness(3);
    promptText.setOutlineColor(Color::Green);

    welcomeTexture.loadFromFile("assets/welcome.png");
    welcome.setTexture(welcomeTexture);
    welcome.setPosition(200, -110);


    gamepng.loadFromFile("assets/game.png");
    game.setTexture(gamepng);
    game.setPosition(400, 230);

    userNameText.setFont(font);
    userNameText.setCharacterSize(60);
    userNameText.setFillColor(Color::Black);
    userNameText.setPosition(620, 650);
    userNameText.setOutlineThickness(3);
    userNameText.setOutlineColor(Color::Yellow);

    wel.setFont(font);
    wel.setCharacterSize(60);
    wel.setString("Welcome ");
    wel.setFillColor(Color::Black);
    wel.setOutlineThickness(3);
    wel.setPosition(100, 0);
    wel.setOutlineColor(Color::Red);

    songPrompt.setFont(font);
    songPrompt.setCharacterSize(60);
    songPrompt.setString("Press 1,2,3,4 to choose ");
    songPrompt.setFillColor(Color::Black);
    songPrompt.setOutlineThickness(3);
    songPrompt.setPosition(100, 0);
    songPrompt.setOutlineColor(Color::Red);

    song1.setFont(font);
    song1.setCharacterSize(60);
    song1.setString("1.Travis Scott - FE!N");
    song1.setFillColor(Color::Black);
    song1.setOutlineThickness(3);
    song1.setPosition(100, 100);
    song1.setOutlineColor(Color::Red);

    song2.setFont(font);
    song2.setCharacterSize(60);
    song2.setString("2.Kar Har Maidaan Fateh");
    song2.setFillColor(Color::Black);
    song2.setOutlineThickness(3);
    song2.setPosition(100, 200);
    song2.setOutlineColor(Color::Red);

    song3.setFont(font);
    song3.setCharacterSize(60);
    song3.setString("3.Believer");
    song3.setFillColor(Color::Black);
    song3.setOutlineThickness(3);
    song3.setPosition(100, 300);
    song3.setOutlineColor(Color::Red);

    back.setFont(font);
    back.setCharacterSize(60);
    back.setString("Press ESC for MAIN MENU");
    back.setFillColor(Color::Black);
    back.setOutlineThickness(3);
    back.setPosition(100, 700);
    back.setOutlineColor(Color::Magenta);

    control.setFont(font);
    control.setCharacterSize(60);
    control.setString("Use + ,- for Volume Control");
    control.setFillColor(Color::Black);
    control.setOutlineThickness(3);
    control.setPosition(100, 500);
    control.setOutlineColor(Color::Green);

    control1.setFont(font);
    control1.setCharacterSize(60);
    control1.setString("Name , Score , Game Played");
    control1.setFillColor(Color::Black);
    control1.setOutlineThickness(3);
    control1.setPosition(50, 0);
    control1.setOutlineColor(Color::Green);

    menuWindow.create(VideoMode(1200, 800), "Game Hub Menu");
}

void Menu::close() {
        if (menuWindow.isOpen())
    {
        menuWindow.close();
		}
}
void Menu::displayAchievements() 
{
    menuWindow.clear();
    menuWindow.draw(backgroundSprite);
    menuWindow.draw(control1);
    menuWindow.draw(back);
    menuWindow.draw(gold);
    menuWindow.draw(silver);
    menuWindow.draw(bronze);

    ifstream file("sorted_scores.txt");
    if (!file.is_open()) 
    {
       cout << "Error: Could not open sortedscore.txt" << endl;
        return;
    }

    const int maxRows = 10;
    string scores[maxRows]; 
    int count = 0;

    while (count < maxRows && std::getline(file, scores[count]))
    {
        count++;
    }

    file.close();

    sf::Font font;
    if (!font.loadFromFile("assets/Bodoni MT Black.ttf"))
    {
        cout << "Error: Could not load font" << endl;
        return;
    }

    for (int i = 0; i < count; i++) 
    {
        sf::Text scoreText(scores[i], font, 60); 
        scoreText.setPosition(50, 80 + i * 50);

        userNameText.setFillColor(Color::Black);
        userNameText.setOutlineThickness(3);
        userNameText.setOutlineColor(Color::Yellow);
        menuWindow.draw(scoreText);
    }

    menuWindow.display();
}

void Menu::getUserName()                                                        //
{                                                                               //
    userName.clear(); // To remove any previous input                           //
    //
    while (menuWindow.isOpen())                                                 //
    {                                                                           //
        Event event;                                                            //
        while (menuWindow.pollEvent(event))                                     //
        {                                                                       //
            if (event.type == Event::Closed)                                    //
            {                                                                   //
                menuWindow.close();                                             //
                exit(0);                                                        //
            }                                                                   //
                                                                                //
            if (event.type == Event::TextEntered)                               //
            {                                                                   //
                     //For backspace                                            //
                if (event.text.unicode == '\b' && !userName.empty())            //
                {                                                               //
                                                                                //
                    userName.pop_back();                                        //
                }                                                               //////
                else if (event.text.unicode == '\r' || event.text.unicode == '\n')  //  
                {                                                                   //
                                                                                    //
                    saveUserNameToFile(); // Save the username when Enter is pressed//  
                    return;                                                         //
                }                                                                   //
                else if (event.text.unicode < 128)                                  //
                {                                                                   //
                       //Append characters to username                              //
                    userName += static_cast<char>(event.text.unicode);              //
                }                                                                   //
            }                                                                       //
        }                                                                           //
                                                                                    //
                                                                                    //
        userNameText.setString(userName);                                           //
        //
//To create the menu                                                      //
        menuWindow.clear();                                                         //
        menuWindow.draw(backgroundSprite);                                          //
        menuWindow.draw(promptText);                                                //
        menuWindow.draw(userNameText);                                              //
        menuWindow.draw(welcome);                                                   //
        menuWindow.draw(game);                                                      //
        menuWindow.display();                                                       //
    }                                                                               //
}

void Menu::saveUserNameToFile()
{
    ofstream outFile("scores.txt", ios::app);

    if (!outFile.is_open())
    {
        cout << "Unable to open file for writing!" << endl;
        return;  
    }

    outFile << userName << " : "; 
    outFile.close();
}

void Menu::saveScore(int score)
{
    ofstream outFile("scores.txt", ios::app);

    if (!outFile.is_open()) 
    {
        cout << "Unable to open file for writing!" << endl;
        return; 
    }

    outFile << score; 
    outFile.close();



}
RenderWindow& Menu::getWindow()
{
    return menuWindow;
}
int Menu::display()
{

    while (menuWindow.isOpen())
    {
        Event event;
        while (menuWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                menuWindow.close();
                return 4;
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);


                
                if (playSnakeButton.getGlobalBounds().contains(mousePos))
                    return 2; // Play Snake
                else if (playWordleButton.getGlobalBounds().contains(mousePos))
                    return 3; // Play Wordle
                else if (playHangmanButton.getGlobalBounds().contains(mousePos))
                    return 1; // Play Hangman
                else if (exitButton.getGlobalBounds().contains(mousePos))
                    return 4;


                else if (Settings.getGlobalBounds().contains(mousePos))
                {

                    return 5;
                }
                else if (Ach.getGlobalBounds().contains(mousePos)) 
                {

                    return 6;
                }


            }
        }


        menuWindow.clear();
        menuWindow.draw(backgroundSprite);
        menuWindow.draw(playSnakeButton);
        menuWindow.draw(playWordleButton);
        menuWindow.draw(gameSprite);
        menuWindow.draw(playHangmanButton);

        userNameText.setPosition(450, 0);
        userNameText.setOutlineColor(Color::Magenta);
        wel.setOutlineColor(Color::Magenta);
        wel.setCharacterSize(70);
        userNameText.setCharacterSize(70);
        menuWindow.draw(Settings);
        menuWindow.draw(userNameText);
        menuWindow.draw(wel);
        menuWindow.draw(exitButton);
        menuWindow.draw(Ach);
        menuWindow.display();

    }

    return 4;
}

void Menu::displaySettings()
{
   
    int volume = 50;

    while (menuWindow.isOpen()) 
    {
        
        menuWindow.clear();
        menuWindow.draw(backgroundSprite);
        menuWindow.draw(songPrompt);
        menuWindow.draw(song1);
        menuWindow.draw(song2);
        menuWindow.draw(song3);
        menuWindow.draw(back);
        menuWindow.draw(control);

       
        string volumeText = "Volume: " + to_string(volume);
        Text volumeDisplay(volumeText, font, 20);


        volumeDisplay.setCharacterSize(60);

        volumeDisplay.setFillColor(Color::Black);
        volumeDisplay.setOutlineThickness(3);
        volumeDisplay.setPosition(300, 400);
        volumeDisplay.setOutlineColor(Color::Red);
        menuWindow.draw(volumeDisplay);
        menuWindow.display();

       
        sf::Event event;
        while (menuWindow.pollEvent(event)) 
        {
           
            if (event.type == sf::Event::Closed) 
            {
                menuWindow.close();
            }

            
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Num1:
                    cout << "Song 1 selected!" << endl;
                    soundSystem.loadSound("assets/1.ogg");
                    soundSystem.playSound();

                    break;
                case sf::Keyboard::Num2:
                    cout << "Song 2 selected!" << endl;
                    soundSystem.loadSound("assets/2.ogg");
                    soundSystem.playSound();
                    break;
                case sf::Keyboard::Num3:
                    cout << "Song 3 selected!" << endl;
                    soundSystem.loadSound("assets/3.ogg");
                    soundSystem.playSound();
                    break;

                case sf::Keyboard::Escape:
                    cout << "Exiting settings!" << endl;
                    return; 
                    break;
                case sf::Keyboard::Equal: // "+" key
                    if (volume < 100) {
                        volume += 5; // Increase volume by 5
                        cout << "Volume increased to " << volume << endl;
                        // Update volume in SoundSystem
                        soundSystem.setVolume(volume);
                    }
                    break;
                case sf::Keyboard::Dash: // "-" key
                    if (volume > 0) {
                        volume -= 5; // Decrease volume by 5
                        cout << "Volume decreased to " << volume << endl;
                        soundSystem.setVolume(volume);
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
}


void Menu::displaySortedScores()
{
   
    ifstream inFile("scores.txt");
    if (!inFile.is_open())
    {
        cout << "Unable to open scores file!" << endl;
        return;
    }

    const int MAX_ENTRIES = 100;  
    string names[MAX_ENTRIES];
    int scores[MAX_ENTRIES];      
    string games[MAX_ENTRIES];
    int count = 0; 

    string line;
    while (getline(inFile, line) && count < MAX_ENTRIES)
    {
        
        size_t colonPos = line.find(":"); 
        size_t gameStartPos = line.find("(");  
        size_t gameEndPos = line.find(")");  

        if (colonPos != string::npos && gameStartPos != string::npos && gameEndPos != string::npos)
        {
            names[count] = line.substr(0, colonPos);

           
            scores[count] = stoi(line.substr(colonPos + 2, gameStartPos - (colonPos + 2))); 

           
            games[count] = line.substr(gameStartPos + 1, gameEndPos - (gameStartPos + 1));

            count++;
        }
    }
    inFile.close();

  
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - 1 - i; ++j)
        {
            if (scores[j] < scores[j + 1])
            {
                // Swap scores
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                // Swap corresponding names
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;

                // Swap corresponding game names
                string tempGame = games[j];
                games[j] = games[j + 1];
                games[j + 1] = tempGame;
            }
        }
    }

   
   ofstream outFile("sorted_scores.txt");
    if (!outFile.is_open())
    {
        cout << "Unable to open file for writing!" << endl;
        return;
    }

    
    for (int i = 0; i < count; ++i)
    {
        outFile << names[i] << " : " << scores[i] << " (" << games[i] << ")" << endl;
    }

    outFile.close();

   
    cout << "Top Scores (Sorted):\n";
    for (int i = 0; i < count; ++i)
    {
       cout << names[i] << " : " << scores[i] << " (" << games[i] << ")" << endl;
    }
}











// Game class definition
Game::Game(const string& gameName) : name(gameName), score(0) {}

void Game::setScore(int newScore)
{
    score = newScore;
}

int Game::getScore() const
{
    return score;
}

// GameBoy class definitions
GameBoy::GameBoy() : isRunning(true) {}

void GameBoy::start()
{
    bool isSettings = false; // Track whether we are in the settings menu
    bool isAchievements = false; // Track whether we are in the achievements menu

    RenderWindow& window = menu.getWindow();

    menu.getUserName();

    while (window.isOpen())
    {
        int choice = -1; // Default invalid choice

        if (!isSettings && !isAchievements) {
           
            choice = menu.display();
        }

       
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (isSettings) {
            
            menu.displaySettings();

           
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                isSettings = false; // Exit settings menu
            }
        }
        else if (isAchievements) {
            // Display achievements menu
            menu.displayAchievements();

            // Logic to exit achievements menu
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                isAchievements = false; // Exit achievements menu
            }
        }
        else {

            switch (choice)
            {
            case 1:
                playHangman();
                appendGameNameToScoreFile("Hangman");
                break;
            case 2:
                playSnake();
                appendGameNameToScoreFile("Snake");
                break;
            case 3:
                playWordle();
                appendGameNameToScoreFile("Wordle");
                break;
            case 4:
                window.close();
                shutdown();

                break;
            case 5:
                isSettings = true; // Enter settings menu
                break;
            case 6:
                isAchievements = true; // Enter achievements menu
                break;

            default:
                break;
            }
        }
    }
}



void GameBoy::appendGameNameToScoreFile(const string& gameName)
{
    
    ifstream inFile("scores.txt");
    string line;
    string lastLine;

   
    while (getline(inFile, line))
    {
        lastLine = line;
    }

   
    inFile.close();

   
    ofstream outFile("scores.txt", ios::app);

    if (!outFile.is_open())
    {
        cout << "Unable to open file for writing!" << endl;
        return; 
    }

   
    if (!lastLine.empty())
    {
        outFile.seekp(-static_cast<int>(lastLine.length()), ios::end); 
        outFile << " (" << gameName << ")" << endl;  // Append the game name in brackets
    }

    outFile.close();  // Close the file after writing
    Menu menu;
    menu.displaySortedScores();
    //  menu.displaySortedScores();
}

void GameBoy::playHangman()
{
    HangmanGame hangman; 
    screen.initWindow("Hangman Game", 800, 600);
    hangman.startGame(screen.getWindow());
    screen.closeWindow();
}

void GameBoy::playSnake()
{
    screen.initWindow("Snake Game", 1300, 900);
    SnakeGame snake(screen.getWindow()); 
    snake.run();                         // SnakeGame's specific function
    screen.closeWindow();
}

void GameBoy::playWordle()
{
    WordleGame wordle; 
    wordle.run();      // This will handle the game loop and render the window
}

void GameBoy::shutdown()
{
    isRunning = false;
    cout << "Thanks for playing! Goodbye!\n";
   
}

















void HangManFigure::initializeShapes() // To initialize the dimensions of the segments
{
    head.setRadius(20);
    head.setFillColor(sf::Color::Transparent);
    head.setOutlineColor(sf::Color::Black);
    head.setOutlineThickness(5);

    body.setSize(sf::Vector2f(5, 75));
    body.setFillColor(sf::Color::Black);

    leftArm.setSize(sf::Vector2f(5, 33));
    leftArm.setFillColor(sf::Color::Black);

    rightArm.setSize(sf::Vector2f(5, 33));
    rightArm.setFillColor(sf::Color::Black);

    leftLeg.setSize(sf::Vector2f(5, 33));
    leftLeg.setFillColor(sf::Color::Black);

    rightLeg.setSize(sf::Vector2f(5, 33));
    rightLeg.setFillColor(sf::Color::Black);

    gallowsBase.setSize(sf::Vector2f(200, 10));
    gallowsBase.setFillColor(sf::Color::Black);

    gallowsPole.setSize(sf::Vector2f(10, 265));
    gallowsPole.setFillColor(sf::Color::Black);

    gallowsBeam.setSize(sf::Vector2f(200, 10));
    gallowsBeam.setFillColor(sf::Color::Black);

    rope.setSize(sf::Vector2f(5, 50));
    rope.setFillColor(sf::Color::Black);

    if (!heartT.loadFromFile("assets/heart1-.png"))
    {
        cout << "Error loading background image!" << endl;
    }
}

HangManFigure::HangManFigure() : parts(6) // Constructor initializing parts to 6
{
    initializeShapes();
}

void HangManFigure::setPosition(float offsetX, float offsetY) // Using an offset to set position of hangman
{
   
    gallowsBase.setPosition(offsetX - 410, offsetY + 50);
    gallowsPole.setPosition(offsetX - 410, offsetY - 210);
    gallowsBeam.setPosition(offsetX - 400, offsetY - 210);
    rope.setPosition(offsetX - 300, offsetY - 210);

    // Position the parts of the hangman
    head.setPosition(offsetX - 317, offsetY - 158);
    body.setPosition(offsetX - 300, offsetY - 115);

    leftArm.setPosition(offsetX - 300, offsetY - 90);
    leftArm.setRotation(135);

    rightArm.setPosition(offsetX - 270, offsetY - 115);
    rightArm.setRotation(45);

    leftLeg.setPosition(offsetX - 270, offsetY - 15);
    leftLeg.setRotation(135);

    rightLeg.setPosition(offsetX - 340, offsetY - 120);
    rightLeg.setRotation(45);
}

void HangManFigure::draw(sf::RenderWindow& window) // Function to draw the structure of the hangman
{
    window.draw(gallowsBase);
    window.draw(gallowsPole);
    window.draw(gallowsBeam);
    window.draw(rope);

    // Draw parts of the hangman depending on the number of parts remaining
    if (parts <= 5) window.draw(head);
    if (parts <= 4) window.draw(body);
    if (parts <= 3) window.draw(leftArm);
    if (parts <= 2) window.draw(rightArm);
    if (parts <= 1) window.draw(leftLeg);
    if (parts == 0) window.draw(rightLeg);

    // Draw hearts based on remaining parts (lives)
    int lives = parts;
    for (int i = 0; i < lives; i++) // Setting hearts dependent on the number of parts drawn
    {
        hearts[i].setTexture(heartT);
        hearts[i].setPosition(700, 50 + (50 * i));
        window.draw(hearts[i]);
    }
}

void HangManFigure::addPart() // To add a part (decrease life)
{
    if (parts > 0)
        parts--;
}

void HangManFigure::reset() // If user wants to play again
{
    parts = 6;
}





LetterTracker::LetterTracker() : correctCount(0), incorrectCount(0)
{
    // Initialize arrays with null characters
    for (int i = 0; i < 26; ++i) correctLetters[i] = '\0';
    for (int i = 0; i < 10; ++i) incorrectLetters[i] = '\0';
}

void LetterTracker::trackCorrectLetter(const string& letter)
{
    if (letter.size() == 1 && !isLetterInArray(letter[0], correctLetters))
    {
        correctLetters[correctCount++] = letter[0];
    }
}

void LetterTracker::trackIncorrectLetter(const string& letter)
{
    if (letter.size() == 1 && !isLetterInArray(letter[0], incorrectLetters))
    {
        incorrectLetters[incorrectCount++] = letter[0];
    }
}

bool LetterTracker::isLetterInArray(char letter, const char* array)
{
    for (int i = 0; i < 26; ++i)
    {
        if (array[i] == letter) return true;
        if (array[i] == '\0') break;
    }
    return false;
}

void LetterTracker::clear()
{
    correctCount = 0;
    incorrectCount = 0;
    // Reset arrays
    for (int i = 0; i < 26; ++i) correctLetters[i] = '\0';
    for (int i = 0; i < 10; ++i) incorrectLetters[i] = '\0';
}

string LetterTracker::getCorrectLetters()
{
    return string(correctLetters, correctCount);
}

string LetterTracker::getIncorrectLetters()
{
    return string(incorrectLetters, incorrectCount);
}





WordCategory::WordCategory() : randomWord(nullptr), currentCategory(""), randomIndex1(3), randomIndex2(1), ptr(&randomIndex1)
{
    srand(static_cast<unsigned int>(time(0))); // Initialize random number
}

void WordCategory::setRandomWord()
{
    randomIndex1 = rand() % 3 + 1; // Random category (1: Cars, 2: Animals, 3: Programming)
    randomIndex2 = rand() % 7;     // Random word within the category

    if (randomIndex1 == 1)
    {
        randomWord = wordsCar[randomIndex2];
        currentCategory = "cars";
    }
    else if (randomIndex1 == 2)
    {
        randomWord = wordsAnimal[randomIndex2];
        currentCategory = "animals";
    }
    else if (randomIndex1 == 3)
    {
        randomWord = wordsProgramming[randomIndex2];
        currentCategory = "programming";
    }
}

string WordCategory::getRandomWord()
{
    return randomWord;
}

string WordCategory::getCategory()
{
    return currentCategory;
}















HangmanGame::HangmanGame() : Game("Hangman"), lives(6), selectedOption(0), gameStarted(false), isPaused(false)
{
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        cout << "Error loading font!" << endl;
    }

    if (!font2.loadFromFile("assets/sewer.ttf"))
    {
        cout << "Error loading font!" << endl;
    }

    if (!backgroundTexture.loadFromFile("assets/bk1.jpg"))
    {
        cout << "Error loading background image!" << endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(static_cast<float>(800) / backgroundTexture.getSize().x,
        static_cast<float>(600) / backgroundTexture.getSize().y);

    if (!pauseTexture.loadFromFile("assets/PAUSE.png"))
    {
        cout << "Error loading PAUSE.png!" << std::endl;
    }
    pauseSprite.setTexture(pauseTexture);

    pauseMessageText.setFont(font);
    pauseMessageText.setString("PRESS (Spacebar) TO CONTINUE");
    pauseMessageText.setCharacterSize(30);
    pauseMessageText.setFillColor(sf::Color::Red);
    pauseMessageText.setPosition(150, 300);


    wordText.setFont(font);
    wordText.setCharacterSize(30);
    wordText.setFillColor(sf::Color::White);
    wordText.setPosition(100, 100);

    incorrectGuessesText.setFont(font);
    incorrectGuessesText.setCharacterSize(24);
    incorrectGuessesText.setFillColor(sf::Color::White);
    incorrectGuessesText.setPosition(400, 200);

    errorMessageText.setFont(font);
    errorMessageText.setCharacterSize(24);
    errorMessageText.setFillColor(sf::Color::White);
    errorMessageText.setPosition(400, 150);

    welcomeText.setFont(font2);
    welcomeText.setCharacterSize(40);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setString("Welcome to Hangman\nChoose Your Mode");
    welcomeText.setPosition(150, 100);

    menuText[0].setFont(font);
    menuText[0].setCharacterSize(30);
    menuText[0].setFillColor(sf::Color::White);
    menuText[0].setString("1 Player");
    menuText[0].setPosition(250, 200);

    menuText[1].setFont(font);
    menuText[1].setCharacterSize(30);
    menuText[1].setFillColor(sf::Color::White);
    menuText[1].setString("2 Player");
    menuText[1].setPosition(250, 250);

    hangmanText.setFont(font2);
    hangmanText.setCharacterSize(30);
    hangmanText.setFillColor(sf::Color::Black);
    hangmanText.setString("HANGMAN, DARE TO PLAY!!!");
    hangmanText.setPosition(150, 50);

    hintText.setFont(font);
    hintText.setCharacterSize(24);
    hintText.setFillColor(sf::Color::Yellow);
    hintText.setPosition(250, 250);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(0, 10);

}

void HangmanGame::startGame(sf::RenderWindow& window)
{
    do
    {
        gameStarted = 0;
        selectedOption = 0;

        while (!gameStarted)
        {
            window.clear();
            window.draw(backgroundSprite);
            window.draw(welcomeText);
            window.draw(menuText[0]);
            window.draw(menuText[1]);
            window.draw(hangmanText);

            window.display();

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return;
                }

                if (event.type == sf::Event::MouseMoved)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (menuText[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        menuText[0].setFillColor(sf::Color::Green);
                        menuText[1].setFillColor(sf::Color::White);
                    }
                    else if (menuText[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        menuText[1].setFillColor(sf::Color::Green);
                        menuText[0].setFillColor(sf::Color::White);
                    }
                    else
                    {
                        menuText[0].setFillColor(sf::Color::Yellow);
                        menuText[1].setFillColor(sf::Color::White);
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (menuText[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) //collision 
                    {
                        selectedOption = 0;
                    }
                    else if (menuText[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                    {
                        selectedOption = 1;
                    }

                    gameStarted = true;
                }
            }
        }

        if (selectedOption == 0)
        {
            runSinglePlayerMode(window);
        }
        else if (selectedOption == 1)
        {
            runTwoPlayerMode(window);
        }

    } while (replayGame(window));
}

void HangmanGame::runSinglePlayerMode(sf::RenderWindow& window)
{
    resetGame();
    wordCategory.setRandomWord();
    currentWord = wordCategory.getRandomWord();
    string category = wordCategory.getCategory(); // Get the current category

    // Set the hint text based on the category
    hintText.setString("Hint: Category is " + category);
    scoreText.setString("Score: " + to_string(score)); 
    letterTracker.clear();
    hangmanFigure.setPosition(500, 400);

    while (lives > 0 && !checkVictory())
    {
        if (isPaused)  // Pause check
        {
            window.clear();
            // Centering PAUSE image
            pauseSprite.setPosition(
                window.getSize().x / 2 - pauseSprite.getGlobalBounds().width / 2,
                window.getSize().y / 2 - pauseSprite.getGlobalBounds().height / 2
            );
            window.draw(pauseSprite);  // Draw the PAUSE.png image

            // Centering pause message below the PAUSE image
            pauseMessageText.setPosition(
                window.getSize().x / 2 - pauseMessageText.getGlobalBounds().width / 2,
                window.getSize().y / 2 + pauseSprite.getGlobalBounds().height / 2 + 10
            );
            window.draw(pauseMessageText);  // Draw the pause message
            window.display();

            
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                {
                    isPaused = false;  // Resume the game
                }
            }
            continue;  // Skip game logic while paused
        }

        window.clear();
        window.draw(backgroundSprite);
        drawHangman(window);
        drawWord(window);
        window.draw(incorrectGuessesText);
        window.draw(errorMessageText);
        window.draw(hintText);
        window.draw(scoreText);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode >= 32 && event.text.unicode <= 126)
                {
                    string guess(1, static_cast<char>(event.text.unicode));
                    guessLetter(guess);
                    updateLives();
                }
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space && !isPaused)
                {
                    isPaused = true;  
                }
            }
        }

        window.display();
    }

    
    string message = (lives == 0) ? "You lost! The word was: " + currentWord : "Congrats! You won!";
    displayMessage(window, message, sf::Color::Cyan);

    
    Menu menu;  
    menu.saveScore(score);  // Save the score
    menu.close();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
        }

    }
}



void HangmanGame::runTwoPlayerMode(sf::RenderWindow& window)
{
    resetGame();
    bool enteringWord = true;
    string inputBuffer;

    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(30);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(50, 200);

    sf::Text instructionText;
    instructionText.setFont(font2);
    instructionText.setCharacterSize(24);
    instructionText.setFillColor(sf::Color::Black);
    instructionText.setString("Player 1, enter a word for Player 2 to guess");
    instructionText.setPosition(50, 150);

    hangmanFigure.setPosition(500, 400);

    while (enteringWord)
    {
        if (isPaused)  // Pause check
        {
            window.clear();
            // Centering PAUSE image
            pauseSprite.setPosition(
                window.getSize().x / 2 - pauseSprite.getGlobalBounds().width / 2,
                window.getSize().y / 2 - pauseSprite.getGlobalBounds().height / 2
            );
            window.draw(pauseSprite);  // Draw the PAUSE.png image

            // Centering pause message below the PAUSE image
            pauseMessageText.setPosition(
                window.getSize().x / 2 - pauseMessageText.getGlobalBounds().width / 2,
                window.getSize().y / 2 + pauseSprite.getGlobalBounds().height / 2 + 10 
            );
            window.draw(pauseMessageText);  // Draw the pause message
            window.display();

            // Wait for Spacebar press to continue
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                {
                    isPaused = false;  // Resume the game
                }
            }
            continue;  // Skip game logic while paused
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(instructionText);

        inputText.setString(inputBuffer);
        window.draw(inputText);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode >= 32 && event.text.unicode <= 126)
                {
                    inputBuffer += static_cast<char>(event.text.unicode);
                }
                else if (event.text.unicode == 8 && !inputBuffer.empty())
                {
                    inputBuffer.pop_back();
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            {
                if (!inputBuffer.empty())
                {
                    currentWord = inputBuffer;
                    enteringWord = false;
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                isPaused = true;  
            }
        }

        window.display();
    }

    letterTracker.clear();

    while (lives > 0 && !checkVictory())
    {
        if (isPaused)  // Pause check
        {
            window.clear();
            // Centering PAUSE image
            pauseSprite.setPosition(
                window.getSize().x / 2 - pauseSprite.getGlobalBounds().width / 2,
                window.getSize().y / 2 - pauseSprite.getGlobalBounds().height / 2
            );
            window.draw(pauseSprite);  // Draw the PAUSE.png image

            // Centering pause message below the PAUSE image
            pauseMessageText.setPosition(
                window.getSize().x / 2 - pauseMessageText.getGlobalBounds().width / 2,
                window.getSize().y / 2 + pauseSprite.getGlobalBounds().height / 2 + 10 // 10px margin below the image
            );
            window.draw(pauseMessageText);  // Draw the pause message
            window.display();

            // Wait for Spacebar press to continue
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                {
                    isPaused = false;  // Resume the game
                }
            }
            continue;  // Skip game logic while paused
        }

        window.clear();
        window.draw(backgroundSprite);
        drawHangman(window);
        drawWord(window);
        window.draw(incorrectGuessesText);
        window.draw(errorMessageText);
        window.draw(hintText);
        window.draw(scoreText);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode >= 32 && event.text.unicode <= 126)
                {
                    string guess(1, static_cast<char>(event.text.unicode));
                    guessLetter(guess);
                    updateLives();
                }
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space && !isPaused)
                {
                    isPaused = true;  // Pause the game when Spacebar is pressed, but only if not paused already
                }
                else if (event.key.code != sf::Keyboard::Space) // Ensure Spacebar is not counted as a guess
                {
                    string guess(1, static_cast<char>(event.key.code));
                    guessLetter(guess); // Handle other key presses as guesses
                }
            }
        }

        window.display();
    }

  
    string message = (lives == 0) ? "Player 2 lost! The word was: " + currentWord : "Player 2 wins!";
    displayMessage(window, message, sf::Color::Cyan);

    
    Menu menu;  
    menu.saveScore(score);  
    menu.close();

    // Wait for the window to close
   
    // Wait for the window to close
  while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
        }
     
  }
}



void HangmanGame::togglePause()
{
    isPaused = !isPaused;
}



void HangmanGame::displayPauseText(sf::RenderWindow& window)
{
    pauseText.setFont(font);
    pauseText.setString("Game Paused - Press P to Resume");
    pauseText.setCharacterSize(30);
    pauseText.setFillColor(sf::Color::Red);
    pauseText.setPosition(window.getSize().x / 2 - pauseText.getGlobalBounds().width / 2, window.getSize().y / 2 - pauseText.getGlobalBounds().height / 2);

    window.draw(pauseText);
}



void HangmanGame::displayMessage(sf::RenderWindow& window, const string& message, const sf::Color& color)
{
    sf::Text msgText;
    msgText.setFont(font);
    msgText.setString(message + "\nClose the window to exit.");
    msgText.setCharacterSize(30);
    msgText.setFillColor(color);
    msgText.setPosition(100, 250);

    window.clear();
    window.draw(backgroundSprite);
    window.draw(msgText);
    window.display();
}

void HangmanGame::guessLetter(const string& guess)
{
    errorMessageText.setString("");

    if (guess.size() != 1 || !isalpha(guess[0]))
    {
        errorMessageText.setString("Invalid input! Please guess a single letter.");
        return;
    }

    char letter = tolower(guess[0]);

    if (letterTracker.isLetterInArray(letter, letterTracker.getCorrectLetters().c_str()) ||
        letterTracker.isLetterInArray(letter, letterTracker.getIncorrectLetters().c_str()))
    {
        errorMessageText.setString("Letter already guessed!");
        return;
    }

    if (currentWord.find(letter) != string::npos)
    {
        letterTracker.trackCorrectLetter(string(1, letter));
        score = score + 100;
    }
    else
    {
        letterTracker.trackIncorrectLetter(string(1, letter));
        hangmanFigure.addPart();
        updateIncorrectGuessesText();
        score = score - 50;
    }

    updateScoreText();
    updateGuessText(guess);
}

void HangmanGame::updateGuessText(const string& guess)
{
    guessText.setString("Last Guess: " + guess);
}

void HangmanGame::drawWord(sf::RenderWindow& window)
{
    string displayWord = "";
    for (char c : currentWord)
    {
        if (letterTracker.isLetterInArray(c, letterTracker.getCorrectLetters().c_str()))
        {
            displayWord += c;
        }
        else
        {
            displayWord += "_";
        }
        displayWord += " ";
    }
    wordText.setString(displayWord);
    wordText.setPosition(450, 475);
    window.draw(wordText);
}

void HangmanGame::drawHangman(sf::RenderWindow& window)
{
    hangmanFigure.draw(window);
}

void HangmanGame::updateLives()
{
    lives = 6 - letterTracker.getIncorrectLetters().length();
}

bool HangmanGame::checkVictory()
{
    string correctGuesses = letterTracker.getCorrectLetters();
    for (char c : currentWord)
    {
        if (correctGuesses.find(c) == string::npos)
        {
            return false;
        }
    }
    return true;
}

void HangmanGame::updateIncorrectGuessesText()
{
    string incorrectGuesses = "Incorrect guesses: " + letterTracker.getIncorrectLetters();
    incorrectGuessesText.setString(incorrectGuesses);
}

bool HangmanGame::replayGame(sf::RenderWindow& window)
{
    sf::Text replayText;
    replayText.setFont(font);
    replayText.setCharacterSize(30);
    replayText.setFillColor(sf::Color::White);
    replayText.setString("Do you want to play again? (Y/N)");
    replayText.setPosition(100, 250);

    sf::Text yesText, noText;
    yesText.setFont(font);
    yesText.setCharacterSize(30);
    yesText.setFillColor(sf::Color::Green);
    yesText.setString("Yes");
    yesText.setPosition(200, 300);

    noText.setFont(font);
    noText.setCharacterSize(30);
    noText.setFillColor(sf::Color::Red);
    noText.setString("No");
    noText.setPosition(400, 300);

    while (window.isOpen())
    {
        window.clear();
        window.draw(replayText);
        window.draw(yesText);
        window.draw(noText);
        window.display();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return false;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (yesText.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    return true;
                }
                else if (noText.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    return false;
                }
            }
        }
    }
    return false; 
}



void HangmanGame::resetGame()
{
    lives = 6;
    letterTracker.clear();
    hangmanFigure.reset();
    errorMessageText.setString("");
    incorrectGuessesText.setString("");
    hintText.setString("");
    score = 0;
    updateScoreText();
}

void HangmanGame::updateScoreText()
{
    scoreText.setString("Score: " + to_string(score));
}





MenuS::MenuS(RenderWindow& win) : window(win)
{
    
    if (!instTexture.loadFromFile("assets/image.png"))
    {
        cout << "Failed to load image.png" << endl;
    }
    inst.setTexture(instTexture);
    inst.setPosition(50, 200);

    if (!backgroundTexture.loadFromFile("assets/background.png"))
    {
        cout << "Failed to load background.png" << endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    if (!instructionTexture.loadFromFile("assets/instructions.png"))
    {
        cout << "Failed to load instructions.png" << endl;
    }
    Instruction.setTexture(instructionTexture);
    Instruction.setPosition(350, 550);

    if (!snakeTexture.loadFromFile("assets/snake.png"))
    {
        cout << "Failed to load snake.png" << endl;
    }
    Snake.setTexture(snakeTexture);
    Snake.setPosition(250, -150);

    if (!hardTexture.loadFromFile("assets/hard.png"))
    {
        cout << "Failed to load hard.png" << endl;
    }
    Hard.setTexture(hardTexture);
    Hard.setPosition(350, 400);

    if (!normalTexture.loadFromFile("assets/normal.png"))
    {
        cout << "Failed to load normal.png" << endl;
    }
    Normal.setTexture(normalTexture);
    Normal.setPosition(350, 250);

    if (!quitTexture.loadFromFile("assets/quit.png"))
    {
        cout << "Failed to load quit.png" << endl;
    }
    Quit.setTexture(quitTexture);
    Quit.setPosition(350, 700);

    if (!backTexture.loadFromFile("assets/back.png"))
    {
        cout << "Failed to load back.png" << endl;
    }
    back.setTexture(backTexture);
    back.setPosition(1000, 600);

    if (!overTexture.loadFromFile("assets/gameover.png"))
    {
        cout << "Failed to load gameover.png" << endl;
    }
    over.setTexture(overTexture);
    over.setPosition(300, 300);
}


void MenuS::displayInstruction()
{
    window.clear();
    window.draw(backgroundSprite);
    window.draw(Snake);
    window.draw(inst);
    window.draw(back);
    window.display();
}


void MenuS::displayMenu()
{
    window.clear();
    window.draw(backgroundSprite);
    window.draw(Snake);
    window.draw(Hard);
    window.draw(Normal);
    window.draw(Quit);
    window.draw(Instruction);
    window.display();
}


void MenuS::gameOver()
{
    window.clear();
    window.draw(backgroundSprite);
    window.draw(Snake);
    window.draw(over);
    window.display();

    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
        {
            window.clear();
            displayMenu();
        }
    }
}


int MenuS::show()
{
    displayMenu();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    Vector2i mousePos = Mouse::getPosition(window);

                    if (Quit.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        window.close();
                        return -1;
                    }

                    if (Hard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        return 2;
                    }

                    if (Normal.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        return 1;
                    }

                    if (Instruction.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        displayInstruction();
                    }

                    if (back.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        displayMenu();
                    }
                }
            }
        }
    }
    return 0; 
}








GameUI::GameUI()
{


    if (!font.loadFromFile("assets/Bodoni MT Black.ttf"))
    {
        cout << "Failed to load font!" << endl;
    }
    if (!heartTexture.loadFromFile("assets/heartk.png"))
    {
        cout << "Failed to load heart texture!" << endl;
    }


    heart.setTexture(heartTexture);
    heart.setPosition(590, 18);

   


    livesText.setFont(font);
    livesText.setCharacterSize(40);
    livesText.setFillColor(Color::Black);
    livesText.setPosition(390, 10);
    livesText.setOutlineThickness(3);
    livesText.setOutlineColor(Color::Red);


    pauseText.setFont(font);
    pauseText.setCharacterSize(40);
    pauseText.setFillColor(Color::White);
    pauseText.setPosition(1100, 10);
    pauseText.setOutlineThickness(3);
    pauseText.setOutlineColor(Color::Red);
}

void GameUI::display(RenderWindow& window, int lives, bool isPaused)
{
   

 
    livesText.setString("Lives: " + to_string(lives) + " x");
    window.draw(livesText);
    window.draw(heart);

 
    pauseText.setString(isPaused ? "Resume" : "Pause");
    window.draw(pauseText);
}











void Grid::draw(RenderWindow& window)
{
    const float gridCellSize = 50.0f;
    const float startX = 50.0f;
    const float startY = 100.0f;
    const float endX = 1250.0f;
    const float endY = 850.0f;


    RectangleShape gridCell(Vector2f(gridCellSize, gridCellSize));
    gridCell.setOutlineColor(Color::White);
    gridCell.setOutlineThickness(1.0f);


    for (float x = startX; x < endX; x += gridCellSize) {
        for (float y = startY; y < endY; y += gridCellSize) {
            gridCell.setPosition(x, y);

            // Alternate colors between cells
            if (static_cast<int>((x / gridCellSize) + (y / gridCellSize)) % 2 == 0)
            {
                gridCell.setFillColor(Color(144, 238, 144)); // Light green
            }
            else
            {
                gridCell.setFillColor(Color(0, 100, 0)); // Dark green
            }

            window.draw(gridCell);
        }
    }
}







Snake::Snake(RenderWindow& win) : window(win), length(5), tailDirection(Vector2i(1, 0))
{
    direction = Vector2i(1, 0);
    lastDirection = direction;

    loadTextures();

    // Initialize snake body
    bodyX[0] = 5; bodyY[0] = 5;
    bodyX[1] = 4; bodyY[1] = 5;
    bodyX[2] = 3; bodyY[2] = 5;
    bodyX[3] = 2; bodyY[3] = 5;
    bodyX[4] = 1; bodyY[4] = 5;
}

void Snake::restart()
{
    length = 5;
    isStarted = false;

    bodyX[0] = 5; bodyY[0] = 5;
    bodyX[1] = 4; bodyY[1] = 5;
    bodyX[2] = 3; bodyY[2] = 5;
    bodyX[3] = 2; bodyY[3] = 5;
    bodyX[4] = 1; bodyY[4] = 5;

    direction = Vector2i(1, 0);
    lastDirection = direction;

    tailDirection = Vector2i(1, 0);

    headSprite.setTexture(headTextureRight);
    tailSprite.setTexture(tailTextureRight);
}

void Snake::loadTextures()
{
    headTextureUp.loadFromFile("assets/head_up.png");
    headTextureDown.loadFromFile("assets/head_down.png");
    headTextureLeft.loadFromFile("assets/head_left.png");
    headTextureRight.loadFromFile("assets/head_right.png");

    tailTextureUp.loadFromFile("assets/tail_up.png");
    tailTextureDown.loadFromFile("assets/tail_down.png");
    tailTextureLeft.loadFromFile("assets/tail_left.png");
    tailTextureRight.loadFromFile("assets/tail_right.png");

    headSprite.setTexture(headTextureRight);
    tailSprite.setTexture(tailTextureRight);
}

void Snake::handleInput()
{
    if (!isStarted)
    {
        if (Keyboard::isKeyPressed(Keyboard::Up) ||
            Keyboard::isKeyPressed(Keyboard::Down) ||
            Keyboard::isKeyPressed(Keyboard::Left) ||
            Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::W) ||
            Keyboard::isKeyPressed(Keyboard::A) ||
            Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::D))
        {
            isStarted = true;
        }
    }
    else
    {
        if (Keyboard::isKeyPressed(Keyboard::Up) && direction.y != 1)
        {
            lastDirection = direction;
            direction = Vector2i(0, -1);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down) && direction.y != -1)
        {
            lastDirection = direction;
            direction = Vector2i(0, 1);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left) && direction.x != 1)
        {
            lastDirection = direction;
            direction = Vector2i(-1, 0);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right) && direction.x != -1)
        {
            lastDirection = direction;
            direction = Vector2i(1, 0);
        }

        else if (Keyboard::isKeyPressed(Keyboard::W) && direction.y != 1)
        {
            lastDirection = direction;
            direction = Vector2i(0, -1);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S) && direction.y != -1)
        {
            lastDirection = direction;
            direction = Vector2i(0, 1);
        }
        else if (Keyboard::isKeyPressed(Keyboard::A) && direction.x != 1)
        {
            lastDirection = direction;
            direction = Vector2i(-1, 0);
        }
        else if (Keyboard::isKeyPressed(Keyboard::D) && direction.x != -1)
        {
            lastDirection = direction;
            direction = Vector2i(1, 0);
        }
    }
}

void Snake::update()
{
    if (isStarted)
    {
        for (int i = length - 1; i > 0; i--)
        {
            bodyX[i] = bodyX[i - 1];
            bodyY[i] = bodyY[i - 1];
        }

        if (length > 1)
        {
            int tailSegmentIndex = length - 2;
            if (bodyX[tailSegmentIndex] != bodyX[tailSegmentIndex - 1] ||
                bodyY[tailSegmentIndex] != bodyY[tailSegmentIndex - 1])
            {
                tailDirection = Vector2i(
                    bodyX[tailSegmentIndex] - bodyX[length - 1],
                    bodyY[tailSegmentIndex] - bodyY[length - 1]
                );
            }
        }

        bodyX[0] += direction.x;
        bodyY[0] += direction.y;
    }
}

void Snake::draw()
{
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            switch (direction.x)
            {
            case 1:
                headSprite.setTexture(headTextureRight);
                break;
            case -1:
                headSprite.setTexture(headTextureLeft);
                break;
            case 0:
                if (direction.y == 1)
                {
                    headSprite.setTexture(headTextureDown);
                }
                else
                {
                    headSprite.setTexture(headTextureUp);
                }
                break;
            }
            headSprite.setPosition(bodyX[i] * segmentSize, bodyY[i] * segmentSize);
            window.draw(headSprite);
        }
        else if (i < length - 1)
        {
            bodySegment.setRadius(segmentSize / 2);
            bodySegment.setFillColor(Color(255, 8, 32));  // red
            bodySegment.setPosition(bodyX[i] * segmentSize, bodyY[i] * segmentSize);
            window.draw(bodySegment);
        }
        else
        {
            setTailSprite();
            tailSprite.setPosition(bodyX[i] * segmentSize, bodyY[i] * segmentSize);
            window.draw(tailSprite);
        }
    }
}

void Snake::setTailSprite()
{
    if (tailDirection.x == 1)
    {
        tailSprite.setTexture(tailTextureRight);
    }
    else if (tailDirection.x == -1)
    {
        tailSprite.setTexture(tailTextureLeft);
    }
    else if (tailDirection.y == 1)
    {
        tailSprite.setTexture(tailTextureDown);
    }
    else if (tailDirection.y == -1)
    {
        tailSprite.setTexture(tailTextureUp);
    }
}

int Snake::getHeadX() const
{
    return bodyX[0];
}

int Snake::getHeadY() const
{
    return bodyY[0];
}

int* Snake::getBodyX()
{
    return bodyX;
}

int* Snake::getBodyY()
{
    return bodyY;
}

void Snake::grow()
{
    if (length < maxLength)
    {
        length++;
        bodyX[length - 1] = bodyX[length - 2];
        bodyY[length - 1] = bodyY[length - 2];
    }
}

int Snake::getLength() const
{
    return length;
}







Food::Food(RenderWindow& win, Snake& snk) : window(win), snake(snk)
{
    // Load textures for apple and mushroom
    if (!appleTexture.loadFromFile("assets/apple.png"))
    {
        cout << "Failed to load apple.png" << endl;
    }

    if (!mushroomTexture.loadFromFile("assets/mushroom.png"))
    {
        cout << "Failed to load mushroom.png" << endl;
    }

    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation

    spawnFood();  // Initially spawn food
}

bool Food::checkIfCellOccupiedBySnake(int x, int y)
{
    int* bodyX = snake.getBodyX();
    int* bodyY = snake.getBodyY();
    int snakeLength = snake.getLength();


    for (int i = 0; i < snakeLength; i++)
    {
        if (bodyX[i] == x && bodyY[i] == y)
        {
            return true;
        }
    }
    return false;
}

void Food::spawnFood()
{
    srand(time(0));
    FoodType = (rand() % 2 == 0) ? 1 : -1;  // Randomly select food type (apple = 1, mushroom = -1)
    foodSprite.setTexture(FoodType == 1 ? appleTexture : mushroomTexture);

    // Generate random position for the food, ensuring it is not on the snake
    do
    {
        foodX = rand() % 23 + 2;  // Random X position in the grid
        foodY = rand() % 15 + 2;  // Random Y position in the grid
    } while (checkIfCellOccupiedBySnake(foodX, foodY));  // Make sure food isn't placed where the snake is

    foodSprite.setPosition(foodX * gridSize, foodY * gridSize);  // Set food position
}

bool Food::checkCollision(int snakeX, int snakeY)
{
    return (snakeX == foodX && snakeY == foodY);  // Check if the snake's head collided with the food
}

void Food::draw()
{
    window.draw(foodSprite);  // Draw the food sprite on the window
}

Vector2i Food::getPosition()
{
    return Vector2i(foodX, foodY);  // Return the position of the food as a Vector2i
}

int Food::getFoodType()
{
    return FoodType;  // Return the type of food (1 for apple, -1 for mushroom)
}






bool Collision::checkWallCollision(int headX, int headY)
{
    if (headX < 1 || headX > 24 || headY <= 1 || headY > 16)  
    {
        return true;
    }

    return false;
}

bool Collision::checkSelfCollision(int headX, int headY, int bodyX[], int bodyY[], int length)
{
    for (int i = 1; i < length; i++)  // Starting from 1 to skip the head
    {
        if (bodyX[i] == headX && bodyY[i] == headY)
        {
            return true;
        }
    }
    return false;
}







PowerUp::PowerUp(RenderWindow& win, Snake& snk) : window(win), snake(snk), isActive(false)
{

    if (!plusTexture.loadFromFile("assets/plus.png"))
    {
        cout << "Failed to load plus.png" << endl;
    }
    if (!minusTexture.loadFromFile("assets/minus.png"))
    {
        cout << "Failed to load minus.png" << endl;
    }
}

void PowerUp::spawnPowerUp(Vector2i food)
{
    srand(time(0));
    powerUpType = (rand() % 2 == 0) ? 1 : -1;  // Randomly select a power-up (1 for plus, -1 for minus)
    powerUpSprite.setTexture(powerUpType == 1 ? plusTexture : minusTexture);

   
    do
    {
        powerUpX = rand() % 23 + 2;
        powerUpY = rand() % 15 + 2;
    } while ((powerUpX == food.x) && (powerUpY == food.y) || checkIfCellOccupiedBySnake(powerUpX, powerUpY));

    // Set the position of the power-up sprite
    powerUpSprite.setPosition(powerUpX * gridSize, powerUpY * gridSize);

    // Start the power-up's clock
    powerUpClock.restart();
    isActive = true;
}

bool PowerUp::checkCollision(int snakeX, int snakeY)
{
    return (snakeX == powerUpX && snakeY == powerUpY);  // Check if snake's head is at the power-up's position
}

void PowerUp::update()
{
    if (isActive && powerUpClock.getElapsedTime().asSeconds() > 5)  // Power-up lasts for 5 seconds
    {
        isActive = false;  // Deactivate the power-up after 5 seconds
    }
}

void PowerUp::draw()
{
    if (isActive)  // Only draw the power-up if it is active
    {
        window.draw(powerUpSprite);
    }
}

bool PowerUp::checkIfCellOccupiedBySnake(int x, int y)
{
    int* bodyX = snake.getBodyX();
    int* bodyY = snake.getBodyY();
    int snakeLength = snake.getLength();

    // Check if the cell is occupied by the snake
    for (int i = 0; i < snakeLength; i++)
    {
        if (bodyX[i] == x && bodyY[i] == y)
        {
            return true;
        }
    }
    return false;
}

Vector2i PowerUp::getPosition()
{
    return Vector2i(powerUpX, powerUpY);  // Return the position of the power-up
}

int PowerUp::getPowerUpType()
{
    return powerUpType;  // Return the type of power-up (plus or minus)
}

bool PowerUp::isPowerUpActive()
{
    return isActive;  // Return if the power-up is currently active
}



SnakeGame::SnakeGame(RenderWindow& win, const string& gameName)
    : Game(gameName), window(win), menu(win), snake(win), food(win, snake), powerUp(win, snake), lives(3), isPaused(false), moveInterval(0.11f), elapsedTime(0.0f), isPowerUpActive(false)
{
    int difficultyChoice = menu.show();

    if (difficultyChoice == -1)
    {
        window.close();
    }
    else
    {
        difficulty = difficultyChoice;
        if (difficulty == 2)
        {
            moveInterval = 0.1f;
            lives = 1;
        }
    }
    if (!font.loadFromFile("assets/Bodoni MT Black.ttf"))
    {
        cout << "Failed to load font!" << endl;
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(50, 10);
    scoreText.setOutlineThickness(3);
    scoreText.setOutlineColor(Color::Green);
}

// Override startGame from Game class
void SnakeGame::startGame(RenderWindow& window)
{
    run();  // Call the run method when starting the game
}


void SnakeGame::drawUI()
{
    Texture Back;
    RectangleShape boundary(Vector2f(1200, 750));
    boundary.setPosition(50.0f, 100.0f);
    boundary.setFillColor(Color::Transparent);
    boundary.setOutlineColor(Color::Cyan);
    boundary.setOutlineThickness(5.0f);

    window.clear();
    window.draw(boundary);
    grid.draw(window);
    gameUI.display(window, lives, isPaused);
    scoreText.setString("Score: " + to_string(score));
    window.draw(scoreText);
    snake.draw();
    food.draw();

    if (isPowerUpActive && difficulty == 2)
    {
        powerUp.draw();
    }

    window.display();
}


void SnakeGame::handleInput()
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }

        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Space)
            {
                isPaused = !isPaused;  // Toggle pause/resume
            }

            if (event.key.code == Keyboard::Equal)
            {
                score += 500;
                if (lives < 10)
                {
                    lives++;
                }
                for (int i = 0; i < 5; i++)
                {
                    snake.grow();
                }
            }
        }
    }

    // If the game is paused, display the pause screen and return to avoid processing further input
    if (isPaused)
    {
        // Load and display PAUSE.png image
        Texture pauseTexture;
        if (!pauseTexture.loadFromFile("assets/PAUSE.png"))
        {
            cerr << "Failed to load PAUSE.png!" << endl;
        }
        Sprite pauseSprite(pauseTexture);

        // Center the image in the window
        FloatRect bounds = pauseSprite.getLocalBounds();
        pauseSprite.setPosition(
            window.getSize().x / 2.0f - bounds.width / 2.0f,
            window.getSize().y / 2.0f - bounds.height / 2.0f
        );

        // Display the pause image and the text
        window.clear();  // Clear the window
        window.draw(pauseSprite);  // Draw the pause image

        // Create the text
        Font font;
        if (!font.loadFromFile("assets/arial.ttf"))  // Load a font (make sure the font file is available)
        {
            cerr << "Failed to load font!" << endl;
        }

        Text continueText("PRESS (SPACEBAR) TO CONTINUE", font, 30);
        continueText.setFillColor(Color::White);
        FloatRect textBounds = continueText.getLocalBounds();
        continueText.setPosition(
            window.getSize().x / 2.0f - textBounds.width / 2.0f,
            window.getSize().y / 2.0f + bounds.height / 2.0f + 10.0f  // Position it under the image
        );

        window.draw(continueText);  // Draw the text
        window.display();  // Display everything

        return;  // Exit from handleInput to avoid game input while paused
    }

    // If not paused, continue with normal input handling (for snake movement)
    snake.handleInput();
}


void SnakeGame::showPauseScreen()
{
    // Load PAUSE.png texture
    Texture pauseTexture;
    if (!pauseTexture.loadFromFile("assets/PAUSE.png"))
    {
        cerr << "Failed to load PAUSE.png!" << endl;
    }
    Sprite pauseSprite(pauseTexture);

    // Center the image in the window
    FloatRect bounds = pauseSprite.getLocalBounds();
    pauseSprite.setPosition(
        window.getSize().x / 2.0f - bounds.width / 2.0f,
        window.getSize().y / 2.0f - bounds.height / 2.0f
    );

    // Create the text
    Font font;
    if (!font.loadFromFile("assets/arial.ttf"))  // Load a font (make sure the font file is available)
    {
        cerr << "Failed to load font!" << endl;
    }

    Text continueText("PRESS (SPACEBAR) TO CONTINUE", font, 30);
    continueText.setFillColor(Color::White);
    FloatRect textBounds = continueText.getLocalBounds();
    continueText.setPosition(
        window.getSize().x / 2.0f - textBounds.width / 2.0f,
        window.getSize().y / 2.0f + bounds.height / 2.0f + 10.0f  // Position it under the image
    );

    // Draw the pause screen
    window.clear();  // Clear the window
    window.draw(pauseSprite);  // Draw the pause image
    window.draw(continueText);  // Draw the continue text
    window.display();  // Display everything
}














void SnakeGame::showGameOver()
{
    bool gameOver = true;
    while (gameOver)
    {
        window.clear();
        menu.gameOver();


    }
}

// Run the game loop
void SnakeGame::run()
{
    while (window.isOpen())
    {
        // Handle user input, including pause/resume
        handleInput();

        // If the game is paused, show the pause screen
        if (isPaused)
        {
            // When the game is paused, display the pause screen
            showPauseScreen();
            continue;  // Skip the rest of the loop, don't update the game while paused
        }

        // If not paused, continue with the regular game logic
        elapsedTime += clock.restart().asSeconds();

        if (elapsedTime >= moveInterval)
        {
            // Update the snake if not paused
            snake.update();
            elapsedTime = 0.0f;

            // Check for food collision and update score, snake, and spawn food
            if (food.checkCollision(snake.getHeadX(), snake.getHeadY()))
            {
                if (food.getFoodType() == -1)
                {
                    score += 20;
                    snake.grow();
                    snake.grow();
                }
                else if (food.getFoodType() == 1)
                {
                    score += 10;
                    snake.grow();
                }
                food.spawnFood();
            }

            // Check for wall collisions
            if (collision.checkWallCollision(snake.getHeadX(), snake.getHeadY()))
            {
                snake.restart();
                lives--;
            }

            // Check for self-collisions
            int* bodyX = snake.getBodyX();
            int* bodyY = snake.getBodyY();

            if (collision.checkSelfCollision(snake.getHeadX(), snake.getHeadY(), bodyX, bodyY, snake.getLength()))
            {
                snake.restart();
                lives--;
            }

            // Handle power-ups if difficulty is set to 2
            if (difficulty == 2)
            {
                if (isPowerUpActive)
                {
                    if (powerUp.checkCollision(snake.getHeadX(), snake.getHeadY()))
                    {
                        if (powerUp.getPowerUpType() == 1)
                        {
                            if (lives < 10)
                            {
                                lives++;
                            }
                            score += 100;
                        }
                        else if (powerUp.getPowerUpType() == -1)
                        {
                            lives--;
                            score -= 100;
                        }

                        isPowerUpActive = false;
                    }

                    powerUp.update();
                    if (!powerUp.isPowerUpActive())
                    {
                        isPowerUpActive = false;
                    }
                }

                if (powerUpSpawnClock.getElapsedTime().asSeconds() >= 10 && !isPowerUpActive)
                {
                    powerUp.spawnPowerUp(food.getPosition());
                    isPowerUpActive = true;
                    powerUpSpawnClock.restart();
                }
            }

            // Check if lives are 0 or less, and close the game if so
            if (lives <= 0)
            {
                // Save the score to the file before closing the game
                Menu menu;
                menu.saveScore(score);

                window.close();  // Close the game window after saving the score
            }
        }

        drawUI();
    }
}










Dictionary::Dictionary()
{
    wordCount = 0;
    loadWords(); // Load valid words into the dictionary
}

// Function to load words into the dictionary (hardcoded for simplicity)
void Dictionary::loadWords()
{
    const char* words[] = { "APPLE", "BANJO", "CRANE", "DRAKE", "EAGER", "FLUTE", "GRAPE", "HOUSE", "IRATE", "JUMPY" };
    for (int i = 0; i < 10; ++i) // Adding 10 words
    {
        strncpy_s(validWords[wordCount], words[i], WORD_LENGTH - 1);
        validWords[wordCount][WORD_LENGTH - 1] = '\0'; // Ensure null termination
        wordCount++;
    }
}



// Check if a word exists in the dictionary
bool Dictionary::isValidWord(const char* word)
{
    for (int i = 0; i < wordCount; ++i)
    {
        if (strcmp(validWords[i], word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Getter function to access valid words at a specific index
const char* Dictionary::getValidWord(int index) const
{
    if (index >= 0 && index < wordCount)
    {
        return validWords[index];
    }
    return nullptr; // Return nullptr if the index is out of bounds
}

// Getter function to return the number of words in the dictionary
int Dictionary::getWordCount() const
{
    return wordCount;
}

// Getter function to return a random valid word
const char* Dictionary::getRandomValidWord() const
{
    if (wordCount > 0) {
        int index = rand() % wordCount;
        return validWords[index];
    }
    return nullptr;
}





Button::Button(float x, float y, const char* texturePath, float scaleX, float scaleY)
{
    // Load texture
    if (!texture.loadFromFile(texturePath))
    {
        std::cout << "Error loading texture: " << texturePath << std::endl;
    }


    sprite.setTexture(texture);

    // Set position of the sprite
    sprite.setPosition(x, y);


    sprite.setScale(scaleX, scaleY);
}

// Method to draw the button
void Button::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

// Method to check if the button is clicked
bool Button::isClicked(sf::Vector2i mousePos)
{
    return sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}





WordDisplay::WordDisplay()
{
    if (!font.loadFromFile("assets/Roboto-Black.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    // Set up the letters
    const char* word = "WORDLE";
    for (int i = 0; i < 6; ++i)
    {
        letters[i].setFont(font);
        letters[i].setString(word[i]);
        letters[i].setCharacterSize(72);
        letters[i].setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    }
}


void WordDisplay::draw(sf::RenderWindow& window, bool inGame)
{
    float totalWidth = 0;
    for (int i = 0; i < 6; ++i)
    {
        totalWidth += letters[i].getLocalBounds().width;
    }

    float startX = (800 - totalWidth) / 2;
    float startY = inGame ? 0 : 100;


    float xPos = startX;
    for (int i = 0; i < 6; ++i)
    {
        letters[i].setPosition(xPos, startY);
        xPos += letters[i].getLocalBounds().width;
        window.draw(letters[i]);
    }
}






namespace key {

    // Constructor to initialize the keyboard keys and their states
    Keyboard::Keyboard(const char* keyPaths[26], float startX, float startY, float scale)
    {
        float keySpacing = 5.f;
        float rowSpacing = 50.f;
        int rowLimits[] = { 10, 9, 7 };

        int currentKey = 0;
        float currentX = startX;
        float currentY = startY;


        if (!font.loadFromFile("assets/Roboto-Black.ttf"))
        {
            cout << "Error loading font!" << endl;
        }

        // Initialize keys and their positions
        for (int row = 0; row < 3; ++row)
        {
            for (int i = 0; i < rowLimits[row]; ++i)
            {
                if (!textures[currentKey].loadFromFile(string("assets/") + keyPaths[currentKey]))

                {
                    cout << "Error loading texture for key: " << keyPaths[currentKey] << endl;
                }

                keys[currentKey].setTexture(textures[currentKey]);
                keys[currentKey].setPosition(currentX, currentY);
                keys[currentKey].setScale(scale, scale);

                // Initialize text for keys
                keyTexts[currentKey].setFont(font);
                keyTexts[currentKey].setString(std::string(1, keyLetters[currentKey]));
                keyTexts[currentKey].setCharacterSize(50);

                // Adjust position: Slightly higher for better alignment
                keyTexts[currentKey].setPosition(
                    currentX + keys[currentKey].getGlobalBounds().width / 4,
                    currentY - keys[currentKey].getGlobalBounds().height / 10 // Adjusted vertically up
                );

                currentX += keys[currentKey].getGlobalBounds().width + keySpacing;
                ++currentKey;
            }

            currentX = startX + (row == 1 ? keySpacing * 5 : (row == 2 ? keySpacing * 10 : 0));
            currentY += rowSpacing;
        }

        // Enter and Backspace keys remain as PNGs
        if (!textures[26].loadFromFile("assets/enter.jpg"))
        {
            cout << "Error loading texture for Enter key." << endl;
        }
        keys[26].setTexture(textures[26]);
        keys[26].setScale(0.065f, 0.065f);
        keys[26].setPosition(keys[19].getPosition().x - keys[26].getGlobalBounds().width - keySpacing, keys[19].getPosition().y);

        if (!textures[27].loadFromFile("assets/backspace.png"))
        {
            cout << "Error loading texture for Backspace key." << endl;
        }
        keys[27].setTexture(textures[27]);
        keys[27].setScale(scale, scale);
        keys[27].setPosition(keys[25].getPosition().x + keys[25].getGlobalBounds().width + keySpacing, keys[25].getPosition().y);
    }

    // Method to draw the keyboard on the screen
    void Keyboard::draw(sf::RenderWindow& window)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (keyStates[i] == Green)
            {
                keyTexts[i].setFillColor(sf::Color::Green);
                window.draw(keyTexts[i]);
            }
            else if (keyStates[i] == Red)
            {
                keyTexts[i].setFillColor(sf::Color::Red);
                window.draw(keyTexts[i]);
            }
            else
            {
                window.draw(keys[i]);
            }
        }


        window.draw(keys[26]);
        window.draw(keys[27]);
    }

    // Handle key click events

    void Keyboard::handleKeyClick(sf::Vector2i mousePos, GameBoard& gameBoard, bool& playerWon)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (keys[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
            {
                gameBoard.insertLetter(keyLetters[i]); // Insert the letter into the game board
                return;
            }
        }

        // Handle Enter key
        if (keys[26].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            if (gameBoard.submitRow(*this)) // Pass the keyboard to submitRow
            {
                if (gameBoard.isWin())
                {
                    cout << "Player won the game via virtual keyboard!" << endl;
                    playerWon = true;
                }
            }
            else
            {
                cout << "Invalid word or incomplete row." << endl;
            }
        }


        if (keys[27].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            gameBoard.deleteLastLetter();
        }
    }




    void Keyboard::updateKeyState(char letter, const std::string& state)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (keyLetters[i] == letter)
            {
                if (state == "green")
                {
                    keyStates[i] = Green;
                }
                else if (state == "red")
                {
                    keyStates[i] = Red;
                }
                break;
            }
        }
    }

}















GameBoard::GameBoard()
{

    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            board[i][j] = ' ';
        }
    }
    // Load the secret word
    loadSecretWord();
    initializeHints(
        "assets/hint.png", "assets/hint2.png",
        100.f, 100.f, 0.30f, 0.30f,
        115.f, 250.f, 0.4f, 0.4f
    );
}

void GameBoard::loadSecretWord()
{
    srand(time(0));
    int randomIndex = rand() % dictionary.getWordCount();           // Choose a random index from the dictionary
    strncpy_s(secretWord, dictionary.getValidWord(randomIndex), 5);
    secretWord[5] = '\0';
}


void GameBoard::initializeHints(const std::string& hint1Path, const std::string& hint2Path,
    float x1, float y1, float scaleX1, float scaleY1,
    float x2, float y2, float scaleX2, float scaleY2)
{
    if (!hintTexture1.loadFromFile(hint1Path))
    {
        cout << "Failed to load " << hint1Path << endl;
    }
    hintSprite1.setTexture(hintTexture1);
    hintSprite1.setPosition(x1, y1);
    hintSprite1.setScale(scaleX1, scaleY1);

    if (!hintTexture2.loadFromFile(hint2Path))
    {
        cout << "Failed to load " << hint2Path << endl;
    }
    hintSprite2.setTexture(hintTexture2);
    hintSprite2.setPosition(x2, y2);
    hintSprite2.setScale(scaleX2, scaleY2);
}

void GameBoard::handleHintClick(sf::Vector2i mousePos)
{
    if (hintSprite1.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        std::string randomWord = dictionary.getRandomValidWord(); // Get a random word from the dictionary
        for (int i = 0; i < 5; ++i)
        {
            insertLetter(randomWord[i]); // Insert the letters of the random word into the current row
        }
    }

    if (hintSprite2.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        // Find a random valid column index in the secret word
        srand(time(0));
        int colIndex;
        do {
            colIndex = rand() % 5;
        } while (board[currentRow][colIndex] != ' '); // Ensure the position is empty

        // Reveal the letter from the secret word in the correct column
        board[currentRow][colIndex] = secretWord[colIndex];
        hintFilled[colIndex] = true; // Mark this position as filled by a hint
    }
}

void GameBoard::insertLetter(char letter)
{
    if (currentRow < 6 && !rowCompleted[currentRow])
    {

        while (currentCol < 5 && hintFilled[currentCol])
        {
            currentCol++;
        }

        // Insert the letter in the first non-hint-filled position
        if (currentCol < 5)
        {
            board[currentRow][currentCol] = letter;
            currentCol++;
        }
    }
}

bool GameBoard::submitRow(key::Keyboard& keyboard)
{
    // Ensure the row is fully filled
    for (int i = 0; i < 5; ++i)
    {
        if (board[currentRow][i] == ' ') // Check for empty spaces
        {
            cout << "Row is incomplete. Please complete the row." << endl;
            return false;
        }
    }


    char currentWord[6] = { 0 };
    for (int i = 0; i < 5; ++i)
    {
        currentWord[i] = board[currentRow][i];
    }

    if (dictionary.isValidWord(currentWord))
    {
        rowCompleted[currentRow] = true;
        score += 100;

        for (int i = 0; i < 5; ++i)
        {
            if (currentWord[i] == secretWord[i])
            {
                keyboard.updateKeyState(currentWord[i], "green");
                score += 10;
            }
            else if (strchr(secretWord, currentWord[i]) == nullptr)
            {
                keyboard.updateKeyState(currentWord[i], "red");
                score -= 10;
            }
        }

        // Check for win condition
        if (isWin())
        {
            cout << "Congratulations! You guessed the word." << endl;
            score += 150;
        }
        else
        {

            decrementLives();
            cout << "Valid guess, but not the word. Lives remaining: " << getLives() << endl;
        }

        currentRow++;
        currentCol = 0;
        return true;
    }
    else
    {
        cout << "Invalid word entered." << endl;
        resetCurrentRow();
        return false;
    }
}

void GameBoard::draw(sf::RenderWindow& window)
{
    float startX = 250.f;
    float startY = 80.f;
    float boxSize = 50.f;
    sf::RectangleShape box(sf::Vector2f(boxSize, boxSize));
    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2);

    sf::Font font;
    if (!font.loadFromFile("assets/Roboto-Black.ttf"))
    {
        cout << "Error loading font!" << endl;
        return;
    }

    sf::Text letterText;
    letterText.setFont(font);
    letterText.setCharacterSize(24);
    letterText.setFillColor(sf::Color::Black);

    sf::Color gray(169, 169, 169);

    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            box.setPosition(startX + col * (boxSize + 10), startY + row * (boxSize + 10));

            // Update box colors only for completed rows
            if (rowCompleted[row])
            {
                char letter = board[row][col];
                if (letter == secretWord[col])
                    box.setFillColor(sf::Color::Green);
                else if (strchr(secretWord, letter) != nullptr)
                    box.setFillColor(sf::Color::Yellow);
                else
                    box.setFillColor(gray);
            }
            else
            {
                box.setFillColor(sf::Color::White);
            }

            window.draw(box);

            if (board[row][col] != ' ')
            {
                letterText.setString(board[row][col]);
                letterText.setPosition(startX + col * (boxSize + 10) + 15, startY + row * (boxSize + 10) + 10);
                window.draw(letterText);
            }
        }
    }

    // Draw hint sprites
    window.draw(hintSprite1);
    window.draw(hintSprite2);
}

void GameBoard::resetCurrentRow()
{
    for (int i = 0; i < 5; ++i)
    {
        board[currentRow][i] = ' ';
    }
    currentCol = 0;
}

void GameBoard::deleteLastLetter()
{
    if (currentCol > 0)
    {
        currentCol--;
        board[currentRow][currentCol] = ' ';
    }
}

bool GameBoard::isWin() const
{
    for (int i = 0; i < 5; ++i)
    {
        if (board[currentRow - 1][i] != secretWord[i])
            return false;
    }
    return true;
}

void GameBoard::decrementLives()
{
    if (lives > 0)
    {
        lives--;
    }
}

int GameBoard::getLives() const
{
    return lives;
}

int GameBoard::getscore() const
{
    return score;
}





WelcomeScreen::WelcomeScreen()
{
    if (!font.loadFromFile("assets/Roboto-Black.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
    }

    if (!backgroundTexture.loadFromFile("assets/bb.jpg"))
    {
        std::cout << "Error loading background image!" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    float scaleX = 800.0f / backgroundTexture.getSize().x;
    float scaleY = 600.0f / backgroundTexture.getSize().y;
    backgroundSprite.setScale(scaleX, scaleY);

    welcomeText.setFont(font);
    welcomeText.setString("Welcome to Wordle");
    welcomeText.setCharacterSize(40);
    welcomeText.setFillColor(sf::Color::Black);
    welcomeText.setStyle(sf::Text::Bold);


    rulesButtonText.setFont(font);
    rulesButtonText.setString("Rules");
    rulesButtonText.setCharacterSize(40);
    rulesButtonText.setFillColor(sf::Color::Red);
}

void WelcomeScreen::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);

    float textWidth = welcomeText.getLocalBounds().width;
    welcomeText.setPosition((800 - textWidth) / 2, 230);
    window.draw(welcomeText);


    float rulesWidth = rulesButtonText.getLocalBounds().width;
    rulesButtonText.setPosition((800 - rulesWidth) / 2, 300);
    window.draw(rulesButtonText);
}

bool WelcomeScreen::isRulesClicked(const sf::Vector2i& mousePos) const
{
    float rulesWidth = rulesButtonText.getLocalBounds().width;
    float rulesHeight = rulesButtonText.getLocalBounds().height;
    sf::FloatRect rulesBounds((800 - rulesWidth) / 2, 300, rulesWidth, rulesHeight);
    return rulesBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}











WordleGame::WordleGame(const std::string& gameName)
    : Game(gameName),
    window(sf::VideoMode(800, 600), gameName),
    wordDisplay(),
    gameBoard(),
    keyboard(new const char* [26] {
    "Q.jpg", "W.jpg", "E.jpg", "R.jpg", "T.jpg", "Y.jpg", "U.jpg", "I.jpg", "O.jpg", "P.jpg",
        "A.png", "S.jpg", "D.jpg", "F.jpg", "G.jpg", "H.jpg", "J.jpg", "K.jpg", "L.jpg",
        "Z.jpg", "X.jpg", "C.jpg", "V.jpg", "B.jpg", "N.jpg", "M.jpg"}, 100.f, 450.f),
    welcomeScreen(),
    playButton(260, 330, "assets/play3.png", 0.3f, 0.3f),
    inGame(false),
    playerWon(false),
    showRules(false)

{

    initializeHearts(150.f, 200.f, 0.5f, 0.5f);
    score = gameBoard.getscore();
    if (!rulesTexture.loadFromFile("assets/rules.png"))
    {
        cout << "Error loading rules.png!" << endl;
    }
    rulesSprite.setTexture(rulesTexture);


    float scaleX = (800.0f / rulesTexture.getSize().x) * 0.9f;
    float scaleY = (600.0f / rulesTexture.getSize().y) * 0.9f;
    rulesSprite.setScale(scaleX, scaleY);


    rulesSprite.setPosition(
        (800.0f - rulesSprite.getGlobalBounds().width) / 2,
        (600.0f - rulesSprite.getGlobalBounds().height) / 2
    );




    if (!gameBackgroundTexture.loadFromFile("assets/b2.jpg"))
    {
        cout << "Error loading b2.jpg!" << std::endl;
    }
    else
    {
        gameBackgroundSprite.setTexture(gameBackgroundTexture);
        gameBackgroundSprite.setScale(1.15f, 1.15f);
    }
}

void WordleGame::initializeHearts(float loseX, float loseY, float loseScaleX, float loseScaleY)
{
    if (!heartTexture.loadFromFile("assets/heart.png"))
    {
        cout << "Error loading heart.png!" << std::endl;
    }

    for (int i = 0; i < 6; ++i)
    {
        hearts[i].setTexture(heartTexture);
        hearts[i].setScale(0.15f, 0.15f);
        hearts[i].setPosition(600.f, 80.f + i * 60.f);
    }

    if (!loseTexture.loadFromFile("assets/lose1.png"))
    {
        cout << "Error loading lose1.png!" << std::endl;
    }

    loseSprite.setTexture(loseTexture);
    loseSprite.setPosition(25, 50);
    loseSprite.setScale(1.0f, 1.0f);
}

void WordleGame::processEvents()
{
    if (inGame && !gameOverScreenShown)
    {
        gameOverScreenShown = false;  // Reset game over screen flag
        clock.restart();  // Restart the clock when a new game begins
    }

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return;
        }

        if (event.type == sf::Event::KeyPressed)
        {
            // Toggle pause on Space key press
            if (event.key.code == sf::Keyboard::Space)
            {
                isPaused = !isPaused;  // Toggle the pause state
                cout << "Pause state: " << (isPaused ? "Paused" : "Resumed") << endl;
            }

            // Handle Enter key for Wordle game (Only process when not paused)
            if (!isPaused && event.key.code == sf::Keyboard::Enter && inGame)
            {
                if (gameBoard.submitRow(keyboard))
                {
                    if (gameBoard.isWin())
                    {
                        playerWon = true;
                    }
                }
            }
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);


            if (!inGame && !showRules && playButton.isClicked(mousePos))
            {
                inGame = true;
            }
            else if (!inGame && !showRules && welcomeScreen.isRulesClicked(mousePos))
            {
                showRules = true;
            }
            else if (showRules)
            {
                showRules = false;
            }


            if (inGame && !isPaused)
            {
                keyboard.handleKeyClick(mousePos, gameBoard, playerWon);
                gameBoard.handleHintClick(mousePos);
            }
        }
    }
}




void WordleGame::showPauseScreen()
{

    Texture pauseTexture;
    if (!pauseTexture.loadFromFile("assets/PAUSE.png"))
    {
        std::cerr << "Failed to load PAUSE.png!" << std::endl;
        return;
    }
    Sprite pauseSprite(pauseTexture);


    FloatRect bounds = pauseSprite.getLocalBounds();
    pauseSprite.setPosition(
        window.getSize().x / 2.0f - bounds.width / 2.0f,
        window.getSize().y / 2.0f - bounds.height / 2.0f
    );


    Font font;
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        cerr << "Failed to load font!" << endl;
        return;
    }

    Text continueText("PRESS (SPACEBAR) TO CONTINUE", font, 30);
    continueText.setFillColor(sf::Color::White);


    FloatRect textBounds = continueText.getLocalBounds();
    continueText.setPosition(
        window.getSize().x / 2.0f - textBounds.width / 2.0f,
        window.getSize().y / 2.0f + bounds.height / 2.0f + 20.0f
    );


    window.clear(sf::Color::Black);
    window.draw(pauseSprite);
    window.draw(continueText);
    window.display();
}













void WordleGame::render()
{
    if (!window.isOpen()) return;

    Font font;
    font.loadFromFile("assets/arial.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(50, 10);
    scoreText.setOutlineThickness(3);
    scoreText.setOutlineColor(Color::Green);

    if (isPaused)
    {
        showPauseScreen();
        return;
    }

    window.clear();

    if (showRules)
    {
        window.clear(sf::Color::Black);
        window.draw(rulesSprite);
        window.display();
    }
    else
    {
        if (playerWon)
        {

            window.clear(sf::Color(255, 182, 193));


            sf::Texture winTexture;
            if (winTexture.loadFromFile("assets/win1.png"))
            {
                sf::Sprite winSprite(winTexture);
                winSprite.setScale(1.0f, 1.0f);
                winSprite.setPosition(55.f, 100.f);
                window.draw(winSprite);
            }


            if (!gameOverScreenShown)
            {
                clock.restart();
                gameOverScreenShown = true;
            }

            if (clock.getElapsedTime().asSeconds() >= 5.f)
            {
                window.close();
            }
        }
        else if (gameBoard.getLives() == 0)
        {
            window.draw(loseSprite);


            if (!gameOverScreenShown)
            {
                clock.restart();
                gameOverScreenShown = true;
            }


            if (clock.getElapsedTime().asSeconds() >= 5.f)
            {
                window.close();
            }
        }
        else if (inGame)
        {
            window.draw(gameBackgroundSprite);
            wordDisplay.draw(window, true);
            gameBoard.draw(window);
            keyboard.draw(window);
            score = gameBoard.getscore();
            scoreText.setString("Score: " + to_string(score));
            window.draw(scoreText);

            for (int i = 0; i < gameBoard.getLives(); ++i)
            {
                window.draw(hearts[i]);
            }
        }
        else
        {
            welcomeScreen.draw(window);
            playButton.draw(window);
        }

        window.display();
    }
}




void WordleGame::startGame(sf::RenderWindow& window)
{

    while (window.isOpen())
    {
        processEvents();
        render();
    }


    int finalScore = gameBoard.getscore();


    Menu menu;
    menu.saveScore(finalScore);
}

void WordleGame::run()
{
    while (window.isOpen())
    {
        processEvents();





        if (isPaused)
        {
            showPauseScreen();
            continue;
        }


        startGame(window);
    }
}







int main()
{
    GameBoy gameHub;
    gameHub.start();


    return 0;
}
