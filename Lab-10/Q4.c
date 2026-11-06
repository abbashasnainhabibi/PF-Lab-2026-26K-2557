#include <stdio.h>
#include <string.h>

int main(){
 char str[150];
   char *ptr = NULL;

  printf("Enter a sentence: ");
   fgets(str, 150, stdin);

 str[strlen(str)-1] = '\0';

  ptr = strchr(str, 'a');
   if(ptr != NULL){
    int index = ptr - str;
   printf("First 'a' found at index %d\n", index);
   }
  else{
     printf("letter a not found\n");
  }

 if(strstr(str, "good") != NULL){
   printf("Word 'good' found.\n");
 }
  else {
    printf("Word 'good' not found.\n");
  }

return 0;
}
