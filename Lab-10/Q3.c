#include <stdio.h>
#include <string.h>

int main()
{
  char pass[30] = "lab10pass";
 char user[30];

 printf("Enter password: ");
   scanf("%s", user);

  if(strcmp(user, pass) == 0){
  printf("Access granted\n");
  }
 else {
    printf("Access denied\n");
 }

   if(strncmp(user, pass, 3) == 0){
  printf("First 3 characters match.\n");
   }
   else{
    printf("First 3 characters do not match.\n");
   }

 return 0;
}
