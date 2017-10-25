CC=gcc
LIBS=-lzyre -lczmq -lzmq

all: zyre_listener zyre_shouter zyre_whisperer

zyre_listener: zyre_listener.c
	gcc -o $@ $^ $(LIBS)
zyre_shouter: zyre_shouter.c
	gcc -o $@ $^ $(LIBS)
zyre_whisperer: zyre_whisperer.c
	gcc -o $@ $^ $(LIBS)
