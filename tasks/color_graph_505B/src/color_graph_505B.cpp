#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <set>
#define VAL 1000000007

class item{
public:
  std::list<std::pair<int, item*>> c;
  int p;
};

int traverse(int c, int u, int v, item * items){
  if(v==u) return 1;
  if(items[u].p) return 0;
  items[u].p = 1;
  for(auto & i : items[u].c){
    if(i.first == c){
      if(traverse(c, i.second - items, v, items))
	return 1;
    }
  }
  return 0;
}
int main(){
  int N;
  int M;
  std::cin >> N >> M;
  item *items = new item[N];
  for(int i = 0; i < M; i++){
    int f;
    int t;
    int c;
    std::cin >> f >> t >> c;
    f--;
    t--;
    items[f].c.push_back(std::pair<int, item*>(c, (items+t)));
    items[t].c.push_back(std::pair<int, item*>(c, (items+f)));
  }
  int Q;
  std::cin >> Q;
  for(int i = 0; i < Q; i++){
    int u;
    int v;
    std::cin >> u >> v;
    u--;
    v--;
    std::set<int> colors_found;
    std::set<int> colors_todo;
    for(auto & i : items[v].c){
      colors_todo.insert(i.first);
      if(i.second == items+u)
	colors_found.insert(i.first);
    }
    for(auto & i : colors_found){
      colors_todo.erase(i);
    }
    for(auto & c : colors_todo){
      for(int j = 0; j < N; j++){
	items[j].p = 0;
      }
      if(traverse(c, u, v, items)){
	colors_found.insert(c);
      }
    }
    std::cout << colors_found.size() << std::endl;
  }
  delete[] items;


  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../../")) */
/* eval: (flycheck-mode) */
/* End:              */
