#include <iostream>
#include <sstream>
#include "lib/pair.cpp"

int main(){
  int res = 0;
  {
    pair<int, const char*> p(3, "ololo");
    if(p.first != 3){
      std::cerr << "First constructor test failed!"<< std::endl;
      res = 1;
    }
  }
  {
    pair<int, const char *> p;
    if(p.first != 0 || p.second != NULL){
      std::cerr << "Default constructor test failed!"<< std::endl;
      res = 1;
    }
  }
  {
    pair<int, const char *> p(3, "ololo");
    pair<int, const char *> a = p;
    if(a.first != 3){
      std::cerr << "Copy constructor test failed!"<< std::endl;
      res = 1;
    }
  }
  {
    pair<int, const char *> p(3, "ololo");
    pair<int, const char *> a(p);
    if(a.first != 3){
      std::cerr << "Second constructor test failed!"<< std::endl;
      res = 1;
    }
  }
   
  return res;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../")) */
/* eval: (flycheck-mode) */
/* End:              */
