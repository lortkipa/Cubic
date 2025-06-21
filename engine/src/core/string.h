#pragma once

#include "defines.h"

typedef struct String {
    char* data;
    u32 length;
} String;

EXPORT String CreateString(void);

EXPORT void DestroyString(String* p_string);

EXPORT void AsignString(String* p_string, const char* data);
