#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/vector.cpp"
#define VAL 1000000007

int main(){
  int N;
  int K;
  std::cin >> N >> K;
  vector<int> l(N+1,1);
  vector<int> tmp(N+1, 0);
  for (int i = 1; i < K; i++){
    for (int j = 1; j <= N; j++){
      for( int k = 1; k <= N/j; k++){
	tmp[k*j]=(tmp[k*j]+l[j])%VAL;
	//	std::cout << i << " " << j <<  " "  << k << " " << tmp[k*j] << " " << l[j] << std::endl;
      }
    }
    l = tmp;
    tmp = vector<int>(N+1,0);
  }
  int sum = 0;
  for(int i = 1; i <= N; i++){
    sum = (sum + l[i])%VAL;
  }
  std::cout << sum << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
