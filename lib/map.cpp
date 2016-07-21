/* In wierd testing system that I am targeting, use of ANY includes is
 * forbidden. Thats why this map implementation is in form of cpp file.
 * And that is why I need map implementation.
 */
#include "lib/pair.cpp"
#ifndef RELEASE
#include <iterator>
#endif
template<typename Key, typename Val>
class map_iterator;

template<typename Key, typename Val>
class map{
public:
  typedef map_iterator<Key, Val> iterator;
  typedef pair<const Key, Val> value_type;
  typedef unsigned int size_type;
  map() : root(NULL), len(0) {}
  Val & operator[](const Key&);
  iterator begin();
  iterator end();
  size_type size();
  pair<iterator, bool> insert(const value_type &);
  void erase(iterator);
  iterator find(const Key &);
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
};

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
  map_iterator(const map_iterator & other);
  map_iterator & operator=(const map_iterator &other);
  map_iterator & operator++();
  map_iterator operator++(int);
  map_iterator & operator--();
  map_iterator operator--(int);
  bool operator==(const map_iterator &other)const;
  bool operator!=(const map_iterator &other)const;
  value_type & operator*() const;
  value_type * operator->() const;
private:
  map_iterator(typename map<Key,Val>::item *);
  friend class map<Key, Val>;
};

/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../")) */
/* eval: (flycheck-mode) */
/* End:              */
