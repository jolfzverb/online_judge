#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#define VAL 1000000007

int main(){
  int M;
  int N;
  std::cin >> M >> N;
  std::vector<int> r(N+1);
  for(int i = 0; i < M; i++){
    for(int j = 1; j <= N; j++){
      int t;
      std::cin >> t;
      int k = r[j] > r[j-1] ? r[j] : r[j-1];
      r[j] = k+t;
    }
    std::cout << r[N] << " ";
  }
  std::cout << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
