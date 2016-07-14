#include "stdio.h"
#include "stdlib.h"

int main(){
  int N;
  int * layout;
  int * sums;
  layout = malloc(200*sizeof(int));//i dont think we need this either
  sums = malloc(200*sizeof(int));//we need only one string
  char * str = malloc(200*sizeof(char));
  int e = scanf("%d",&N);
  if(e == EOF) return 1;
  int i,j,k;
  int m,n;
  int max;
  for (i = 0; i < N; i++){
    for (j = 0; j < 200; j ++)
      sums[j] = -1;
    sums[0] = 0;
    int e = scanf("%d",&m);
    if(e == EOF) return 1;
    e = scanf("%d",&n);
    if(e == EOF) return 1;
    max = 0;
    for(k = 0; k < n; k++){
      //read one line;
        int e = scanf("%s", str);
	if(e == EOF) return 1;
      for(j = 0; j < m; j++){
        switch (str[j]){
          case '0':
            layout[j] = 0;
            break;
          case 'T':
            layout[j] = 1;
            break;
          case '#':
            layout[j] = -1;
            break;
          default:
            break;
        }
      }
      int start;
      int step;
      int end;
      if(k%2){
        start = m-1;
        step = -1;
        end = -1;
      } else {
        start = 0;
        step = 1;
        end = m;
      }
      int down;
      int side;
      for(j = start; j != end; j += step){
        if(j == start){
          if(layout[j] == -1 || sums[j] == -1){
            sums[j] = -1;
          } else {
            sums[j] += layout[j];
          }
        } else {
          if(layout[j] == -1){
            sums[j] = -1;
          } else {
            down = sums[j] == -1 ? -1 : sums[j] + layout[j];
            side = sums[j-step] == -1 ? -1 : sums[j-step] + layout[j];
            sums[j] = down > side ? down : side;
          }
        }
        max = sums[j]>max?sums[j]:max;
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
