#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/string.cpp"
#include "lib/algo.cpp"
#define VAL 1000000007

int main(){
  string s;
  std::cin >> s;
  if(!count(s.begin(), s.end(), '.')){
    unsigned int i = 0;
    while(i < s.length() && s[i] == '0') i++;
    if(i == s.length()) std::cout << 0 << std::endl;
    else if(i == s.length()-1) std::cout << s[i] << std::endl;
    else{
      std::cout << s[i] << ".";
      for(unsigned int j = i+i; j < s.length(); j++){
	std::cout << s[j];
      }
    }


  }


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
