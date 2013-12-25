#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: 9999
int main(){
  int N;
  int i;
  int k;
  scanf("%d", &N);
  char * number = malloc(1000000*sizeof(char));
  for(i = 0; i < N; i++){

    scanf("%s", number);  // > 0

    int len = strlen(number);

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
    printf("\n");
  }
  return 0;
}
