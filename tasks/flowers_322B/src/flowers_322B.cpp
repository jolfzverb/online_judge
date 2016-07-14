#include <iostream>

int main(){
  int a;
  int b;
  int c;
  std::cin >> a >> b >> c;
  int A = a/3;
  int B = b/3;
  int C = c/3;
  a %= 3;
  b %= 3;
  c %= 3;
  int result = A+B+C;
  if ( a == 0 && b == 2 &&  c == 2){
    if(A)
      result++;
  }
  if ( a == 2 && b == 0 &&  c == 2){
    if(B)
      result++;
  }
  if ( a == 2 && b == 2 &&  c == 0){
    if(C)
      result++;
  }
  int min = a < b ? a : b;
  min = min < c ? min : c;
  result += min;

  std::cout << result << std::endl;
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
