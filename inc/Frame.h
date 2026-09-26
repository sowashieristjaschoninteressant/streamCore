#pragma once
#include <cstddef>
#include <ctime>
#include <vector>
#include <chrono>
#include <cstdint>

typedef struct {
    std::uint64_t frame_id;
    std::chrono::steady_clock::time_point timestamp;
    std::vector<std::byte> payload;
} Frame;