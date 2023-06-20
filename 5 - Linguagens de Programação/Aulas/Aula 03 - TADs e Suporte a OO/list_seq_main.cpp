#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

int main() {
    ListSeq ls(5);
    ls.add(12);
    ls.add(2);
    ls.add(30);
    ls.add(4);
    ls.add(5);
    sort(ls.data, ls.data + ls.size);
    
    //ls.resize();
    //ls.add(20); 
    ls.print();
    // ls.insert(0, 0);
    // ls.print();
    // ls.resize();
}
