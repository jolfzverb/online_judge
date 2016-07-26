#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <set>
#define VAL 1000000007


int main(){
  int N;
  std::cin >> N;
  N+=2;
  int *s = new int[N];
  int *d = new int[N];
  int *s_min = new int[N];
  int *d_min = new int[N];
  int *h = new int[N];
  h[0] = 0;
  h[N-1] = 0;
  for(int i = 1; i < N-1; i++){
    int h;
    std::cin >> h;
    s[i] = h+i;
    d[i] = h-i;
  }
  s[0] = 0;
  s[N-1] = N-1;
  d[0] = 0;
  d[N-1] = 1-N;
  int min = 2000000000;
  for(int i = 0; i < N; i++){
    min = min < d[i] ? min : d[i];
    d_min[i] = min;
  }
  min = 2000000000;
  for(int i = N-1; i >= 0; i--){
    int h = s[i];
    min = min < h ? min : h;
    s_min[i] = min;
  }
  /*  for(int i = 0; i < N; i++){
    std::cout << s[i] << " " << d[i] << " " << s_min[i] << " " << d_min[i] << " " << std::endl;
    }*/
  int max = 0;
  for (int i = 0; i < N; i++){
    int min = s_min[i] - i;
    int t = d_min[i] + i;
    min = min < t ? min : t;
    max  = max > min ? max : min;
  }
  std::cout << max << std::endl;

  delete[] s;
  delete[] h;
  delete[] d;
  delete[] s_min;
  delete[] d_min;
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../../")) */
/* eval: (flycheck-mode) */
/* End:              */
