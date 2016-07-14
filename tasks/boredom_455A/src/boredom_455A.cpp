#include <iostream>
#include <vector>

#define MAX 100002
int main(){
  int N;
  std::cin >> N;
  std::vector<long long> l(MAX);
  for (int i = 0; i < N; i++){
    int input;
    std::cin >> input;
    l[input]++;
  }
  //  std::cout << l[100000];
  std::vector<long long> res(MAX);
  res[0] = l[0];
  res[1] = l[1]; //because l[0]==0
  for(int i = 2; i < MAX; i++){
    long long a = res[i-2]+(l[i]*i);
    long long b = res[i-1];
    res[i] = a > b ? a : b;
  }
    
    

  std::cout << res[MAX-1] << std::endl;
  
  
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
