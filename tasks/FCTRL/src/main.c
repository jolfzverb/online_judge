
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: 9999
int main(){
  int N;
  int i;
  scanf("%d", &N);
  for(i = 0; i < N; i++){

    int t;
    scanf("%d", &t);  // > 0
    int sum = 0;
    while(t/5){
      sum+=t/5;
      t/=5;
    }
    printf("%d\n",sum);

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