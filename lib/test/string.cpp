#include <iostream>
#include <sstream>
#include "lib/string.cpp"

int main(){
  int res = 0;
  {
    string s;
    if(s.str() != std::string()){
      std::cerr << "Default constructor test failed!"<< std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    if(s.str() != std::string("ololo")){
      std::cerr << "Constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    string t = s;
    if(t.str() != std::string("ololo")){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    string t(s);
    if(t.str() != std::string("ololo")){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    string r;
    r+=s;
    if(r.str() != std::string("ololo")){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    string t("pewpew");
    string r;
    r=s+t;
    if(r.str() != std::string("ololopewpew")){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("oloasdfasdfasdfasdfasdfasdfasdfffdsdfasdfgadflaklasdlo");
    string t("pewpffffkdksldflasdlfkasdlkflalklalalasdkfkdfjawepqiw2340492934uew");
    string r;
    r=s+t;
    if(r.str() != std::string("oloasdfasdfasdfasdfasdfasdfasdfffdsdfasdfgadflaklasdlopewpffffkdksldflasdlfkasdlkflalklalalasdkfkdfjawepqiw2340492934uew")){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("abcdef");
    if(s[3] != 'd'){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("abcdef");
    if(s[3] != 'd'){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("abcdef");
    int j = 0;
    for(string::iterator i = s.begin(); i != s.end(); i++){
      if(*i != "abcdef"[j]){
	std::cerr << "Copy constructor failed!" << std::endl;
	res = 1;
      }
      j++;
    }
  }
  {
    string s("abcdef");
    if(s.length() != 6){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    if(std::string("ololo") != std::string(s.c_str())){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    if(std::string("ololo") != s.str()){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s(std::string("ololo"));
    if(std::string("ololo") != s.str()){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    std::string str("OLOLO");
    std::stringstream st(str);
    string a;
    st >> a;
    if(std::string("OLOLO")!= a.str()){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
    a = string("pewpew");
    st = std::stringstream();
    st << a;
    if(st.str() != std::string("pewpew")){
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    std::string str("olololo");
    string s("olololo");
    std::string::size_type str_p = 0;
    string::size_type s_p = 0;
    while(str_p != std::string::npos){
      str_p = str.find("lo", str_p);
      s_p = s.find("lo", s_p);
      if(str_p != std::string::npos){
	if(str_p != s_p){
	  std::cerr << "Copy constructor failed!" << std::endl;
	  res = 1;
	}
	str_p++;
	s_p++;
      }
    }
    if(str_p == std::string::npos && s_p == string::npos){
    } else {
      std::cerr << "Copy constructor failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    string p = "pew" + s;
    if(std::string("pewololo") != p.str()){
      std::cerr << "Add const char * and string failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    string p = "pew" + s;
    if(! (s < p)){
      std::cerr << "Less failed!" << std::endl;
      res = 1;
    }
  }
  {
    string s("ololo");
    string p = s;
    if(! (s == p)){
      std::cerr << "Compare equal failed!" << std::endl;
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
