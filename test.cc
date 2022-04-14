#include "seqlist.h"
#include <iostream>

int main() {
    container::linked_list<int> l{1,2,3,4,5,6};
    for(std::size_t i=0;i<6;++i){
        std::cout<<l[i]<<std::endl;
    }

    return 0;
}