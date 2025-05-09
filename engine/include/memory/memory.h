#pragma once

#include "CubicEngine/defines.h"

typedef struct cubic_memory_allocator {
    b running;
    u64 allocated;
    u64 reallocated;
    u64 freed;
} cubic_memory_allocator;

void cubic_memory_startup(void);

void cubic_memory_shutdown(void);

cubic_memory_allocator cubic_memory_getAllocator(void);

void* cubic_memory_allocate(const u64 size);

void* cubic_memory_reallocate(void* memory, const u64 size);

void* cubic_memory_free(void* memory);

void cubic_memory_clear(void* memory, const u64 size);
