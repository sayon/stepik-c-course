#ifndef _IO_H_
#define _IO_H_

#include <stdint.h>

uint64_t read_uint64();
int64_t read_int64();
size_t read_size();
void print_uint64( uint64_t );
void print_int64( int64_t );
void print_newline(void);

void err( const char* msg, ... );

#endif
