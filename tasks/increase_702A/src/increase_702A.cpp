#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define VAL 1000000007
int main(){
  int N;
  std::cin >> N;
  int prev = 2000000000;
  int max = 0;
  int cur = 0;
  for (int i = 0; i < N; i++){
    int a;
    std::cin >> a;
    //  std::cout << a << " " << prev << " " << max << " " << cur << "\n";
    if (a > prev){
      cur ++;
    }
    else{
      max = max > cur+1 ? max : cur+1;
      cur = 0;
    }
    prev = a;

  }
  max = max > cur+1 ? max : cur+1;
  std::cout << max << "\n";

  return 0;
}
