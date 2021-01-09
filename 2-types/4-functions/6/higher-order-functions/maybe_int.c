#include <stdio.h>
#include <inttypes.h>

#include "maybe_int.h"


struct maybe_int64 some_int64(int64_t i) {return (struct maybe_int64) { i, true };}
const struct maybe_int64 none_int64 = { 0 };



