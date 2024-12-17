#include "/home/aman/code/metaalgo/include/ds/linear/linkedList/List.h"
#include <iostream>


int main(){
    List<int> l1 = {1,2,3,4,5};
  
  
    l1.push_front(0);

    l1.insert_at(69 , 3);
    int a = l1.pop_front();
    std::cout << a << std::endl;
    l1.print();
    std::cout << sizeof(l1) << std::endl;
    l1.pop_back();
    l1.print();
    std::cout << sizeof(l1) << std::endl;
    l1.remove(3);
    l1.remove(1);
    l1.print();
    l1.remove(5);

}