#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "lib/pair.cpp"


int main(){
  int N;
  std::cin >> N;
  std::vector<pair<int, int> > xh(N);
  for(int i = 0; i < N; i++){
    int x;
    int h;
    std::cin >> x >> h;
    xh[i] = pair<int, int>(x,h);
  }
  int l_count = 1;
  int l_x = xh[0].first;
  int r_count = 1;
  int r_x = xh[0].first;
  for(int i = 1; i < N; i++){
    int x = xh[i].first;
    int h = xh[i].second;
    int newl = x;
    int newcl = l_count;
    if(x - l_x > h) newcl++;
    if(x - r_x > h) newcl = newcl > r_count+1 ? newcl : r_count +1;
    newcl = newcl > r_count ? newcl : r_count;
    int newr = x;
    int newcr = r_count > l_count ? r_count : l_count;
    if(i == N-1 || xh[i+1].first - x > h){
      newr += h;
      newcr ++;
    }
    l_count = newcl;
    l_x = newl;
    r_count = newcr;
    r_x = newr;
  }
  std::cout << (l_count > r_count ? l_count : r_count) << std::endl;
    



  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
