#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/string.cpp"
#define VAL 1000000007

int main(){
  int N;
  std::cin >> N;
  for(int i = 0; i < N; i++){
    string s;
    std::cin >> s;
    int c = 0;
    int b = 0;
    //check for 1x12
    for(char i : s){
      if(i == 'X'){
	c++;
	b |= 1<<0;
	break;
      }
    }
    //check for 2x6
    for(int i = 0; i < 6; i++){
      if(s[i] == 'X' && s[i+6] == 'X'){
	c++;
	b |= 1<<1;
	break;
      }
    }
    //check for 3x4
    for (int i = 0; i < 4; i++){
      if(s[i] == 'X' && s[i+4] == 'X' && s[i+8] == 'X'){
	c++;
	b|= 1<<2;
	break;
      }
    }
    //check for 4x3
    for (int i = 0; i < 3; i++){
      if(s[i] == 'X' && s[i+3] == 'X' && s[i+6] == 'X' && s[i+9] == 'X'){
	c++;
	b|=1<<3;
	break;
      }
    }
    //check for 6x2
    for (int i = 0; i < 2; i++){
      if(s[i] == 'X' && s[i+2]=='X' && s[i+4]=='X' && s[i+6] == 'X' && s[i+8] == 'X' && s[i+10] == 'X'){
	c++;
	b|=1<<4;
	break;
      }
    }
    //check for 12x1
    c++;
    b |= 1 << 5;
    for(char i : s){
      if(i != 'X'){
	c--;
	b ^= 1 << 5;
	break;
      }
    }
    std::cout << c
	      << (b & 1 ? " 1x12" : "")
      	      << (b & 1<<1 ? " 2x6" : "")
	      << (b & 1<<2 ? " 3x4" : "")
      	      << (b & 1<<3 ? " 4x3" : "")
	      << (b & 1<<4 ? " 6x2" : "")
      	      << (b & 1<<5 ? " 12x1" : "") << std::endl;
  }

    


      

  

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
