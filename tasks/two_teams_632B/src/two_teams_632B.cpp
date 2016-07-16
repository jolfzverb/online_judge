#include <iostream>
#include <vector>
#include "lib/string.cpp"

class world{
  public:
    world(): res(0) {}
    void process();
    long long calculate(long long len);
    int find_optimal();


    int n;
    std::vector<int> p;
    std::vector<int> a;
    long long res;

};
int world::find_optimal(){
    long long default_sum = 0;
    for(int i = 0; i < n; i++){
	default_sum += a[i] ? p[i] : -p[i];
    }
//    std::cout << "default: " << default_sum <<std::endl;
    long long max_sum = default_sum;
    long long max_index = 0;
    long long new_sum = default_sum;
    for(int i = 0; i < n; i++){
	new_sum += a[i] ? -p[i] : p[i];
//	std::cout << "new: " << new_sum  << " " << i <<std::endl;
	if(new_sum > max_sum){
	    max_sum = new_sum;
	    max_index = i+1;
	}
    }
    new_sum = default_sum;
    for(int i = n-1; i >= 0; i--){
	new_sum += a[i] ? -p[i] : p[i];
//	std::cout << "new: " << new_sum <<" " << max_sum <<std::endl;
	if(new_sum > max_sum){
	    max_sum = new_sum;
	    max_index = i-n;
	}
    }
//    std::cout << max_index << std::endl;
    return max_index;
}



long long world::calculate(long long len){
    long long r = 0;
    if(len >=0){
	for(int i = 0; i < n; i++){
	    r += i<len? !a[i] ? p[i] : 0 : a[i] ? p[i] : 0;
	}
    } else {
	for(int i = 0; i < n; i++){
	    r += i>=n+len? !a[i] ? p[i] : 0 : a[i] ? p[i] : 0;
	}
    }
    return r;
}



void world::process(){
    int i = find_optimal();
    res =  calculate(i);
}
    
std::istream & operator >> (std::istream & in, world & w){
    in >> w.n;
    for (int i = 0; i < w.n; i++){
	int t;
	in >> t;
	w.p.push_back(t);
    }
    string s;
    in >> s;
    const char * sp = s.c_str();
    for (const char * a = sp; *a; a++){
	if(*a == 'A')
	  w.a.push_back(0);
	else
	  w.a.push_back(1);
    }
    return in;
}
std::ostream & operator << (std::ostream & out, world & w){
    return out << w.res;
}


int main(){
    world w;
    std::cin >> w;
    w.process();
    std::cout << w << std::endl;
    return 0;
}
