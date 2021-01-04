#include "mem.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


const bool SHOULD_USE_MALLOC = false ;
static void check_after() __attribute__((destructor));


/* ---- malloc/free wrappers ---- */


#define MALLOC_HISTORY_SIZE 1024


enum ptr_status {PTR_ALLOCATED, PTR_FREED,};

static bool ___allocated = false;

struct ptr_entry {
  void* ptr;
  size_t size;
  enum ptr_status status;
};

const struct ptr_entry NO_ENTRY =  {
  .ptr = NULL, .size = 0, .status = PTR_FREED
};

static bool ptr_entry_empty( const struct ptr_entry p) {
  return p.ptr == NULL;
}

static struct ptr_entry malloc_pointers[MALLOC_HISTORY_SIZE] = { 0 };

static bool ptr_register( void* ptr, size_t sz ) {
  if (sz) ___allocated = true;
  for (size_t i = 0; i < sizeof(malloc_pointers)/sizeof(malloc_pointers[0]); i++)
    if (ptr_entry_empty( malloc_pointers[i] ) ) {
      malloc_pointers[i] = (struct ptr_entry) { ptr, sz, PTR_ALLOCATED };
      return true;
    }

  return false;
}

static bool ptr_unregister( void* ptr ) {
  for (size_t i = 0; i < sizeof(malloc_pointers)/sizeof(malloc_pointers[0]); i++)
    if ( malloc_pointers[i].ptr == ptr )
      switch (malloc_pointers[i].status)
        {
        case PTR_ALLOCATED: malloc_pointers[i].status = PTR_FREED; break;
        case PTR_FREED: fprintf(stderr,"Trying to free memory twice\n"); abort(); break;
        default: fprintf(stderr,"Not implemented\n"); abort(); break;
        }

  return false;
}

static bool ptr_registered( const void* ptr ) {
  for (size_t i = 0; i < sizeof(malloc_pointers)/sizeof(malloc_pointers[0]); i++)
    if (malloc_pointers[i].ptr == ptr ) return true;
  return false;
}

static void ptr_showall_full(FILE* f) {
  for (size_t i = 0; i < sizeof(malloc_pointers)/sizeof(malloc_pointers[0]); i++)
    if ( ! ptr_entry_empty( malloc_pointers[i] ) )
      fprintf( f, "allocated: %p %zu\n", malloc_pointers[i].ptr, malloc_pointers[i].size );
}

static void ptr_showall(FILE* f) {
  size_t n = 0;
  for (size_t i = 0; i < sizeof(malloc_pointers)/sizeof(malloc_pointers[0]); i++)
    if ( malloc_pointers[i].ptr && malloc_pointers[i].status == PTR_ALLOCATED )
      {
        fprintf( f, "block %zu: %zu\n", n, malloc_pointers[i].size );
        n++;
      }
  fprintf( f, "total: %zu \n", n );
}

static bool ptr_all_deallocated(void) {
  for (size_t i = 0; i < sizeof(malloc_pointers)/sizeof(malloc_pointers[0]); i++)
    if ( malloc_pointers[i].ptr && malloc_pointers[i].status != PTR_FREED ) return false;
  return true;
}

void* _malloc( size_t sz ) {
  void* result = malloc(sz);
  ptr_register( result, sz );
  return result;
}

void _free( void* ptr ) {
  if (ptr) {
    ptr_unregister( ptr );
  }
}



static void check_after() {
  (void)free;
  (void)malloc;
  (void)ptr_registered;
  (void)ptr_showall_full;
  (void)ptr_showall;
  if (!ptr_all_deallocated()) {
    fprintf(stderr, "Not all dynamically allocated memory is freed\n");
    abort();
  }

  if (SHOULD_USE_MALLOC && !___allocated) {
    fprintf(stderr, "You should use malloc\n");
    abort();
  }
}
