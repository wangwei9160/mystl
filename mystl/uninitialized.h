
/*
uninitialized_copy( b , e , b2 )：从迭代器b和e指出的输入范围中拷贝元素到迭代器b2指定的未构造的原始内存中。b2指向的内存必须足够大，能容纳输入序列中元素的拷贝
uninitialized_copy_n( b , n , b2 )：从迭代器b指向的元素开始，拷贝n个元素到b2开始的内存中
uninitialized_fill( b , e , t )：在迭代器b和e指定的原始内存范围中创建对象，对象的值均为t的拷贝
uninitialized_fill_n( b , n , t )：从迭代器b指向的内存地址开始创建n个对象。b必须指向足够大的未构造的原始内存，能够容纳给定数量的对象

*/


#ifndef MTSTL_UNINITIALIZED_H
#define MTSTL_UNINITIALIZED_H


namespace mystl{

/*
uninitialized_copy:
把[first,last)上的内容复制到一result为起始处的空间，返回结束位置。
*/
template <class InputerIter , class ForwardIter>
ForwardIter uninitialized_copy(InputerIter first , InputerIter last , ForwardIter result){
        
}


/*
uninitialized_copy_n:
把[first,first+n)上的内容复制到一result为起始处的空间，返回结束位置。
*/
template <class InputerIter , class Size , class ForwardIter>
ForwardIter uninitialized_copy_n(InputerIter first , Size n, ForwardIter result){
        
}

/*
uninitialized_fill:
在[first，last)区间内填充指定的元素值
*/
template <class ForwardIter , class T>
void uninitialized_fill(ForwardIter fist , ForwardIter last , const T& value){

}

/*
uninitialized_fill_n:
在[first，fist+n)区间内填充指定的元素值，返回结束位置。
*/
template <class ForwardIter , class Size , class T>
ForwardIter uninitialized_fill(ForwardIter fist , Size n , const T& value){

}

} /* namespace mystl */

#endif 


