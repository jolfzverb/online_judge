#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>


int main(){
  std::string s;
  std::cin >> s;
  int C = 0;
  for(auto a : s){
    C += (a == '+' ? 1 : -1);
  }
  std::cin >> s;
  int ucount = 0;
  int c = 0;
  for (auto a :s){
    if( a == '?'){
      ucount ++;
    } else {
      c+=(a=='+' ? 1 : -1);
    }
  }
  std::vector<long double> r(2*ucount+1, 0);
  std::vector<long double> l(2*ucount+1, 0);
  r[ucount] = 1;
  for( int i = 0; i < ucount; i++){
    for(unsigned int i = 0; i < r.size(); i++){
      if(i > 0)
	l[i-1]+=r[i]/2;
      if(i < r.size()-1)
	l[i+1]=r[i]/2;
    }
    r = l;
  }
  if(C-c <= ucount && c-C <= ucount)
    std::cout << std::setprecision(12) << r[ucount + C - c] <<std::endl;
  else
    std::cout << 0 << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
