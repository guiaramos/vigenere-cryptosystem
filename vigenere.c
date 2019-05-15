#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// This a program for encrypt any text with caesar sytem.

/* Usage:
* When runing the user needs to inform a key to increment the plaintext
* after that, the user needs to inform the plain text to be encrypted
*/

int main(int argc, char const *argv[])
{
  // Check if the argument was informed and not a negative
  if (argc != 2 || argc < 0)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  // Ask for the plaintext to be encrypted
  string plaintext = get_string("plaintext: ");
  int n = strlen(plaintext); // getting the length of the plaintext

  int k = atoi(argv[1]); // assigning the key to a variable int

  printf("ciphertext: ");

  for (int i = 0; i < n; i++)
  {
    bool sNode = islower(plaintext[i]); // assigning to check the char type
    char x = plaintext[i]; // assigning for prompt

    if (isalpha(plaintext[i])) // first check if Alphabet
    {
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
