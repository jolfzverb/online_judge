#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>


int main(){
  int N;
  std::cin >> N;
  std::vector<int> a(N);
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
  std::vector<int> L(N);
  int countL = 0;
  std::vector<int> R(N);
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

  /*
  std::vector<long long> s(N+1);
  long long sum = 0;
  s[0] = 0;

  //  std::cout << std::endl;
  // [a,b) = s[b] - s[a];
  std::vector<std::pair<int, long long>> A(N); // a = (b+c)/2
  auto itA = A.begin();
  std::vector<std::pair<int, long long>> C(N); // a = (b+c)/2
  auto itC = C.begin();
  for (int i = 1; i < N; i++){
    //    std::cout << i << " " << s[i] - s[0] << " "<< (s[N] - s[i])/2<< " " << s[N] - s[i]<<  " " << (s[i] - s[0])/2 << std::endl;
    if((s[i] - s[0])*2 == (s[N] - s[i])){
      *itA++ = std::pair<int, long long>(i, s[i] - s[0]);
    }
    if((s[N] - s[i]) && (s[N] - s[i])*2 == (s[i] - s[0])){
      *itC++ = std::pair<int, long long>(i, s[N] - s[i]);
    }
  }
    for (auto i = A.begin(); i != itA; i++){
    std::cout << i->first << " A " << i->second << std::endl;
  }
  for (auto i = C.begin(); i != itC; i++){
    std::cout << i->first << " C " << i->second << std::endl;
    }*/
  /*
  int res = 0;
  int c = std::count_if(A.begin(), itA, [](const std::pair<int, long long> &p) ->bool{return p.second == 0;});
  //  std::cout << c;
  res += (c*(c-1))/2;
  for( auto i = A.begin(); i != itA; i++){
    if(i->second)
      res += std::count_if(C.begin(), itC, [i](const std::pair<int, long long> &p) -> bool {return p.first>i->first && p.second == i->second;});
  }
  std::cout << res << std::endl;
  */

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
