#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>
#include <stddef.h>

struct list {
  int64_t value;
  struct list* next;
};

struct list* node_create( int64_t value );

void list_destroy( struct list* list );
void list_add_front( struct list** old, int64_t value );

struct list* list_last( struct list * list );

void list_add_back( struct list** old, int64_t value );

size_t list_length( struct list const* list );

struct list* list_node_at( struct list* list, size_t idx );
struct maybe_int64 list_at(struct list* list, size_t idx);

struct list* list_reverse( const struct list* list );

void list_print(const struct list* l);

#endif
