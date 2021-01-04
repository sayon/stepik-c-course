#ifndef _MEM_H_
#define _MEM_H_
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>


void* _malloc( size_t sz );
void _free( void* ptr );

#define malloc _malloc
#define free _free
#endif
