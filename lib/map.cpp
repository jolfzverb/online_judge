template<typename Key, typename Val>
class map_iterator;

template<typename Key, typename Val>
class map{
public:
  typedef map_iterator iterator;
  typedef unsigned int size_type;
  map();
  Val & operator[](const Key&);
  iterator begin();
  iterator end();
  size_type size();
private:
  friend class map_iterator<Key, Val>;
};

template<typename Key, typename Val>
class map_iterator{
public:
  typedef pair<Key, Val> value_type;
}
