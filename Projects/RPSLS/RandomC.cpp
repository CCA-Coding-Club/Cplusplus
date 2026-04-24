#include <ostream>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


//rock beats scissors
//rock beats lizard
//paper beats rock
//paper beats spock
//scissors beats paper
//scissors beats lizard
//lizard beats paper
//lizard beats spock
//spock beats rock
//spock beats scissors


int main(){
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  int c = rand() % 5 + 1;
  int u = 0;
  std::string comp = " The computer beat you.";
  std::string use = " User wins!";
  //menu
  std::cout << "__________________" << "\nRock, Paper, Scissors, Lizard, Spock\n" << "==================\n";
  std::cout << "Enter a number 1-5 ex. 4\n";
  std::cout << "1. Rock\n" << "2. Paper\n" << "3. Scissors\n" << "4. Lizard\n" << "5. Spock\n";
  std::cin >> u;
  //logic
  if (u == 1 && c == 2) {
    std::cout << "Paper beats rock. The computer beat you.";
  } else if (u == 1 && c == 3) {
    std::cout << "Rock beats Scissors. User wins!";
  } else if (u == 1 && c == 4) {
    std::cout << "Rock beats Lizard. User wins!";
  } else if (u == 1 && c == 5) {
    std::cout << "Spock blasts rock. The computer beat you.";
  } else if (u == 2 && c == 1) {
    std::cout << "Paper covers Rock. User wins!";
  } else if (u == 2 && c == 3) {
    std::cout << "Scissors cut paper. The computer beat you.";
  } else if (u == 2 && c == 4) {
    std::cout << "Lizard eats paper. The computer beat you.";
  } else if (u == 2 && c == 5) {
    std::cout << "Spock hates paperwork. User wins!";
  } else if (u == 3 && c == 1) {
    std::cout << "Rock crushes scissors. The computer beat you.";
  } else if (u == 3 && c == 2) {
    std::cout << "Scissors cut paper. User wins!";
  } else if (u == 3 && c == 4) {
    std::cout << "Scissors slice Lizard. User wins!";
  } else if (u == 3 && c == 5) {
    std::cout << "Spock crushes scissors. The computer beat you.";
  } else if (u == 4 && c == 1) {
    std::cout << "Rock beats lizard." << comp;
  } else if (u == 4 && c == 2) {
    std::cout << "Lizard eats paper." << use;
  } else if (u == 4 && c == 3) {
    std::cout << "Scissors slice Lizard." << comp;
  } else if (u == 4 && c == 5) {
    std::cout << "Lizard poisons Spock." << use;
  } else if (u == 5 && c == 1) {
    std::cout << "Spock blasts rock." << use;
  } else if (u == 5 && c == 2) {
    std::cout << "Spock hates paperwork." << comp;
  } else if (u == 5 && c == 3) {
    std::cout << "Spock crushes scissors." << use;
  } else if (u == 5 && c == 4) {
    std::cout << "Spock gets poisoned by the lizard." << comp;
  } else if (u == c) {
    std::cout << "An epic battle takes place but because of my poor variable assignment we won't only you know what is fighting what. either way, Tie. Try again.";
  }
  std::cout << std::endl;
}