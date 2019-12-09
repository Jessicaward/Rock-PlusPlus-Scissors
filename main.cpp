#include <iostream>
#include <cstdlib>

enum Outcome { user, bot, draw };
std::string outcomeMap[3] = {"You win!", "Bot wins!", "It was a draw!"};
enum Choice { rock, paper, scissors };
std::string choiceMap[3] = {"rock", "paper", "scissors"};

Choice getUserChoice() {
    std::cout << "Rock, paper or scissors? \r\n";

    std::string input;
    getline(std::cin, input);
    //Check the return value was successful
    if(std::cin) {
        if(input == "rock" || input == "ROCK" || input == "1" || input == "r" || input == "R") {
            return rock;
        } else if(input == "paper" || input == "PAPER" || input == "2" || input == "p" || input == "P") {
            return paper;
        } else if(input == "scissors" || input == "SCISSORS" || input == "3" || input == "s" || input == "S") {
            return scissors;
        } else {
            throw std::invalid_argument("You must choose rock, paper or scissors.");
        }
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
            return scissors;
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
    std::cout << "Quit?" << "\r\n";
    std::string input;
    getline(std::cin, input);

    //Check the return value was successful
    if(std::cin) {
        return input != "no" && input != "NO" && input != "n" && input != "N" && input != "0";
    }

    return true;
}

void gameLoop() {
    for(auto quit = false; !quit; quit = shouldGameExit()) {
        auto userChoice = getUserChoice();
        auto botChoice = getBotChoice();

        std::cout << "You chose " << choiceMap[userChoice] << "\r\n";
        std::cout << "The bot chose " << choiceMap[botChoice] << "\r\n";
        std::cout << outcomeMap[decideOutcomeOfGame(userChoice, botChoice)] << "\r\n";
    }
}

int main() {
    gameLoop();
}