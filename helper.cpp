#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;

string divider = "_ _ _ _ _";
vector<char> board(9, ' '); 
// create a vector of 3x1 vectors
// {row1, row2, row3, col1, col2, col3, diag1 (top left to bottom right), and diag2 (top right to bottom left)}
vector<vector<int>> poss(8);

void print_start() {
  cout << "TIC-TAC-TOE\nHere is your board. This is a two player game. The numbers mark the positions on the board.\n=====================================\n";
  cout << "1 | 2 | 3\n_ _ _ _ _\n4 | 5 | 6\n_ _ _ _ _\n7 | 8 | 9\n";
  cout << "Please decide who is Player 1 and who is Player 2.\n=====================================\nLet the game begin!\n";
}

void print_board() {
  cout << "Current board: \n";
  cout << board[0] << " | " << board [1] << " | " << board[2] << "\n";
  cout << divider << "\n";
  cout << board[3] << " | " << board [4] << " | " << board[5] << "\n";
  cout << divider << "\n";
  cout << board[6] << " | " << board [7] << " | " << board[8] << "\n";
}

void player_turn(int player) {
  int position;
  cout << "Player " << player << ": ";
  cin >> position;
  if (board[position - 1] == ' ' && position > 0 && position < 10) {
    if (player == 1) {
      board[position -1] = 'X';
    } else {
      board[position - 1] = 'O';
    }
    switch (position) {
    case 1:
      poss[0].push_back(player); // row1
      poss[3].push_back(player); // col1
      poss[6].push_back(player); // diag1
      break; 
    case 2:
      poss[0].push_back(player); // row1
      poss[4].push_back(player); // col2
      break;
    case 3:
      poss[0].push_back(player); // row1
      poss[5].push_back(player); // col3
      poss[7].push_back(player); // diag2
      break;
    case 4:
      poss[1].push_back(player); // row2
      poss[3].push_back(player); // col1
      break;
    case 5:
      poss[1].push_back(player); // row2
      poss[4].push_back(player); // col2
      poss[6].push_back(player); // diag1
      poss[7].push_back(player); // diag2
      break;
    case 6:
      poss[1].push_back(player); // row2
      poss[5].push_back(player); // col3
      break;
    case 7:
      poss[2].push_back(player); // row3
      poss[3].push_back(player); // col1
      poss[7].push_back(player); // diag2
      break;
    case 8:
      poss[2].push_back(player); // row3
      poss[4].push_back(player); // col2
      break;
    case 9:
      poss[2].push_back(player); // row3
      poss[5].push_back(player); // col3
      poss[6].push_back(player); // diag1
      break;
    default:
    // invalid input
      break;
  }
  } else {
    cout << "Invalid turn. Moving to next player.\n";
  }
}

int check_winner() {
  // iterate through every possibility
  for (int i = 0; i < poss.size(); i++) {
    int value = 0;
    bool winner = true;
    // only iterate through possibilty if there are three elements
    if (poss[i].size() == 3) {
      value = poss[i][0];
      // check every element in possibility vector to make sure they are the same
      for (int j = 0; j < 3; j++) {
        if (value != poss[i][j]) {
          winner = false;
        }
      }
      // after iterating through a whole possibility, if all elements are the same, then there is a winner
      if (winner) {
        return value;
      }
    }
  }
  // if after iterating through every possibility, there is no winner
  return 0;
}

void print_winner(int winner) {
  if (winner != 0) {
    cout << "\n=====================================\n\n=====================================\nWE HAVE A WINNER!\nPlayer " << winner << " wins!\n";
  } else {
    cout << "Game has ended in a tie. No winner.\n";
  }
  print_board();
}
