/* In wierd testing system that I am targeting, use of ANY includes is
 * forbidden. Thats why this map implementation is in form of cpp file.
 * And that is why I need map implementation.
 */
#include "lib/pair.cpp"
#ifndef RELEASE
#include <iterator>
#include <iostream>
#include <functional>
#endif
template<typename Key, typename Val>
class map_iterator;

template<typename Key, typename Val>
class map{
public:
  typedef map_iterator<Key, Val> iterator;
  typedef pair<const Key, Val> value_type;
  typedef unsigned int size_type;
  map();
  ~map();
  size_type size();
  Val & operator[](const Key&);
  iterator begin();
  iterator end();
  pair<iterator, bool> insert(const value_type &);
  void erase(iterator);
  iterator find(const Key &);
  void dump();
private:
  class item {
  public:
    item * parent;
    item * left;
    item * right;
    value_type * value;
    int color; //0 is red, 1 is black
  };
  item * root;
  size_type len;
  friend class map_iterator<Key, Val>;
  item * grandparent(item*);
  item * uncle(item*);
  void rotate_left(item*);
  void rotate_right(item*);
  void insert_0(item*, const Key &, const Val&);
  void insert_1(item*);
  void insert_2(item*);
  void insert_3(item*);
  void insert_4(item*);
  void insert_5(item*);
  static const item null_item;
  void recursive_remove_node(item*);
  void delete_node(item*);
  item* sibling(item*n);
  void delete_one_child(item *);
  void delete_1(item *);
  void delete_2(item *);
  void delete_3(item *);
  void delete_4(item *);
  void delete_5(item *);
  void delete_6(item *);
  item * internal_find(const Key &);
  item * next(item *);
  item * prev(item *);
#ifndef RELEASE
  void print_one(std::string&,item*);
#endif
};
#ifndef RELEASE
template<typename Key, typename Val>
void map<Key,Val>::print_one(std::string &s, item * n){
  if(n->value == NULL){
    return;
  }
  std::cout << s;
  std::cout << n->value->first << " " << n->value->second << " " << n->color << std::endl;
  std::string ns = s+"  ";
  print_one(ns,n->left);
  print_one(ns, n->right);
}
#endif
template<typename Key, typename Val>
void map<Key,Val>::dump(){
#ifndef RELEASE
  std::cout << "len: " << len << std::endl;
  std::string s = "";
  print_one(s, root);
#endif
}
template<typename Key, typename Val>
const typename map<Key,Val>::item map<Key,Val>::null_item = {NULL, NULL, NULL, NULL, 1};
template<typename Key, typename Val>
typename map<Key,Val>::item * map<Key,Val>::prev(item * n){
  if(n->left->value!=NULL){
    item * p = n->left;
    while(p->right->value!=NULL) p = p->right;
    return p;
  }
  while(n->parent != NULL && n == n->parent->left) n = n->parent;
  return n->parent;
}
template<typename Key, typename Val>
typename map<Key,Val>::item * map<Key,Val>::next(item * n){
  if(n->right->value!=NULL){
    item * p = n->right;
    while(p->left->value!=NULL) p = p->left;
    return p;
  }
  while(n->parent != NULL && n == n->parent->right) n = n->parent;
  return n->parent;
}
template<typename Key, typename Val>
typename map<Key,Val>::iterator map<Key,Val>::find(const Key & k){
  item * f = internal_find(k);
  if(f->value!= NULL){
    return iterator(this,f);
  } else {
    return iterator(this,NULL);
  }
}
template<typename Key, typename Val>
void map<Key,Val>::erase(iterator i){
  if(i.i != NULL)
    delete_node(i.i);
}
template<typename Key, typename Val>
pair<typename map<Key,Val>::iterator, bool> map<Key,Val>::insert(const value_type & v){
  const Key & k = v->first;
  const Val & val = v->second;
  item * f = internal_find(k);
  if(f->value == NULL){
    insert_0(f, k, v);
    return pair<iterator, bool>(iterator(this,f), true);
  } else {
    return pair<iterator, bool>(iterator(this,f), false);
  }
}
template<typename Key, typename Val>
typename map<Key,Val>::iterator map<Key,Val>::end(){
  return iterator(this,NULL);
}
template<typename Key, typename Val>
typename map<Key,Val>::iterator map<Key,Val>::begin(){
  item * n = root;
  while(n->left->value != NULL) n=n->left;
  return iterator(this,n);
}
template<typename Key, typename Val>
Val& map<Key,Val>::operator[](const Key & k){
  item * s = internal_find(k);
  if(s->value == NULL){
    insert_0(s, k, Val());
  }
  return s->value->second;
}
template<typename Key, typename Val>
typename map<Key,Val>::item * map<Key,Val>::internal_find(const Key & k){
  item * res = root;
  while(res->value != NULL){
    if(res->value->first == k)
      break;
    if(res->value->first < k){
      res = res->right;
    } else {
      res = res->left;
    }
  }
  return res;
}
template<typename Key, typename Val>
void map<Key, Val>::delete_6(item *n){
  item * s = sigling(n);
  s->color = n->parent->color;
  n->parent->color = 1;
  if(n->parent->left == n){
    s->right->color = 1;
    rotate_left(n->parent);
  } else {
    s->left->color = 1;
    rotate_right(n->parent);
  }
}
template<typename Key, typename Val>
void map<Key, Val>::delete_5(item *n){
  item * s = sigling(n);
  if(s->color == 1){
    if((n==n->parent->left) &&
       (s->right->color == 1) &&
       (s->left->color == 0)) {
      s->color = 0;
      s->left->color = 1;
      rotate_right(s);
    } else if ((n==n->parent->right) &&
	       (s->left->color = 1) &&
	       (s->right->color = 0)) {
      s->color = 0;
      s->right->color = 1;
      rotate_left(s);
    }
  }
  delete_6(n);
}
template<typename Key, typename Val>
void map<Key, Val>::delete_4(item *n){
  item * s = sigling(n);
  if((n->parent->color == 0) &&
     (s->color == 1) &&
     (s->left->color == 1) &&
     (s->right->color == 1)) {
    s->color = 0;
    n->parent->color=1;
  } else {
    delete_5(n);
  }
}
template<typename Key, typename Val>
void map<Key, Val>::delete_3(item *n){
  item * s = sibling(n);
  if((n->parent->color == 1) &&
     (s->color == 1) &&
     (s->left->color == 1) &&
     (s->right->color == 1)) {
    s->color = 0;
    delete_1(n->parent);
  } else {
    delete_4(n);
  }
}
template<typename Key, typename Val>
void map<Key, Val>::delete_2(item *n){
  item * s = sibling(n);
  if(s->color == 0){
    n->parent->color = 0;
    s->color = 1;
    if(n->parent->left == n){
      rotate_left(n->parent);
    } else {
      rotate_right(n->parent);
    }
  }
  delete_3(n);
}
template<typename Key, typename Val>
void map<Key, Val>::delete_1(item *n){
  if(n->parent != NULL){
    delete_2(n);
  }
}
template<typename Key, typename Val>
void map<Key, Val>::delete_one_child(item *n){
  item * c;
  if(n->left->value == NULL){
    c = n->right;
    delete n->left;
  } else {
    c = n->left;
    delete n->right;
  }
  // replace n with c
  if(n->parent != NULL){
    if(n->parent->left == n){
      n->parent->left = c;
    } else {
      n->parent->right = c;
    }
  }
  c->parent = n->parent;
  delete n->value;
  if(n->color == 1){
    if(c->color == 0){
      c->color = 1;
    } else {
      delete_1(c);
    }
  }
  delete n;
  len--;
}
template<typename Key, typename Val>
typename map<Key,Val>::item * map<Key,Val>::sibling(item*n){
  if(n->parent == NULL)
    return NULL;
  if(n->parent->left == n){
    return n->parent->right;
  } else {
    return n->parent->left;
  }
}
template<typename Key, typename Val>
void map<Key, Val>::delete_node(item* n){
  //find a node to replace n;
  item * p;
  if(n->left->value==NULL){
    if(n->right->value==NULL){
      return delete_one_child(n);
    }
    p = n->right;
    while(p->left->value != NULL){
      p = p->left;
    }
  } else {
    p = n->left;
    while(n->right->value != NULL){
      p = p->right;
    }
  }
  value_type * tmp = n->value;
  n->value = p->value;
  p->value = tmp;
  delete_one_child(p);
}
template<typename Key, typename Val>
void map<Key,Val>::insert_0(item *n, const Key & k, const Val & v){
  // assume n->value == NULL;
  len++;
  n->color = 0;
  n->left = new item(null_item);
  n->left->parent = n;
  n->right = new item(null_item);
  n->right->parent = n;
  n->value = new value_type(k,v);
  insert_1(n);
}
template<typename Key, typename Val>
void map<Key,Val>::recursive_remove_node(item*n){
  if(n->value == NULL){
    delete n;
    return;
  }
  recursive_remove_node(n->left);
  recursive_remove_node(n->right);
  delete n->value;
  delete n;
}
template<typename Key, typename Val>
map<Key,Val>::~map(){
  recursive_remove_node(root);
}
template<typename Key, typename Val>
map<Key,Val>::map(){
  len = 0;
  root = new item(null_item);
}
template<typename Key, typename Val>
void map<Key,Val>::insert_5(map<Key,Val>::item *n){
  map<Key,Val>::item * g = grandparent(n);
  n->parent->color=1;
  g->color=0;
  if((n==n->parent->left) && (n->parent==g->left)){
    rotate_right(g);
  } else {
    rotate_left(g);
  }
}
template<typename Key, typename Val>
void map<Key,Val>::insert_4(map<Key,Val>::item *n){
  map<Key,Val>::item * g = grandparent(n);
  if((n==n->parent->right) && (n->parent == g->left)){
    rotate_left(n->parent);
    n=n->left;
  } else  if((n==n->parent->left) && (n->parent == g->right)){
    rotate_right(n->parent);
    n=n->right;
  }
  insert_5(n);
}
template<typename Key, typename Val>
void map<Key,Val>::insert_3(map<Key,Val>::item *n){
  map<Key,Val>::item * u = uncle(n);
  map<Key,Val>::item * g;
  if((u!=NULL) && (u->color == 0) && (n->parent->color == 0)){
    n->parent->color = 1;
    u->color = 1;
    g = grandparent(n);
    g->color = 0;
    insert_1(g);
  } else {
    insert_4(n);
  }
}
template<typename Key, typename Val>
void map<Key,Val>::insert_2(map<Key,Val>::item *n){
  if(n->parent->color == 1){
    return;
  } else {
    insert_3(n);
  }
}
template<typename Key, typename Val>
void map<Key,Val>::insert_1(map<Key,Val>::item *n){
  if(n->parent==NULL){
    n->color=1;
  } else {
    insert_2(n);
  }
}
template<typename Key, typename Val>
void map<Key,Val>::rotate_right(map<Key,Val>::item *n){
  map<Key,Val>::item * pivot = n->left;
  pivot->parent = n->parent;
  if(n->parent!=NULL){
    if(n->parent->left == n){
      n->parent->left = pivot;
    } else {
      n->parent->right = pivot;
    }
  }
  n->left = pivot->right;
  if(pivot->right!=NULL){
    pivot->right->parent = n;
  }
  n->parent = pivot;
  pivot->right = n;
  if(root==n) root=pivot;
}
template<typename Key, typename Val>
void map<Key,Val>::rotate_left(map<Key,Val>::item *n){
  map<Key,Val>::item * pivot = n->right;
  pivot->parent = n->parent;
  if(n->parent!=NULL){
    if(n->parent->left == n){
      n->parent->left = pivot;
    } else {
      n->parent->right = pivot;
    }
  }
  n->right = pivot->left;
  if(pivot->left!=NULL){
    pivot->left->parent = n;
  }
  n->parent = pivot;
  pivot->left = n;
  if(root==n) root=pivot;
}
template<typename Key, typename Val>
typename map<Key,Val>::item * map<Key,Val>::uncle(map<Key,Val>::item * n){
  map<Key,Val>::item * g = grandparent(n);
  if(g==NULL){
    return NULL;
  }
  if(n->parent==g->right){
    return g->left;
  } else {
    return g->right;
  }
}

