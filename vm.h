#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#include "table.h"

#define STACK_MAX 256

typedef struct {
  Chunk* chunk;
  uint8_t* ip; // instruction pointer, points to the instruction to be executed
  Value stack[STACK_MAX];
  Value* stackTop;
  Table strings; // our internalized strings!! this is why string == string works.
  Obj* objects; // all of our heap allocated objects!
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);

void push(Value value);
Value pop();

#endif