#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/vector.cpp"


int main(){
  int N;
  std::cin >> N;
  vector<int> a(N);
  long long sum = 0;
  for (int i = 0; i < N; i++){
    int t;
    std::cin >> t;
    a[i] = t;
    sum+=t;
  }
  //  std::cout << sum << std::endl;
  if(sum%3 || N<3){
    std::cout << 0 << std::endl;
    return 0;
  }
  long long st = 0;
  vector<int> L(N);
  int countL = 0;
  vector<int> R(N);
  int countR = 0;
  for (int i = 0; i < N-1; i++){
    st+=a[i];
    //std::cout << st << std::endl;;
    if(st*3 == sum){
      //std::cout << "l: " << i <<std::endl;
      L[countL] = i;
      countL++;
    }
    if(st*3 == sum*2){
      //std::cout << "r: " << i <<std::endl;
      R[countR] = i;
      countR++;
    }
  }
  L.resize(countL);
  R.resize(countR);
  long long count = 0;
  auto ir = R.begin();
  for(auto i = L.begin(); i!=L.end(); i++){
    while(ir != R.end() && *i >= *ir) ir++;
    count+=R.end()-ir;
  }
  std::cout << count << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
