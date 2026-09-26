#include "FrameConsumer.h"
#include "streamcutils.h"
#include <chrono>

bool FrameConsumer::consumeFrame(){
    Frame frame;
    
    if(!buffer.pop(frame)){
        return false;
    }

    auto now = std::chrono::steady_clock::now();
    auto diff = now - frame.timestamp;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();


    info("consume frame: %i", frame.frame_id);
    info("latency: %i",ms);
    info("payload bytes: %i", frame.payload.size());
    return true;
}