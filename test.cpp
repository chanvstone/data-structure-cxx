#include <iostream>
#include "seqlist.h"
#include "linked_list.h"

int main() {
    container::linked_list<int> l{1, 2, 4, 5};
    l.insert(2, 3);
    auto a = l[0];
    auto b = l[2];
    return 0;
}