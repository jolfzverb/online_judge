#include <iostream>
#include <vector>
#include <climits>

int get(std::vector<int>& l, std::vector<int>& cost, int N){
  if(N<0) return -1;
  //std::cout << N << " " << l[N] << std::endl;
  if(N==0) return 0;
  if(l[N] != -1) return l[N];
  if(l[N] == -2) return -1;
  int max = 0;
  for(auto i : cost){
    if(i > N) continue;
    int a = get(l, cost, N-i);
    if(a!=-1){
      max = max < a+1 ? a+1 : max;
    }
  }
  if(!max) max = -2;
  l[N] = max;
  //std::cout << N << " " << l[N] << std::endl;
  return max;
}
    

int main(){
  int N;
  std::cin >> N;
  std::vector<int> cost(3);
  std::cin >> cost[0] >> cost[1] >> cost[2];
  std::vector<int> l(N+1,-1);
  std::cout << get(l, cost, N) << std::endl;;
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
