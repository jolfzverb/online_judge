#include <iostream>
#include <list>
#include "lib/string.cpp"
#include "lib/list.cpp"

int main(){
    int N;
    int price;
    list<string> l;
    std::cin >> N >> price;
    for (int i = 0; i < N; i++){
	string t;
	std::cin >> t;
	l.push_front(t);
    }
    long long j = 0;
    int count = 0;
    for (auto i = l.begin(); i != l.end(); i++){
	if(*i == "half") j<<=1;
	else {
	    j = (j<<1) +1;
	    count++;
	}
    }

    std::cout << j*price - count*(price/2) << std::endl;
}


