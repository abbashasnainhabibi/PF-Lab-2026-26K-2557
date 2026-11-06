#include <stdio.h>
#include <stdlib.h>

int main()
{
 FILE *fp;
   char name[50];
  int i;
 int count = 0;

  fp = fopen("students.txt", "w");
 if(fp == NULL){
    printf("Error opening file!\n");
   return 1;
 }

  printf("Enter 3 student names:\n");
 for(i=0; i<3; i++){
   scanf("%s", name);
    fprintf(fp, "%s\n", name);
  }
 fclose(fp);

  fp = fopen("students.txt", "r");
 if(fp == NULL){
   printf("Cannot read file\n");
    return 1;
 }

  printf("\nNames read from students.txt:\n");
 while(fscanf(fp, "%s", name) != EOF){
    count++;
   printf("%d. %s\n", count, name);
 }
  fclose(fp);

 printf("Total students in file: %d\n", count);

return 0;
}
