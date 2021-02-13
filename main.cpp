#include <iostream>
#include "String.h"
int main()
{
    String test("abcefghrtasasafsafsafsafaffafs");
    std::cout << test << std::endl;
    String test_2(test);
    String test_3;
    String test_4;
    std::cout << test_2 << std::endl;
    std::cout << "Size: " <<test.Size() << std::endl;
    std::cout << test.Search('b')<<std::endl;
    std::cout << test.Search("ffa")<<std::endl;
    test.replacement( "a",  "l");
   std::cout << test << std::endl;
   test_3 = test_2 + test;
   std::cout << test_3 << std::endl;
    std::cin >> test_4;
    std::cout << test_4.Size() << std::endl;
    std::cout << test_4 << std::endl;
   
    return 0;
}
