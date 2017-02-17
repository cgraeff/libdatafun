TARGET = libdatafun
INCLUDE = -I../headers/
CC = gcc
CFLAGS = -Wall -Wno-unknown-pragmas

# Add path for gsl from Homebrew in OSX
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	INCLUDE = -I/usr/local/include
endif

.PHONY: default all clean

all: default

debug: CFLAGS += -g
debug: lib

default: CFLAGS += -O3
default: lib

lib: $(TARGET)

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard ../headers/*.h)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	@ar -cq $(TARGET).a *.o
	@mv $(TARGET).a ..

clean:
	@-rm -f *.o
	@-rm -f *.a
