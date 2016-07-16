#include <iostream>
#include <list>

int main(){
    int N;
    int price;
    std::list<std::string> l;
    std::cin >> N >> price;
    for (int i = 0; i < N; i++){
	std::string t;
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


