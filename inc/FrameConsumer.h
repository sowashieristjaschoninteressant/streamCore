#pragma once
#include "Frame.h"
#include <vector>
#include <RingBuffer.h>

class FrameConsumer{
    private:
    RingBuffer<Frame>& buffer;
    
    

    public:
    
    FrameConsumer(RingBuffer<Frame>& buff): buffer(buff){

    }
    bool consumeFrame();
};