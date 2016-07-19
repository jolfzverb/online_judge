#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/vector.cpp"
#define VAL 1000000007

int main(){
  int V1;
  int V2;
  int T;
  int D;
  std::cin >> V1 >> V2 >> T >> D;
  vector<int> s(T);
  s[0]=V1;
  s[T-1] = V2;
  int i = 1;
  int j = T-2;
  while (i < j) {
    if(V1 > V2){
      V2+=D;
      s[j] = V2;
      j--;
    } else{
      V1+=D;
      s[i] = V1;
      i++;
    }
  }
  if(i == j)
    s[i] = V1>V2? V2+D : V1+D;
  int sum = 0;
  for (int i = 0; i < T; i++){
    sum += s[i];
  }
  std::cout << sum << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
