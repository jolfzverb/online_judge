#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "lib/vector.cpp"


int main(){
  int N;
  int K;
  std::cin >> N;
  std::cin >> K;
  vector<int> h(N);
  for (int i = 0; i < N; i++){
    int a;
    std::cin >> a;
    h[i] = a;
  }
  int sum = 0;
  for (int i = 0; i < K; i++){
    sum += h[i];
  }
  int min = sum;
  //  std::cout << min << std::endl;
  int amin = -1;
  for (int i = 0; i < N-K; i++){

    sum = sum - h[i] + h[K+i];
    if(min > sum){
      amin = i;
      min = sum;
    }
    //    std::cout << i << " " << h[i] << " " << h[K+i] << " " << sum << std::endl;;
  }
  std::cout << amin+2 << std::endl;
  


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
