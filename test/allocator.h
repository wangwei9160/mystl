/*

ptrdiff_t : 两个指针的距离差

函数包括：
allocate(n)
dellocate(p)
dellocate(p,n)
construct(p)
construct(p,T&)
construct(p,T)
construct(p,Args)
destroy(p)
destroy(p,n)



*/


// 避免重复导入头文件
#ifndef MTSTL_ALLOCATOR_H
#define MTSTL_ALLOCATOR_H

namespace mystl{

template<class T> 
class allocator
{
    public:
        typedef T           value_type;
        typedef T*          pointer;
        typedef const T*    const_pointer;
        typedef T&          reference;
        typedef const T&    const_reference;
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;

        // 给定了类型T的分配器，根据相同的策略得到另外一个类型TT的分配器，
        // 那么allocator<TT>=allocator<T>::Rebind<TT>::other.
        template <class TT >
        struct rebind{
            typedef allocator<TT > other;
        };

    public:
        static T* allocate();//默认生成一个
        static T* allocate(size_type n);//生成多个,n>=0,特判0的情况

        static void dellocate(T* ptr);//默认释放一个
        static void dellocate(T* ptr , size_type n);//释放多个,n>=0,特判0的情况

        static void construct(T* ptr);//构造一个默认为空的
        static void construct(T* ptr , const T& value);//创建一个对象，方式是调用T的有参构造函数，参数为传过来的值
        static void construct(T* ptr , T&& value);//创建一个对象，方式是调用T的有参构造函数，参数为传过来的值
        template<class... Args>
        static void construct(T* ptr , Args&& ...args);//带参数列表的构造

        static void destroy(T* ptr);//对p所指的对象进行析构函数
        static void destroy(T* ptr , size_type n );
    
};

template <class T >
T* allocator<T>::allocate(){
    return static_cast<T*>(::operator new(sizeof(T)));
}
template<class T>
T* allocator<T>::allocate(size_type n){
    if ( n == 0 )
        return nullptr;
    return static_cast<T*>(::operator new(n * sizeof(T)));
}

template<class T>
void allocator<T>::dellocate(T* ptr){
    if ( ptr == nullptr )
        return ;
    ::operator delete(ptr);
}

template <class T>
void allocator<T>::construct(T* ptr){
    // construct.h 中写模块
}
template <class T>
void allocator<T>::construct(T* ptr , const T& value){
    // construct.h 中写模块
}
template <class T>
void allocator<T>::construct(T* ptr , T&& value){
    // construct.h 中写模块
}
template <class T>
template <class ...Args>
void allocator<T>::construct(T* ptr, Args&& ...args){
    // construct.h 中写模块
}

template<class T>
void allocator<T>::destroy(T* ptr){
    // construct.h 中写模块
}




}// **mystl**
#endif // MTSTL_ALLOCATOR_H