// chunk = sequence of bytecode

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// each instruction in this language is represented by a 1-byte opcode (operation code)
typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OpCode;

typedef struct {
  int count;     // used array elements
  int capacity;  // total array size (allocated)
  uint8_t* code; // contains opcodes + operands (operand = index of the value in the constants array)
  int* lines;    // lines[i] is the line of code where we got instruction code[i] from
  ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif