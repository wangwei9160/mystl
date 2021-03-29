#include <iostream>
#include "vector.h"

int main(){
    mystl::vector<int> vec (10);   // 10 zero-initialized ints
    for(int i = 0 ; i < 10 ; i++) vec[i] = i;
    std::cout << *(vec.begin() + 5) << std::endl;
    return 0;
}
