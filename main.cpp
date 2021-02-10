#include <iostream>
#include "String.h"
int main()
{
    String k("aaatggtg");
    String m("t");
    String s;
    String l(k);
    
    std::cout << l << std::endl;
    std::cout << "Size: " <<k.Size() << std::endl;
    std::cout << k << std::endl;
    std::cout << k.Search(m)<<std::endl;
    
    k.replacement("t", "k");
    
    std::cout << k << std::endl;
    
    if(k==m)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    
    s = k+m;
    std::cout << s << std::endl;
    std::cout << s.Size()<< std::endl;
    String My;
    std::cout << "Enter: ";
    std::cin >> My;
    std::cout << My << std::endl;
    std::cout << My.Size() << std::endl;
    return 0;
}
