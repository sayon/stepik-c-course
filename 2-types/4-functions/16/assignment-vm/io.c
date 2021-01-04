#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdlib.h>

#include "io.h"


uint64_t read_uint64() { uint64_t i; scanf("%" SCNu64 , &i); return i; }
int64_t read_int64() { int64_t i; scanf("%" SCNd64 , &i); return i; }
size_t read_size() { size_t i; scanf("%zu", &i); return i; }
void print_uint64( uint64_t i ) { printf("%" PRIu64 , i); }
void print_int64( int64_t i ) { printf("%" PRId64 , i); }
void print_newline(void) { printf("\n"); }

void err( const char* msg, ... ) {
  va_list args;
  va_start (args, msg);
  vfprintf(stderr, msg, args);
  va_end (args);
  abort();
}
