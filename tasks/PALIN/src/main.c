#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct num{
  char * start;
  char * compare_left;
  char * compare_right;
  char * increment_start;
};


int all_nines(struct num a){
  char * ololo = a.start;
  while(*ololo)
    if(*ololo++ != '9')
      return 0;
  return 1;
}


void handle_nines(struct num a){
  int len = strlen(a.start);
  printf("1");
  while(--len)
    printf("0");
  printf("1\n");
}

void indexer(struct num * a, char * num){
  int len = strlen(num);
  a->start = num;
  if(len % 2) {
    a->compare_left = num + len/2 - 1;
    a->compare_right = num + len/2 + 1;
  } else {
    a->compare_left = num + len/2 - 1;
    a->compare_right = num + len/2;
  }
  a->increment_start = num + (len - 1) / 2;

}
int increment_needed(struct num a){
  char * left = a.compare_left;
  char * right = a.compare_right;
  while(*right) {
    if (*left != *right)
      return *left > *right ? 0 : 1;
    left --;
    right ++;
  }
  return 1;
}
void increment(struct num a){
  char *cur = a.increment_start;
  while(*cur == '9')
    *cur-- = '0';
  (*cur)++;
}
void duplicate(struct num a){
  char * left = a.compare_left;
  char * right = a.compare_right;
  while(*right) {
    *right++ = *left--;
  }
}
void print_num(struct num a){
  printf("%s\n",a.start);
}

void process(char*num){
  struct num a;
  indexer(&a, num);
  if(all_nines(a)){
    handle_nines(a);
    return;
  }
    
  if(increment_needed(a))
    increment(a);

  duplicate(a);
  print_num(a);


}
// TODO: 9999
int main(){
  int N;
  int i;
  int e = scanf("%d", &N);
  if(e == EOF) return 1;
  char * number = malloc(1000004*sizeof(char));
  for(i = 0; i < N; i++){

    int e = scanf("%s", number);  // > 0
    if(e == EOF) return 1;
    process(number);

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
  free(number);
  return 0;
}
