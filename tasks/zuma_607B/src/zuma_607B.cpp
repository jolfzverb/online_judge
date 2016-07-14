#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>

int get(std::vector<int> & c, std::vector<int> & res, int l, int r){
  int N = c.size();
  if(l > r) return 0;
  if(l == r) return 1;
  if(res[l*N+r] != -1) return res[l*N+r];
  int min = 1 + get(c,res, l+1, r);
  if(c[l] == c[l+1]){
    int a = 1 + get(c, res, l+2, r);
    min = min < a? min : a;
    for (int i = l+2; i <= r; i++){
      if(c[l]==c[i]){
	int a = get(c, res, l+1, i-1) + get(c, res, i+1, r);
	min = min < a ? min : a;
      }
    }
  }else{
    for (int i = l+1; i <= r; i++){
      if(c[l]==c[i]){
	int a = get(c, res, l+1, i-1) + get(c, res, i+1, r);
	min = min < a ? min : a;
      }
    }
  }

  res[l*N+r] = min;
  return min;
}

int main(){
  int N;
  std::cin >> N;
  std::vector<int> c(N);
  for (int i = 0; i < N; i++){
    int a;
    std::cin >> a;
    c[i] = a;
  }
  std::vector<int> res(N*N, -1);
  
  std::cout << get(c,res, 0,N-1)  << std::endl;

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
