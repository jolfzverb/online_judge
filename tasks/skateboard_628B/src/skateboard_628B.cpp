#include <iostream>
int main(){
    std::string s;
    std::cin >> s;
    long long count= 0;
    s = "0"+s;
    const char* c = s.c_str();
    c++;
    const char * compar = c;
    for (;*c;c++){
	if ((*c-'0') % 2)
	  continue;
	if (!((*c-'0') % 4)){
	    count ++;
	    if((*(c-1)-'0') % 2)
	      continue;
	    count += c - compar;
	    continue;
	}
	if((*(c-1)-'0') % 2)
	  count += c - compar;
    }
    std::cout << count << std::endl;
}


