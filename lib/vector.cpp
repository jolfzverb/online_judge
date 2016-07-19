/* In wierd testing system that I am targeting, use of ANY includes is
 * forbidden. Thats why this vector implementation is in form of cpp file.
 * And that is why I need vector implementation.
 */
#ifndef RELEASE
#include <iterator>
#endif
template<typename T> class vector_iterator;
#ifndef NULL
#define NULL 0
#endif
template<typename T>
class vector{
public:
  typedef unsigned int size_type;
  typedef vector_iterator<T> iterator;

  vector();
  vector(size_type);
  vector(size_type, const T &);
  vector(const vector &);
  ~vector();
  iterator begin();
  iterator end();
  T& operator[](size_type);
  size_type size();
  vector & operator=(const vector & );
  void resize(size_type);
  void resize(size_type, const T &);
  void push_back(const T&);

private:
  T * v;
  size_type len;
  size_type allocated;
  friend class vector_iterator<T>;
};
//very unoptimal push_back
template <typename T> void vector<T>::push_back(const T& val){
  return resize(len+1,val);
}
template <typename T> void vector<T>::resize(size_type count){
  if(count > allocated){
    T * n = new T[count];
    for(size_type i = 0; i < len; i++){
      n[i] = v[i];
    }
    for(size_type i = len; i < count; i++){
      n[i] = T();
    }
    allocated = count;
    len = count;
    delete[] v;
    v = n;
  } else {
    for(size_type i = len; i < count; i++){
      v[i] = T();
    }
    len = count;
  }
}
template <typename T> void vector<T>::resize(size_type count, const T&val){
  if(count > allocated){
    T * n = new T[count];
    for(size_type i = 0; i < len; i++){
      n[i] = v[i];
    }
    for(size_type i = len; i < count; i++){
      n[i] = val;
    }
    allocated = count;
    len = count;
    delete[] v;
    v = n;
  } else {
    for(size_type i = len; i < count; i++){
      v[i] = val;
    }
    len = count;
  }
}
template <typename T> vector<T> & vector<T>::operator=(const vector<T> & other){
  if(v) delete[] v;
  len = other.len;
  allocated = other.allocated;
  v = new T[other.allocated];
  for(unsigned i = 0; i < other.len; i++) v[i] = other.v[i];
  return *this;
}
template <typename T> vector<T>::vector(const vector<T> & other){
  len = other.len;
  allocated = other.allocated;
  v = new T[other.allocated];
  for(unsigned i = 0; i < other.len; i++) v[i] = other.v[i];
}
template <typename T> vector<T>::vector(){
  v = NULL;
  len = 0;
  allocated = 0;
}
template <typename T> vector<T>::vector(size_type i){
  v = new T[i];
  len = i;
  allocated = i;
  for(unsigned int j = 0; j < len; j++){
    v[j] = T();
  }
}
template <typename T> vector<T>::vector(size_type i, const T& val){
  v = new T[i];
  len = i;
  allocated = i;
  for(unsigned int j = 0; j < len; j++){
    v[j] = val;
  }
}
template <typename T> vector<T>::~vector(){
  len = 0;
  allocated = 0;
  delete[] v;
  v = NULL;
}
template <typename T> typename vector<T>::size_type vector<T>::size(){
  return len;
}
template<typename T> typename vector<T>::iterator vector<T>::begin(){
  return vector<T>::iterator(this, 0);
}
template<typename T> typename vector<T>::iterator vector<T>::end(){
  return vector<T>::iterator(this, len);
}
template<typename T> T & vector<T>::operator[](size_type i){
  return v[i];
}
template<typename T>
class vector_iterator{
public:
  typedef int difference_type;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
#ifndef RELEASE
  typedef std::random_access_iterator_tag iterator_category;
#endif
  vector_iterator() : v(NULL), i(0) {};
  vector_iterator(const vector_iterator & other): v(other.v), i(other.i) {};
  vector_iterator & operator=(const vector_iterator &other){v = other.v; i = other.i; return *this;};
  vector_iterator & operator++(){if(i!=v->len) i++; return *this;}//prefix
  vector_iterator operator++(int){vector_iterator tmp = *this; if(i!=v->len) i++; return tmp;}//postfix
  vector_iterator & operator--(){if(i) i--; return *this;}//prefix
  vector_iterator operator--(int){vector_iterator tmp = *this; if(i) i--; return tmp;}//postfix
  bool operator==(const vector_iterator &other)const {return i==other.i;}
  bool operator!=(const vector_iterator &other)const {return i!=other.i;}
  bool operator<(const vector_iterator &other)const {return i<other.i;}
  bool operator<=(const vector_iterator &other)const {return  i<=other.i;}
  bool operator>(const vector_iterator &other)const {return  i>other.i;}
  bool operator>=(const vector_iterator &other)const {return  i>=other.i;}
  T & operator*() const{return (v->v)[i];}
  T * operator->() const{return (v->v)+i;}
  int operator-(const vector_iterator & other)const {return i-other.i;}
  vector_iterator & operator+=(int p){i+=p; if(i > v->len) i = v->len; return *this;}
  vector_iterator & operator-=(int p){i-=p;  return *this;}
  vector_iterator operator+(int p) const{vector_iterator tmp = *this; tmp.i+=p; return tmp;}
  vector_iterator operator-(int p) const{vector_iterator tmp = *this; tmp.i-=p;  return tmp;}
  void swap(vector_iterator & other){int t = i; i = other.i; other.i = t;};
private:
  vector<T> * v;
  typename vector<T>::size_type i;
  vector_iterator(vector<T> *v, typename vector<T>::size_type i): v(v), i(i) {}
  friend class vector<T>;
};


/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../")) */
/* eval: (flycheck-mode) */
/* End:              */
