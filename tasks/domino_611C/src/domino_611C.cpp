#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
#include "lib/string.cpp"
#include "lib/vector.cpp"
#define VAL 1000000007

int main(){
  int H;
  int W;
  std::cin >> H >> W;
  vector<int> f(H*W,0);
  for (int y = 0; y < H; y++){
    string s;
    std::cin >> s;
    for (int x = 0; x < W; x++){
      if(s[x]=='.') f[y*W+x] = 1;
      else f[y*W+x] = 0;
    }
  }
  vector<int> N(H*W, 0); // N[y][x] - number of places in rect (0,0,x,y)
  vector<int> Nx(H*W, 0); //Nx[y][x] - number of horisontal pieces [x-1, x] in (0,y) part of column x
  vector<int> Ny(H*W, 0); // Ny[y][x] - number of vertical pieces [y-1, y] in [0,x] part of row y

  for(int y = 1; y < H; y++){
    for(int x = 0; x < W; x++){
      Ny[y*W+x] = (x > 0 ? Ny[y*W+x-1] : 0) +(f[y*W+x]&& f[(y-1)*W+x] ? 1: 0);
    }
  }
  for(int x = 1; x < W; x++){
    for(int y = 0; y < H; y++){
      Nx[y*W+x] = (y > 0 ? Nx[(y-1)*W+x] : 0) + (f[y*W+x] && f[y*W+x-1] ? 1 : 0);
    }
  }
  for(int x = 1; x < W; x++){
    N[x] = N[x-1]+ Nx[x];
  }
  for(int y = 1; y < H; y++){
    N[y*W] = N[(y-1)*W]+ Ny[y*W];
  }
  for(int sum = 2; sum < W+H; sum++){
    for (int diff = 1; diff < sum; diff++){
      int y = sum - diff;
      int x = diff;
      if(x < W && y < H)
	N[y*W+x] = N[(y-1)*W+x] +N[y*W+x-1] - N[(y-1)*W+x-1] + (f[y*W+x] && f[y*W+x-1]) + (f[y*W+x] && f[(y-1)*W+x]);
    }
  }
  /*  std::cout << std::endl;
  for (int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
      std::cout << Nx[y*W+x] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for (int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
    std::cout << Ny[y*W+x] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for (int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
      std::cout << N[y*W+x] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;*/
  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; i++){
    int r1;
    int c1;
    int r2;
    int c2;
    std::cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    //    std::cout << N[r2*W+c2] << "-" << (r1>0? N[(r1-1)*W+c2]:0)<< "-"<< (c1>0?N[r2*W+c1-1]:0)<< "+"<< (r1*c1>0?N[(r1-1)*W+c1-1]:0)<< "-" << ((Nx[r2*W+c1]-(r1>0?Nx[(r1-1)*W+c1]:0))) <<"-" << ((Ny[(r1)*W+c2]-(c1>0?Ny[(r1)*W+c1-1]:0))) << std::endl;
    std::cout << N[r2*W+c2] - (r1>0? N[(r1-1)*W+c2]:0) - (c1>0?N[r2*W+c1-1]:0) + (r1*c1>0?N[(r1-1)*W+c1-1]:0) - ((Nx[r2*W+c1]-(r1>0?Nx[(r1-1)*W+c1]:0))) - ((Ny[(r1)*W+c2] - (c1>0?Ny[(r1)*W+c1-1]:0))) << std::endl;
  }

  return 0;
}
/* Local Variables:  */
/* eval: (setq flycheck-clang-language-standard "c++1z") */
/* eval: (flycheck-mode) */
/* End:              */