template<typename Key, typename Val>
typename map<Key,Val>::item * map<Key,Val>::grandparent(map<Key,Val>::item * n){
  if((n!=NULL) && (n->parent!=NULL)){
    return n->parent->parent;
  }
  return NULL;
}

template<typename Key, typename Val>
typename map<Key, Val>::size_type map<Key, Val>::size(){
  return len;
}

template<typename Key, typename Val>
class map_iterator{
  public:
  typedef int difference_type;
  typedef pair<const Key, Val> value_type;
  typedef value_type* pointer;
  typedef value_type& reference;
#ifndef RELEASE
  typedef std::bidirectional_iterator_tag iterator_category;
#endif
  map_iterator();
  map_iterator(const map_iterator &);
  map_iterator & operator=(const map_iterator &);
  map_iterator & operator++();//prefix
  map_iterator operator++(int);//postfix
  map_iterator & operator--();//prefix
  map_iterator operator--(int);//postfix
  bool operator==(const map_iterator &)const;
  bool operator!=(const map_iterator &)const;
  value_type & operator*() const;
  value_type * operator->() const;
private:
  map_iterator(map<Key,Val> *,typename map<Key,Val>::item *);
  typename map<Key,Val>::item *i;
  map<Key,Val> * m;
  friend class map<Key, Val>;
};
template<typename Key, typename Val>
map_iterator<Key,Val> map_iterator<Key,Val>::operator--(int){
  map_iterator tmp = *this;
  i = m->prev(i);
  return tmp;
}
template<typename Key, typename Val>
map_iterator<Key,Val> & map_iterator<Key,Val>::operator--(){
  i = m->prev(i);
  return *this;
}
template<typename Key, typename Val>
map_iterator<Key,Val> map_iterator<Key,Val>::operator++(int){
  map_iterator tmp = *this;
  i = m->next(i);
  return tmp;
}
template<typename Key, typename Val>
map_iterator<Key,Val> & map_iterator<Key,Val>::operator++(){
  i = m->next(i);
  return *this;
}
template<typename Key, typename Val>
typename map_iterator<Key,Val>::value_type * map_iterator<Key,Val>::operator->() const{
  return i->value;
}
template<typename Key, typename Val>
typename map_iterator<Key,Val>::value_type & map_iterator<Key,Val>::operator*() const{
  return *(i->value);
}
template<typename Key, typename Val>
bool map_iterator<Key,Val>::operator!=(const map_iterator<Key,Val> & other) const{
  return m!=other.m || i!=other.i;
}
template<typename Key, typename Val>
bool map_iterator<Key,Val>::operator==(const map_iterator<Key,Val> & other) const{
  return m==other.m && i==other.i;
}
template<typename Key, typename Val>
map_iterator<Key,Val> & map_iterator<Key,Val>::operator=(const map_iterator<Key,Val> & other){
  i = other.i;
  m = other.m;
}
template<typename Key, typename Val>
map_iterator<Key,Val>::map_iterator(): i(NULL), m(NULL) {}
template<typename Key, typename Val>
map_iterator<Key,Val>::map_iterator(const map_iterator<Key,Val> & other): i(other.i), m(other.m) {}
template<typename Key, typename Val>
map_iterator<Key,Val>::map_iterator(map<Key,Val> *m, typename map<Key,Val>::item *i): i(i), m(m) {}

/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../")) */
/* eval: (flycheck-mode) */
/* End:              */
