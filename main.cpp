#include <iostream>
#include <stdlib.h>

using namespace std;

enum Outcome { user, bot, draw };
string outcomeMap[3] = {"You win!", "Bot wins!", "It was a draw!"};
enum Choice { rock, paper, scissors };
string choiceMap[3] = {"rock", "paper", "scissors"};

Choice getUserChoice() {
    cout << "Rock, paper or scissors? " << endl;

    string input;
    getline(cin, input);

    if(input == "rock" || input == "ROCK" || input == "1" || input == "r" || input == "R") {
        return rock;
    } else if(input == "paper" || input == "PAPER" || input == "2" || input == "p" || input == "P") {
        return paper;
    } else if(input == "scissors" || input == "SCISSORS" || input == "3" || input == "s" || input == "S") {
        return scissors;
    } else {
        throw invalid_argument("You must choose rock, paper or scissors.");
    }
}

Choice getBotChoice() {
    auto randomNumber = rand() % 3 + 1;

    switch(randomNumber) {
        case 1:
            return rock;
        case 2:
            return paper;
        case 3:
            return scissors;
        default:
            throw invalid_argument("Random number was generated outside of the given range.");
    }
}

Outcome decideOutcomeOfGame(Choice userChoice, Choice botChoice) {
    if (userChoice == botChoice) {
        return draw;
    } else if (userChoice == rock && botChoice == paper) {
        return bot;
    } else if (userChoice == rock && botChoice == scissors) {
        return user;
    } else if (userChoice == paper && botChoice == rock){
        return user;
    } else if (userChoice == paper && botChoice == scissors){
        return bot;
    } else if (userChoice == scissors && botChoice == rock){
        return bot;
    } else if (userChoice == scissors && botChoice == paper) {
        return user;
    }
}

bool shouldGameExit() {
    cout << "Quit?" << "\r\n";
    string input;
    getline(cin, input);
    if(input == "no" || input == "NO" || input == "n" || input == "N" || input == "0") {
        return false;
    } else {
        return true;
    }
}

void gameLoop() {
    auto quit = false;
    while(!quit) {
        auto userChoice = getUserChoice();
        auto botChoice = getBotChoice();

        cout << "You chose " << choiceMap[userChoice] << "\r\n";
        cout << "The bot chose " << choiceMap[botChoice] << "\r\n";
        cout << outcomeMap[decideOutcomeOfGame(userChoice, botChoice)] << "\r\n";

        quit = shouldGameExit();
    }
}

int main() {
    gameLoop();
    return 0;
}