/* In wierd testing system that I am targeting, use of ANY includes is
 * forbidden. Thats why this string implementation is in form of cpp file.
 * And that is why I need string implementation.
 */
#ifndef RELEASE
#include <string>
#include <istream>
#include <ostream>
#endif
class string{
public:
  typedef char * iterator;
  typedef unsigned int size_type;
  static const size_type npos = -1;
  string();
  string(const char *);
  string(const string &);
  ~string();
  string & operator = (const string &);
  bool operator == (const string &) const;
  bool operator < (const string &) const;
  string & operator += (const string &);
  string operator + (const string &) const;
  char & operator[](size_type) const;
  size_type length() const;
  iterator begin() const;
  iterator end() const;
  size_type find(const char *, size_type) const;
  size_type find(const string &, size_type) const;
  const char * c_str() const;
#ifndef RELEASE
  string(const std::string &s);
  std::string str() const;
  size_type find(const std::string &, size_type) const;
#endif
private:
  char * s;
  size_type allocated;
  size_type l;
  static size_type strlen(const char * str);
  static void strcpy(char *, const char *, size_type);
};
string operator + (const char * first, const string &second){
  return string(first)+second;
}
bool string::operator<(const string &str) const{
  const char * my = s;
  const char * other = str.s;
  while(*my && *other){
    if(*my != *other)
      return *my < *other;
    my++;
    other++;
  }
  return *my < *other;
}
bool string::operator==(const string &str) const{
  if(l!=str.l) return false;
  for(unsigned int i = 0; i < l; i++){
    if(s[i]!=str.s[i]) return false;
  }
  return true;
}
string::size_type string::find(const string & str, string::size_type start) const{
  return find(str.c_str(), start);
}
string::size_type string::find(const char * p, string::size_type start) const{
  while(start <= l){
    const char * matched = p;
    char * my = s + start;
    while(*matched && *my == *matched){
      my++;
      matched++;
    }
    if(!*matched){
      return start;
    }
    start++;
  }
  return npos;
}
#ifndef RELEASE
string::size_type string::find(const std::string & str, string::size_type start) const{
  return find(str.c_str(), start);
}

std::istream & operator>>(std::istream & str, string &s){
  std::string a;
  str >> a;
  s = string(a);
  return str;
}
std::ostream & operator<<(std::ostream & str, string &s){
  std::string a = s.str();
  return str << a;
}
string::string(const std::string & str){
  l = strlen(str.c_str());
  s = new char[l+1];
  allocated = l+1;
  strcpy(s, str.c_str(), l);
}
std::string string::str() const{
  return std::string(s);
}
#endif
const char * string::c_str() const{
  return s;
}
string::size_type string::strlen(const char * str){
  string::size_type len = 0;
  while(str[len]) len++;
  return len;
}
void string::strcpy(char * dest, const char * src, string::size_type len){
  while(len--) *dest++ = *src++;
  *dest = 0;
}
string::size_type string::length() const{
  return l;
}
string::iterator string::begin() const{
  return s;
}
string::iterator string::end() const{
  return s+l;
}
string::string(){
  s = new char[16];
  allocated = 16;
  l = 0;
  s[0] = 0;
}
string::~string(){
  delete[] s;
}
string::string(const char * str){
  l = strlen(str);
  s = new char[l+1];
  allocated = l+1;
  strcpy(s, str, l);
}
string::string(const string & str){
  s = new char[str.allocated];
  allocated = str.allocated;
  l = str.l;
  strcpy(s, str.s, l);
}
string & string::operator=(const string &str){
  delete[] s;
  s = new char[str.allocated];
  allocated = str.allocated;
  l = str.l;
  strcpy(s, str.s, l);
  return *this;
}
string & string::operator+=(const string &str){
  if(l+str.l+1 >= allocated){
    string::size_type newlen = l+str.l+16 + (l+str.l)/2;
    char * n = new char[newlen];
    strcpy(n, s, l);
    delete[] s;
    s = n;
    allocated = newlen;
  }
  strcpy(s+l, str.s, str.l);
  l += str.l;
  return *this;
}
string  string::operator+(const string & str) const{
  string res;
  res += *this;
  res += str;
  return res;
}
char & string::operator[](string::size_type i) const{
  return s[i];
}

/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
