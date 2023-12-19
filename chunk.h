// chunk = sequence of bytecode

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// each instruction in this language is represented by a 1-byte opcode (operation code)
typedef enum {
  OP_RETURN,
} OpCode;

typedef struct {
  int count;     // used array elements
  int capacity;  // total array size (allocated)
  uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif