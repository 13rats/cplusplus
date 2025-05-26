#include <iostream>
#include <cstring>

using namespace std; // Zach Russell Graph Creator, 5/25/2025

void makeAdjTable(int** &adjTable, int &S, char* &labTable, bool first);
void addVertex(int** &adjTable, int &S, char* &labTable);
int labelInd(char* labTable, int S, char label);
void addEdge(int** adjTable, int S, char* labTable);
void printAdjTable(int** adjTable, int S, char* labTable);

int labelInd(char* labTable, int S, char label) {
  for (int i = 0; i < S; i++) {
    if (labTable[i] == label) {
      return i;
    }
  }
  return -1;
}

void makeAdjTable(int** &adjTable, int &S, char* &labTable, bool first) {
  if (first) {
    cout << "first is true, resetting table." << endl;
    for (int i = 0; i < S; i++) {
      for (int j = 0; j < S; j++) {
        adjTable[i][j] = 0;
      }
    }
  } else {
    cout << "first is false, expanding the table." << endl;
    int** newAdjTable = new int*[S + 1];
    for (int i = 0; i < S + 1; i++) {
      newAdjTable[i] = new int[S + 1]();
    }
    for (int i = 0; i < S; i++) {
      for (int j = 0; j < S; j++) {
        newAdjTable[i][j] = adjTable[i][j];
      }
    }
    for (int i = 0; i < S; i++) {
      delete[] adjTable[i];
    }
    delete[] adjTable;
    adjTable = newAdjTable;
    S++;
  }
}

void addVertex(int** &adjTable, int &S, char* &labTable) {
  if (S == 20) {
    cout << "already reached maximum number of vertices, cancelling add." << endl;
  } else {
    char label;
    cout << "please enter your 1 character label for the new vertex" << endl;
    cin >> label;
    if (labelInd(labTable, S, label) == -1) {
      char* newLabTable = new char[S + 1];
      for (int i = 0; i < S; i++) {
        newLabTable[i] = labTable[i];
      }
      newLabTable[S] = label;
      delete[] labTable;
      labTable = newLabTable;
      cout << "added " << label << " to the label list." << endl;
      makeAdjTable(adjTable, S, labTable, false);
    } else {
      cout << "that label has already been used. invalid :)" << endl;
    }
  }
}

void addEdge(int** adjTable, int S, char* labTable) {
  for (int i = 0; i < S; i++) {
    cout << labTable[i];
    if (i < S - 1) cout << ", ";
  }
  cout << endl;
  char vertA, vertB;
  cout << "which vertex does this new edge start at? " << endl;
  cin >> vertA;
  cout << "and which vertex does this new edge end at? " << endl;
  cin >> vertB;
  int indA = labelInd(labTable, S, vertA);
  int indB = labelInd(labTable, S, vertB);
  if (indA != -1 && indB != -1) {
    int weight = 0;
    while (weight <= 0) {
      cout << "and what is the weight of this edge? " << endl;
      cin >> weight;
      if (cin.fail() || weight <= 0) {
        cout << "invalid weight, must be greater than 0. please enter a new weight." << endl;
        cin.clear();
      }
    }
    adjTable[indA][indB] = weight;
  } else {
    cout << "invalid vertex entered. cannot add an edge to a non-existent vertex." << endl;
  }
}

void printAdjTable(int** adjTable, int S, char* labTable) {
  for (int i = 0; i < S; i++) {
    cout << labTable[i] << " ";
  }
  cout << endl;
  for (int i = 1; i < S; i++) {
    cout << labTable[i] << " ";
    for (int j = 1; j < S; j++) {
      cout << adjTable[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int S = 1;
  int** adjTable = new int*[S];
  for (int i = 0; i < S; i++) {
    adjTable[i] = new int[S]();
  }
  char* labTable = new char[S]();
  makeAdjTable(adjTable, S, labTable, true);
  while (true) {
    char input[20];
    cout << "enter print, addE, addV, exit" << endl;
    cin >> input;
    if (strcmp(input, "print") == 0) {
      printAdjTable(adjTable, S, labTable);
    } else if (strcmp(input, "addE") == 0) {
      addEdge(adjTable, S, labTable);
    } else if (strcmp(input, "addV") == 0) {
      addVertex(adjTable, S, labTable);
    } else if (strcmp(input, "exit") == 0) {
      break;
    } else {
      cout << "invalid selection." << endl;
    }
  }
  for (int i = 0; i < S; i++) {
    delete[] adjTable[i];
  }
  delete[] adjTable;
  delete[] labTable;
  return 0;
}
