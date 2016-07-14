#include <stdio.h>
#include <stdlib.h>
/**
 * Spoj problem TEST
 * prints all numbers from input until 42 is found
 */
int main() {
  int N, i, j;
  int len = 0;
  int max = 0;
  int allocated = 10;
  int * list = malloc(allocated*sizeof(int));
  list[0] = 2;
  list[1] = 3;
  list[2] = 5;
  list[3] = 7;
  len = 4;
  max = 9;
  int e = scanf("%d", &N);
  if(e == EOF) return 1;
  for(i = 0; i < N; i++){
    if(i)printf("\n"); 
    //printf("started N cycle, %d %d\n", i, N); 
    int a,b;
    int e = scanf("%d", &a);
    if(e == EOF) return 1;
    e = scanf("%d", &b);
    if(e == EOF) return 1;
    if(b>max){ // generating new numbers
      //printf("started generation, %d %d\n", b, max); 
      for (j = max+2; j <=b; j+=2){
        // j is probable next prime
        //printf("checking j, %d...", j); 
        
        int index = 1;
        int number;
        int prime=1;
        for(number=list[index]; number*number<=j && index<len; number=list[++index]){
          //printf("number %d %d %d %d\n", number, max, len, index); 
          if (!(j%number)){
            //not prime
            //printf("not prime\n"); 
            prime=0;
            break;
          }
        }
        if(prime){
            //printf("prime\n"); 
          if(len==allocated){
             list=realloc(list,allocated*2*sizeof(int));
             allocated*=2;
          }
          list[len++] = j;
        }
        max = j;
      }
    }
    //printf("printing %d %d %d\n", a, b, len);
    int * p;
    for (p = list; p != list+len; p++){
      if(*p>=a && *p <=b) printf("%d\n", *p); 
    }
  }
  return 0;
}
