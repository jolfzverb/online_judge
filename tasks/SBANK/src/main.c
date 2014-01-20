#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct num{
  int code;
  int bank;
  int num1;
  int num2;
  int num3;
  int num4;
};

int compare_nums(const void * p1, const void * p2){
  struct num * n1 = (struct num *) p1;
  struct num * n2 = (struct num *) p2;
  if(n1->code - n2->code)
    return n1->code - n2->code;
  if(n1->bank - n2->bank)
    return n1->bank - n2->bank;
  if(n1->num1 - n2->num1)
    return n1->num1 - n2->num1;
  if(n1->num2 - n2->num2)
    return n1->num2 - n2->num2;
  if(n1->num3 - n2->num3)
    return n1->num3 - n2->num3;
  if(n1->num4 - n2->num4)
    return n1->num4 - n2->num4;
  return 0;
}

read(struct num* n, int k){
  int i;
  for(i = 0; i < k; i ++){
    scanf("%d %d %d %d %d %d", &(n->code), &(n->bank), &(n->num1), &(n->num2), &(n->num3), &(n->num4));
    n++;
  }
}
p(struct num* n, int k){
  int c = 1;
  struct num pn;
  pn = *n++;
  int i;
  for(i = 1; i < k; i++){
    if(!compare_nums(&pn, n)){
      c++;
    }
    else {
      printf("%02d %08d %04d %04d %04d %04d %d\n", pn.code, pn.bank, pn.num1, pn.num2, pn.num3, pn.num4, c);
      c = 1;
      pn = *n;
    }
    n++;
  }
  printf("%02d %08d %04d %04d %04d %04d %d\n", pn.code, pn.bank, pn.num1, pn.num2, pn.num3, pn.num4, c);
}




// TODO: 9999
int main(){
  int N;
  int i;
  int k;
  scanf("%d", &N);
  struct num * number = malloc(100000*sizeof(struct num));
  for(i = 0; i < N; i++){

    scanf("%d", &k);  // > 0
    read(number, k);
    qsort(number, k, sizeof(struct num), compare_nums);
    p(number, k);
    if(i!=N-1)
    printf("\n");

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
