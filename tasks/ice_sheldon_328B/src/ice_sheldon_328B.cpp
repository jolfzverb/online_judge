#include <string>
#include <iostream>
int main(){
  std::string s;
  std::string d;
  std::cin >> s >> d;
  const char * s_ = s.c_str();
  int si[10];
  int di[10];
  for(int i =0 ; i < 10; i++){
    si[i]=0;
    di[i] = 0;
  }
  for (;*s_; s_++){
    switch( *s_){
    case '0':
      si[0]++;
      break;
    case '1':
      si[1]++;
      break;
    case '2':
    case '5':
      si[2]++;
      break;
    case '3':
      si[3]++;
      break;
    case '4':
      si[4]++;
      break;
    case '6':
    case '9':
      si[6]++;
      break;
    case '7':
      si[7]++;
      break;
    case '8':
      si[8]++;
    default:
      break;
    }
  }
  for (const char * d_ = d.c_str();*d_; d_++){
    switch( *d_){
    case '0':
      di[0]++;
      break;
    case '1':
      di[1]++;
      break;
    case '2':
    case '5':
      di[2]++;
      break;
    case '3':
      di[3]++;
      break;
    case '4':
      di[4]++;
      break;
    case '6':
    case '9':
      di[6]++;
      break;
    case '7':
      di[7]++;
      break;
    case '8':
      di[8]++;
    default:
      break;
    }
  }
  int max = 10000;
  for (int i = 0; i<10; i++){
    if(si[i]){
      max = max< di[i]/si[i]?max : di[i]/si[i];
    }
  }
  std::cout << max << std::endl;
}
      
