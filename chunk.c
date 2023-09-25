#include <stdlib.h>
#include <stdio.h>
#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk* chunk){
    chunk->size = 0;
    chunk->capacity = 0;
    initValueArray(&chunk->constants);
    chunk->code = NULL;
    chunk->lines = NULL;
}

/*
adds a byte of code to the chuck of memory
It increase the size of chuck by 2 if there is no space left
it adds the byte and its line number to the arrays
*/
void writeChunk(Chunk* chunk, uint8_t byte, int line){
    if(chunk->size + 1 >= chunk->capacity){
        int oldCap = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCap);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,oldCap, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldCap, chunk->capacity);
    }

    chunk->code[chunk->size] = byte;
    chunk->lines[chunk->size] = line;
    chunk->size++;
}
/*
frees the chuck by deallocating the arrays
*/
void freeChunk(Chunk* chunk){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
}

int addConstant(Chunk* chunk, Value value){
    writeValueArray(&chunk->constants, value); // writes the value to constant array
    return chunk->constants.size -1; // returns the index of the value
}