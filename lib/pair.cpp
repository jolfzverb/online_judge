/* In wierd testing system that I am targeting, use of ANY includes is
 * forbidden. Thats why this pair implementation is in form of cpp file.
 * And that is why I need pair implementation.
 */
template<class T1, class T2>
struct pair {
  T1 first;
  T2 second;
  pair() : first(), second() {}
  pair(const T1 &first, const T2 &second) : first(first), second(second) {}
  pair(const pair<T1, T2> &p) : first(p.first), second(p.second) {}
  pair<T1, T2> operator=(const pair<T1, T2> &);
};
template<class T1, class T2>
pair<T1, T2> pair<T1, T2>::operator=(const pair<T1, T2> & other){
  first = other.first;
  second = other.second;
  return *this;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../")) */
/* eval: (flycheck-mode) */
/* End:              */
