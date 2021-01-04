CC=gcc 
CFLAGS=-std=c18 -Wall -pedantic-errors -ggdb


TARGET ?= vm
SRC_DIRS ?= ./

SRCS := $(shell find $(SRC_DIRS) -name '*.c' )
OBJS := $(addsuffix .o,$(basename $(SRCS)))

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))


$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)


