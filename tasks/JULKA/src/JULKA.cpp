#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include "lib/string.cpp"
#define VAL 1000000007

string add(string & first, string & second){
  int over = 0;
  const char * a = first.c_str();
  const char * b = second.c_str();
  char res[101];
  char * p = res;
  while(*a && *b){
    *p = ((*a - '0') + (*b - '0') + over)%10 + '0';
    over = ((*a - '0') + (*b - '0') + over)/10;
    a++;
    b++;
    p++;
  }

  if(!*a) a = b;
  while(*a){
    *p = ((*a - '0') + over)%10 + '0';
    over = ((*a - '0') + over)/10;
    a++;
    p++;
  }

  if(over)
    *p++ = over+'0';
  *p = 0;
  return string(res);
}
string sub(string & first, string & second){
  int over = 0;
  const char * a = first.c_str();
  const char * b = second.c_str();
  char res[101];
  char * p = res;
  while(*a && *b){
    int diff = ((*a-'0') - (*b - '0')+over);
    over = 0;
    if(diff < 0){
      over = -1;
      diff+=10;
    }
    *p = diff+'0';
    a++;
    b++;
    p++;
  }

  while(*a){
    int diff = ((*a-'0')+over);
    over = 0;
    if(diff < 0){
      over = -1;
      diff+=10;
    }
    *p = diff+'0';
    a++;
    p++;
  }

  *p = 0;
  return string(res);
}
string divide(string &str){
  int over = 0;
  const char * s = str.c_str();
  char res[101];
  char *p = res;
  while(*s){
    *p = (*s-'0')/2 + over + '0';
    over = (*s-'0')%2 ? 5 : 0;
    p++;
    s++;
  }
  *p = 0;
  if(over) exit(1);
  return string(res);
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  string a;
  string b;
  for(int i = 0; i < 10; i++){
    std::cin >> a >> b;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    string sum = add(a,b);
    std::reverse(sum.begin(), sum.end());
    string diff = sub(a,b);
    std::reverse(diff.begin(), diff.end());
    sum = divide(sum);
    //  std::cout << diff << std::endl;
    diff = divide(diff);
    //    std::cout << diff << std::endl;
    const char * d = diff.c_str();
    while (*d=='0') d++;
    diff = string(d);
    const char * s = sum.c_str();
    while (*s=='0') s++;
    sum = string(s);
    if (sum.length() == 0) sum = "0";
    std::cout << sum << std::endl;
    if (diff.length() == 0) diff = "0";
    std::cout << diff << std::endl;
  }


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../../")) */
/* eval: (flycheck-mode) */
/* End:              */
