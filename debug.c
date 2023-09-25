#include <stdio.h>

#include "debug.h"
# include "value.h"
void disassembleChunk(Chunk* chunk, const char* name){
    printf("== %s ==\n", name);

    for(int offset = 0; offset < chunk->size;){
       offset =  disassembleInstruction(chunk, offset);
    }
}

static int simpleInstruction(const char* name, int offset){
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
  uint8_t constant = chunk->code[offset + 1];
  // name is opcode
  // constant is the index(memory spot) spot for the value in the constants array
  printf("%-16s 0X%04X '", name, constant);
  printValue(chunk->constants.values[constant]);
  printf("'\n");
  return offset + 2;
}
int disassembleInstruction(Chunk* chunk, int offset){
    printf("%04d ", offset);
    if(offset > 0 && chunk->lines[offset] == chunk->lines[offset-1]){
        printf("    |");
    }
    else{
        printf("%4d ", chunk->lines[offset]);
    }
    uint8_t instr = chunk->code[offset];
    switch(instr){
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        default:
            printf("Unknown opcode %d", instr);
            return offset + 1;
    }

}
