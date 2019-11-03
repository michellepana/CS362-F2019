#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
   
    //Generate random number between 32 and 125 to cover all the possible if statements in testme()
    //num = (rand() % (upper – lower + 1)) + lower
    char randomChar = (rand()%(125 - 32 + 1)) + 32;
    return randomChar;
}

char *inputString()
{
    // TODO: rewrite this function
    static char s[6];		//creating a string
  	int i = 0;
  
  	//Possible input chars are ranging from 97 - a to 122 - z, closer range is 101 - e to 116 - t
  	while (i < 5) 
  	{
  		s[i] = (rand()%(116 - 101 + 1)) + 101;
  		i++;
  	}

    return s;
    
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    printf("in main ");
    srand(time(NULL));
    testme();
    return 0;
}
