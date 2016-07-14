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
  std::cin >> N;
  long long a = 1;
  long long b = 0;
  for(int i = 2; i < N+1; i++){
    b = (3*a)%VAL;
    a = i%2? b+1 : b-1;
    if(a<0) a = VAL-1;
  }
  std::cout << b << std::endl;
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
