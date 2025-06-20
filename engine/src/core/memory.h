#pragma once

#include "defines.h"

typedef struct MemoryTracker {
    b8 running;
    u32 allocated;
    u32 freed;
    u32 usage;
} MemoryTracker;

EXPORT b8 StartupMemorySystem(void);

EXPORT void ShutdownMemorySystem(void);

EXPORT void* AllocateMemory(const u16 size);

EXPORT void FreeMemory(void* memory, const u16 size);
