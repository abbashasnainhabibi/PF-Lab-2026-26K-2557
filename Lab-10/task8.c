#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t)
{
 int i = 0;
   int j = 0;

 while(i < (int)strlen(s) && j < (int)strlen(t)){
    if(s[i] == t[j]){
      i++;
    }
   j++;
 }

  if(i == (int)strlen(s)){
   return true;
  }
 else{
     return false;
 }
}

int main(){
 char s[100];
   char t[100];

  printf("Enter string s: ");
 scanf("%s", s);

   printf("Enter string t: ");
  scanf("%s", t);

 if(isSubsequence(s, t) == true){
   printf("Result: true\n");
 }
  else{
    printf("Result: false\n");
  }

return 0;
}
