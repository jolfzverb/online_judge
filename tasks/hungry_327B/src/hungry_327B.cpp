#include <iostream>
int main(){
  int N;
  std::cin>>N;
  for(int i = 9000000; i< 9000000+N; i++){
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
