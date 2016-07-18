#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "lib/pair.cpp"
#define VAL 1000000007
int main(){
  int N;
  std::cin >> N;
  std::vector<pair<int, int> > p(N);
  int len = 0;
  int h1 = 0;
  int h2 = 0;
  for (int i = 0; i < N; i++){
    int h;
    int w;
    std::cin >> w >> h;
    p[i] = pair<int, int>(h, w);
    if(h >= h1){
      h2 = h1;
      h1 = h;
    } else if (h > h2){
      h2 = h;
    }
    len += w;
  }
  for(int i = 0; i < N; i++){
    int size = len - p[i].second;
    size *= (p[i].first == h1? h2 : h1);
    std::cout << size << " ";
  }
  std::cout << std::endl;


  return 0;
}
