#include <iostream>
#include <cstring>
#include <climits>

using namespace std; // Zach Russell 5/29 graph creator + shortest path

void makeAdjTable(int** &adjTable, int &S, char* &labTable, bool first);
void addVertex(int** &adjTable, int &S, char* &labTable);
int labelInd(char* labTable, int S, char label);
void addEdge(int** adjTable, int S, char* labTable);
void printAdjTable(int** adjTable, int S, char* labTable);
void removeVertex(int** &adjTable, int &S, char* &labTable);
void removeEdge(int** adjTable, int S, char* labTable);
void shortestPath(int** adjTable, int S, char* labTable);

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
        cin.ignore(INT_MAX, '\n');
      }
    }
    adjTable[indA][indB] = weight;
  } else {
    cout << "invalid vertex entered. cannot add an edge to a non-existent vertex." << endl;
  }
}

void removeVertex(int** &adjTable, int &S, char* &labTable) {
  char label;
  cout << "please enter the 1 character label for the vertex to be removed" << endl;
  cin >> label;
  int ind = labelInd(labTable, S, label);
  if (ind != -1) {
    int** newAdjTable = new int*[S - 1];
    for (int i = 0; i < S - 1; i++) {
      newAdjTable[i] = new int[S - 1]();
    }
    char* newLabTable = new char[S - 1];
    int newI = 0;
    for (int i = 0; i < S; i++) {
      if (i != ind) {
        newLabTable[newI] = labTable[i];
        int newJ = 0;
        for (int j = 0; j < S; j++) {
          if (j != ind) {
            newAdjTable[newI][newJ] = adjTable[i][j];
            newJ++;
          }
        }
        newI++;
      }
    }
    for (int i = 0; i < S; i++) {
      delete[] adjTable[i];
    }
    delete[] adjTable;
    delete[] labTable;
    adjTable = newAdjTable;
    labTable = newLabTable;
    S--;
  } else {
    cout << "invalid vertex label." << endl;
  }
}

void removeEdge(int** adjTable, int S, char* labTable) {
  for (int i = 0; i < S; i++) {
    cout << labTable[i];
    if (i < S - 1) cout << ", ";
  }
  cout << endl;
  char vertA, vertB;
  cout << "which vertex does the edge to remove start at? " << endl;
  cin >> vertA;
  cout << "and which vertex does the edge to remove end at? " << endl;
  cin >> vertB;
  int indA = labelInd(labTable, S, vertA);
  int indB = labelInd(labTable, S, vertB);
  if (indA != -1 && indB != -1 && adjTable[indA][indB] != 0) {
    adjTable[indA][indB] = 0;
    cout << "edge removed." << endl;
  } else {
    cout << "no such edge exists." << endl;
  }
}

void shortestPath(int** adjTable, int S, char* labTable) {
  char start, end;
  cout << "enter the starting vertex label: " << endl;
  cin >> start;
  cout << "enter the ending vertex label: " << endl;
  cin >> end;
  int startInd = labelInd(labTable, S, start);
  int endInd = labelInd(labTable, S, end);
  if (startInd == -1 || endInd == -1) {
    cout << "invalid vertex label." << endl;
    return;
  }
  int* dist = new int[S];
  int* prev = new int[S];
  bool* visited = new bool[S]();
  for (int i = 0; i < S; i++) {
    dist[i] = INT_MAX;
    prev[i] = -1;
  }
  dist[startInd] = 0;
  for (int i = 0; i < S; i++) {
    int minDist = INT_MAX;
    int u = -1;
    for (int j = 0; j < S; j++) {
      if (!visited[j] && dist[j] < minDist) {
        minDist = dist[j];
        u = j;
      }
    }
    if (u == -1) break;
    visited[u] = true;
    for (int v = 0; v < S; v++) {
      if (!visited[v] && adjTable[u][v] > 0) {
        int newDist = dist[u] + adjTable[u][v];
        if (newDist < dist[v]) {
          dist[v] = newDist;
          prev[v] = u;
        }
      }
    }
  }
  if (dist[endInd] == INT_MAX) {
    cout << "no path exists." << endl;
  } else {
    cout << "shortest path: ";
    int* path = new int[S];
    int pathLen = 0;
    int curr = endInd;
    while (curr != -1) {
      path[pathLen++] = curr;
      curr = prev[curr];
    }
    for (int i = pathLen - 1; i >= 0; i--) {
      cout << labTable[path[i]];
      if (i > 0) cout << " -> ";
    }
    cout << endl << "total weight: " << dist[endInd] << endl;
    delete[] path;
  }
  delete[] dist;
  delete[] prev;
  delete[] visited;
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
    cout << "enter print, addE, addV, remV, remE, path, exit" << endl;
    cin >> input;
    if (strcmp(input, "print") == 0) {
      printAdjTable(adjTable, S, labTable);
    } else if (strcmp(input, "addE") == 0) {
      addEdge(adjTable, S, labTable);
    } else if (strcmp(input, "addV") == 0) {
      addVertex(adjTable, S, labTable);
    } else if (strcmp(input, "remV") == 0) {
      removeVertex(adjTable, S, labTable);
    } else if (strcmp(input, "remE") == 0) {
      removeEdge(adjTable, S, labTable);
    } else if (strcmp(input, "path") == 0) {
      shortestPath(adjTable, S, labTable);
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
