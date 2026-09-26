#include "tests.h"
#include "RingBuffer.h"
#include <assert.h>
#include <streamcutils.h>

void RingbufferTests::ringBufferTests(void)
{

    info("starting ringbufferTests");
    RingbufferTests::stressTestWRapAround();
    RingbufferTests::bufferPushOneToMutch();
    info("ending ringbuffertests");
    return;
}

void RingbufferTests::stressTestWRapAround(void)
{
    constexpr size_t capacity{3};

    RingBuffer<int> buffer(capacity);

    for (int i = 10; i < 40; i += 10)
    {

        assert(buffer.push(i));
    }

    int value{0}, expected{10};
    buffer.pop(value);

    assert(value == expected);

    assert(buffer.push(20));

    assert(buffer.pop(value));
    assert(buffer.pop(value));
    assert(buffer.pop(value));
    assert(!buffer.pop(value));
    buffer.push(20);
    buffer.push(40);
    buffer.pop(value);

    okay("stresstest wraparound successfull!");
    return;
}

void RingbufferTests::bufferPushOneToMutch(void)
{

    constexpr size_t capacity{3};

    RingBuffer<int> buffer(capacity);

    buffer.push(20);
    buffer.push(30);
    buffer.push(40);
    assert(!buffer.push(50));
    assert(buffer.full());
    assert(buffer.size() == capacity);

    okay("buffer doesnt allow more pushing if full good!");
    return;
}