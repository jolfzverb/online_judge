#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * a, char * t){
  int i;
  int len = strlen(t);
  for(i = 0; i < len; i++)
    *a++ = t[len-i-1];
  *a = '\0';
  return;
}

// TODO: 9999
int main(){
  int N;
  int i;
  int e = scanf("%d", &N);
  if (e == EOF) return 1;
  char * a = malloc(30*sizeof(char));
  char * b = malloc(30*sizeof(char));
  char * t = malloc(30*sizeof(char));
  for(i = 0; i < N; i++){

    int e = scanf("%s", t);  // > 0
    if (e == EOF) return 1;
    reverse(a,t);
    int a1 = atoi(a);
    e = scanf("%s", t);  // > 0
    if (e == EOF) return 1;
    reverse(b,t);
    int b1 = atoi(b);
    snprintf(t, 30, "%d", a1+b1);
    reverse(a,t);
    printf("%d\n",atoi(a));

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
  free(a);
  free(b);
  free(t);
  return 0;
}
