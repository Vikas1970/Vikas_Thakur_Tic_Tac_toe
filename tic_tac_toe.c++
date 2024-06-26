#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
void drawBoard() {
  cout << "  |  |  " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " | ";
    }
    cout << endl;
    if (i < 2) {
      cout << "-----+-----+-----" << endl;
    }
  }
  cout << "  |  |  " << endl;
}
int getPlayerMove(char player) {
  int move;
  while (true) {
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;
    if (move >= 1 && move <= 9) {
      int row = (move - 1) / 3;
      int col = (move - 1) % 3;
      if (board[row][col] == ' ') {
        return move;
      } else {
        cout << "Invalid move. Spot already taken." << endl;
      }
    } else {
      cout << "Invalid move. Enter a number between 1 and 9." << endl;
    }
  }
}
bool checkWin(char player) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}
bool isDraw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}
int main() {
  char currentPlayer = 'X';
  while (true) {
    drawBoard();
    int move = getPlayerMove(currentPlayer);
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
    if (checkWin(currentPlayer)) {
      drawBoard();
      cout << "Player " << currentPlayer << " wins!" << endl;
      break;
    } else if (isDraw()) {
      drawBoard();
      cout << "It's a draw!" << endl;
      break;
    }
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }
  return 0;
}