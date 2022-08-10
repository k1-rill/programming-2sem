#ifndef LAB3_ALGO_H
#define LAB3_ALGO_H

#include <iostream>

template <typename T, typename predicate>
bool allof(T begin, T end, predicate p){
    for (; begin != end; ++begin)
        if (!p(*begin))
            return false;
    return true;
}

template <typename T, typename predicate>
bool anyof( T begin,  T end, predicate p){
    for (; begin != end; ++begin)
        if (p(*begin))
            return true;
    return false;
}


template <typename T, typename predicate>
bool noneof( T begin,  T end, predicate p){
    for(; begin != end; ++begin)
        if (p(*begin))
            return false;
    return true;
}


template <typename T, typename predicate>
bool oneof( T begin,  T end, predicate p){
    int k = 0;
    for(; begin != end; ++begin)
        if (p(*begin)) {
            k += 1;
            if (k>=2)
                return false;
        }
    if (k==1) return true;
    else return false;
}


template <typename T, typename comparator>
bool issorted( T begin,  T end, comparator comp){
    if (begin == end) return true;
    T next = begin;
    while (++next!=end){
        if (!comp(*next, *begin))
            return false;
        ++begin;
    }
    return true;
}

template <typename T, typename predicate>
bool ispartitioned( T begin,  T end, predicate p){
    for(; begin != end; ++begin)
        if (!p(*begin))
            break;
    for (; begin!=end; ++ begin)
        if(p(*begin))
            return false;
    return true;
}

template <typename T, typename element>
T findnot( T begin,  T end, element x){
    for(; begin != end; ++begin)
        if (x!=*begin)
            return begin;
    return begin;
}

template <typename T, typename element>
T findbackward( T begin,  T end, element x){
    T tmp = end;
    for (; begin != end; begin++)
        if (*begin == x)
            tmp = begin;
    return tmp;
}

template <typename T, typename comparator>
bool ispalindrome( T begin,  T end, comparator comp){
    if (begin == end)
        return true;
    end--;
    while (begin != end){
        if (!comp(*begin, *end))
            return false;
        ++begin;
        if (begin == end)
            break;
        --end;
    }
    return true;

}
#endif