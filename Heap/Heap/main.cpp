#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std; // Zach Russell, 2/24/25, Heap program for C++/Data Structures

void print(int* array, int pos, int depth, int size);
void removeL(int* array, int pos, int& size);
void removeA(int* array, int pos, int& size);

int main(){ // main user input loop
  int SIZE = 101;
  int SPOT = 1;
  int CAP = 0;
  int* array = new int[SIZE];
  for (int i = 0; i < 101; i++){
    array[i] = -1;
  }
  ifstream file("numbers.txt");

  bool mainLoop = true;
  bool fileLoop = true;

  while (mainLoop == true){
    char input[20];
    for (int i = 0; i < 20; i++){
      input[i] = '\n';
    }
    cout << "enter 'ADD' to add a number manually, enter 'FILE' to add numbers from numbers.txt, enter 'PRINT' to print the tree, enter 'REMOVE' to remove the largest number from the tree, and enter 'ALL' to remove every number in the tree" << endl;
    cin >> input;
    cin.ignore();

    if (strcmp(input, "ADD")== 0){ // adding numbers manually
      cout << "how many numbers would you like to add" << endl;
      int inpo = 0;
      cin >> inpo;
      if (CAP + inpo > 100){
	cout << "too many numbers, please enter 100 or fewer." << endl;
      }
      else{
	CAP = CAP+inpo;
      }
      cout << "enter your numbers seperated by spaces" << endl;
      if (CAP <= 100){
	for(SPOT; SPOT < CAP + 1; SPOT++){
	  cin >> array[SPOT];
	  float PID = (SPOT/ 2);
	  int parID = floor(PID);
	  int cur = array[SPOT];
	  int temp = array[parID];
	  if (SPOT != 1){
	    int a = SPOT;
	    while ((array[SPOT] > array[parID]) && (SPOT != 1)){
	      int big = array[SPOT];
	      int small = array[parID];
	      array[parID] = big;
	      array[SPOT] = small;
	      SPOT = parID;
	      PID = (SPOT/2);
	      parID = floor(PID);
	    }
	    SPOT = a;
	  }
	}
      }
      print(array, 1, 0, SIZE);
    }
    
    else if(strcmp(input, "FILE")== 0){ // adding numbers from the file "numbers.txt"
      cout << "how many numbers would you like to load in. MAX is 100" << endl;
      int inpint = 0;
      cin >> inpint;
      if (inpint > 100 || inpint < 1){
	cout << "this is an invalid amount. you can only add between 1 and 100 numbers." << endl;
      }
      else {
	while (fileLoop == true){
	  for (SPOT; SPOT < inpint+1; SPOT++){
	    file >> array[SPOT];
	    float PID = (SPOT / 2);
	    int parID = floor(PID);
	    int cur = array[SPOT];
	    int temp = array[parID];
	    if (SPOT != 1){
	      int a = SPOT;
	      while ((array[SPOT] > array[parID]) && (SPOT != 1)){
		int big = array[SPOT];
		int small = array[parID];
		array[parID] = big;
		array[SPOT] = small;
		SPOT = parID;
		PID = (SPOT/2);
		parID = floor(PID);
	      }
	      SPOT = a;
	    }
	  }
	  fileLoop = false;
	}
      }
    }
    else if (strcmp(input, "REMOVE") == 0){ // removing the largest number
      if(SIZE < 1){
	cout << "heap is empty, nothing to remove" << endl;
      }
      else{
	cout << "largest: " << array[1] << endl;
	array[1] = array[SIZE];
	array[SIZE] = -1;
	SIZE--;
	removeL(array, 1, SIZE);
	print(array, 1, 0, SIZE);
      }
    } 
    else if (strcmp(input, "ALL") == 0){ // removing every number, 1 by 1, removing the largest one every time
      removeA(array, 1, SIZE);
    }

    else if (strcmp(input, "PRINT")==0){ // prints the Heap
      print(array, 1, 0, SIZE);
    }
  }
  return 0;
}

void print(int* array, int pos, int depth, int size){
  if(pos > size || array[pos] == -1){
    return;
  }
  if (pos * 2 + 1 <= size){ // check right
    print(array, pos * 2 + 1, depth + 1, size); // recursive right call
  }
  for (int a = 0; a < depth; a++){
    cout << '\t';
  }
  cout << array[pos] << endl;
  if (pos*2 <= size){ // check left
    print(array, pos*2, depth+1, size); // recursive left
  }
}

void removeL(int* array, int pos, int& size){ // removing the largest number
  int leftC = pos*2;
  int rightC = pos*2+1;
  int largest = pos;
  
  if (leftC <= size && array[leftC] > array[largest]){
      largest = leftC;
  }
  if (rightC <= size && array[rightC] > array[largest]){
    largest = rightC;
  }

  if (largest != pos) {
    int temp = array[pos];
    array[pos] = array[largest];
    array[largest] = temp;
    removeL(array, largest, size);
  }
}

void removeA(int* array, int pos, int& size){ // calls the removeL untill all numbies are gone
  while(size > 0){
    cout << "removing: " << array[1] << endl;
    array[1] = array[size];
    array[size] = -1;
    size--;
    removeL(array, 1, size);
  }
  cout << "all numbies removed" << endl;
}
