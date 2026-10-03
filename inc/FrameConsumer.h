#pragma once
#include "Frame.h"
#include <vector>
#include <atomic>
#include <RingBuffer.h>
#include <thread>

class FrameConsumer{
    private:
    RingBuffer<Frame>& buffer;
    std::thread worker;
    std::atomic<bool> running{false};
    std::condition_variable cv;
    void consumeWorker();
    bool consumeFrame();
    public:
    
    void start(void);
    void stop(void);
    FrameConsumer(RingBuffer<Frame>& buff): buffer(buff){

    }
  
};