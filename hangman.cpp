/* 
 * Abdelkader Faid
 * CS 1610 Project
 * Vincent Mierlak
 * This is a game of Hangman.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Returns 6 for E/e input, 8 for M/m input, and 10 for H/h input
int tryfinder(char difficulty);
// Opens and closes easy/medium/hard word files and randomizes it and returns
// secret word
string wordfinder(int attempts);
//prints dots at the beginning of game.
void printdots(string secretword);
//couts ascii hangman
void hangman(int attempts, int difficulty);
//game mechanics are implemented determined by difficulty, and the secret word
void game_player(int attempts, int difficulty, string secretword);

int main()
{
    bool repeat_game = true;
    char option;
    char difficulty;

    cout << "Welcome to Hangman. Prepare to get hanged.\n";
    //do/while loop to allow for resetting
    do{

    cout << "Choose a difficulty: [E]asy, [M]edium, or [H]ard.\n"; 
    cin >> difficulty;

    int attempts = tryfinder(difficulty);

    string secretword = wordfinder(attempts);

    game_player(attempts, difficulty, secretword);
    
    cout << "Would you like to play again? [Y]es or [N]o?\n";
    cin >> option;
    if (option == 'Y' || option == 'y')
    {
        repeat_game = true; //restarts the game
    }
    else
    {
        repeat_game = false; // closes the game.
    }
      }while (repeat_game);
}

int tryfinder(char difficulty)
{
    bool is_asking = true;

    while (is_asking)//will always allow user to put difficulty
    {
        if (difficulty == 'E' || difficulty == 'e') //easy = 6 tries
            return 6;
        else if (difficulty == 'M' || difficulty == 'm')//medium = 8 tries
            return 8;
        else if (difficulty == 'H' || difficulty == 'h')//hard = 10 tries
            return 10;
        else 
            cout << "Invalid input. Try again.\n";
            cin >> difficulty;
    }
    return 0;
}

string wordfinder(int attempts)
{
    ifstream ifs; //stream files

    if (attempts == 6) {
        ifs.open("easyhangman.txt"); //uses easy word files
    } else if (attempts == 8) {
        ifs.open("mediumhangman.txt"); //uses medium word files
    } else if (attempts == 10) {
        ifs.open("hardhangman.txt"); //uses hard word files
    }

    if (ifs.fail())
    {
        cout << "Error: file failed to open.\n";
        exit(1); // for exiting the program if the files fail to open.
  
    }

    unsigned seed;
    seed = time(0);
    srand(seed);

    int random = (rand() % 6) + 1; //randomizes from 1 - 6

    string word;

    int loop_count = 0;

    while (loop_count < random) //loop randomizes strings from txt files
    {
        ifs >> word;
        ++loop_count;
    }
    
    ifs.close(); //closes ifstream
    return word;
}
void print_dots(string secretword)
{
    int length = secretword.length(); //grabs # of chars without /0

    for (int x = 0; x < length; x++)
    {
        cout << '.';
    }
    cout << endl;
    return;
}
void hangman(int attempts, int difficulty)
{ //determines hangman layout for each difficulty
    if (attempts > 8 && difficulty == 'H')
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (attempts > 6 && attempts <= 8 && difficulty == 'H')
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (attempts > 4 && attempts <= 6 && difficulty == 'H')
    { 
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << "  |      | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'H' && attempts > 2 && attempts <= 4)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << " -|-     | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'H' && attempts > 0 && attempts <= 2)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << " -|-     | \n"
         << "  |      | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'E' && attempts > 5)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'E' && attempts >= 5)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  0      | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'E' && attempts > 2 && attempts <= 4)
    { 
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << " -|-     | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'E' && attempts > 0 && attempts <= 2)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << " -|-     | \n"
         << "  |      | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }   

    if (difficulty = 'M' && attempts > 6)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'M' && attempts >= 4 && attempts <= 6)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  0      | \n"
         << "  |      | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'M' && attempts > 2 && attempts < 4)
    { 
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << " -|-     | \n"
         << "         | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
    if (difficulty = 'M' && attempts > 0 && attempts <= 2)
    {
    cout << "  +______+ \n"
         << "  |      | \n"
         << "  O      | \n"
         << " -|-     | \n"
         << "  |      | \n"
         << "         | \n"
         << "        _|_ \n";
    return;
    }
}
void game_player(int attempts, int difficulty, string secretword)
{  
    vector<char> taken; //vector takes false letters and couts them.

    int length = secretword.length(); //grabs # of chars without /0
    
    constexpr int MAX_SIZE = 20;//max size of the array.
    
    char guess[MAX_SIZE];
    
    print_dots(secretword);//prints dots at the beginning of the game to let
    //the player know how long the dots are.

    for (int i = 0; i < length; ++i) {
        guess[i] = '.';
    }//array of dots as long as the length of secretword
    
    char letter;
    bool is_playing = true;

    while (is_playing)
    {
        hangman(attempts, difficulty);
        bool found = false;
        cout << "Enter one or more letters to guess:\n";
        cin >> letter;
     
        for (int i = 0; i < length; ++i)
        {
            if (secretword[i] == letter) //correct letter
            {
                found = true;
                guess[i] = letter; //replaces dots in array with letter
            }
        }
        if (found == false)
        {
            bool already_taken = false;
   
            for (auto y: taken)
            {
                if (y == letter)//doesn't deduct attempts if already incorrect
                    already_taken = true;
            }
            
            if (!already_taken)
            {
                cout << "Incorrect guess. Please try again." << endl << endl;
                --attempts;
                taken.push_back(letter);//adds false letter
                sort(taken.begin(), taken.end());//sorts letters alphabetically
            }
        }
        for (int j = 0; j < length; ++j)
        {
            cout << guess[j];
        }
        cout << endl;
        cout << "You have " << attempts << " attempts left.\n";
        cout << "You guessed these letters:\n";
        
        for (auto z: taken)
        {
            cout << z << " ";
        }
        cout << endl << endl;
   
        int dots = 0;
   
        for (int x = 0; x < length; ++x)
        {
            if (guess[x] == '.')
                ++dots;
        }

        if (dots == 0)
        {
            cout << "You won!\n";
            is_playing = false;
        }
        else if (attempts == 0)
        { 
            cout << "  +______+ \n"
                 << "  |      | \n"
                 << "  O      | \n"
                 << " -|-     | \n"
                 << "  |      | \n"
                 << " | |     | \n"
                 << "        _|_ \n";
            cout << "You lost!\n";
            cout << "The secret word was: " << secretword << endl;
            is_playing = false; //endgame
        }
    }
    return;
}
