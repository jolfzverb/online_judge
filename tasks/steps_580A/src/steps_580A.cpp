#include <iostream>

int main(){
  int N;
  int len = 1;
  int prev ;
  int max = 0;
  std::cin >> N;
  std::cin >> prev;
  for(int i = 1; i < N; i++){
    int b;
    std::cin >> b;
    if(b >= prev){
      len ++;
      prev = b;
    }
    else{
      max = max > len ? max : len;
      len = 1;
      prev = b;
    }
  }
  std::cout << (max > len ? max : len) << std::endl;

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
