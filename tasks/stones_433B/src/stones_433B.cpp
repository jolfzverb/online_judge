#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#define VAL 1000000007

int main(){
  int N;
  std::cin >> N;
  std::vector<long long> v(N);
  std::vector <long long> vsum(N);
  std::vector<long long> u(N);
  long long sum = 0;
  for (int i = 0; i < N; i++){
    int a;
    std::cin >> a;
    v[i] = a;
    u[i] = a;
    sum+=a;
    vsum[i] = sum;
  }
  std::sort(u.begin(), u.end());

  sum = 0;
  std::vector <long long> usum(N);
  for (int i = 0; i < N; i++){
    sum += u[i];
    usum[i] = sum;
  }
  int M;
  std::cin >> M;
  for (int i = 0; i < M; i++){
    int type;
    int l;
    int r;
    std::cin >> type >> l >> r;
    l--;
    r--;
    if(type==1){
      std::cout << vsum[r]-(l>0?vsum[l-1]:0) << std::endl;
    } else {
      std::cout << usum[r]-(l>0?usum[l-1]:0) << std::endl;
    }
  }


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
