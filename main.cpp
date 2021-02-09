#include <iostream>
#include "String.h"
int main()
{
    String k("aaatggtg");
    String m("t");
    String l(k);
    std::cout << l << std::endl;
    std::cout << "Size: " <<k.Size() << std::endl;
    std::cout << k << std::endl;
    std::cout << k.Search(m)<<std::endl;
    k.replacement("t", "k");
    std::cout << k << std::endl;
    return 0;
}
