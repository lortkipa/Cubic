#include "CubicEngine/memory/memory.h"
#include "CubicEngine/debug/logger.h"
#include "CubicEngine/debug/assert.h"

#include <stdlib.h>
#include <string.h>

// singleton allocator structure
cubic_memory_allocator allocator;

void cubic_memory_startup(void)
{
    // start the system
    allocator.running = true;

    // zero out stuff
    allocator.allocated = 0;
    allocator.reallocated = 0;
    allocator.freed = 0;

    // log
    CUBIC_LOG_SUCCESS("memory allocator started tracking");
}

void cubic_memory_shutdown(void)
{
    // stop the system
    allocator.running = false;

    // log
    CUBIC_LOG_SUCCESS("memory allocator stoped tracking");
    CUBIC_LOG_TRACE("(count) allocated: {i}. reallocated: {i}. freed: {i}", allocator.allocated, allocator.reallocated, allocator.freed);
}

cubic_memory_allocator cubic_memory_getAllocator(void)
{
    // return allocator structure
    return allocator;
}

void* cubic_memory_allocate(const u64 size)
{
    // check for errors
    CUBIC_ASSERT(size > 1, "can not allocate memory of less then zero bytes");

    // track allocation
    if (allocator.running)
    {
        allocator.allocated++;
    }

    // allocate new memory
    void* newMemory = malloc(size);

    // check for errors
    CUBIC_ASSERT(newMemory != NULL, "memory not allocated");

    // return new memory
    return newMemory;
}

void* cubic_memory_reallocate(void* memory, const u64 size)
{
    // check for errors
    CUBIC_ASSERT(memory != NULL, "can not reallocate memory of invalid pointer");
    CUBIC_ASSERT(size > 1, "can not reallocate memory of less then zero bytes");

    // track reallocation
    if (allocator.running)
    {
        allocator.reallocated++;
    }

    // reallocate new memory
    void* newMemory = realloc(memory, size);
    
    // check for errors
    CUBIC_ASSERT(newMemory != NULL, "memory not reallocated");

    // return new memory
    return newMemory;
}

void* cubic_memory_free(void* memory)
{
    // check for errors
    CUBIC_ASSERT(memory != NULL, "can not free memory of invalid pointer");

    // track free
    if (allocator.running)
    {
        allocator.freed++;
    }

    // free the memory
    free(memory);

    // return NULL as sign of "memory is freed"
    return NULL;
}

void cubic_memory_clear(void* memory, const u64 size)
{
    // clear the memory with zeros
    memset(memory, 0, size);
}
