// 主要包括：对已分配的内存进行调用构造函数和析构函数操作
// construct : 负责对象的构造
// destroy   : 负责对象的析构

#ifndef MYSTL_CONSTRUCT_H
#define MYSTL_CONSTRUCT_H

#include <new>
#include <iterator>

namespace mystl
{
    template<class T>
    void construct(T* ptr){
        ::new ((void*)ptr) T();
    }

    template<class T1 , class T2>
    void construct(T1* ptr , const T2& value){
        ::new ((void*)ptr) T1(value);
    }

    template <class T1 , class... Args>
    void construct(T1* ptr , Args&&... args){
        
    }

    template<class T>
    void destroy_one(T* , std::true_type){}

    template<class T>
    void destroy_one(T* ptr , std::false_type){
        if(ptr != nullptr){
            ptr -> ~T();
        }
    }

    template <class Iter>
    void destroy_cat(Iter , Iter , std::true_type) {}


    template<class Iter>
    void destroy_cat(Iter first , Iter last , std::false_type){
        for(; first != last ; ++first) destroy(&*first);
    }
    
    template<class T>
    void destroy(T* ptr){
        destroy_one(ptr,std::is_trivially_destructible<T>{});
    }

    template<class Iter>
    void destroy(Iter first , Iter last){
        destroy_cat(first, last, std::is_trivially_destructible<
              typename std::iterator_traits<Iter>::value_type>{});
    }


    
}/* namespace mystl */

#endif /* MYSTL_CONSTRUCT_H */