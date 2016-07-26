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
  int g = 0;
  int c = 0;
  for (int i = 0; i < N; i++){
    int cur;
    std::cin >> cur;
    int gym = cur >> 1;
    int cont = cur & 1;
    int new_g = c+gym > g ? c+gym : g;
    int new_c = g+cont > c ? g+cont : c;
    g = new_g;
    c = new_c;
  }
  std::cout << N - (g > c ? g : c) << std::endl;

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../../")) */
/* eval: (flycheck-mode) */
/* End:              */
