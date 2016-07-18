#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/pair.cpp"
#define VAL 1000000007
int get(std::vector<pair<int,int> > &l, int K, int D, int N, int inc){
  //  std::cout << N << std::endl;
  if(inc){
    if(l[N].second != -1)
      return l[N].second;
  } else {
    if(l[N].first != -1)
      return l[N].first;
  }

  int sum = 0;
  if(inc) {
    for(int i = 1; i <= K; i++){
      if(N-i>=0)
	sum = (sum+get(l, K, D, N-i, 1))%VAL;
      else
	break;
    }
    for (int i = D; i <= K; i++){
      if(N-i>=0)
	sum = (sum + get(l, K, D, N-i, 0))%VAL;
      else
	break;
    }
  } else {
    for(int i = 1; i < D; i++){
      if(N-i>=0)
	sum = (sum+get(l, K, D, N-i, 0))%VAL;
      else
	break;
    }
  }
  if(inc){
    l[N].second = sum;
  } else {
    l[N].first = sum;
  }
  return sum;

}
int main(){
  int N;
  int K;
  int D;
  std::cin >> N >> K >> D;
  std::vector<pair<int, int> > l(N+1, pair<int, int>(-1,-1));
  l[0].first = 1;
  l[0].second = 0;
  //  l[1].first = 1;
  //  l[1].second = 0;
  std::cout << get(l, K, D, N, 1) << std::endl;

  

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
