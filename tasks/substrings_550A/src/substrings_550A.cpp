#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>



  

int main(){
  std::string s;
  std::cin >> s;
  std::list<std::string::size_type> ab;
  std::list<std::string::size_type> ba;
  std::string::size_type a = 0;
  for(int i = 0; i < 3; i++){
    std::string::size_type b = s.find("AB",a);
    if(b == std::string::npos)
      break;
    ab.push_back(b);
    a = b+1;
  }
  a = 0;
  for(int i = 0; i < 3; i++){
    std::string::size_type b = s.find("BA",a);
    if(b == std::string::npos)
      break;
    ba.push_back(b);
    a = b+1;
  }
  if(ab.size() == 0 || ba.size() == 0){
    std::cout << "NO" << std::endl;
  } else {
    for (auto i : ab){
      for(auto j : ba){
	int diff = i > j ? i - j : j - i;
	if (diff > 1){
	  std::cout << "YES" << std::endl;
	  return 0;
	}
      }
    }
    std::cout << "NO" << std::endl;
  }





  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
