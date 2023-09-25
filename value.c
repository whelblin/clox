#include <stdlib.h>
#include <stdio.h>
#include "chunk.h"
#include "memory.h"


void initValueArray(ValueArray* array){
    array->size = 0;
    array->capacity = 0;
    array->values = NULL;
}
void writeValueArray(ValueArray* array, Value value){
    if(array->capacity < array->size + 1){
        int oldCap = array->capacity;
        array->capacity = GROW_CAPACITY(oldCap);
        array->values = GROW_ARRAY(Value, array->values, oldCap, array->capacity);
    }
    array->values[array->size++] = value;
}
void freeValueArray(ValueArray* array){
    FREE_ARRAY(Value, array->values, array->capacity);
    initValueArray(array);
}

void printValue(Value value) {
  printf("%g", value);
}