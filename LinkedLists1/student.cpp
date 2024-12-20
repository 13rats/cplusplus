#include "student.h"
#include <cstring>
#include <iostream>
Student::Student(){
  id = 0;
  gpa = 1.1;
  name = new char[20];
}
Student::Student(int inid, float ingpa, char* inname){
  name = new char[20];
  strcpy(name, inname);
  id = inid;
  gpa = ingpa;
}
void Student::setID(int input){
  id = input;
}
int Student::getID(){
  return id;
}
void Student::setGPA(float input){
  gpa = input;
}
float Student::getGPA(){
  return gpa;
}
void Student::setName(char* input){
  strcpy(name, input);
}
char* Student::getName(){
  return name;
}
void Student::stuPrint(){
  cout << name << " - " << id << " - " << gpa << "; ";
}
