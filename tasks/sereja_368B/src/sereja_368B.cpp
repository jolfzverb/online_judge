#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/vector.cpp"
#define MAX 100001

int main(){
  int N;
  int M;
  std::cin >> N >> M;
  vector<int> a(N);
  vector<int> count(MAX, 0);
  int c = 0;
  for (int i = 0; i < N; i++){
    int tmp;
    std::cin >> tmp;
    a[i] = tmp;
    if(count[tmp] == 0)
      c++;
    count[tmp]++;
  }
  vector<int> res(N);
  for (int i = 0; i < N; i++){
    res[i] = c;
    count[a[i]]--;
    if(count[a[i]] == 0)
      c--;
  }
  for (int i = 0; i < M; i++){
    int tmp;
    std::cin >> tmp;
    std::cout << res[tmp-1] << std::endl;
  }
  


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
