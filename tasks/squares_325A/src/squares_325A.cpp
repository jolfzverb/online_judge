#include <iostream>
#include <vector>
#include <algorithm>
class rect{
public:
  int x1;
  int y1;
  int x2;
  int y2;
};
  

int main(){
  int N;
  std::cin >> N;
  std::vector<rect> l;
  rect max = {31400, 31400, 0, 0};
  for (int i = 0 ; i < N; i++){
    rect a;
    std::cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    max.x1 = max.x1 > a.x1 ? a.x1 : max.x1;
    max.y1 = max.y1 > a.y1 ? a.y1 : max.y1;
    max.x2 = max.x2 < a.x2 ? a.x2 : max.x2;
    max.y2 = max.y2 < a.y2 ? a.y2 : max.y2;
    l.push_back(a);
  }
  if(max.y1-max.x1 != max.y2-max.x2){
    std::cout << "NO" << std::endl;
    return 0;
  }
  std::vector<rect> t = l;
  // search neighbours of each rect
  for(int i = 0; i < N; i++){
    //upper neighbours
    // upper border is in y1, from x1 to x2, so search for
    std::sort(t.begin(), t.end(), [](const rect &a, const rect &b) -> bool {return a.x1 < b.x1;});
    int startx = l[i].x1;
    int endx = l[i].x2;
    for (auto & r : t){
      if(r.y2 == l[i].y1){
	if(r.x1 <= startx && r.x2 > startx)
	  startx = r.x2;
      }
    }
    if(l[i].y1 != max.y1 && startx<endx){
      std::cout << "NO" << std::endl;
      return 0;
    }
    //down neighbours
    //down border is in y2, from x1 to x2, so search for
    startx = l[i].x1;
    endx = l[i].x2;
    for (auto & r : t){
      if(r.y1 == l[i].y2){
	if(r.x1 <= startx && r.x2 > startx)
	  startx = r.x2;
      }
    }
    if(l[i].y2 != max.y2 && startx<endx){
      std::cout << "NO" << std::endl;
      return 0;
    }
        //left neighbours
    // left border is in x1, from y1 to y2, so search for
    std::sort(t.begin(), t.end(), [](const rect &a, const rect &b) -> bool {return a.y1 < b.y1;});
    startx = l[i].y1;
    endx = l[i].y2;
    for (auto & r : t){
      if(r.x2 == l[i].x1){
	if(r.y1 <= startx && r.y2 > startx)
	  startx = r.y2;
      }
    }
    if(l[i].x1 != max.x1 && startx<endx){
      std::cout << "NO" << std::endl;
      return 0;
    }
    //down neighbours
    //down border is in x2, from y1 to y2, so search for
    startx = l[i].y1;
    endx = l[i].y2;
    for (auto & r : t){
      if(r.x1 == l[i].x2){
	if(r.y1 <= startx && r.y2 > startx)
	  startx = r.y2;
      }
    }
    if(l[i].x2 != max.x2 && startx<endx){
      std::cout << "NO" << std::endl;
      return 0;
    }
    
  }
  std::cout << "YES" << std::endl;
    
  
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* End:              */
