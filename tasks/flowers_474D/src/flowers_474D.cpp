#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/vector.cpp"

#define VAL 1000000007 
int main(){
  int T;
  int K;
  std::cin >> T >> K;
  vector<int> l(100001);
  l[0] = 1;
  for(int i = 1; i < K; i++){
    l[i] = 1;
    //    std::cout << i << " " << l[i].first << " " << l[i].second << std::endl;
  }
  for(int i = K; i < 100001; i++){
    l[i] = (l[i-1]+l[i-K])%VAL;
    //    std::cout << i << " " << l[i].first << " " <<  l[i].second << std::endl;
  }
  int s = 0;
  vector<int> sum(100001);
  for (int i = 0; i < 100001; i++){
    s+=l[i];
    s%=VAL;
    sum[i] = s;
    //    std::cout << i << " " << sum[i] << std::endl;
  }
  
  for(int i = 0; i < T; i++){
    int a;
    int b;
    std::cin >> a >> b;
    int res = sum[b] - sum[a-1];
    if(res < 0) res+=VAL;
    std::cout << res << std::endl;
  }
  


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
