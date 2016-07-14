#include <iostream>

int main(){
  int N;
  std::cin >> N;
  if(N%2){
    std::cout << "-1" << std::endl;
    return 0;
  }
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
	if(i%2 ^ (j/2)%2 ^ (k/2)%2) std::cout << "b";
	else std::cout << "w";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
