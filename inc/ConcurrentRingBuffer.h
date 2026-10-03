#pragma once
#include <mutex>
#include <condition_variable>
#include "RingBuffer.h"

template <typename T>
class ConcurrentRingBuffer{
    private:
    RingBuffer<T> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    
    bool empty(){
        const std::lock_guard<std::mutex> guard(mtx);
        return buffer.empty();
    }
    public:
    ConcurrentRingBuffer(size_t cap): buffer(cap){
    }

    bool waitPop(T& value){

       std::unique_lock<std::mutex> lock(mtx);
       cv.wait(lock,[this]{
            return !buffer.empty();
        });

       return buffer.pop(value);
    }

    bool tryPush(T&& item){
        std::unique_lock<std::mutex> lock(mtx);
        bool wasEmpty{false};
        bool success{false};
        
        wasEmpty = empty();
        success = buffer.push(std::move(item));

        if(wasEmpty && success)
            cv.notify_one();
        
        return successfull;      
    }

    
  

};