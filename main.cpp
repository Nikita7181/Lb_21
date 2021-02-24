#include <iostream>
#include "String.h"
int main()
{
    String test("abcefghrtasasafsafsafsafaffafs");
    std::cout << test << std::endl;
    String test_2(test);
    String tets_5("abcaaabcabbc");
    
    std::cout << test_2 << std::endl;
    std::cout << "---------------------------------Size------------------------------------" << std::endl;
    std::cout << "Size: " <<test.Size() << std::endl;
    std::cout << "---------------------------------Search------------------------------------" << std::endl;
    std::cout << test.Search('b')<<std::endl;
    std::cout << "---------------------------------Search------------------------------------" << std::endl;
    std::cout << test.Search("ffa")<<std::endl;
    std::cout << "---------------------------------Search------------------------------------" << std::endl;
    std::cout << tets_5.Search("aab") << std::endl;
    test.replacement( 'a',  'l');
    std::cout << "---------------------------------replacement------------------------------------" << std::endl;
    std::cout << test << std::endl;
    String test_3;
    std::cout << "----------------------------------Plus-----------------------------------"<< std::endl;
    test_3 = test_2 + test;
  std::cout << test_3 << std::endl;
    std::cout << "---------------------------------Equauls------------------------------------" << std::endl;
  if(test == test_3)
      std::cout << "true" << std::endl;
   else
       std::cout << "false" << std::endl;
    String test_4;
    std::cout << "Enter: ";
    std::cin >> test_4;
    std::cout << "---------------------------------Size------------------------------------" << std::endl;
    std::cout << test_4.Size() << std::endl;
    std::cout << "---------------------------------Cin------------------------------------" << std::endl;
    std::cout << test_4 << std::endl;
   
    return 0;
}
