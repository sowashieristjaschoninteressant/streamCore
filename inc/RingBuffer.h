#pragma once

#include <cstddef>
#include <vector>
#include <mutex>
#include <assert.h>

template <typename T>
class RingBuffer
{
private:
    std::vector<T> buffer;
    size_t current_capacity{0};
    size_t current_size{0};
    size_t read{0}, write{0};

public:
    RingBuffer(size_t cap) : current_capacity(cap), buffer(cap)
    {   
        // zero capacity should be a bug from the programmer so i will for now just abort
        assert(cap > 0);
        
    }

    bool push(T&& item){
       

        if (current_size == current_capacity)
            return false;    
        
        buffer[write] =  std::move(item);
        current_size++;

        write == (current_capacity -1) ? write = 0 : write++;

        return true;
    }

    bool push(const T& item)
    {
       
        if (current_size == current_capacity)
            return false;    

        buffer[write] = item;
        current_size++;
        
        write == (current_capacity -1) ? write = 0 : write++;

        return true;
    }

    bool pop(T& value){
        
       
        if(empty()){
            return false;
        }

        value = std::move(buffer[read]);

        current_size--;

        read == (current_capacity -1) ? read = 0 : read++;

        return true;
    }

    bool empty () const {
       
        return current_size == 0;
    }

    bool full() const {
        
        return current_size == current_capacity;}

    size_t size() const{ 
        
        return current_size;
    }
    size_t capacity() const{
         return current_capacity;
        }

};