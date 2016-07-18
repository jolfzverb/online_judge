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
  int l0 = 0;//first 0 before first 1
  int l1 = 0;//first 1;
  int r1 = 0;// l1 plus K ones and points to zero
  int r0 = 0;// r1 and all the zeroes and points to one
  while(l1 < N && s[l1]=='0') l1++;
  r1 = l1;
  int count = 0;
  while (r1 < N && count < K){
    if(s[r1]=='1') count ++;
    r1++;
  }
  r0 = r1;
  while(r0 < N && s[r0] == '0')r0++;
  int res = 0;
  res += (l1 - l0) * (r0-r1);
  

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
