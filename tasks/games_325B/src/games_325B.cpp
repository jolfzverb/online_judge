#include <iostream>
#include <set>
#define ull unsigned long long

int main(){

  ull N;
  std::cin >> N;
  unsigned k = 0;
  std::set<ull> result;
  while((1ull << k) <= N+1){
    ull l = 2;
    ull r = l;
    std::cout << "find r " << k << std::endl;
    while (((1<<k)-1)*r+r*(r-1)/2 <= N) r*=2;
    std::cout << "r = " << r << std::endl;
    while (l!=r){
      std::cout << "main " << l << " " << r << std::endl;
      ull mid = (l+r)/2;
      ull sum = (((1<<k)-1)*mid) + ((mid*(mid-1))/2);
      if(mid%2 || mid==2){
	if(sum == N){
	  ull res = mid*(1<<k);
	  result.insert(res);
	  break;
	}
      }
      if ((((1<<k)-1)*mid) > N - ((mid*(mid-1))/2)){
	if(r==mid) r = mid-1;
	else r = mid;
      } else {
	if(l==mid) l = mid+1;
	else l = mid;
      }
    }
    k++;
  }
  if(k > 0 && (1ull<<(k-1))==N+1) result.insert(N+1);
  if(result.empty()) std::cout << -1 << std::endl;
  for(ull i : result){
    std::cout << i << std::endl;
  }
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
