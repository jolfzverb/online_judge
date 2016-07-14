#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#define VAL 1000000007

int main(){
  int N;
  std::cin >>N;
  std::vector<int> a(N);
  for (int i = 0; i < N; i++){
    int t;
    std::cin >> t;
    a[i] = t;
  }
  if(N == 1){
   std::cout << 1 << std::endl;
   return 0;
  }
  if(N == 2){
    std::cout << 2 << std::endl;
    return 0;
  }
  int max = 2;
  std::list<std::pair<int, int> > l;
  int start=0;
  int end=1;
  while(start!=N){
    while(end < N && a[end] > a[end-1]) end++; //a[end] is not in seq
    if(end - start > 1){
      int len = end - start +1;
      max = max > len ? max : len;
      l.push_back(std::pair<int, int> (start, end));
    }
    start = end++;
  }
  if (l.size() > 1) {
    for(auto it = l.begin(); it != l.end(); it++){
      auto next = it;
      next++;
      if(next == l.end()) break;
      int l = it->first;
      int c1 = it->second;
      int c2 = next->first;
      int r = next->second;
      if(c1 == c2){
	//check if we can merge a-b and c-d
	if(a[c1] - a[c1-2]>1 || a[c1+1] - a[c1-1] >1){
	  max = max > r-l ? max : r-l;
	}
      }

    }
  }
  max = max > N ? N : max;
  std::cout << max << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
