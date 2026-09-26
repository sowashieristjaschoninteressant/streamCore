#pragma once
#include <cstddef> 
#include <cstdint>
#include <memory>
#include <chrono>
#include "Frame.h"

class FrameProducer{
    private:
    std::uint64_t current_frameId{0};
    size_t payloadSize{0};
    std::vector<std::byte> generateBytes(size_t amount);

    public:
    FrameProducer(size_t payloadSize):payloadSize(payloadSize){

    }
 

   Frame produceFrame();
};