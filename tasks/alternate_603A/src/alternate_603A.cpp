#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#define VAL 1000000007
int main(){
  int N;
  std::cin >> N;
  std::string s;
  std::cin >> s;
  char prev = s[0];
  int count = 1;
  int same = 0;
  for (int i = 1; i < N; i++){
    if(s[i]!=prev){
      count++;
      prev = s[i];
    } else{
      same++;
    }
  }
  if(same >1)
    count +=2;
  else if(same == 1)
    count ++;
  std::cout << count << std::endl;
  return 0;
}
