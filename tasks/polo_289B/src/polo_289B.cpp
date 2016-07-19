#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/vector.cpp"
#include "lib/algo.cpp"
#define VAL 1000000007

int main(){
  int N;
  int M;
  int D;
  std::cin >> N >> M >> D;
  vector<int> a(N*M);
  int min = 100000;
  for(int i =0; i < N*M; i++){
    int t;
    std::cin >> t;
    a[i] = t;
    min = min > t ? t : min;
  }
  sort(a.begin(), a.end());
  int sum = 0;
  vector<int> s(N*M);
  for (int i = 0; i < N*M; i++){
    a[i] -= min;
    if(a[i]%D){
      std::cout << -1 << std::endl;
      return 0;
    }
    a[i]/=D;
    sum += a[i];
    s[i] = sum;
  }
  /*  for(int i = 0; i < N*M; i++){
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;*/
  sum = 0;
  for (int i = 0; i < N*M; i++){
    int t = a[(N*M-1)/2] - a[i];
    t = t > 0 ? t : -t;
    sum += t;
  }
  std::cout << sum << std::endl;







  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
