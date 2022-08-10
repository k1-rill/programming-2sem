#include <iostream>
#include <algorithm>
#include <vector>
#include "circular_buffer.h"
#include "algo.h"

bool pred(int x){
    return x>0;
}

bool comp(int x, int y){
    return x>y;
}

void test(){
    std::vector <int> a = {1, 1, 3};
    if (allof(a.begin(), a.end(), pred))
        std::cout<<"true\n";
    else std::cout<<"false\n";

    if (anyof(a.begin(), a.end(), pred))
        std::cout<<"true\n";
    else std::cout<<"false\n";

    if (noneof(a.begin(), a.end(), pred))
        std::cout<<"true\n";
    else std::cout<<"false\n";

    if (oneof(a.begin(), a.end(), pred))
        std::cout<<"true\n";
    else std::cout<<"false\n";

    if (issorted(a.begin(), a.end(), comp))
        std::cout<<"true\n";
    else std::cout<<"false\n";

    if (ispartitioned(a.begin(), a.end(), pred))
        std::cout<<"true\n";
    else std::cout<<"false\n";

    std::cout << (*findnot(a.begin(), a.end(), 5)) << "\n";

    std::cout << (*findbackward(a.begin(), a.end(), 5)) << "\n";

    if (ispalindrome(a.begin(), a.end(), comp))
        std::cout<<"true\n";
    else std::cout<<"false\n";

}

int main() {
    Circular_Buffer<int> buf(5);
    buf.PushFront(3);
    buf.PushBack(2);
    buf.Output();
//    buf.PushBack(1);
//    buf.PushBack(3);
//    buf.Output();
//    buf.PushBack(2);
//    buf.PushBack(4);
//    buf.PushBack(0);
//    buf.Output();
//
//    std::cout << buf[0] << ' ' << buf[3] << '\n';
//
//    buf.PushBack(100);
//    buf.Output();
//    std::cout << buf[3] << '\n';
//
//    buf.PopFront();
//    buf.Output();
//
//    buf.PushBack(12);
//    buf.Output();
//
//    std::sort(buf.begin(), buf.end());
//    buf.Output();

    //test();

}
