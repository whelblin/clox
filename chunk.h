#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// the opcodes that the language can use
typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

/*
the chunk of memory
it contains an array of code and an array that has the amount of lines
It also has a ValueArray that stores the constants stored in the chuck
*/
typedef struct {
    int size; // amount of elements used
    int capacity; // amount of spots
    ValueArray constants;
    uint8_t* code;
    int* lines;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void freeChunk(Chunk* chunk);
int addConstant(Chunk* chunk, Value value);

#endif