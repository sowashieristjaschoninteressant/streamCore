#include "RingBuffer.h"
#include "FrameProducer.h"

int main(){

    FrameProducer f(50);
    RingBuffer<Frame> buffer(20);
    auto frame = f.produceFrame();
    
    buffer.push(frame);

    return 0;
}