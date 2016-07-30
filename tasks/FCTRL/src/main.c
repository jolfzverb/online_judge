
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

  }
  return 0;
}
