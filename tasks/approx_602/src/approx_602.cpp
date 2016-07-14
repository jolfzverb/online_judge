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
  std::vector<int> a(N);
  for (int i = 0; i < N; i++){
    int b;
    std::cin >> b;
    a[i] = b;
  }
  int val; //current m, M == m+1
  int l; //start of current range
  int n; //start of next range
  l = 0;
  n = 0;
  val = a[0];
  int max = 0;
  for (int i = 1; i <= N; i++){
    if(i == N){
      int len = i - l;
      max = max > len ? max : len;
    } else if(a[i]==val+2){
      //our sequence is finished
      int len = i - l;
      max = max > len ? max : len;
      l = n;
      val = val+1;
      n = i;
    } else if(a[i] == val +1){
      if(a[n]!=a[i]) n = i;
    } else if(a[i] == val){
      if(a[n]!=a[i]) n = i;
    } else if(a[i] == val-1){
      //seq is finished
      int len = i -l;
      max = max > len ? max : len;
      l = n;
      val = val-1;
      n = i;
    }
    //    std::cout << l << " " << n << " " << val << " " << a[i] << std::endl;

  }
  std::cout << max << std::endl;




  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
