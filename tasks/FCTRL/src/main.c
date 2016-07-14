
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: 9999
int main(){
  int N;
  int i;
  int e = scanf("%d", &N);
  if(e == EOF) return 1;
  for(i = 0; i < N; i++){

    int t;
    int e = scanf("%d", &t);  // > 0
    if(e == EOF) return 1;
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
