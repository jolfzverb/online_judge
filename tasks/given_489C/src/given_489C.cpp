#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/string.cpp"
#include "lib/algo.cpp"


    

int main(){
  int M;
  int S;
  std::cin >> M >> S;
  if(!S){
    if(M==1)
      std::cout << "0 0" << std::endl;
    else
      std::cout << "-1 -1" << std::endl;
    return 0;
  }
  if(M*9 < S){
    std::cout << "-1 -1" << std::endl;
    return 0;
  }
  std::stringstream lesser;
  int s = S;
  for (int i = 0; i < M; i++){
    if(s>9){
      s-=9;
      lesser << "9";
    }
    else if (s!=1){
      if(i < M-1){
	lesser << s-1;
	s = 1;
      } else {
	lesser << s;
	s = 0;
      }
    }else{
      if(i < M-1){
	lesser << "0";
      } else {
	lesser << s;
	s = 0;
      }
    }
  }
  string l = lesser.str();
  reverse(l.begin(), l.end());
  std::stringstream greater;
  s = S;
  for(int i = 0; i < M; i++){
    if(s > 9){
      s -=9;
      greater << "9";
    } else{
      greater << s;
      s = 0;
    }
  }
  std::cout << l << " " << greater.str() << std::endl;
  
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
