CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -g

#EXEC = iterative recursive
EXEC = recursive
all: $(EXEC)

#iterative: iterative.c
#	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: main.c Binary_tree.o recursive.o
	$(CC) -o $@ $^
%.o : %.c
	$(CC) -c $(CFLAGS_common) -o $@ $^

run:$(EXEC)
	@echo --------Recursive Version Start--------                       
	@./recursive
	@echo --------Recursive Version End----------

clean:
	$(RM) $(EXEC) *.o perf.*
