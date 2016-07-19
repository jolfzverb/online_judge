#include <iostream>
#include <vector>
#include <algorithm>
#include "lib/vector.cpp"
#include "lib/algo.cpp"

int main(){
  int N;
  int M;
  std::cin >> N;
  std::cin >> M;
  vector<int> l(M);
  for(int i = 0; i < M; i++){
    int a;
    std::cin >> a;
    l[i] = a;
  }
  sort(l.begin(), l.end());
  int min = l[M-1] - l[0];
  for(int i = 0; i <= M-N; i++){
    int diff = l[i+N-1] - l[i];
    min = min < diff ? min : diff;
  }
  std::cout << min << std::endl;

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
