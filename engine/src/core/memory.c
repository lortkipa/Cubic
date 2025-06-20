#include "core/memory.h"
#include "core/assert.h"
#include "core/logger.h"
#include <stdlib.h>

static MemoryTracker tracker = {};

b8 StartupMemorySystem(void)
{
    // make sure system is not started
    Assert("Memory", !tracker.running, "System Is Already Initialized");

    // startup system
    tracker.running = true;
    LogSuccess("Memory", "System Initialized");

    // no reason to return failure
    return true;
}

void ShutdownMemorySystem(void)
{
    // make sure system is started
    Assert("Memory", tracker.running, "System Is Not Already Initialized Yet");

    // shutdown system
    tracker.running = false;
    LogSuccess("Memory", "System Terminated");
    
    // log memory tracker stats
    LogInfo("Memory", "Allocated: %dB. Freed: %dB. Usage: %dB",
            tracker.allocated, tracker.freed, tracker.usage);

    // zero out tracker
    tracker.allocated = 0;
    tracker.freed = 0;
    tracker.usage = 0;
}

void* AllocateMemory(const u16 size)
{
    // check params
    Assert("Memory", size > 0, "Invalid Size");

    // allocate memory
    void* memory = malloc(size);

    // log result and track it
    if (memory)
    {
        if (tracker.running)
        {
            tracker.allocated += size;
            tracker.usage += size;
        }
        LogSuccess("Memory", "Allocated %dB. Usage: %dB", size, tracker.usage);
    }
    else
    {
        LogError("Memory", "Failed To Allocate %dB", size);
    }

    // return allocated memory pointer
    return memory;
}

void FreeMemory(void* memory, const u16 size)
{
    // check params
    Assert("Memory", memory != null, "Invalid Memory");
    Assert("Memory", size > 0, "Invalid Size");

    // log result and track it
    if (tracker.running)
    {
        tracker.freed += size;
        tracker.usage -= size;
    }
    LogSuccess("Memory", "Freed %dB. Usage: %dB", size, tracker.usage);

    // free provided memory
    free(memory);
}
