#ifndef LAB3_ITER_H
#define LAB3_ITER_H

#include <iterator>
#include <iostream>
#include <algorithm>
template <class T>
class buff_iterator: public std::iterator<std::random_access_iterator_tag, T>{
private:
    T* _ptr;
    size_t _begin;
    size_t _end;
    size_t _position;
public:
    explicit buff_iterator(T* ptr, size_t begin, size_t end, size_t position):_ptr(ptr), _begin(begin), _end(end), _position(position){}
    buff_iterator(): _ptr(nullptr), _begin(0), _end(0), _position(0){}
    buff_iterator(const buff_iterator &other): _ptr(other._ptr), _begin(other._begin), _end(other._end), _position(other._position){}



    buff_iterator &operator+=(const int a){
        for (int i = 0; i<a; ++i){
            _ptr++;
            if (_ptr == _end)
                _ptr = _begin;
            _position ++;
        }
        return *this;
    }


    buff_iterator operator+(const int a) const {
        buff_iterator other(*this);
        other+=a;
        return other;
    }

    buff_iterator &operator++(){
        if (_ptr == _end)
            _ptr = _begin;
        else
            _ptr++;
        _position ++;
        return *this;
    }

    buff_iterator operator++(int){
        buff_iterator tmp(*this);
        ++_ptr;
        return tmp;
    }

    buff_iterator &operator--(){
        if (_ptr == _begin)
            _ptr = _end;
        else
            _ptr--;
        _position--;
        return *this;
    }

    buff_iterator operator-(const int a) const {
        buff_iterator other(*this);
        other -= a;
        return (*this);
    }

    buff_iterator &operator-=(const int a){
        for (int i = 0; i<a; ++i){
            _ptr--;
            if (_ptr == _begin)
                _ptr = _end;
            _position-=1;
        }
        return *this;
    }

    T &operator*() const{
        return *_ptr;
    }
    T *operator->() const{
        return _ptr;
    }
    T &operator[](const int a){
        return _ptr[a];
    }

    bool operator==(const buff_iterator &other) const{
        return (_ptr == other._ptr);
    }

    bool operator!=(const buff_iterator &other) const {
        return (_ptr != other._ptr);
    }

    bool operator>(const buff_iterator &other) const {
        return _position > other._position;
    }

    bool operator<(const buff_iterator &other) const {
        return _position < other._position;
    }

    bool operator>=(const buff_iterator &other) const {
        return _position >= other._position;
    }

    bool operator<=(const buff_iterator &other) const {
        return _position <= other._position;
    }


};
#endif