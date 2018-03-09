#include <iostream>
#include <vector>

int main(){
  int N;
  long long P;
  long long Q;
  long long R;
  std::cin >> N >> P >> Q >> R;
  std::vector<long long> p(N);
  std::vector<long long> q(N);
  std::vector<long long> r(N);
  for (int i = 0; i < N; i++) {
    long long a;
    std::cin >> a;
    p[i] = P*a;
    q[i] = Q*a;
    r[i] = R*a;
  }
  long long maxp = p[0];
  long long maxr = r[N-1];
  for (int i = 0; i < N; i++) {
    if(p[i] > maxp){
      maxp = p[i];
    }
    p[i] = maxp;

    if(r[N-i-1] > maxr){
      maxr = r[N-i-1];
    }
    r[N-i-1] = maxr;

  }

  long long max = p[0] + r[0] + q[0];
  for (int i = 0; i < N; i++) {
    long long cur = p[i] + r[i] + q[i];
    if(cur > max) max = cur;
  }

  std::cout << max << std::endl;
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
