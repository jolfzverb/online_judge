/* In wierd testing system that I am targeting, use of ANY includes is
 * forbidden. Thats why this vector implementation is in form of cpp file.
 * And that is why I need vector implementation.
 */
#ifndef NULL
#define NULL 0
#endif
template<typename It, typename T>
int count(const It & begin, const It & end, const T& val){
  int count = 0;
  for (It i = begin; i != end; i++){
    if(*i == val) count ++;
  }
  return count;
}
template<typename It>
It max_element(const It &begin, const It &end){
  It max = begin;
  for(It i = begin; i != end; i++){
    if(*i > *max) max = i;
  }
  return max;
}
template<typename It>
void it_swap(const It & first, const It & second){
  typename It::value_type temp = *first;
  *first = *second;
  *second = temp;
}
template<typename It>
void reverse(It first, It last){
  while((first != last) &&  (first != --last)){
    it_swap(first++, last);
  }
}
template<typename It, typename Cmp>
void sort_sift_up(It* v, int len, int i, Cmp cmp){
  if(!i)
    return;
  int c = (i + 1)/2 - 1;
  if(!cmp(*(v[i]), *(v[c]))){
    it_swap(v[i], v[c]);
    sort_sift_up(v,len,c, cmp);
  }
}
template<typename It, typename Cmp>
void sort_sift_down(It* v, int len, int i, Cmp cmp){
  if(i >= len/2)
    return;
  int c1 = (i+1)*2 -1;
  int c2 = (i+1)*2;
  if(c2 == len){
    if(!cmp(*(v[c1]), *(v[i]))){
      it_swap(v[c1], v[i]);
    }
    return;
  }
  int c = (!cmp(*(v[c1]), *(v[c2]))) ? c1 : c2;
  if(!cmp(*(v[c]), *(v[i]))){
    it_swap(v[c], v[i]);
    sort_sift_down(v, len, c, cmp);
  }
}
template<typename It, typename Cmp>
void sort_heapify(It* v, int len, Cmp cmp){
  for(int i = len/2-1; i >= 0; i--){
    sort_sift_down(v, len, i, cmp);
  }
}

template<typename It, typename Cmp>
void sort(It begin, It end, Cmp cmp){
  int count = 0;
  for(It i = begin; i != end; i++){
    count ++;
  }
  It * vec = new It[count];
  int c = 0;
  for(It i = begin; i != end; i++){
    vec[c] = i;
    c++;
  }
  sort_heapify(vec, count, cmp);
  for(int i = count-1; i>0; i--){
    it_swap(vec[0], vec[i]);
    sort_sift_down(vec,i,0, cmp);
  }
  delete[] vec;
}
template<typename It>
void sort_sift_up(It* v, int len, int i){
  if(!i)
    return;
  int c = (i + 1)/2 - 1;
  if(*(v[i]) > *(v[c])){
    it_swap(v[i], v[c]);
    sort_sift_up(v,len,c);
  }
}
template<typename It>
void sort_sift_down(It* v, int len, int i){
  if(i >= len/2)
    return;
  int c1 = (i+1)*2 -1;
  int c2 = (i+1)*2;
  if(c2 == len){
    if(*(v[c1]) > *(v[i])){
      it_swap(v[i], v[c1]);
    }
    return;
  }
  int c = *(v[c1]) > *(v[c2]) ? c1 : c2;
  if(*(v[c]) > *(v[i])){
    it_swap(v[c], v[i]);
    sort_sift_down(v, len, c);
  }
}
template<typename It>
void sort_heapify(It* v, int len){
  for(int i = len/2-1; i >= 0; i--){
    sort_sift_down(v, len, i);
  }
}

template<typename It>
void sort(It begin, It end){
  int count = 0;
  for(It i = begin; i != end; i++){
    count ++;
  }
  It * vec = new It[count];
  int c = 0;
  for(It i = begin; i != end; i++){
    vec[c] = i;
    c++;
  }
  sort_heapify(vec, count);
  for(int i = count-1; i>0; i--){
    it_swap(vec[0], vec[i]);
    sort_sift_down(vec,i,0);
  }
  delete[] vec;
}


/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../")) */
/* eval: (flycheck-mode) */
/* End:              */
