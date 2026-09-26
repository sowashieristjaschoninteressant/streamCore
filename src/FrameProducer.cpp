#include <memory>
#include <cstddef>
#include <random>
#include "FrameProducer.h"
#include "streamcutils.h"

std::vector<std::byte> FrameProducer::generateBytes(size_t amount){

    std::vector<std::byte> payload(amount);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 255);

    for(size_t i = 0; i < amount; i++){
        payload[i] = static_cast<std::byte>(dist(gen));
    }

    return payload;
}

Frame FrameProducer::produceFrame(){

    if(current_frameId == _UI64_MAX){
        // what to do here?
        warn("max frameID reached frame Ids will duplicate now!");
    }

    return Frame{
        this->current_frameId++,
        std::chrono::steady_clock::now(),
        generateBytes(payloadSize)
    };
}