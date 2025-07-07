#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void* memcpy(void* dest, const void* src, size_t count);
void* memove(void* dest, const void* src, size_t count);
void* memset(void* dest, int c, size_t count);

#ifdef __cplusplus
}
#endif