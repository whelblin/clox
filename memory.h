#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8: (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCap, newCap) \
    (type*)reallocate(pointer,sizeof(type) * oldCap, sizeof(type)*newCap)
#define FREE_ARRAY(type, pointer,oldCap) \
    reallocate(pointer, sizeof(type)*oldCap, 0)
void* reallocate(void* pointer, size_t oldSize, size_t newSize);
#endif 