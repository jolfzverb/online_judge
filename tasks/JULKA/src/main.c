#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct lint {
  int * num;
  int len;
};

struct lint read_lint(){
  char *s = malloc(128*sizeof(char));
  int e = scanf("%s", s);
  if(e == EOF) abort();
  struct lint ret;
  ret.len = strlen(s);
  ret.num = malloc(128*sizeof(int));
  char *t = s;
  int * ti = ret.num;
  while(*t)
    *ti++ = *t++ - '0';
  return ret;
}

//lin%2
int p(struct lint a){
  return a.num[a.len-1]%2;
}

//lin=lin/2;
void divby(struct lint a){
  int i;
  int overflow = 0;
  if(a.len < 2){
    a.num[0]/=2;
    return;
  }
  if(a.num[0]/2)
    for(i = 0; i < a.len; i++){
      int overflowt = (a.num[i]%2)*5;
      a.num[i] = a.num[i]/2 + overflow; 
      overflow = overflowt;
    }
  else {
    overflow = a.num[0]*5;
    for(i = 1; i < a.len; i++){
      int overflowt = (a.num[i]%2)*5;
      a.num[i-1] = a.num[i]/2+overflow;
      overflow = overflowt;
    }
    a.len--;
  }
}

struct lint sum(struct lint a, struct lint b){
  int * tmp = malloc(128*sizeof(int));
  int i;
  for(i = 0; i < 128; i ++)
    tmp[i] = 0;
  int len = a.len>b.len? a.len : b.len;
  len ++;
  for(i = 0; i < len; i ++){
    int ta = i < a.len ? a.num[len-i-1] : 0;
    int tb = i < b.len ? b.num[len-i-i] : 0;
    tmp[len - i - 1]  += ta + tb;
    if(tmp[len - i - 1] > 9){
      tmp[len - i - 1] -=10;
      tmp[len - i]++;
    }
    if(tmp[len-i-1]< 0){
      tmp[len - i - 1] +=10;
      tmp[len - i]--;
    }

  }
  struct lint res;
  res.len = len;
  res.num = tmp;
  return res;
}
    

void neg(struct lint a){
  int i;
  for (i = 0; i < a.len; i ++)
    a.num[i] = -a.num[i];
}

void plint(struct lint a){
  int * tmp = a.num;
  int N = a.len;
  while (!(*tmp++) && --N){}

  int i;
  for(i = 0; i < N; i++)
    printf("%d", *tmp++);
}
    

int main(){
  int i;
  
  //char * input;
  //int * klaud;
  //int * nat;
  //int * diff;
  for(i = 0; i < 10; i++){

    struct lint a = read_lint();
    struct lint b = read_lint();
    //int tmp = p(a);
    divby(a);
    divby(b);
    struct lint big = sum(a,b);
    neg(b);
    struct lint small = sum(a,b);
    plint(big);
    printf("\n");
    plint(small);
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
