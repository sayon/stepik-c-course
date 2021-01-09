#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "maybe_int.h"
#include "io.h"

#error Вставьте часть решения https://stepik.org/lesson/408350/step/8 содержащую нужные функции и исключая read_int64, maybe_int64_print и определение struct list.

/*
 Список нужных определений:

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

*/
