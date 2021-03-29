// Created by Kimberly Burke 2021
// Codecademy C++ Exercise - Tic Tac Toe

#include <iostream>
#include <string>
#include <vector>
#include "helper.hpp"
using namespace std;

int winner = 0; // winner is either 1 or 2
int turns = 0;
int active_player = 1;

int main() {
  print_start();
  while (winner == 0 && turns < 9) {
    print_board();
    player_turn(active_player);
    winner = check_winner();
    if (active_player == 1) {
      active_player = 2;
    } else {
      active_player = 1;
    }
    turns++;
  }
  print_winner(winner);
}
