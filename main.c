#include "common.h"
#include "chunk.h"
#include "debug.h"
int main(int argc, const char *argv[]){
    Chunk chunk; // creates a chunk
    initChunk(&chunk); // initizes it to 0 

    // 
    int constant = addConstant(&chunk, 1.2); // creats a constant by adding it to the chunks arrayConstants
    writeChunk(&chunk, OP_CONSTANT,123); // adds the opcode for a constant into memory
    writeChunk(&chunk, constant,123); // adds the constant into memory. must be after the opcode
    writeChunk(&chunk, OP_RETURN,123);
    constant = addConstant(&chunk, 1.3);
    writeChunk(&chunk, OP_CONSTANT,124);
    writeChunk(&chunk, constant,124);
    writeChunk(&chunk, OP_RETURN,124);

    disassembleChunk(&chunk, "Testing chunk");
    freeChunk(&chunk);
    return 0;
}