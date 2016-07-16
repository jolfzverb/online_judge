#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#define VAL 1000000007
int main(){
  int N;
  int K;
  std::cin >> N >> K;
  std::vector<int> a(N);
  for(int i=0; i < N; i++){
    int t;
    std::cin >> t;
    a[i] = t;
  }
  std::map<int, long long> one;
  std::map<int, long long> two;
  std::map<int, long long>three;
  for(int i = 0; i < N; i++){
    if(a[i]%K==0){
      three[a[i]] += two[a[i]/K];
      two[a[i]] += one[a[i]/K];
    }
    one[a[i]]++;
  }
  long long sum = 0;
  for(auto it : three){
    sum += it.second;
  }
  std::cout << sum << std::endl;
  return 0;
}
