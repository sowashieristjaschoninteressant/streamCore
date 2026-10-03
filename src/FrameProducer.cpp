#include <memory>
#include <cstddef>
#include <random>
#include <thread>
#include <chrono>
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

     return {
        this->current_frameId++,
        std::chrono::steady_clock::now(),
        generateBytes(payloadSize)
    };
}

void FrameProducer::produceWorker(void){
    constexpr auto frameDuration = std::chrono::duration<double>(1.0 / 60.0);
    int produced{0};
    int dropped{0};
    auto nextFrameTime = std::chrono::steady_clock::now();

    while(this->running){
        auto frame = produceFrame();
        
        if(buffer.push(std::move(frame)))
            produced++;
        else
            dropped++;
       
        nextFrameTime += std::chrono::duration_cast<std::chrono::steady_clock::duration>(frameDuration);
        
        std::this_thread::sleep_until(nextFrameTime);
    }

    info("frames produced: %i", produced);
    info("frames dropped: %i", dropped);
    
}

void FrameProducer::start(void){
     this->running = true;
     info("producerThread started!");
     worker = std::thread(&FrameProducer::produceWorker, this);
}

void FrameProducer::stop(void){
    this->running = false;

    if(worker.joinable())
        worker.join();
}