#include <iostream>
#include <vector>
#include <cstring>
using namespace std; // Student list program by Zach Russell, completed 10/23/24

struct Student {
  char fName[10];
  char lName[10];
  int id;
  float gpa;
};

void printStudent (Student* x){ // Prints one student

  cout << "Name: " << (x -> fName) << " " << (x -> lName) << " id# : " << (x -> id) << " gpa# : " << (x -> gpa) << endl;
}

void printAll (vector<Student*> x){ // Prints all students
  for(int i = 0; i < x.size(); i++){
    printStudent(x[i]);
    cout << "" << endl;
  }
}

void addStudent (vector<Student*>& x){ // Adds a new student using user input
  Student* pA = new Student;

  cout << "enter fName" << endl;
  cin.getline(pA -> fName, 20, '\n');
  cout << "enter lName" << endl;
  cin.getline(pA -> lName, 20, '\n');
  cout << "enter id" << endl;
  cin >> (pA -> id);
  cin.ignore();
  cout << "enter gpa" << endl;
  cin >> (pA -> gpa);
  cin.ignore();

  x.push_back(pA);

}

void deleteStudent (vector<Student*>& x, int givenid){ // deletes a student and its pointer given the student ID
  int pos = -1;
  for(int i = 0; i < x.size(); i++){
    if (x[i] -> id == givenid){
      pos = i;
    }
  }
  if (pos != -1){
    delete x[pos];
    x.erase(x.begin() + pos);
  }
}

int main(){ // Main program loop, prompts for input and runs the given task
  bool runnig = true;
  vector<Student*> StuVec;
  char input[20];
  while (runnig == true){
    for (int i = 0; i < 20; i++){
      input[i] = '\n';
    }
    cout << "enter 'ADD' to add a student, enter 'PRINT' to print the list of students, enter 'DELETE' to remove a student, or enter 'QUIT to quit" << endl;
    cin >> input;
    cin.ignore();

    if (strcmp(input, "ADD")== 0){
      cout << "adding student" << endl;
      addStudent(StuVec);
    }

    else if (strcmp(input, "PRINT") == 0){
      printAll(StuVec);
    }

    else if (strcmp(input, "DELETE") == 0){
      int numberphone = -1;
      cout << "enter the ID of the student you would like to remove" << endl;
      cin >> numberphone;
      if (numberphone != -1){
	cout << "deleting " << numberphone << endl;
	deleteStudent(StuVec, numberphone);
      }
    }
    else if (strcmp(input, "QUIT") == 0){
      cout << "exiting program" << endl;
      runnig = false;
    }
    else{
      cout << input << endl;
      cout << "unknown command" << endl;
    }
  }
  return 0;
}
