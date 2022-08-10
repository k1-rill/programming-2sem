#ifndef LAB3_CIRCULAR_BUFFER_H
#define LAB3_CIRCULAR_BUFFER_H

#include <iostream>
#include "iter.h"


template <typename T>
class Circular_Buffer{
private:
    T *_buffer;
    size_t _capacity = 0; // size of all buffer
    size_t _begin;
    size_t _end;
    size_t _element_count;
public:
    explicit Circular_Buffer(size_t capacity = 0) : _capacity(capacity){
        _begin = 0;
        _end = 0;
        _element_count = 0;
        _buffer = new T[capacity];
    }

    buff_iterator<T> begin() {
        return buff_iterator(_buffer + _begin);
    }

    buff_iterator<T> end() {
        return buff_iterator(_buffer + _end + 1);
    }

    buff_iterator <const T> begin() const {
        return buff_iterator(_buffer + _begin);
    }

    buff_iterator <const T> end() const {
        return buff_iterator(_buffer + _end + 1);
    }

    const T &operator[] (const int &a) const {
        if (a > _capacity)
            throw std::invalid_argument("the size of buffer is less than index");
        else if (_end - _begin + 1 < a)
            throw std::invalid_argument("no such element in buffer");
        else{
            if (a+_begin <=_capacity)
                return _buffer[a+_begin];
            else
                return _buffer[(a+_begin) % _capacity];
        }

    }

    T &get_front() const {
        return _begin;
    }

    const T &get_front_const() const {
        return _begin;
    }

    T &get_back() const {
        return _end -1;
    }

    const T&get_back_const() const{
        return _end - 1;
    }


    void resize(const int size){
        if (size < _capacity)
            throw std::invalid_argument("this size is less than size of buffer");
        T *tmp = new T[size];
        int k = _begin;
        int i = 0;
        while (k!=_end) {
            if (k == _capacity)
                k = 0;
            tmp[i] = _buffer[k];
            i++;
            k++;
        }
        tmp[i] = _buffer[k];
        delete[] _buffer;
        _buffer = tmp;
        _capacity = size;
        _begin = 0;
        _end = _element_count - 1;
    }

    void PushFront(const T &elem){
        if (_element_count == _capacity)
            resize(_element_count*2);

        if (_begin == 0 && _end == 0) {
            _begin = _capacity - 1;
            _end = -1;
        }
        else if (_begin==0)
            _begin = _capacity - 1;
        else
            _begin--;
        _buffer[_begin] = elem;
        _element_count++;
    }

    void PushBack(const T &elem){
        if (_element_count == _capacity)
            resize(_element_count*2);
        if (_element_count==0){
            _buffer[0] = elem;
            _element_count++;
        }else {
            if (_end == _capacity - 1)
                _end = 0;
            else
                _end++;
            _buffer[_end] = elem;
            _element_count++;
        }
    }

    void PopBack(){
        if (_capacity == 0 || _element_count == 0)
            throw std::invalid_argument("buf size = 0 or no  elements");
        if (_end == 0){
            _end = _capacity - 1;
            _element_count--;
        }
        _element_count--;
//        _buffer[_end] = -1;
        _end--;

    }

    void PopFront(){ // кольцо
        if (_capacity == 0)
            throw std::invalid_argument("buf size = 0");
        if (_begin == _capacity-1){
            _begin = 0;
            _element_count--;
        }
        _element_count--;
//        _buffer[_begin] = -1;
        _begin ++;
    }

     void Output(){
        auto it = _begin;

        while (it!=_end) {
            std::cout << _buffer[it] << " ";
            it ++;
            if (it == _capacity)
                it = 0;
        }
        std::cout<<_buffer[it] << ' ';
        std::cout << '\n';
    }


};

#endif
