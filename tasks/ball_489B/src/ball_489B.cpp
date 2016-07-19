#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/vector.cpp"
#include "lib/algo.cpp"


    

int main(){
  int N;
  int M;
  std::cin >> N;
  vector<int> n(N);
  for (int i = 0; i < N; i++){
    int a;
    std::cin >> a;
    n[i] = a;
  }
  std::cin >> M;
  vector<int> m(M);
  for(int i = 0; i < M; i++){
    int a;
    std::cin >> a;
    m[i] = a;
  }
  sort(n.begin(), n.end());
  sort(m.begin(), m.end());

  int count = 0;
  int i = 0;
  int j = 0;
  while(i < N && j < M){
    int diff = n[i] - m[j];
    if(diff < 2 && diff > -2){
      count++;
      i++;
      j++;
    }else{
      if(diff < 0) i++;
      else j++;
    }
  }
  std::cout << count << std::endl;

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
