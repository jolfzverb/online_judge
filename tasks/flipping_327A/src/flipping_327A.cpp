#include <iostream>
#include <vector>
#define MAX 101



int main(){
  int N;
  std::cin >> N;
  std::vector<int> sum(N);
  std::cin >> sum[0];
  for (int i = 1; i < N; i++){
    int a;
    std::cin >> a;
    sum[i] = sum[i-1]+a;
  }
  int max = 0;
  for (int i = 0; i < N; i++){
    for (int j = i; j < N; j++){
      int right = i > 0 ? sum[i-1] : 0;
      int left = j < N-1 ? sum[N-1] - sum[j] : 0;
      int mid = i ? (j - (i-1))-(sum[j]-sum[i-1]) : (j + 1 - sum[j]);
      int sum = right+left+mid;
      max = sum > max ? sum : max;
    }
  }
  std::cout << max << std::endl;
      
  
  
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
