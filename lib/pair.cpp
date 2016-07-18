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
