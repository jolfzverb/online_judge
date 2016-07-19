#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#define VAL 1000000007

int main(){

  int *a = new int[1000*1000];
  int N;
  int M;
  std::cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      int t;
      std::cin >> t;
      a[i*1000+j] = t;
    }
  }
  int *x = new int[1000*1000];
  int *y = new int[1000*1000];
  int *xe = new int[1000*1000];
  int *ye = new int[1000*1000];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      // x
      if(i==0 && j == 0){
	x[i*1000+j] = a[i*1000+j];
      }else if(i == 0){
	x[i*1000+j] = x[i*1000+j-1]+a[i*1000+j];
      }else if(j == 0){
	x[i*1000+j] = x[(i-1)*1000+j]+a[i*1000+j];
      }else{
	x[i*1000+j] = (x[(i-1)*1000+j] > x[i*1000+j-1] ? x[(i-1)*1000+j] : x[i*1000+j-1]) + a[i*1000+j];
      }
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = M-1; j >=0; j--){
      if(i==0 && j == M-1){
	ye[i*1000+j] = a[i*1000+j];
      }else if(i == 0){
	ye[i*1000+j] = ye[i*1000+j+1]+a[i*1000+j];
      }else if(j == M-1){
	ye[i*1000+j] = ye[(i-1)*1000+j]+a[i*1000+j];
      }else{
	ye[i*1000+j] = (ye[(i-1)*1000+j] > ye[i*1000+j+1] ? ye[(i-1)*1000+j] : ye[i*1000+j+1]) + a[i*1000+j];
      }
    }
  }
  for(int i = N-1; i >=0; i--){
    for(int j = 0; j < M; j++){
      if(i==N-1 && j == 0){
	y[i*1000+j] = a[i*1000+j];
      }else if(i == N-1){
	y[i*1000+j] = y[i*1000+j-1]+a[i*1000+j];
      }else if(j == 0){
	y[i*1000+j] = y[(i+1)*1000+j]+a[i*1000+j];
      }else{
	y[i*1000+j] = (y[(i+1)*1000+j] > y[i*1000+j-1] ? y[(i+1)*1000+j] : y[i*1000+j-1]) + a[i*1000+j];
      }
    }
  }
  for(int i = N-1; i >=0; i--){
    for(int j = M-1; j >=0; j--){
      if(i==N-1 && j == M-1){
	xe[i*1000+j] = a[i*1000+j];
      }else if(i == N-1){
	xe[i*1000+j] = xe[i*1000+j+1]+a[i*1000+j];
      }else if(j == M-1){
	xe[i*1000+j] = xe[(i+1)*1000+j]+a[i*1000+j];
      }else{
	xe[i*1000+j] = (xe[(i+1)*1000+j] > xe[i*1000+j+1] ? xe[(i+1)*1000+j] : xe[i*1000+j+1]) + a[i*1000+j];
      }
    }
  }
  /*  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      std::cout << a[i*1000+ j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      std::cout << x[i*1000+ j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      std::cout << xe[i*1000+ j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      std::cout << y[i*1000+ j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      std::cout << ye[i*1000+ j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;*/
  int max = 0;
  for(int i = 1; i < N-1; i++){
    for (int j = 1; j < M-1; j++){
      int sum1 = x[(i-1)*1000+j]+xe[(i+1)*1000+j]+y[i*1000+j-1]+ye[i*1000+j+1];
      int sum2 = x[i*1000+j-1]+xe[i*1000+j+1]+y[(i+1)*1000+j]+ye[(i-1)*1000+j];
      int sum = sum1 > sum2 ? sum1 : sum2;
      max = max > sum ? max : sum;
    }
  }
  std::cout << max << std::endl;
  delete[] a;
  delete[] x;
  delete[] y;
  delete[] xe;
  delete[] ye;
  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (setq flycheck-clang-include-path (list "../../../")) */
/* eval: (flycheck-mode) */
/* End:              */
