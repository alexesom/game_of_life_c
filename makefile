CC = cc
CFLAGS = -Wall -pedantic -std=c11 -g
CFLAGS_OBJ = -Wall -pedantic -std=c11 -g -c
objects = bin/main.o bin/alloc.o bin/evolve.o bin/generator.o bin/save2image.o bin/tester.o bin/toml_parser.o bin/array_functions.o bin/neighbours.o bin/memory_free.o bin/gifenc.o bin/parse_arg.o

all: main alloc evolve generator save2image tester toml_parser array_functions neighbours memory_free arg_parser
	$(CC) $(CFLAGS) -o game.out $(objects) -lm

main:
	$(CC) $(CFLAGS_OBJ) src/main.c -o bin/main.o

alloc: 
	$(CC) $(CFLAGS_OBJ) src/alloc.c -o bin/alloc.o

evolve: 
	$(CC) $(CFLAGS_OBJ) src/evolve.c -o bin/evolve.o

neighbours: 
	$(CC) $(CFLAGS_OBJ) src/neighbours.c -o bin/neighbours.o

array_functions: 
	$(CC) $(CFLAGS_OBJ) src/array_functions.c -o bin/array_functions.o

toml_parser: 
	$(CC) $(CFLAGS_OBJ) src/toml_parser.c -o bin/toml_parser.o

tester: 
	$(CC) $(CFLAGS_OBJ) src/tester.c -o bin/tester.o

generator: 
	$(CC) $(CFLAGS_OBJ) src/generator.c -lm -o bin/generator.o

memory_free: 
	$(CC) $(CFLAGS_OBJ) src/memory_free.c -o bin/memory_free.o

save2image:
	$(CC) $(CFLAGS_OBJ) src/gifenc/gifenc.c -o bin/gifenc.o
	$(CC) $(CFLAGS_OBJ) src/save2image.c -lm -o bin/save2image.o

arg_parser:
	$(CC) $(CFLAGS_OBJ) src/parse_arg.c -o bin/parse_arg.o


.PHONY: clean

clean:
	-rm bin/*.o *.out bin/*.a ./src/result_files/*.toml ./src/result_files/*.txt ./src/result_files/*.jpg ./src/result_files/*.png ./src/result_files/*.gif 
