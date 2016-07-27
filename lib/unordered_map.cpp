#include <functional>
#include <vector>
#include <list>
#include <utility>

template<class Key, class T, class Hash, class KeyEqual>
class unordered_map_iterator;

template<class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key> >
class unordered_map{
public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef std::pair<const Key, T> value_type;
  typedef unsigned int size_type;
  typedef int difference_type;
  typedef Hash hasher;
  typedef KeyEqual key_equal;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef unordered_map_iterator<Key, T, Hash, KeyEqual> iterator;

  unordered_map(size_type c = 1<<7, const Hash& h = Hash(), const KeyEqual& e = KeyEqual());
  unordered_map(const unordered_map&);
  ~unordered_map();
  unordered_map & operator=(const unordered_map&);
  iterator begin();
  iterator end();
  bool empty() const;
  size_type size() const;
  void clear();
  std::pair<iterator, bool> insert(const value_type&);
  iterator erase(const iterator);
  iterator erase(const key_type&);
  T & operator[](const Key&);
  iterator find(const Key &);
  double max_load_factor() const;
  void max_load_factor(double);
  void rehash(size_type);
  void dump();
private:
  size_type bucket_count;
  size_type element_count;
  hasher h;
  key_equal e;
  double mlf;
  std::vector<std::list<std::pair<key_type, value_type> > > buckets;
  friend class unordered_map_iterator<Key, T, Hash, KeyEqual>;
};
template<class Key, class T, class Hash, class KeyEqual>
void unordered_map<Key, T, Hash, KeyEqual>::dump(){
}
template<class Key, class T, class Hash, class KeyEqual>
void unordered_map<Key, T, Hash, KeyEqual>::rehash(size_type b){
  if(bucket_count == b) return;
  //this is quite nasty, but should work
  std::vector<std::list<std::pair<key_type, value_type> > > from = buckets;
  clear();
  buckets.resize(b);
  bucket_count = b;
  for(typename std::vector<std::list<std::pair<key_type, value_type> > >::iterator i = from.begin(); i!= from.end(); ++i){
    for(typename std::list<std::pair<key_type,value_type> >::iterator j = i->begin(); j!= i->end(); ++j){
      insert(*j);
    }
  }
}
template<class Key, class T, class Hash, class KeyEqual>
void unordered_map<Key, T, Hash, KeyEqual>::max_load_factor(double m){
  mlf = m;
  rehash(bucket_count);
}
template<class Key, class T, class Hash, class KeyEqual>
double unordered_map<Key, T, Hash, KeyEqual>::max_load_factor() const{
  return mlf;
}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map<Key, T, Hash, KeyEqual>::iterator unordered_map<Key, T, Hash, KeyEqual>::find(const key_type& k){
  size_type b = h(k) % bucket_count;
  typename std::list<std::pair<key_type, value_type> >::iterator it;
  for(it = buckets[b].begin(); it!= buckets[b].end(); ++it){
    if(e(it->first, k)) return iterator(this, b, it);
  }
  return end();
}
template<class Key, class T, class Hash, class KeyEqual>
T& unordered_map<Key, T, Hash, KeyEqual>::operator[](const key_type& k){
  iterator it = find(k);
  if(it == end()){
    it = insert(k, T());
  }
  return it->second;
}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map<Key, T, Hash, KeyEqual>::iterator unordered_map<Key, T, Hash, KeyEqual>::erase(const key_type& k){
  return erase(find(k));
}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map<Key, T, Hash, KeyEqual>::iterator unordered_map<Key, T, Hash, KeyEqual>::erase(const iterator pos){
  iterator res = pos;
  ++res;
  element_count--;
  buckets[pos.i].erase(pos.it);
  return res;
}
template<class Key, class T, class Hash, class KeyEqual>
std::pair<typename unordered_map<Key, T, Hash, KeyEqual>::iterator, bool> unordered_map<Key, T, Hash, KeyEqual>::insert(const value_type& val){
  size_type bucket = h(val.first) % bucket_count;
  for(typename std::list<std::pair<key_type, value_type> >::iterator it = buckets[bucket].begin(); it!= buckets[bucket].end(); ++it){
    if(e(it->first, val->first))
      return std::pair<iterator, bool>(iterator(this, bucket, it), false);
  }
  element_count++;
  buckets[bucket].push_back(val);
  if(double(element_count)/double(bucket_count) > mlf){
    rehash(2*bucket_count);
    return std::pair<iterator, bool>(find(val.first),true);
  } else {
    typename std::list<std::pair<key_type, value_type> >::iterator it = buckets[bucket].end();
    return std::pair<iterator, bool>(iterator(this, bucket, --it), true);
  }
}
template<class Key, class T, class Hash, class KeyEqual>
void unordered_map<Key, T, Hash, KeyEqual>::clear(){
  for(size_type i = 0; i < bucket_count; i++){
    buckets[i].clear();
  }
  element_count = 0;
}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map<Key, T, Hash, KeyEqual>::size_type unordered_map<Key, T, Hash, KeyEqual>::size() const{
  return element_count;
}
template<class Key, class T, class Hash, class KeyEqual>
bool unordered_map<Key, T, Hash, KeyEqual>::empty() const{
  return element_count == 0;
}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map<Key, T, Hash, KeyEqual>::iterator unordered_map<Key, T, Hash, KeyEqual>::end(){
  return iterator(this, bucket_count-1, buckets[bucket_count-1].end());
}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map<Key, T, Hash, KeyEqual>::iterator unordered_map<Key, T, Hash, KeyEqual>::begin(){
  return iterator(this, 0, buckets[0].begin());
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map<Key, T, Hash, KeyEqual> & unordered_map<Key, T, Hash, KeyEqual>::operator=(const unordered_map&other){
  buckets = other.buckets;
  bucket_count = other.bucket_count;
  element_count = other.element_count;
  h = other.h;
  e = other.e;
  mlf = other.mlf;
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map<Key, T, Hash, KeyEqual>::~unordered_map(){
  clear();
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map<Key, T, Hash, KeyEqual>::unordered_map(const unordered_map&other): buckets(other.buckets), bucket_count(other.bucket_count), element_count(other.element_count), h(other.h), e(other.e), mlf(other.mlf){}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map<Key, T, Hash, KeyEqual>::unordered_map(size_type c, const Hash& h, const KeyEqual& e): buckets(c), bucket_count(c), element_count(0), h(h), e(e), mlf(1.0) {}


template<class Key, class T, class Hash, class KeyEqual>
class unordered_map_iterator{
  public:
  typedef typename unordered_map<Key, T, Hash, KeyEqual>::difference_type difference_type;
  typedef typename unordered_map<Key, T, Hash, KeyEqual>::value_type value_type;
  typedef value_type* pointer;
  typedef value_type& reference;
#ifndef RELEASE
  typedef std::bidirectional_iterator_tag iterator_category;
#endif
  unordered_map_iterator();
  unordered_map_iterator(const unordered_map_iterator &);
  unordered_map_iterator & operator=(const unordered_map_iterator &);
  unordered_map_iterator & operator++();//prefix
  unordered_map_iterator operator++(int);//postfix
  unordered_map_iterator & operator--();//prefix
  unordered_map_iterator operator--(int);//postfix
  bool operator==(const unordered_map_iterator &)const;
  bool operator!=(const unordered_map_iterator &)const;
  value_type & operator*() const;
  value_type * operator->() const;
private:
  unordered_map_iterator(unordered_map<Key, T, Hash, KeyEqual> *, typename unordered_map<Key, T, Hash, KeyEqual>::size_type, typename std::list<std::pair<Key, T> >::iterator);
  friend class unordered_map<Key, T, Hash, KeyEqual>;
  unordered_map<Key, T, Hash, KeyEqual> *m;
  typename unordered_map<Key, T, Hash, KeyEqual>::size_type i;
  typename std::list<std::pair<Key, T> >::iterator it;
};
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual>::unordered_map_iterator(unordered_map<Key, T, Hash, KeyEqual> * m, typename unordered_map<Key, T, Hash, KeyEqual>::size_type i, typename std::list<std::pair<Key, T> >::iterator it): m(m), i(i), it(it) {}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map_iterator<Key, T, Hash, KeyEqual>::value_type* unordered_map_iterator<Key,T,Hash,KeyEqual>::operator->() const{
  return it;
}
template<class Key, class T, class Hash, class KeyEqual>
typename unordered_map_iterator<Key, T, Hash, KeyEqual>::value_type& unordered_map_iterator<Key,T,Hash,KeyEqual>::operator*() const{
  return *it;
}
template<class Key, class T, class Hash, class KeyEqual>
bool unordered_map_iterator<Key,T,Hash,KeyEqual>::operator!=(const unordered_map_iterator & other) const{
  return !(other.m==m && other.i==i && other.it==it);
}
template<class Key, class T, class Hash, class KeyEqual>
bool unordered_map_iterator<Key,T,Hash,KeyEqual>::operator==(const unordered_map_iterator & other) const{
  return (other.m==m && other.i==i && other.it==it);
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual> unordered_map_iterator<Key,T,Hash,KeyEqual>::operator--(int){
  unordered_map_iterator tmp = *this;
  while(it == m->buckets[i].begin()){
    if(i > 0){
      i--;
      it = m->buckets[i].end();
    }else{
      break;
    }
  }
  if (it == m->buckets[i].end() && it != m->buckets[0].begin()){
    it--;
  }
  return tmp;
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual> & unordered_map_iterator<Key,T,Hash,KeyEqual>::operator--(){
  while(it == m->buckets[i].begin()){
    if(i > 0){
      i--;
      it = m->buckets[i].end();
    }else{
      break;
    }
  }
  if (it == m->buckets[i].end() && it != m->buckets[0].begin()){
    it--;
  }
  return *this;
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual> unordered_map_iterator<Key,T,Hash,KeyEqual>::operator++(int){
  unordered_map_iterator tmp = *this;
  ++it;
  while(it == m->buckets[i].end()){
    if(i < m->bucket_count){
      i++;
      it = m->buckets[i].begin();
    }
  }
  return tmp;
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual> & unordered_map_iterator<Key,T,Hash,KeyEqual>::operator++(){
  ++it;
  while(it == m->buckets[i].end()){
    if(i < m->bucket_count){
      i++;
      it = m->buckets[i].begin();
    }
  }
  return *this;
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual> & unordered_map_iterator<Key,T,Hash,KeyEqual>::operator=(const unordered_map_iterator & other){
  m = other.m;
  i = other.i;
  it = other.it;
}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual>::unordered_map_iterator(const unordered_map_iterator & other): m(other.m), i(other.i), it(other.i) {}
template<class Key, class T, class Hash, class KeyEqual>
unordered_map_iterator<Key,T,Hash,KeyEqual>::unordered_map_iterator(): m(NULL), i(), it() {}

/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../")) */
/* eval: (flycheck-mode) */
/* End:              */
