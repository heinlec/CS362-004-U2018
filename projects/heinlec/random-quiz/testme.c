#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//reference for ASCII characters: https://www.asciitable.com/

char inputChar()
{
 	//select characters via their ASCII decimal value, range 32 to 125
    	int min = 32;   //ASCII decimal for space
	int max = 125;   //ASCII decimal for }

	char randChar = (rand() % max) + min;
	return randChar;

}
char *inputString()
{
	//select lower case characters via their ASCII decimal value, range e - t  
    	//build a 6 character random string from the range of letters
	static char s[6];
	
	//range 0-15, adding 101 brings us into the ASCII value range of e - t
	int i = 0;
	while (i < 5) {
		s[i] = (rand() % 16) + 101;
		i++;
	}

	return s;
}
void testme()
{
int tcCount = 0;
//char s[] = "myTmp";
char *s;
char c;
//char* charPtr = &c;
int state = 0;
while (1)
{
tcCount++;
c = inputChar();
s = inputString();
printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, 
state);
if (c == '[' && state == 0) state = 1;
if (c == '(' && state == 1) state = 2;
if (c == '{' && state == 2) state = 3;
if (c == ' '&& state == 3) state = 4;
if (c == 'a' && state == 4) state = 5;
if (c == 'x' && state == 5) state = 6;
if (c == '}' && state == 6) state = 7;
if (c == ')' && state == 7) state = 8;
if (c == ']' && state == 8) state = 9;
if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
{
printf("error ");
exit(200);
}
}
}
int main(int argc, char *argv[])
{
srand(time(NULL));
testme();

return 0;
}
