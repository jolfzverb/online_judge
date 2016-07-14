#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>


int main(){
  int N;
  std::cin >> N;
  std::vector<int> n(7,0);
  int count = 0;
  int max = 0;
  while(N){
    int a = N%10;
    n[count] = a;
    max = max > a ? max : a;
    N = N/10;
    count++;
  }
  std::cout << max << std::endl;
  for(int j = 0; j < max; j++){
    int mul = 1;
    int out = 0;
    for(int i = 0; i < count; i++){
      out += mul * (n[i] ? 1 : 0);
      mul*=10;
      n[i] = n[i] ? n[i] -1 : 0;
    }
    std::cout << out << " ";
  }
  std::cout << std::endl;


    
  


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
