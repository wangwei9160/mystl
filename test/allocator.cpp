//  allocator<string> alloc;            
//  auto const p = alloc.allocate(n);   
//  auto q = p ;                      // q指向最后构造的元素之后的位置  
//  alloc.construct(q++);             // *q为空字符串     
//  alloc.construct(q++, 10 , 'c');   //*q为cccccccccc  
//  alloc.construct(q++ , "hi" ) ;    //*q为hi!   
//  while (q != p)  alloc.destory(--q); // 释放真正构造的string 
//  alloc.deallocator(p,n);

#include <iostream>
#include "allocator.h"

int main(){
    
    return 0;
}
