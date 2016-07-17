#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/string.cpp"
#define VAL 1000000007

int main(){
  string s;
  std::cin >> s;
  int start = 0;
  int end = s.length()-1;
  while(start <= end){
    switch(s[start]){
    case 'A':
    case 'H':
    case 'I':
    case 'M':
    case 'O':
    case 'o':
    case 'T':
    case 'U':
    case 'V':
    case 'v':
    case 'W':
    case 'w':
    case 'X':
    case 'x':
    case 'Y':
      if(s[end]!=s[start]){
	std::cout << "NIE" << std::endl;
	return 0;
      }
      end--;
      start++;
      break;
    case 'b':
      if(s[end]!='d'){
	std::cout << "NIE" << std::endl;
	return 0;
      }
      end--;
      start++;
      break;
    case 'd':
      if(s[end]!='b'){
	std::cout << "NIE" << std::endl;
	return 0;
      }
      end--;
      start++;
      break;
    case 'p':
      if(s[end]!='q'){
	std::cout << "NIE" << std::endl;
	return 0;
      }
      end--;
      start++;
      break;
    case 'q':
      if(s[end]!='p'){
	std::cout << "NIE" << std::endl;
	return 0;
      }
      end--;
      start++;
      break;
    default:
      std::cout << "NIE" << std::endl;
      return 0;
    }


  }
  std::cout << "TAK" << std::endl;

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
