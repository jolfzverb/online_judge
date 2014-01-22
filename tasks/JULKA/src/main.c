#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int i;
  
  char * input;
  int * klaud;
  int * nat;
  int * sum;
  int * diff;
  input = malloc(128*sizeof(char))
  klaud = malloc(128*sizeof(int))
  nat = malloc(128*sizeof(int))
  sum = malloc(128*sizeof(int))
  diff = malloc(128*sizeof(int))
  for(i = 0; i < 10; i++){
    int k;
    for(k = 0; k < 128; k ++)
      klaud[k] = nat[k] = sum[k] = diff[k] = 0;
    scanf("%s", input);
    int * temp = sum;
    for(k = strlen(input)-1;k >=0; k--)
      *temp++ = input[k] - '0';
    scanf("%s", input);
    temp = diff;
    for(k = strlen(input)-1;k >=0; k--)
      *temp++ = input[k] - '0';
    //klaud = sum/2+diff/2 +diff%2;
    //nat = sum/2-diff/2;
    for(k = 0; k < 128; k ++){
      klaud[k] = 


    /*int len = strlen(number);

    if (len%2) {
      if(number[len / 2 - 1] <= number[len / 2 + 1]){
        number[len/2]++;
      }
      for(k = 0; k < len/2+1; k++){
        printf("%c", number[k]);
      }
      for(k = len/2-1; k >=0; k--){
        printf("%c", number[k]);
      }
    } else {
      if(number[len/2-1] <= number[len/2])
        number[len/2-1]++;
      for (k = 0; k < len/2; k++)
        printf("%c", number[k]);
      for(k = len/2-1; k>=0; k--)
        printf("%c", number[k]);

    } 
    */
  }
  return 0;
}
