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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  std::cin >> T;
  vector<int> val(5000001, 1);
  val[0] = 0;
  val[1] = 0;
  for(int i = 2; i < 5000001; i++){
    for (int j = 2; j <= i; j++){
      if(i*j > 5000000) break;
      val[i*j] = val[i] + val[j];
    }
  }
  int s = 0;
  vector<int> sum(5000001, 0);
  for (int i = 0; i < 5000001; i++){
    s+=val[i];
    sum[i] = s;
  }
  for (int i = 0; i < T; i++){
    int a;
    int b;
    std::cin >> a >> b;
    std::cout <<   sum[a] - sum[b]<< "\n";
  }

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
