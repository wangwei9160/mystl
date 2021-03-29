#ifndef MYSTL_ALGORITHM_H
#define MYSTL_ALGORITHM_H



namespace mystl
{
#ifdef max
#undef max
#endif // max

#ifdef min
#undef min
#endif // min

template<class T>
const T& max(const T& lhs , const T& rhs){
    return lhs < rhs ? rhs : lhs ;
}

template <class T , class Compare>
const T& max(const T& lhs , const T& rhs , Compare cmp){
    return cmp(lhs , rhs ) ? rhs : lhs ;
}

template<class T>
const T& min(const T& lhs , const T& rhs){
    return lhs < rhs ? lhs : rhs ;
}

template <class T , class Compare>
const T& min(const T& lhs , const T& rhs , Compare cmp){
    return cmp(lhs , rhs ) ? lhs : rhs ;
}


    
} // namespace name



#endif /*MYSTL_ALGORITHM_H*/