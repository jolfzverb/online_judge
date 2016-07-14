#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#define VAL 1000000007

int main(){
  unsigned int N;
  unsigned int M;
  int K;
  std::cin >> N >> M >> K;
  std::vector<int> p(N);
  for(unsigned int i = 0; i < N; i++){
    int a;
    std::cin >> a;
    p[i] = a;
  }
  long long sum = 0;
  for(unsigned int i = 0; i < M; i++){
    sum += p[i];
  }
  std::vector<long long> s(N-M+1);
  s[0] = sum;
  for(unsigned int i = 1; i <= N-M; i++){
    sum += p[i+M-1];
    sum -= p[i-1];
    s[i] = sum;
  }
  std::vector<std::list<std::pair<long long, unsigned int> > > dp(K+1);
  dp[0].push_back(std::pair<long long,unsigned int>(0,0));
  for(unsigned int i = 0; i <= N-M; i++){
    for(int j = 0; j < K; j++){
      if(dp[j].size() == 0) break;
      std::pair<long long, unsigned int> top = dp[j].front();
      if(top.second > i) break;
      std::pair<long long,unsigned int> n(top.first+s[i], i+M);
      dp[j+1].push_back(n);
      if(dp[j+1].size() > M+1){
	std::pair<long long, unsigned int> f = dp[j+1].front();
	dp[j+1].pop_front();
	std::pair<long long, unsigned int> s = dp[j+1].front();
	s.first = s.first > f.first ? s.first : f.first;
	dp[j+1].front() = s;
      }
      /*      for(int k = 0; k <= K; k++){
	for(auto l : dp[k]){
	  std::cout << l.first << " " << l.second << std::endl;
	}
	std::cout << std::endl;
	}*/
    }
  }
  long long max = 0;
  for(auto i : dp[K]){
    long long a = i.first;
    max = max > a ? max : a;
  }
  std::cout << max << std::endl;

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
