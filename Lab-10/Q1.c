#include <stdio.h>
#include <string.h>

int main()
{
 char name[100];
   char copy[100];
  int len;

  printf("Enter your name: ");
   fgets(name, 100, stdin);

 name[strlen(name)-1] = '\0';
   len = strlen(name);

    printf("Length of name: %d\n", len);

   strcpy(copy, name);
 printf("Copied name: %s\n", copy);

  printf("sizeof of array is: %d\n", (int)sizeof(name));
   printf("strlen of name is: %d\n", (int)strlen(name));

return 0;
}
