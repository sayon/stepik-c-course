#ifndef _MAYBE_INT_H_
#define _MAYBE_INT_H_

#include <stdint.h>
#include <stdbool.h>

struct maybe_int64 {
    int64_t value; 
    bool valid; 
};

struct maybe_int64 some_int64(int64_t i);

extern const struct maybe_int64 none_int64;

void maybe_int64_print( struct maybe_int64 i );

#endif
