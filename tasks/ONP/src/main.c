#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
char* operators_start;
char* cur;
void push(char a){
  if(!a)
    return;
  *cur++ = a;
}
char pop(){
  if(cur==operators_start)
    return '\0';
  return *(--cur);
}

void transform(char * start){
  char a;
  while(*start){
    switch(*start){
      case '(':
        push(*start++);
        break;
      case ')':
        while(a = pop(), (a && a != '(')){
          printf("%c",a);
        }
        start++;
        break;
      case '^':
        push(*start++);
        break;
      case '*':
      case '/':
        while(a = pop(), (a && a == '^'))
          printf("%c",a);
        push(a);
        push(*start++);
        break;
      case '+':
      case '-':
        while(a = pop(), (a == '^' || a == '*' || a == '/'))
          printf("%c",a);
        push(a);
        push(*start++);
        break;
      default:
        if(isalpha(*start)){
          printf("%c", *start++);
          break;
        }
        break;
    }
  }
  while(a = pop()){
    if(!a)
      break;
    printf("%c",a);
  }
  printf("\n");
}



int main(){
  int N;
  int i;
  char * string;
  operators_start = cur = malloc(400*sizeof(char));
  string = malloc(400*sizeof(char));
  scanf("%d",&N);
  for (i = 0; i< N; i++){
    cur = operators_start;
    scanf("%s", string);
    transform(string);
  }
  return 0;
}
