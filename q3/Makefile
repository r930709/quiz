CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -g

EXEC = iterative recursive
all: $(EXEC)
SRCS_common = main.c

iterative: main.c iterative.c
	$(CC) $(CFLAGS_common) -DITER -o $@ \
		$(SRCS_common) Binary_tree.c $@.c

recursive: main.c recursive.c
	$(CC) $(CFLAGS_common) -DRECUR -o $@ \
		$(SRCS_common) Binary_tree.c $@.c
run:$(EXEC)
	@echo --------Recursive Version Start--------                       
	@./recursive
	@echo --------Recursive Version End----------
	@echo --------Iterative Version Start--------                       
	@./iterative
	@echo --------Iterative Version End----------

clean:
	$(RM) $(EXEC) *.o perf.*
