#pragma once

#include "CIntDef.h"

#ifdef __cplusplus
extern "C" {
#endif

void* memcpy(void* dest, const void* src, USize count);
void* memmove(void* dest, const void* src, USize count);
void* memset(void* dest, int c, USize count);

#ifdef __cplusplus
}
#endif