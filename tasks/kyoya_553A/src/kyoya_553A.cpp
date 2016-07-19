#include <iostream>
#include <vector>
#include "lib/vector.cpp"
#define VAL 1000000007
int main(){
  int K;
  std::cin >>K;
  vector<int> a(K);
  int max=0;
  int sum = 0;
  for(int i = 0; i < K; i++){
    int t;
    std::cin >> t;
    max = max > t ? max : t;
    sum += t;
    a[i] = t-1;
  }
  int dp[1001][1001];
  for(int i = 0; i < sum; i++){
    dp[0][i] = 1;
  }
  for(int i = 1; i < max+1; i ++){
    int s = 0;
    for(int j = 0; j < sum; j++){
      s+=dp[i-1][j];
      s%=VAL;
      dp[i][j] = s;
    }
  }
  int len = 1;
  long long res = 1;
  for(int i = 0; i < K; i++){
    int count = a[i];
    int ways = dp[count][len-1];
    res *= ways;
    res %= VAL;
    len+=a[i]+1;
  }
  std::cout << res << std::endl;
  
  return 0;
}
