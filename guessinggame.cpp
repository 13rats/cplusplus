#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
  int input = 0;
  int compNum = 0;
  srand(time(NULL));
  compNum = rand() % 100 + 1;
  cout << "guess what number i'm thinking of. 1-100" << endl;
  cout << compNum << endl;
  while (input != compNum){
    cin >> input;
    if (input == compNum){
      cout << "you got it! I was thinking of " << compNum << endl;
    }
    else {
      cout << "not quite, try again!" << endl;
    }
  }
  cout << "would you like tp play again (y/n)" << endl;
  char again;
  cin >> again;
  if (again == 'y'){
      main();
  }
}
