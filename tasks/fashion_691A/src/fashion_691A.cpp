#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/vector.cpp"
#define VAL 1000000007

int main(){
  int N;
  std::cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    int t;
    std::cin >> t;
    a[i] = t;
  }
  if(N==1 && a[0]==1){
    std::cout << "YES"<< std::endl;
    return 0;
  } else if(N==1){
    std::cout << "NO"<< std::endl;
    return 0;
  } else {
    int t = std::count(a.begin(), a.end(), 0);
    if(t == 1){
      std::cout << "YES"<< std::endl;
      return 0;
    } else {
      std::cout << "NO"<< std::endl;
      return 0;
    }
  }



  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
