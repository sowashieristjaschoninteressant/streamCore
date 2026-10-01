#include <thread>
#include <chrono>
#include "RingBuffer.h"
#include "FrameProducer.h"
#include "FrameConsumer.h"
#include "streamcutils.h"


int main(){

  
    RingBuffer<Frame> buffer(20);
    FrameProducer producer(5000, buffer);
    FrameConsumer consumer(buffer);

    producer.start();
    consumer.start();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    producer.stop();
    consumer.stop();

    return 0;
}