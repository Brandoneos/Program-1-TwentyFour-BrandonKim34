#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc,char* argv[]) {
  char str1[4];
  printf("Enter a 3 character string: ");
  // scanf("%s",str1);
  printf("\n");
  // char str2[] = {'t','a','x'};
  char str3[3] = "Tax";
  // char str4[3] = {"Tax"};
  printf("Here: \n");
  printf("%c\n",str3[0]);
  if (str3[0] == 'T') {
    printf("Confirmed character.\n");
  }
  // printf("%s\n",str2);
  // printf("%s\n",str3); 
  // printf("%s\n",str4);
  
  return 0;
}