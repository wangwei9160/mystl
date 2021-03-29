#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include <initializer_list>


namespace mystl{

template < class T >
class vector{
public:
    typedef mystl::allocator<T> data_allocator;

    // vector 的嵌套型别定义
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T&    const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef value_type* iterator;
    typedef const value_type* const_iterator;

protected:
    iterator _begin;         //表示目前使用的空间的头
    iterator _end;        //表示目前使用的空间的尾
    iterator _capacity;      //表示目前可用空间的尾

    void insert_aux(iterator position , const value_type& x);
    void deallocate(){
        if( _begin ) data_allocator::deallocate(_begin , _capacity - _begin);
    }
    

public:
    // 构造、复制、移动、析构函数
    vector() : _begin(0),_end(0),_capacity(0) {}
    vector(size_type n , const value_type& value) {fill_initialize(n,value);}
    explicit vector(size_type n ) {fill_initialize(n,T());}
    
    vector(const vector& rhs){
        range_init(rhs._begin , rhs._end);
    }

    vector(vector&& rhs) noexcept 
    :_begin(rhs._begin),_end(rhs._end),_capacity(rhs._capacity){
        rhs._begin = nullptr;
        rhs._end = nullptr;
        rhs._end = nullptr
    }

    //列表初始化容器 vector<T> vec({1,2,3,4,5}) 
    vector(std::initializer_list<value_type> ilist){
        range_init(ilist.begin() , ilist.end());
    }
    vector& operator=(const vector& rhs);
    vector& operator=(vector&& rhs) noexcept;
    vector& operator=(std::initializer_list<value_type> ilist){
        vector temp(ilist.begin() , ilist.end());
        swap(temp);
        return *this;
    }
    ~vector(){
        destory(_begin , _end);
        _begin = _end = _capacity = nullptr;
    }

    // 迭代器
    iterator begin() noexcept {return _begin;}
    const_iterator begin() cosnt noexcept {return _begin;}
    iterator end() {return _end;}
    const_iterator end() cosnt noexcept {return _end;}
    const_iterator cbegin() const noexcept {return begin();}
    const_iterator cend() const noexcept {return end();}
    // rbegin、rend 反向迭代器

    // 容量
    size_type size() const noexcept {
        return static_cast<size_type>(_end - _begin);
    }
    size_type capacity() const noexcept {
        return static_cast<size_type>(capacity() - begin()); 
    }

    bool empty() const {
        return begin() == end();
    }

    // 容器大小设置
    void pppppgod();
    void resize(size_type n);      // 设置大小 size
    void resize(size_type n , const value_type& value);
    void reserve(size_type n);     // 设置容量 _capacity
    void shrink_to_fit();           // 容器降低其容量和size相匹配


    // 访问元素
    reference operator[](size_type n) {
        // n < size()
        return *(_begin + n );
    }
    const_reference operator[](size_type n) const {
        // n < size()
        return *(_begin + n );
    }
    // vec.at(i)
    reference at(size_type n){
        // n < size()
        return (*this)[n];
    }
    const_reference at(suze_type n ) const {
        // n < size()
        return (*this)[n];
    }
    reference front() {
        // !empty()
        return *_begin;
    }
    const_reference front() const {
        // !empty()
        return *_begin;
    }
    reference back(){
        // !empty()
        return *(_end - 1 );
    }
    const_reference back() const {
        // !empty()
        return *(_end - 1 );
    }

    // data返回一个指向数据的指针，
    pointer data() noexcept { return _begin;}
    const_pointer data() const noexcept { return _begin;}
    
    // 修改
    // assign
    void assign(size_type n , const value_type& value);
    template<class Iter>
    void assign(Iter first , Iter last);
    void assign(std::initializer_list<value_type> ilist);

    //emplace、emplace_back
    template<class... Args>
    iterator emplace(const_iterator pos , Args&& ...args);
    template <class... Args>
    void emplace_back(Args&& ...args);

    //push_back、pop_back
    void push_back(const value_type& value);
    void push_back(value_type&& value){
        emplace_back(move(value));
    }
    void pop_back(){
        --_end;
        //销毁_end;
    }
    
    //insert
    iterator insert(const_iterator pos , const value_type& value);
    iterator insert(const_iterator pos , value_type&& value){
        return emplace(pos,move(value));
    }
    iterator insert(const_iterator pos , size_type n , const value_type& value){
        // begin() <= pos <= end() 
        return fill_insert(const_cast<iterator> pos , n , value);
    }
    template<class Iter>
    void insert(const_iterator pos,Iter first,Iter last){
        // begin() <= pos <= end() &&  first < last
        // 复制并插入
    }

    //erase、clear
    iterator erase(const_iterator pos);
    iterator erase(const_iterator first , const_iterator last);
    void clear() {erase(begin() , end());}

    //swap
    void swap(vector& rhs) noexcept;

private:
    void init_space(size_type size , size_type cap);
    void fill_initialize(size_type n , const value_type& value);
    template<class Iter>
    void range_init(Iter first , Iter last);


};
// class 到底结束
/*----------------------------------------------------------*/

template<class T>
void vector<T>::init_space(size_type size , size_type cap){
    try
    {
        _begin = data_allocator::allocate(cap);
        _end = _begin + size;
        _capacity = _begin + cap;
    }
    catch(...)
    {
        _begin = nullptr;
        _end = nullptr;
        _capacity = nullptr;
        throw;
    }
    
}

template<class T>
void vector<T>::fill_initialize(size_type n , const value_type& value){
    const size_type init_cap = std::max(static_cast<size_type>(16) , n );
    init_space(n , n);
}

template<class T>
template<class Iter>
void vector<T>::range_init(Iter first , Iter last){
    const size_type init_size = std::max(static_cast<size_type>(last-first) , static_cast<size_type>(16));
    init_space(static_cast<size_type>(last-first) , init_size);
    // copy
}


template<class T>
void vector<T>::reserve(size_type n){
    if(capacity() < n ){
        const auto old_size = size();
        auto temp = data_allocator::allocate(n);
        // move
        data_allocate(_begin , _capacity - _begin);
        _begin = temp;
        _end = _begin + old_size;
        _capacity = _begin + n ;
    }
}

template<class T>
void vector<T>::resize(size_type n , const value_type& value){
    if(n < size()){
        erase(begin() + n , end());
    }else {
        fill_insert(end() , n - size() , value );
    }
}

template<class T>
void vector<T>::resize(size_type n){
    resize(n , T());
}

template<class T>
void vector<T>::shrink_to_fit(){
    if(_end < _capacity){
        // _capacity = _end;
    }
}

//重载mystl的swap
template<class T>
void swap(vector<T>& lhs , vector<T>& rhs){
    lhs.swap(rhs);
}


} /* namespace mystl */

#endif /*MYSTL_VECTOR_H*/