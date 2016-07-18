#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/pair.cpp"
#define VAL 1000000007

int main(){
  int N;
  std::cin >> N;
  std::vector<pair <int, int> > ab(N);
  for (int i = 0; i < N; i++){
    int a;
    int b;
    std::cin >> a >> b;
    ab[i] = pair<int, int>(a,b);
  }
  std::sort(ab.begin(), ab.end(), [](const pair<int, int> & a, const pair<int, int> & b) -> int {return a.first < b.first;});
  std::vector<int> fired(N);
  fired[0] = 1;
  auto it = ab.begin();
  for(int i = 1; i < N; i++){
    it++;
    //find in ab last pair with first val < ab[i].second;
    pair<int, int> cmp(ab[i].first-ab[i].second, 0);
    int j = std::lower_bound(ab.begin(), it, cmp, [](const pair<int, int> & a, const  pair<int, int> & b) -> bool {return a.first < b.first;}) - ab.begin();
    //    std::cout << i << " " << j << std::endl;
    if(j == 0) fired[i] = 1;
    else fired[i] = fired[j-1] + 1;
  }

  /*  for(int i = 0; i < N; i++){
    std::cout << fired[i] << std::endl;
    }*/
    int res = (N - *std::max_element(fired.begin(), fired.end()));
  std::cout << res << std::endl;
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
