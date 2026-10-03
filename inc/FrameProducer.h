#pragma once
#include <cstddef> 
#include <cstdint>
#include <memory>
#include <chrono>
#include <atomic>
#include "Frame.h"
#include "RingBuffer.h"
#include <thread>

class FrameProducer{
    private:
    std::atomic<std::uint64_t> current_frameId{0};
    std::atomic<bool> running{false};
    std::thread worker;
    RingBuffer<Frame>& buffer;
    size_t payloadSize{0};
    std::vector<std::byte> generateBytes(size_t amount);
    Frame produceFrame();
    void produceWorker(void);
    
    public:
    FrameProducer(size_t payloadSize, RingBuffer<Frame>& buff): payloadSize(payloadSize), buffer(buff){

    }

    void start(void);
    void stop(void);
};