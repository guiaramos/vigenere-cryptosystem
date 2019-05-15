#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int shift(char c); // this functions convert the char into int

int main(int argc, char const *argv[])
{
  // Check if the argument was informed and not a negative
  int isInt = atoi(argv[1]); // assigning the key to a variable int for checking

  if (argc != 2 || argc < 0 || isdigit(isInt))
  {
    printf("Usage: ./vigenere keyword\n");
    return 1;
  }

  // Ask for the plaintext to be encrypted
  string plaintext = get_string("plaintext: ");
  int n = strlen(plaintext); // getting the length of the plaintext
  int lenK = strlen(argv[1]); // getting the length of the keywork
  int j = 0; // assigning for looping the keyword length

  printf("ciphertext: ");

  for (int i = 0; i < n; i++)
  {
    bool sNode = islower(plaintext[i]); // assigning to check the char type
    char x = plaintext[i]; // assigning for prompt

    if (isalpha(plaintext[i])) // first check if Alphabet
    {
      if (j == lenK) // reseting the keyword char
      {
        j = 0;
      }

      int k = shift(argv[1][j]); // transform the keyword into int
      j++; // junping to the next keyword

      if (sNode)
      {
        x = ((((plaintext[i] + k)- 97) % 26 ) +97);
      }
      else
      {
        x = ((((plaintext[i] + k)- 65) % 26 ) + 65);
      }
    }
    printf("%c", x); // printing for user
  }
  printf("\n"); // just formating for another line

}

int shift (char c)
{
  int s = 0;
  bool ctype = islower(c); // assigning to check the char type

  if (ctype)
  {
    s = (c - 97);
  }
  else
  {
    s = (c - 65);
  }
 return s;
}
