/* In wierd testing system that I am targeting, use of ANY includes is
 * forbidden. Thats why this list implementation is in form of cpp file.
 * And that is why I need list implementation.
 */
template<typename T> class list_iterator;
#ifndef NULL
#define NULL 0
#endif
template<typename T>
class list{
public:
  typedef unsigned int size_type;
  typedef list_iterator<T> iterator;

  list():first(NULL), last(NULL), len(0) {}
  ~list();
  void push_back(const T&);
  void push_front(const T&);
  void pop_front();
  void pop_back();
  size_type size();
  T& front();
  const T& front() const;
  iterator begin();
  iterator end();



private:
  class item {
  public:
    item * next;
    item * prev;
    T * value;
  };
  item * first;
  item * last;
  size_type len;

  friend class list_iterator<T>;
};
template <typename T> void list<T>::pop_front(){
  if(first){
    len--;
    item * tmp = first->next;
    delete(first->value);
    delete(first);
    first = tmp;
    if(first)
      first->prev = NULL;
  }
}
template <typename T> void list<T>::pop_back(){
  if(last){
    len--;
    item * tmp = last->prev;
    delete(last->value);
    delete(last);
    last = tmp;
    if(last)
      last->next = NULL;
  }
}
template <typename T> list<T>::~list(){
  while (first){
    delete(first->value);
    item * tmp = first->next;
    delete first;
    first = tmp;
  }
}
template <typename T> void list<T>::push_back(const T& val){
  item *n = new item();
  n->value = new T(val);
  if(last != NULL){
    n->prev = last;
    last->next = n;
    last = n;
    len++;
  }else{
    first = n;
    last = n;
    len++;
  }
}
template <typename T> void list<T>::push_front(const T& val){
  item *n = new item();
  n->value = new T(val);
  if(first != NULL){
    n->next = first;
    first->prev = n;
    first = n;
    len++;
  }else{
    first = n;
    last = n;
    len++;
  }
}
template <typename T> typename list<T>::size_type list<T>::size(){
  return len;
}
template <typename T> T& list<T>::front(){
  return *(first->value);
}
template <typename T> const T& list<T>::front() const{
  return *(first->value);
}
template<typename T> typename list<T>::iterator list<T>::begin(){
  return list<T>::iterator(first);
}
template<typename T> typename list<T>::iterator list<T>::end(){
  return list<T>::iterator(NULL);
}

template<typename T>
class list_iterator{
  public:
  list_iterator() : i(NULL) {};
  list_iterator(const list_iterator & other): i(other.i) {};
  list_iterator & operator=(const list_iterator &other){i = other.i; return *this;};
  list_iterator & operator++(){if(i) i = i->next; return *this;}//prefix
  list_iterator operator++(int){list_iterator tmp = *this;if(i) i = i->next; return tmp;}//postfix
  list_iterator & operator--(){if(i) i = i->prev; return *this;}//prefix
  list_iterator operator--(int){list_iterator tmp = *this;if(i) i = i->prev; return tmp;}//postfix
  bool operator==(const list_iterator &other)const {return i==other.i;}
  bool operator!=(const list_iterator &other)const {return i!=other.i;}
  T & operator*() const{return *(i->value);}
  T * operator->() const{return i->value;}
  private:
  
  typename list<T>::item *i;
  list_iterator(typename list<T>::item *i): i(i) {}
  friend class list<T>;
};


/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../")) */
/* eval: (flycheck-mode) */
/* End:              */
