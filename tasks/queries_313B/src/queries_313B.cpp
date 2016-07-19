#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/string.cpp"
#include "lib/vector.cpp"



  

int main(){
  string s;
  std::cin >> s;
  vector<int> sum(s.length()+1);
  int tmp = 0;
  sum[0] = 0;
  for(unsigned int i = 0; i < s.length()-1; i++){
    if(s[i] == s[i+1]){
      tmp++;
    }
    sum[i+1] = tmp;
  }
  int N;
  std::cin >> N;
  for(int i = 0; i < N; i++){
    int r;
    int l;
    std::cin >> r >> l;
    std::cout << sum[l-1] - sum[r-1] << std::endl;
  }

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
