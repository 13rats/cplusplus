#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student{
 public:
  Student();
  Student(int inid, float ingpa, char* inname);
  void setID(int input);
  int getID();
  void setGPA(float input);
  float getGPA();
  void setName(char* input);
  char* getName();
  void stuPrint();
 private:
  int id;
  float gpa;
  char* name;
};
#endif
