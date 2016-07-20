#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "lib/string.cpp"
#include "lib/algo.cpp"
#define VAL 1000000007
int main(){
  int N;
  std::cin >> N;
  std::map<string, int> d;
  d["polycarp"]=1;
  int max = 0;
  for (int i = 0; i < N; i++){
    string n;
    string t;
    string o;
    std::cin >> n >> t >>o;
    transform(n.begin(), n.end(), n.begin(), ::tolower);
    transform(o.begin(), o.end(), o.begin(), ::tolower);
    int res = d[o] +1;
    max = max > res ? max : res;
    d[n] = res;
  }
  /*  for (auto i : d){
    std::cout << i.first << " " << i.second << std::endl;
    }*/
  std::cout << max << std::endl;
  return 0;
}
