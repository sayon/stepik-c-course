#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "maybe_int.h"
#include "array_int.h"

struct stack {
  size_t count;
  struct array_int data;
};

struct stack stack_create( size_t size );
void stack_destroy( struct stack* s );
bool stack_full( struct stack s);
bool stack_empty( struct stack s);

bool stack_push( struct stack* s, int64_t value );
struct maybe_int64 stack_pop( struct stack* s );
void stack_print( struct stack s );

#endif
