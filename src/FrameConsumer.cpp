#include "FrameConsumer.h"
#include "streamcutils.h"
#include <chrono>
#include <thread>

bool FrameConsumer::consumeFrame()
{
  Frame frame;

  if (!buffer.pop(frame)) {
    return false;
  }

  auto now = std::chrono::steady_clock::now();
  auto diff = now - frame.timestamp;
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();

  info("consume frame: %i", frame.frame_id);
  info("latency: %i", ms);
  info("payload bytes: %i", frame.payload.size());
  return true;
}

void FrameConsumer::consumeWorker(void)
{   
    int consumed{0};
    info("consumeThread started!");
    while(this->running){
        if(this->consumeFrame())
          consumed++;
        
    }

    info("frames consumed: %i", consumed);
}

void FrameConsumer::start(void)
{
  this->running = true;
  
  worker = std::thread(&FrameConsumer::consumeWorker, this);
}
void FrameConsumer::stop(void)
{
  this->running = false;
  if(worker.joinable())
    worker.join();
  
}