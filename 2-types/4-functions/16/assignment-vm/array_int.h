#ifndef _ARRAY_INT_H_
#define _ARRAY_INT_H_

#include <stdint.h>
#include <stdbool.h>

struct array_int {
    int64_t* data; 
    size_t size;
};

struct array_int array_int_create( size_t sz );
int64_t* array_int_last( struct array_int a );
struct maybe_int64 array_int_get( struct array_int a, size_t i );
bool array_int_set( struct array_int a, size_t i, int64_t value );
void array_int_print( struct array_int array );
void array_int_free( struct array_int* a );

#endif
