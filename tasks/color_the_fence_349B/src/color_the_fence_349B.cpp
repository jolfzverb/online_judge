#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#define VAL 1000000007

int main(){
  int N;
  int k;
  int k_vol = 1000000;
  std::cin >> N;
  std::vector<int> v(10);
  for (int i = 1; i < 10; i ++){
    int t;
    std::cin >> t;
    v[i] = t;
    if(k_vol >= t){
      k = i;
      k_vol = t;
    }
  }
  if(N < k_vol){
    std::cout << -1 << std::endl;
    return 0;
  }
  int count = N / k_vol;
  N = N % k_vol;
  //now we can print count digits of k
  std::vector<int> add(10);
  for (int i = 9; i > k; i--){
    if(v[i]-k_vol <= N){
      add[i] = N/(v[i]-k_vol);
      N = N %(v[i]-k_vol);
    }
  }
  int c = 0;
  for(int i = 9; i > 0; i--){
    for(;add[i]>0; add[i]--){
      std::cout << i;
      c++;
    }
  }
  for(;c < count; c++){
    std::cout << k;
  }
  std::cout << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
