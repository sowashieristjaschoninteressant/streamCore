#include <memory>
#include <cstddef>
#include <random>
#include "FrameProducer.h"
#include "streamcutils.h"

std::vector<std::byte> FrameProducer::generateBytes(size_t amount){

    std::vector<std::byte> payload(amount);

    for(size_t i = 0; i < amount; i++){
        payload[i] = static_cast<std::byte>(0xFF);
    }

    return payload;
}

Frame FrameProducer::produceFrame(){

    return Frame{
        this->current_frameId++,
        std::chrono::steady_clock::now(),
        generateBytes(payloadSize)
    };
}