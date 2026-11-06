#include <stdio.h>
#include <string.h>

int main()
{
  char cities[5][50];
 int i;
   int max = 0;
 int maxIndex = 0;

 printf("Enter 5 city names:\n");
  for(i=0; i<5; i++){
    fgets(cities[i], 50, stdin);
   cities[i][strlen(cities[i])-1] = '\0';
  }

  printf("\nAll Cities:\n");
 for(i=0; i<5; i++){
   printf("%s\n", cities[i]);
    if((int)strlen(cities[i]) > max){
      max = (int)strlen(cities[i]);
     maxIndex = i;
    }
 }

  printf("\nLongest city name: %s\n", cities[maxIndex]);
 printf("Length: %d\n", max);

 return 0;
}
