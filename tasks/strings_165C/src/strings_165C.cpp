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
  int K;
  string s;
  std::cin >> K >> s;

  int N = s.length();
  long long left0 = 0;
  long long left1 = 0;
  long long right1 = 0;
  long long right0 = 0;
  int count = 0;
  long long sum = 0;
  if(K==0){
    long long start = 0;
    long long end = 0;
    while(start < N){
      while(start < N && s[start]=='1') start++;
      end = start;
      while(end < N && s[end]=='0') end++;
      sum += ((end-start)*(end-start+1))/2;
      start = end;
    }
  } else
  while(right0 < N){
    while(left1 < N && s[left1]=='0')left1++;
    while(right1 < N && count < K){
      if(s[right1]=='1') count++;
      right1++;
    }
    right0 = right1;
    while(right0 < N && s[right0]=='0') right0++;
    //    std::cout << left0 << " " << left1 << " " << right1 << " " << right0 << std::endl;
    if(count == K) sum+=(left1-left0+1ll)*(right0-right1+1ll);
    left0 = ++left1;
    count--;
  }
  std::cout << sum << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
