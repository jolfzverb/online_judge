#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/vector.cpp"
#define MAX 200

int main(){
  int a;
  int b;
  std::cin >> a >> b;
  vector<int> r(MAX*MAX, 0);

  for (int i = 3; i <= a+b; i++){
    for (int j = 1; j < i; j++){
      int x = i - j;
      int y = j;
      int max = 0;
      if(x > 1){
	max = max > r[(x-2)*MAX+y+1] +1 ? max : r[(x-2)*MAX+y+1]+1;
      }
      if(y > 1){
	max = max > r[(x+1)*MAX+y-2] +1 ? max : r[(x+1)*MAX+y-2]+1;
      }
      r[x*MAX+y] = max;
    }
  }
  std::cout << r[a*MAX+b] << std::endl;

  

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
