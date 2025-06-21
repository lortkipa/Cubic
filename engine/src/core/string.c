#include "core/string.h"
#include "core/memory.h"
#include "core/assert.h"
#include <string.h>

String CreateString(void)
{
    // create structure
    String string;

    // zero out structure
    string.data = null;
    string.length = 0;

    // return created string
    return string;
}

void DestroyString(String* p_string)
{
    // check params
    Assert("String", p_string != null, "Invalid String Pointer");

    // if data is not null, free it from heap
    if (p_string->data)
    {
        FreeMemory(p_string->data, p_string->length + 1);
    }

    // update length
    p_string->length = 0;
}

void AsignString(String* p_string, const char* data)
{
    // check params
    Assert("String", p_string != null, "Invalid String Pointer");
    Assert("String", data != null, "Invalid Data Pointer");

    // if there is string data on heap, free it
    if (p_string->data)
    {
        FreeMemory(p_string->data, p_string->length + 1);
    }
    
    // update length
    p_string->length = strlen(data);

    // allocate memory
    p_string->data = AllocateMemory(p_string->length + 1);

    // asign memory
    strcpy_s(p_string->data, p_string->length + 1, data);
}
