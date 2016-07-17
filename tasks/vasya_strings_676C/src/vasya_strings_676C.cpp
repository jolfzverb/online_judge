#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/string.cpp"
#define VAL 1000000007

int main(){
  int N;
  int K;
  std::cin >> N >> K;
  string s;
  std::cin >> s;
  int max = 0;
  int count = 0;
  int start = 0;
  for (int i = 0; i < N;){
    while(i < N && count < K){
      if(s[i] != 'a') count ++;
      i++;
    }
    while(i < N && s[i] == 'a') i++;
    max = max > i - start ? max : i - start;
    while(start < N && s[start] == 'a') start++;
    start++;
    count--;
  }
  count = 0;
  start = 0;
  for (int i = 0; i < N;){
    while(i < N && count < K){
      if(s[i] != 'b') count ++;
      i++;
    }
    while(i < N && s[i] == 'b') i++;
    max = max > i - start ? max : i - start;
    while(start < N && s[start] == 'b') start++;
    start++;
    count --;
  }
  std::cout << max << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
