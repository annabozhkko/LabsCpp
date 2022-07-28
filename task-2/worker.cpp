#include <iostream>
#include <memory>
#include <type_traits>

class C{
public:
    C(int i) : i(i) {} //< constructor needed (until C++20)
    int i;
};

int main(){
    // using `auto` for the type of `sp1`
    auto sp1 = std::make_shared<C>(12);
    std::cout << sp1->i << '\n';

    // being explicit with the type of `sp2`
    std::shared_ptr<C> sp2 = std::make_shared<C>(13);
    std::cout << sp2->i << '\n';
}