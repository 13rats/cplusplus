#include <iostream>
#include <string.h>

using namespace std; // Palindrome checking program made by Zach Russell, completed on 9/13/24

int main()
{
  char str[20];
  char str2[20];
  char str3[20];

  for (int i = 0; i < 20; i++){
    str[i] = '\0';
    str2[i] = '\0';
    str3[i] = '\0';
  }
  cout << "please enter the word/phrase" << endl; // Input
  cin.get(str,20);
  cin.get();
  
  int count = 0;
  int bigcount = 0;
  for (int i = strlen(str) - 1; i >= 0; i--) // Removing unwanted things and reversing the string
  {
    if (str[i] != '\0')
      {
	if (!ispunct(str[i]))
	{
	  str2[count] = (char)tolower(str[i]);
	  count++;
	}
      }
  }
  str2[count] = '\0';
  for (int i = 0; str[i] != '\0'; i++)
    {
      if(str[i] != '\0')
	{
	  if (!ispunct(str[i]))
	    {
	      str3[bigcount] = (char)tolower(str[i]);
	      bigcount++;
	    }
	}
    }
  str3[bigcount] = '\0';
  int result = 0; // The big reveal
  result = strcmp(str2, str3);
  cout << result << endl;
  if (result == 0){
    cout << "it is a palindrome" << endl;
  }
  else{
    cout << "not a palindrome" << endl;
  }
  
  return 0;
}
