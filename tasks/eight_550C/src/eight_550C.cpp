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
  // 0
  int a1_159 = 0;
  int a2_159 = 0;
  int a_13579 = 0;
  int a1_37 = 0;
  int a2_37 = 0;
  int a_26 = 0;
  int a_4 = 0;
  for(auto i : s){
    switch(i){
    case '0':
      std::cout << "YES" << std::endl << "0" << std::endl;
      return 0;
    
    case '8':
      std::cout << "YES" << std::endl << "8" << std::endl;
      return 0;
      
    case '2':
      a_26 = 2;
      if(a2_159){
	std::cout << "YES" << std::endl << a1_159 << a2_159 << 2 << std::endl;
	return 0;
      }
      if(a1_37){
	std::cout << "YES" << std::endl << a1_37 << 2 << std::endl;
	return 0;
      }
      break;

    case '6':
      a_26 = 6;
      if(a1_159){
	std::cout << "YES" << std::endl << a1_159 << 6 << std::endl;
	return 0;
      }
      if(a2_37){
	std::cout << "YES" << std::endl << a1_37 << a2_37 << 6 << std::endl;
	return 0;
      }
      break;

    case '4':
      if(a_13579 && a_4){
	std::cout << "YES" << std::endl << a_13579 << 4 << 4 << std::endl;
	return 0;
      }
      if(a_13579) a_4 = 4;
      if(a_26){
	std::cout << "YES" << std::endl << a_26 << 4 << std::endl;
	return 0;
      }
      break;
      
    case '1':
      if(!a1_159) {
	a1_159 = 1;
      }
      else {
	a2_159 = 1;
      }
      if(!a_13579) a_13579 = 1;
      break;
      
    case '5':
      if(!a1_159) {
	a1_159 = 5;
      }
      else {
	a2_159 = 5;
      }
      if(!a_13579) a_13579 = 5;

      break;
      
    case '9':
      if(!a1_159) {
	a1_159 = 9;
      }
      else {
	a2_159 = 9;
      }
      if(!a_13579) a_13579 = 9;

      break;
      

    case '3':
      if(!a1_37) {
	a1_37 = 3;
      }
      else {
	a2_37 = 3;
      }
      if(!a_13579) a_13579 = 3;

      break;
      
    case '7':
      if(!a1_37) {
	a1_37 = 7;
      }
      else {
	a2_37 = 7;
      }
      if(!a_13579) a_13579 = 7;

      break;

    }
  }
  std::cout << "NO" << std::endl;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
