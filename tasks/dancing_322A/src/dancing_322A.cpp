#include <iostream>

int main(){
  int N;
  int M;
  std::cin >> N >> M;
  std::cout << N+M-1 << std::endl;
  for(int i = 0; i < M; i++){
    std::cout << "1 " << i+1 << std::endl;
  }
  for (int i = 0; i < N-1; i++){
    std::cout << i+2 << " " << M << std::endl;
  }
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
