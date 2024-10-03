#include <iostream>
#include <cstring>

using namespace std; // Zach Russell, 10/3/2024 - 2 player local tic-tac-toe game in the command line

int print_board(char board[3][3], char player) // prints the board
{
  cout << "\t" << "\t" << "0" << "\t" << "1" << "\t" << "2" << endl;

  int i, j;

  for(i = 0; i <= 2; i++)
    {
      cout << '\t' << i;
      for(j = 0; j <= 2; j++)
        {
          cout <<"\t"<< board[i][j];
        }
      cout<<endl;
    }
  return 0;
}
int check_win(char board[3][3], char player){ // checks for a win
  bool winner = false;
  for (int i = 0; i < 3; i++){
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == player){
      winner = true;
    }
    else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == player){
      winner = true;
    }
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == player){
    winner = true;
  }
  else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == player){
    winner = true;
  }
  if (winner == true){
    return 1;
  }
  else {
    return 0;
  }
}
int check_tie(char board[3][3]){ // checks for a tie
  int count = 0;
  bool tiegame = false;
  int i,j;
  for (int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if (board[i][j] != '-'){
	count++;
      }
      if (count >= 9){
	tiegame = true;
      }
    }
  }
  if (tiegame == true){
    return 1;
  }
  else {
    return 0;
  }
}
int make_move(char board[3][3], char player, int row, int col, int& xwins, int& owins){ // places the player, does the post-win + tie
  if (board[row][col] == '-'){
    board[row][col] = player;
    if (check_win(board,player) == 1){
      if (player == 'X'){
	xwins++;
      }
      else{ // o and x win counters
	owins++;
      }
      cout << player << " wins" << endl;
      cout << "if you want to play again, type 'y'" << endl;
      char choice;
      cin >> choice;
      if (choice == 'y'){ // new game
	int i, j;
	for (int i = 0; i < 3; i++){
	  for (int j = 0; j < 3; j++){
	    board[i][j] = '-';
	  }
	}
      }
    }
    else if (check_tie(board) == 1){
      cout << "tie game" << endl;
      cout << "if you want to play again, type 'y'" << endl;
      char choice;
      cin >> choice;
      if (choice == 'y'){
	int i, j;
	for(int i = 0; i < 3; i++){
	  for(int j = 0; j < 3; j++){
	    board[i][j] = '-';
	  }
	}
      }
    }
  }
  else {
    cout << "that space is taken" << endl;
     cout << "enter a row" << endl;
     cin >> row;
     cout << "enter a col" << endl;
     cin >> col;
     make_move(board, player, row, col, xwins, owins);
  }
  return 0;
}
int take_turn(char board[3][3], char player, int& xwins, int& owins) // running through what happens on a turn (input, move, board)
{
  print_board(board,player);
  cout << player << "'s turn." << endl;
  cout << "x wins:" << xwins << endl;
  cout << "o wins:" << owins << endl;
  int row;
  int col;
  cout << "enter a row" << endl;
  cin >> row;
  cout << "enter a col" << endl;
  cin >> col;
  if (0 <= row < 3){
    if (0 <= col < 3){
      make_move(board, player, row, col, xwins, owins);
      if (player == 'X'){
	player = 'O';
      }
      else {
	player = 'X';
      }
      take_turn(board, player, xwins, owins);
    }
  }
  else{
    cout << "invalid move" << endl;
    take_turn(board,player, xwins, owins);
  }
  return 0;
}
int main() // main :3
{
  char board[3][3] = {
    {'-','-','-'},
    {'-','-','-'},
    {'-','-','-'}
  } ;
  int xwins = 0;
  int owins = 0;
  char player = 'X';
  
  take_turn(board, player, xwins, owins);
}
